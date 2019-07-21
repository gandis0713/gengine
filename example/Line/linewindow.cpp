#include "linewindow.h"
#include "ui_linewindow.h"

#include "coqtrenderer.h"
#include "coorthographiccamera.h"
#include "coline.h"

LineWindow::LineWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LineWindow)
{
    ui->setupUi(this);

    CoQtRenderer *m_pRender = new CoQtRenderer(ui->widget);
    CoOrthographicCamera* m_pCamera = new CoOrthographicCamera();

    m_pRender->setCamera(m_pCamera);

    CoLine *pLine1 = new CoLine(CoVec3( -1.0f, -1.0f, 1.0f), CoVec3( 1.0f, -1.0f, 1.0f));
    CoLine *pLine2 = new CoLine(CoVec3( 1.0f, -1.0f, 1.0f), CoVec3( 0.0f, 1.0f, 1.0f));
    CoLine *pLine3 = new CoLine(CoVec3( 0.0f, 1.0f, 1.0f), CoVec3( -1.0f, -1.0f, 1.0f));

    m_pRender->addNode(pLine1);
    m_pRender->addNode(pLine2);
    m_pRender->addNode(pLine3);
}

LineWindow::~LineWindow()
{
    delete ui;
}
