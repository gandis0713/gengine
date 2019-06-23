#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "coqtrenderer.h"
#include "coperspectivecamera.h"

#define INT2FLOAT 200

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->left->setRange(-5  * INT2FLOAT, 5 * INT2FLOAT);
    ui->left->setValue(-0.5  * INT2FLOAT);
    ui->lvalue->setText(QString::number(-0.5));
    ui->right->setRange(-5  * INT2FLOAT, 5 * INT2FLOAT);
    ui->right->setValue(0.5  * INT2FLOAT);
    ui->rvalue->setText(QString::number(0.5));
    ui->bottom->setRange(-5  * INT2FLOAT, 5 * INT2FLOAT);
    ui->bottom->setValue(-0.5  * INT2FLOAT);
    ui->bvalue->setText(QString::number(-0.5));
    ui->top->setRange(-5  * INT2FLOAT, 5 * INT2FLOAT);
    ui->top->setValue(0.5  * INT2FLOAT);
    ui->tvalue->setText(QString::number(0.5));
    ui->lnear->setRange(0, 10 * INT2FLOAT);
    ui->lnear->setValue(1 * INT2FLOAT);
    ui->nvalue->setText(QString::number(1 ));
    ui->lfar->setRange(0, 10 * INT2FLOAT);
    ui->lfar->setValue(10 * INT2FLOAT);
    ui->fvalue->setText(QString::number(10));

    connect(ui->left, SIGNAL(valueChanged(int)), this, SLOT(SlotLeftChanged(int)));
    connect(ui->right, SIGNAL(valueChanged(int)), this, SLOT(SlotRightChanged(int)));
    connect(ui->bottom, SIGNAL(valueChanged(int)), this, SLOT(SlotBottomChanged(int)));
    connect(ui->top, SIGNAL(valueChanged(int)), this, SLOT(SlotTopChanged(int)));
    connect(ui->lnear, SIGNAL(valueChanged(int)), this, SLOT(SlotNearChanged(int)));
    connect(ui->lfar, SIGNAL(valueChanged(int)), this, SLOT(SlotFarChanged(int)));

    m_pRender = new CoQtRenderer(ui->widget);

    m_pCamera = new CoPerspectiveCamera();
    m_pRender->setCamera(m_pCamera);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::SlotLeftChanged(int value)
{
    float fValue = (float)value/(float)INT2FLOAT;
    ui->lvalue->setText(QString::number(fValue));
    m_pCamera->setLeftPosition(fValue);
    m_pCamera->update();

}
void MainWindow::SlotRightChanged(int value)
{
    float fValue = (float)value/(float)INT2FLOAT;
    ui->rvalue->setText(QString::number(fValue));
    m_pCamera->setRightPosition(fValue);
    m_pCamera->update();
}
void MainWindow::SlotBottomChanged(int value)
{
    float fValue = (float)value/(float)INT2FLOAT;
    ui->bvalue->setText(QString::number(fValue));
    m_pCamera->setBottomPosition(fValue);
    m_pCamera->update();
}
void MainWindow::SlotTopChanged(int value)
{
    float fValue = (float)value/(float)INT2FLOAT;
    ui->tvalue->setText(QString::number(fValue));
    m_pCamera->setTopPosition(fValue);
    m_pCamera->update();
}
void MainWindow::SlotNearChanged(int value)
{
    float fValue = (float)value/(float)INT2FLOAT;
    ui->nvalue->setText(QString::number(fValue));
    m_pCamera->setNearPosition(fValue);
    m_pCamera->update();
}
void MainWindow::SlotFarChanged(int value)
{
    float fValue = (float)value/(float)INT2FLOAT;
    ui->fvalue->setText(QString::number(fValue));
    m_pCamera->setFarPosition(fValue);
    m_pCamera->update();
}
