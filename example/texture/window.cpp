#include "window.h"
#include "ui_window.h"

#include "coqtrenderer.h"
#include "coorthographiccamera.h"
#include "cotexture.h"

#include <QFileDialog>

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    QString strFileName = QFileDialog::getOpenFileName(this,
                                         "Select image file",
                                         ".",
                                         "");

    CoQtRenderer *m_pRender = new CoQtRenderer(ui->widget);
    CoOrthographicCamera* m_pCamera = new CoOrthographicCamera();

    m_pRender->setCamera(m_pCamera);

    CoTexture *pTexture = new CoTexture;
    pTexture->load(strFileName.toLocal8Bit().constData());
    m_pRender->addNode(pTexture);
}

Window::~Window()
{
    delete ui;
}
