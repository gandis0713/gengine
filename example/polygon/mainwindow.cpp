#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "coqtrenderer.h"
#include "copolygon.h"
#include "coobjreader.h"

#include <QDebug>
#include <QFileDialog>

#define INT2FLOAT 200
#define VIEW_SIZE 5000
#define NEAR 1000
#define NEAR_INIT -1000
#define FAR 10000
#define FAR_INIT 10000
#define CAMERA_SIZE 1000
#define TARGET_SIZE 1000

#define SIZE_RATIO 1.5
#define CAMERA_RATIO 3

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->left->setRange(-VIEW_SIZE  * INT2FLOAT, VIEW_SIZE * INT2FLOAT);
    ui->right->setRange(-VIEW_SIZE  * INT2FLOAT, VIEW_SIZE * INT2FLOAT);
    ui->bottom->setRange(-VIEW_SIZE  * INT2FLOAT, VIEW_SIZE * INT2FLOAT);
    ui->top->setRange(-VIEW_SIZE  * INT2FLOAT, VIEW_SIZE * INT2FLOAT);
    ui->lnear->setRange(-NEAR * INT2FLOAT, NEAR * INT2FLOAT);
    ui->lfar->setRange(NEAR * INT2FLOAT, FAR * INT2FLOAT);

    connect(ui->left, SIGNAL(sliderMoved(int)), this, SLOT(SlotLeftChanged(int)));
    connect(ui->right, SIGNAL(sliderMoved(int)), this, SLOT(SlotRightChanged(int)));
    connect(ui->bottom, SIGNAL(sliderMoved(int)), this, SLOT(SlotBottomChanged(int)));
    connect(ui->top, SIGNAL(sliderMoved(int)), this, SLOT(SlotTopChanged(int)));
    connect(ui->lnear, SIGNAL(sliderMoved(int)), this, SLOT(SlotNearChanged(int)));
    connect(ui->lfar, SIGNAL(sliderMoved(int)), this, SLOT(SlotFarChanged(int)));

    ui->SCameraX->setRange(-CAMERA_SIZE, CAMERA_SIZE);
    ui->SCameraY->setRange(-CAMERA_SIZE, CAMERA_SIZE);
    ui->SCameraZ->setRange(-CAMERA_SIZE, CAMERA_SIZE);
    ui->STargetX->setRange(-TARGET_SIZE, TARGET_SIZE);
    ui->STargetY->setRange(-TARGET_SIZE, TARGET_SIZE);
    ui->STargetZ->setRange(-TARGET_SIZE, TARGET_SIZE);

    connect(ui->SCameraX, SIGNAL(sliderMoved(int)), this, SLOT(SlotCameraXChanged(int)));
    connect(ui->SCameraY, SIGNAL(sliderMoved(int)), this, SLOT(SlotCameraYChanged(int)));
    connect(ui->SCameraZ, SIGNAL(sliderMoved(int)), this, SLOT(SlotCameraZChanged(int)));
    connect(ui->STargetX, SIGNAL(sliderMoved(int)), this, SLOT(SlotTargetXChanged(int)));
    connect(ui->STargetY, SIGNAL(sliderMoved(int)), this, SLOT(SlotTargetYChanged(int)));
    connect(ui->STargetZ, SIGNAL(sliderMoved(int)), this, SLOT(SlotTargetZChanged(int)));

    initialize();

    // camera

    ui->STargetX->setValue(0);
    SlotTargetXChanged(0);

    ui->STargetY->setValue(0);
    SlotTargetYChanged(0);

    ui->STargetZ->setValue(0);
    SlotTargetZChanged(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialize()
{
    m_pRender = new CoQtRenderer(ui->widget);
    m_pOrthoCamera = new CoOrthographicCamera();

    m_pCamera = m_pOrthoCamera;
    m_pRender->setCamera(m_pCamera);

    QString strOBJFilePath = QFileDialog::getOpenFileName(this,
                                         "Select OBJ file",
                                         ".",
                                         "");

    const Gchar *pPath = strOBJFilePath.toLocal8Bit().constData();

    CoOBJReader *pOBJReader = new CoOBJReader();

    std::vector<CoVec3> vecTempVertices;
    std::vector<CoVec2> vecUVCoords;
    std::vector<CoVec3> vecTempVertexNormals;
    CoFaceIndex faceIndices;

    pOBJReader->load(pPath,
                     vecTempVertices,
                     vecUVCoords,
                     vecTempVertexNormals,
                     faceIndices);

    std::vector<Guint> vecVertexIndices;
    faceIndices.getVertexIndices(vecVertexIndices);    

    std::vector<Guint> vecVertexNormalIndices;
    faceIndices.getVertexNormalIndices(vecVertexNormalIndices);

    std::vector<CoVec3> vecVertices;
    std::vector<CoVec3> vecVertexNormals;

    Gbool bNormalEmpty = false;
    if(vecTempVertexNormals.size() == 0)
    {
        bNormalEmpty = true;
    }

    for(Gint nIndex = 0; nIndex < vecVertexIndices.size(); nIndex += 3)
    {
        CoVec3 vPoint[3];
        vPoint[0] = vecTempVertices[vecVertexIndices[nIndex] - 1];
        vPoint[1] = vecTempVertices[vecVertexIndices[nIndex + 1] - 1];
        vPoint[2] = vecTempVertices[vecVertexIndices[nIndex + 2] - 1];

        vecVertices.push_back(vPoint[0]);
        vecVertices.push_back(vPoint[1]);
        vecVertices.push_back(vPoint[2]);

        if(bNormalEmpty == true)
        {
            CoVec3 vP2P1 = vPoint[1] - vPoint[0];
            CoVec3 vP3P1 = vPoint[2] - vPoint[0];
            CoVec3 vNormal = vP2P1.cross(vP3P1);
            vNormal.normalize();

            vecVertexNormals.push_back(vNormal);
            vecVertexNormals.push_back(vNormal);
            vecVertexNormals.push_back(vNormal);
        }
        else
        {
            CoVec3 vNormal[3];
            vNormal[0] = vecTempVertexNormals[vecVertexNormalIndices[nIndex] - 1];
            vNormal[1] = vecTempVertexNormals[vecVertexNormalIndices[nIndex + 1] - 1];
            vNormal[2] = vecTempVertexNormals[vecVertexNormalIndices[nIndex + 2] - 1];

            vecVertexNormals.push_back(vNormal[0]);
            vecVertexNormals.push_back(vNormal[1]);
            vecVertexNormals.push_back(vNormal[2]);
        }
    }

    CoPolygon *pPolygon = new CoPolygon();

    pPolygon->setPoints(vecVertices);
    pPolygon->setNormals(vecVertexNormals);

    m_pRender->addNode(pPolygon);




    CoVec3 vMin = CoVec3( 10000,  10000,  10000);
    CoVec3 vMax = CoVec3(-10000, -10000, -10000);
    for(Gint nIndex = 0; nIndex < vecVertices.size(); nIndex++)
    {
        CoVec3 vPoint = vecVertices[nIndex];

        if(vMin[0] > vPoint[0])
        {
            vMin[0] = vPoint[0];
        }
        if(vMin[1] > vPoint[1])
        {
            vMin[1] = vPoint[1];
        }
        if(vMin[2] > vPoint[2])
        {
            vMin[2] = vPoint[2];
        }

        if(vMax[0] < vPoint[0])
        {
            vMax[0] = vPoint[0];
        }
        if(vMax[1] < vPoint[1])
        {
            vMax[1] = vPoint[1];
        }
        if(vMax[2] < vPoint[2])
        {
            vMax[2] = vPoint[2];
        }
    }

    ui->left->setValue(vMin[0] * INT2FLOAT * SIZE_RATIO);
    SlotLeftChanged(vMin[0] * INT2FLOAT * SIZE_RATIO);

    ui->right->setValue(vMax[0] * INT2FLOAT * SIZE_RATIO);
    SlotRightChanged(vMax[0] * INT2FLOAT * SIZE_RATIO);

    ui->bottom->setValue(vMin[1] * INT2FLOAT * SIZE_RATIO);
    SlotBottomChanged(vMin[1] * INT2FLOAT * SIZE_RATIO);

    ui->top->setValue(vMax[1] * INT2FLOAT * SIZE_RATIO);
    SlotTopChanged(vMax[1] * INT2FLOAT * SIZE_RATIO);

    ui->lnear->setValue(NEAR_INIT * INT2FLOAT);
    SlotNearChanged(NEAR_INIT * INT2FLOAT);

    ui->lfar->setValue(FAR_INIT * INT2FLOAT);
    SlotFarChanged(FAR_INIT * INT2FLOAT);



    ui->SCameraX->setValue(0);
    SlotCameraXChanged(0);

    ui->SCameraY->setValue(0);
    SlotCameraYChanged(0);

    ui->SCameraZ->setValue(vMax[2] * CAMERA_RATIO);
    SlotCameraZChanged(vMax[2] * CAMERA_RATIO);
}


void MainWindow::SlotLeftChanged(int value)
{
    leftvalue = (Gfloat)value/(Gfloat)INT2FLOAT;
    ui->lvalue->setText(QString::number(leftvalue));
    m_pCamera->setLeftPosition(leftvalue);
    m_pCamera->update();

}
void MainWindow::SlotRightChanged(int value)
{
    rightvalue = (Gfloat)value/(Gfloat)INT2FLOAT;
    ui->rvalue->setText(QString::number(rightvalue));
    m_pCamera->setRightPosition(rightvalue);
    m_pCamera->update();
}
void MainWindow::SlotBottomChanged(int value)
{
    bottomvalue = (Gfloat)value/(Gfloat)INT2FLOAT;
    ui->bvalue->setText(QString::number(bottomvalue));
    m_pCamera->setBottomPosition(bottomvalue);
    m_pCamera->update();
}
void MainWindow::SlotTopChanged(int value)
{
    topvalue = (Gfloat)value/(Gfloat)INT2FLOAT;
    ui->tvalue->setText(QString::number(topvalue));
    m_pCamera->setTopPosition(topvalue);
    m_pCamera->update();
}
void MainWindow::SlotNearChanged(int value)
{
    nearvalue = (Gfloat)value/(Gfloat)INT2FLOAT;
    ui->nvalue->setText(QString::number(nearvalue));
    m_pCamera->setNearPosition(nearvalue);
    m_pCamera->update();
}
void MainWindow::SlotFarChanged(int value)
{
    farvalue = (Gfloat)value/(Gfloat)INT2FLOAT;
    ui->fvalue->setText(QString::number(farvalue));
    m_pCamera->setFarPosition(farvalue);
    m_pCamera->update();
}

void MainWindow::SlotCameraXChanged(int value)
{
    ui->lCameraX->setText(QString::number(value));
    CoVec3 vPosition = m_pCamera->getPosition();
    vPosition[0] = value;
    m_pCamera->setPosition(vPosition);
    m_pCamera->update();
}

void MainWindow::SlotCameraYChanged(int value)
{
    ui->lCameraY->setText(QString::number(value));
    CoVec3 vPosition = m_pCamera->getPosition();
    vPosition[1] = value;
    m_pCamera->setPosition(vPosition);
    m_pCamera->update();
}

void MainWindow::SlotCameraZChanged(int value)
{
    ui->lCameraZ->setText(QString::number(value));
    CoVec3 vPosition = m_pCamera->getPosition();
    vPosition[2] = value;
    m_pCamera->setPosition(vPosition);
    m_pCamera->update();
}

void MainWindow::SlotTargetXChanged(int value)
{
    ui->lTargetX->setText(QString::number(value));
    CoVec3 vTarget = m_pCamera->getTarget();
    vTarget[0] = value;
    m_pCamera->setTarget(vTarget);
    m_pCamera->update();
}

void MainWindow::SlotTargetYChanged(int value)
{
    ui->lTargetY->setText(QString::number(value));
    CoVec3 vTarget = m_pCamera->getTarget();
    vTarget[1] = value;
    m_pCamera->setTarget(vTarget);
    m_pCamera->update();
}

void MainWindow::SlotTargetZChanged(int value)
{
    ui->lTargetZ->setText(QString::number(value));
    CoVec3 vTarget = m_pCamera->getTarget();
    vTarget[2] = value;
    m_pCamera->setTarget(vTarget);
    m_pCamera->update();
}

