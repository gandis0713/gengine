#include "linewindow.h"
#include "ui_linewindow.h"

#include "coqtrenderer.h"
#include "coorthographiccamera.h"

LineWindow::LineWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LineWindow)
{
    ui->setupUi(this);

    CoQtRenderer *m_pRender = new CoQtRenderer(ui->widget);

    CoOrthographicCamera* m_pCamera = new CoOrthographicCamera();

    m_pRender->setCamera(m_pCamera);
}

LineWindow::~LineWindow()
{
    delete ui;
}
