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
#define NEAR_INIT 1
#define FAR 10000
#define FAR_INIT 10000
#define CAMERA_SIZE 1000
#define TARGET_SIZE 1000

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->ortho->setChecked(true);
    connect(ui->pers, SIGNAL(toggled(bool)), this, SLOT(SlotPersToggle(bool)));
    connect(ui->ortho, SIGNAL(toggled(bool)), this, SLOT(SlotOrthoToggle(bool)));

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

    ui->left->setValue(-VIEW_SIZE * INT2FLOAT);
    SlotLeftChanged(-VIEW_SIZE * INT2FLOAT);

    ui->right->setValue(VIEW_SIZE * INT2FLOAT);
    SlotRightChanged(VIEW_SIZE * INT2FLOAT);

    ui->bottom->setValue(-VIEW_SIZE * INT2FLOAT);
    SlotBottomChanged(-VIEW_SIZE * INT2FLOAT);

    ui->top->setValue(VIEW_SIZE * INT2FLOAT);
    SlotTopChanged(VIEW_SIZE * INT2FLOAT);

    ui->lnear->setValue(NEAR_INIT * INT2FLOAT);
    SlotNearChanged(NEAR_INIT * INT2FLOAT);

    ui->lfar->setValue(FAR_INIT * INT2FLOAT);
    SlotFarChanged(FAR_INIT * INT2FLOAT);

    // camera

    ui->SCameraX->setValue(0);
    SlotCameraXChanged(0);

    ui->SCameraY->setValue(0);
    SlotCameraYChanged(0);

    ui->SCameraZ->setValue(0);
    SlotCameraZChanged(0);

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
    m_pPersCamera = new CoPerspectiveCamera();

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
    std::vector<CoVec3> vecVertexNormals;
    CoFaceIndex faceIndices;

    pOBJReader->load(pPath,
                     vecTempVertices,
                     vecUVCoords,
                     vecVertexNormals,
                     faceIndices);

    std::vector<Guint> vecVertexIndices;
    faceIndices.getVertexIndices(vecVertexIndices);

    std::vector<CoVec3> vecVertices;

    Gbool bNormalEmpty = false;
    if(vecVertexNormals.size() == 0)
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
            CoVec3 vNormal = vP3P1.cross(vP2P1);
            vNormal.normalize();

            vecVertexNormals.push_back(vNormal);
            vecVertexNormals.push_back(vNormal);
            vecVertexNormals.push_back(vNormal);
        }
    }

    CoPolygon *pPolygon = new CoPolygon();

    pPolygon->setPoints(vecVertices);
    pPolygon->setNormals(vecVertexNormals);
    pPolygon->setColor(CoVec3(1.0, 0.0, 0.0));

    m_pRender->addNode(pPolygon);
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


void MainWindow::SlotPersToggle(bool checked)
{
    if(checked)
    {
        m_pCamera = m_pPersCamera;
        m_pRender->setCamera(m_pCamera);

        ui->left->setValue(leftvalue * INT2FLOAT);
        ui->right->setValue(rightvalue * INT2FLOAT);
        ui->bottom->setValue(bottomvalue * INT2FLOAT);
        ui->top->setValue(topvalue * INT2FLOAT);

        ui->lvalue->setText(QString::number(leftvalue));
        ui->rvalue->setText(QString::number(rightvalue));
        ui->tvalue->setText(QString::number(bottomvalue));
        ui->tvalue->setText(QString::number(topvalue));

        m_pCamera->setClipSpace(leftvalue,
                                    rightvalue,
                                    bottomvalue,
                                    topvalue,
                                    nearvalue,
                                    farvalue);
        m_pCamera->update();
    }
}

void MainWindow::SlotOrthoToggle(bool checked)
{
    if(checked)
    {
        m_pCamera = m_pOrthoCamera;
        m_pRender->setCamera(m_pCamera);

        ui->left->setValue(leftvalue * INT2FLOAT);
        ui->right->setValue(rightvalue * INT2FLOAT);
        ui->bottom->setValue(bottomvalue * INT2FLOAT);
        ui->top->setValue(topvalue * INT2FLOAT);

        ui->lvalue->setText(QString::number(leftvalue));
        ui->rvalue->setText(QString::number(rightvalue));
        ui->tvalue->setText(QString::number(bottomvalue));
        ui->tvalue->setText(QString::number(topvalue));

        m_pCamera->setClipSpace(leftvalue,
                                    rightvalue,
                                    bottomvalue,
                                    topvalue,
                                    nearvalue,
                                    farvalue);

        m_pCamera->update();
    }
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

