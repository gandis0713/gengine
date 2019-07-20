#include "linewindow.h"
#include "ui_linewindow.h"

LineWindow::LineWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LineWindow)
{
    ui->setupUi(this);

    CoQtRenderer m_pRender = new CoQtRenderer(ui->widget);
}

LineWindow::~LineWindow()
{
    delete ui;
}
