#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "coqtrenderer.h"
#include <QDebug>

#define MIN -50
#define MAX 50
#define INIT 0

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->left->setRange(MIN, MAX);
    ui->left->setValue(INIT);
    ui->right->setRange(MIN, MAX);
    ui->right->setValue(INIT);
    ui->bottom->setRange(MIN, MAX);
    ui->bottom->setValue(INIT);
    ui->top->setRange(MIN, MAX);
    ui->top->setValue(INIT);
    ui->lnear->setRange(MIN, MAX);
    ui->lnear->setValue(INIT);
    ui->lfar->setRange(MIN, MAX);
    ui->lfar->setValue(INIT);

    connect(ui->left, SIGNAL(valueChanged(int)), this, SLOT(SlotLeftChanged(int)));
    connect(ui->right, SIGNAL(valueChanged(int)), this, SLOT(SlotRightChanged(int)));
    connect(ui->bottom, SIGNAL(valueChanged(int)), this, SLOT(SlotBottomChanged(int)));
    connect(ui->top, SIGNAL(valueChanged(int)), this, SLOT(SlotTopChanged(int)));
    connect(ui->lnear, SIGNAL(valueChanged(int)), this, SLOT(SlotNearChanged(int)));
    connect(ui->lfar, SIGNAL(valueChanged(int)), this, SLOT(SlotFarChanged(int)));

    new CoQtRenderer(ui->widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::SlotLeftChanged(int value)
{
    qDebug() << __FUNCTION__ << value;
}
void MainWindow::SlotRightChanged(int value)
{
    qDebug() << __FUNCTION__ << value;
}
void MainWindow::SlotBottomChanged(int value)
{
    qDebug() << __FUNCTION__ << value;
}
void MainWindow::SlotTopChanged(int value)
{
    qDebug() << __FUNCTION__ << value;
}
void MainWindow::SlotNearChanged(int value)
{
    qDebug() << __FUNCTION__ << value;
}
void MainWindow::SlotFarChanged(int value)
{
    qDebug() << __FUNCTION__ << value;
}
