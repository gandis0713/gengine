#include "samplewindow.h"
#include "ui_samplewindow.h"

CSampleWindow::CSampleWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CSampleWindow),
    m_pQtRenderer(NULL)
{
    ui->setupUi(this);

    connect(ui->btnRotate, SIGNAL(clicked(bool)), this, SLOT(slotRotateBtnClicked(bool)));
    connect(ui->btnPan, SIGNAL(clicked(bool)), this, SLOT(slotPanBtnClicked(bool)));
    connect(ui->btnZoom, SIGNAL(clicked(bool)), this, SLOT(slotZoomBtnClicked(bool)));
    connect(ui->btnFit, SIGNAL(clicked(bool)), this, SLOT(slotFitBtnClicked(bool)));
}

CSampleWindow::~CSampleWindow()
{
    delete ui;
}

void CSampleWindow::setQtRenderer(CoQtRenderer *pQtRenderer)
{
    m_pQtRenderer = pQtRenderer;
}

QWidget* CSampleWindow::getMainWidget()
{
    return ui->widget;
}

void CSampleWindow::slotRotateBtnClicked(bool)
{
    m_pQtRenderer->setEvent(CoQtRenderer::EEvent::eRotate);
}

void CSampleWindow::slotPanBtnClicked(bool)
{
    m_pQtRenderer->setEvent(CoQtRenderer::EEvent::ePan);
}

void CSampleWindow::slotZoomBtnClicked(bool)
{
    m_pQtRenderer->setEvent(CoQtRenderer::EEvent::eZoom);
}

void CSampleWindow::slotFitBtnClicked(bool)
{
    m_pQtRenderer->fit();
}
