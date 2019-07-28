#include "window.h"
#include "ui_window.h"

#include "coqtrenderer.h"
#include "coorthographiccamera.h"
#include "cotexture.h"

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    CoQtRenderer *m_pRender = new CoQtRenderer(ui->widget);
    CoOrthographicCamera* m_pCamera = new CoOrthographicCamera();

    m_pRender->setCamera(m_pCamera);

    CoTexture *pTexture = new CoTexture;
    pTexture->load("C:/Users/gandis/Downloads/test.png");
    m_pRender->addNode(pTexture);
}

Window::~Window()
{
    delete ui;
}
