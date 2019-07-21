#include "splinewindow.h"
#include "ui_splinewindow.h"

#include "coqtrenderer.h"
#include "coorthographiccamera.h"

SplineWindow::SplineWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SplineWindow)
{
    ui->setupUi(this);

    CoQtRenderer *m_pRender = new CoQtRenderer(ui->widget);
    CoOrthographicCamera* m_pCamera = new CoOrthographicCamera();

    m_pRender->setCamera(m_pCamera);
}

SplineWindow::~SplineWindow()
{
    delete ui;
}
