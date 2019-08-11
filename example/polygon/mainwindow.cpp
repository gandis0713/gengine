#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "coqtrenderer.h"
#include "copolygon.h"
#include "coobjreader.h"

#include <QDebug>
#include <QFileDialog>

#define INT2FLOAT 200
#define VIEW_SIZE 5000
#define NEAR 100
#define FAR 1000

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->left->setRange(-VIEW_SIZE  * INT2FLOAT, VIEW_SIZE * INT2FLOAT);
    ui->left->setValue(-VIEW_SIZE  * INT2FLOAT);
    ui->lvalue->setText(QString::number(-VIEW_SIZE));
    leftvalue = -VIEW_SIZE;

    ui->right->setRange(-VIEW_SIZE  * INT2FLOAT, VIEW_SIZE * INT2FLOAT);
    ui->right->setValue(VIEW_SIZE  * INT2FLOAT);
    ui->rvalue->setText(QString::number(VIEW_SIZE));
    rightvalue = VIEW_SIZE;

    ui->bottom->setRange(-VIEW_SIZE  * INT2FLOAT, VIEW_SIZE * INT2FLOAT);
    ui->bottom->setValue(-VIEW_SIZE  * INT2FLOAT);
    ui->bvalue->setText(QString::number(-VIEW_SIZE));
    ui->top->setValue(VIEW_SIZE  * INT2FLOAT);
    bottomvalue = -VIEW_SIZE;

    ui->top->setRange(-VIEW_SIZE  * INT2FLOAT, VIEW_SIZE * INT2FLOAT);
    ui->top->setValue(VIEW_SIZE  * INT2FLOAT);
    ui->tvalue->setText(QString::number(VIEW_SIZE));
    topvalue = VIEW_SIZE;

    ui->lnear->setRange(-NEAR, NEAR * INT2FLOAT);
    ui->lnear->setValue(1 * INT2FLOAT);
    ui->nvalue->setText(QString::number(1 ));
    nearvalue = 1;

    ui->lfar->setRange(NEAR, FAR * INT2FLOAT);
    ui->lfar->setValue(FAR * INT2FLOAT);
    ui->fvalue->setText(QString::number(FAR));
    farvalue = FAR;

    connect(ui->left, SIGNAL(sliderMoved(int)), this, SLOT(SlotLeftChanged(int)));
    connect(ui->right, SIGNAL(sliderMoved(int)), this, SLOT(SlotRightChanged(int)));
    connect(ui->bottom, SIGNAL(sliderMoved(int)), this, SLOT(SlotBottomChanged(int)));
    connect(ui->top, SIGNAL(sliderMoved(int)), this, SLOT(SlotTopChanged(int)));
    connect(ui->lnear, SIGNAL(sliderMoved(int)), this, SLOT(SlotNearChanged(int)));
    connect(ui->lfar, SIGNAL(sliderMoved(int)), this, SLOT(SlotFarChanged(int)));

    ui->ortho->setChecked(true);
    connect(ui->pers, SIGNAL(toggled(bool)), this, SLOT(SlotPersToggle(bool)));
    connect(ui->ortho, SIGNAL(toggled(bool)), this, SLOT(SlotOrthoToggle(bool)));

    initialize();
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

//    QString strOBJFilePath = QFileDialog::getOpenFileName(this,
//                                         "Select OBJ file",
//                                         ".",
//                                         "");

//    const Gchar *pPath = strOBJFilePath.toLocal8Bit().constData();

    Gstring strPath = "C:/Users/gandis/Desktop/obj/trash.obj";
//    Gstring strPath = "C:/Users/gandis/Desktop/obj/test1.obj";
    const Gchar *pPath = strPath.c_str();

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
//            CoVec3 vNormal = vP2P1.cross(vP3P1);
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
    leftvalue = (float)value/(float)INT2FLOAT;
    ui->lvalue->setText(QString::number(leftvalue));
    m_pCamera->setLeftPosition(leftvalue);
    m_pCamera->update();

}
void MainWindow::SlotRightChanged(int value)
{
    rightvalue = (float)value/(float)INT2FLOAT;
    ui->rvalue->setText(QString::number(rightvalue));
    m_pCamera->setRightPosition(rightvalue);
    m_pCamera->update();
}
void MainWindow::SlotBottomChanged(int value)
{
    bottomvalue = (float)value/(float)INT2FLOAT;
    ui->bvalue->setText(QString::number(bottomvalue));
    m_pCamera->setBottomPosition(bottomvalue);
    m_pCamera->update();
}
void MainWindow::SlotTopChanged(int value)
{
    topvalue = (float)value/(float)INT2FLOAT;
    ui->tvalue->setText(QString::number(topvalue));
    m_pCamera->setTopPosition(topvalue);
    m_pCamera->update();
}
void MainWindow::SlotNearChanged(int value)
{
    nearvalue = (float)value/(float)INT2FLOAT;
    ui->nvalue->setText(QString::number(nearvalue));
    m_pCamera->setNearPosition(nearvalue);
    m_pCamera->update();
}
void MainWindow::SlotFarChanged(int value)
{
    farvalue = (float)value/(float)INT2FLOAT;
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

        ui->left->setValue(leftvalue * farvalue * INT2FLOAT);
        ui->right->setValue(rightvalue * farvalue * INT2FLOAT);
        ui->bottom->setValue(bottomvalue * farvalue * INT2FLOAT);
        ui->top->setValue(topvalue * farvalue * INT2FLOAT);

        ui->lvalue->setText(QString::number(leftvalue * farvalue));
        ui->rvalue->setText(QString::number(rightvalue * farvalue));
        ui->tvalue->setText(QString::number(bottomvalue * farvalue));
        ui->tvalue->setText(QString::number(topvalue * farvalue));

        m_pCamera->setClipSpace(leftvalue * farvalue,
                                rightvalue * farvalue,
                                bottomvalue * farvalue,
                                topvalue * farvalue,
                                nearvalue,
                                farvalue);
        m_pCamera->update();
    }
}
