#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "coqtrenderer.h"
#include "coline.h"

#define INT2FLOAT 200

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->left->setRange(-5  * INT2FLOAT, 5 * INT2FLOAT);
    ui->left->setValue(-0.5  * INT2FLOAT);
    ui->lvalue->setText(QString::number(-0.5));
    leftvalue = -0.5;

    ui->right->setRange(-5  * INT2FLOAT, 5 * INT2FLOAT);
    ui->right->setValue(0.5  * INT2FLOAT);
    ui->rvalue->setText(QString::number(0.5));
    rightvalue = 0.5;

    ui->bottom->setRange(-5  * INT2FLOAT, 5 * INT2FLOAT);
    ui->bottom->setValue(-0.5  * INT2FLOAT);
    ui->bvalue->setText(QString::number(-0.5));
    ui->top->setValue(0.5  * INT2FLOAT);
    bottomvalue = -0.5;

    ui->top->setRange(-5  * INT2FLOAT, 5 * INT2FLOAT);
    ui->top->setValue(0.5  * INT2FLOAT);
    ui->tvalue->setText(QString::number(0.5));
    topvalue = 0.5;

    ui->lnear->setRange(0, 10 * INT2FLOAT);
    ui->lnear->setValue(1 * INT2FLOAT);
    ui->nvalue->setText(QString::number(1 ));
    nearvalue = 1;

    ui->lfar->setRange(0, 10 * INT2FLOAT);
    ui->lfar->setValue(10 * INT2FLOAT);
    ui->fvalue->setText(QString::number(10));
    farvalue = 10;

    connect(ui->left, SIGNAL(sliderMoved(int)), this, SLOT(SlotLeftChanged(int)));
    connect(ui->right, SIGNAL(sliderMoved(int)), this, SLOT(SlotRightChanged(int)));
    connect(ui->bottom, SIGNAL(sliderMoved(int)), this, SLOT(SlotBottomChanged(int)));
    connect(ui->top, SIGNAL(sliderMoved(int)), this, SLOT(SlotTopChanged(int)));
    connect(ui->lnear, SIGNAL(sliderMoved(int)), this, SLOT(SlotNearChanged(int)));
    connect(ui->lfar, SIGNAL(sliderMoved(int)), this, SLOT(SlotFarChanged(int)));

    ui->pers->setChecked(true);
    connect(ui->pers, SIGNAL(toggled(bool)), this, SLOT(SlotPersToggle(bool)));
    connect(ui->ortho, SIGNAL(toggled(bool)), this, SLOT(SlotOrthoToggle(bool)));

    m_pRender = new CoQtRenderer(ui->widget);
    m_pOrthoCamera = new CoOrthographicCamera();
    m_pPersCamera = new CoPerspectiveCamera();

    m_pCamera = m_pPersCamera;
    m_pRender->setCamera(m_pCamera);

    CoLine *pLine1 = new CoLine(CoVec3( -1.0f, -1.0f, 1.0f), CoVec3( 1.0f, -1.0f, 1.0f));
    CoLine *pLine2 = new CoLine(CoVec3( 1.0f, -1.0f, 1.0f), CoVec3( 0.0f, 1.0f, 1.0f));
    CoLine *pLine3 = new CoLine(CoVec3( 0.0f, 1.0f, 1.0f), CoVec3( -1.0f, -1.0f, 1.0f));
    CoLine *pLine4 = new CoLine(CoVec3( -4.0f, -1.0f, -1.0f), CoVec3( -2.0f, -1.0f, -1.0f));
    CoLine *pLine5 = new CoLine(CoVec3( -2.0f, -1.0f, -1.0f), CoVec3( -3.0f, 1.0f, -1.0f));
    CoLine *pLine6 = new CoLine(CoVec3( -3.0f, 1.0f, -1.0f), CoVec3( -4.0f, -1.0f, -1.0f));
    CoLine *pLine7 = new CoLine(CoVec3( 2.0f, -1.0f, -1.0f), CoVec3( 4.0f, -1.0f, -1.0f));
    CoLine *pLine8 = new CoLine(CoVec3( 4.0f, -1.0f, -1.0f), CoVec3( 3.0f, 1.0f, -1.0f));
    CoLine *pLine9 = new CoLine(CoVec3( 3.0f, 1.0f, -1.0f), CoVec3( 2.0f, -1.0f, -1.0f));

    m_pRender->addNode(pLine1);
    m_pRender->addNode(pLine2);
    m_pRender->addNode(pLine3);
    m_pRender->addNode(pLine4);
    m_pRender->addNode(pLine5);
    m_pRender->addNode(pLine6);
    m_pRender->addNode(pLine7);
    m_pRender->addNode(pLine8);
    m_pRender->addNode(pLine9);
}

MainWindow::~MainWindow()
{
    delete ui;
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
