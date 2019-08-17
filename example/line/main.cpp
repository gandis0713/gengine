#include <QApplication>

#include "samplewindow.h"
#include "coqtrenderer.h"
#include "coorthographiccamera.h"
#include "coline.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    CSampleWindow w;

    CoQtRenderer *m_pRender = new CoQtRenderer(w.getMainWidget());
    CoOrthographicCamera* m_pCamera = new CoOrthographicCamera();

    m_pRender->setCamera(m_pCamera);

    CoLine *pLine1 = new CoLine(CoVec3( -1.0f, -1.0f, 1.0f), CoVec3( 1.0f, -1.0f, 1.0f));
    pLine1->setColor(CoVec3(1.0, 0.0, 0.0));
    CoLine *pLine2 = new CoLine(CoVec3( 1.0f, -1.0f, 1.0f), CoVec3( 0.0f, 1.0f, 1.0f));
    pLine2->setColor(CoVec3(1.0, 1.0, 0.0));
    CoLine *pLine3 = new CoLine(CoVec3( 0.0f, 1.0f, 1.0f), CoVec3( -1.0f, -1.0f, 1.0f));
    pLine2->setColor(CoVec3(0.0, 1.0, 1.0));

    m_pRender->addNode(pLine1);
    m_pRender->addNode(pLine2);
    m_pRender->addNode(pLine3);


    w.setQtRenderer(m_pRender);
    w.show();

    return a.exec();
}
