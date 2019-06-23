#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "coqtrenderer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    new CoQtRenderer(ui->widget);
}

MainWindow::~MainWindow()
{
    delete ui;

}
