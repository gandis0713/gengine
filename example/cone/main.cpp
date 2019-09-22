#include "samplewindow.h"
#include "coqtrenderer.h"
#include "coorthographiccamera.h"
#include "cocone.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CSampleWindow w;

    CoQtRenderer *m_pRender = new CoQtRenderer(w.getMainWidget());
    CoOrthographicCamera* m_pCamera = new CoOrthographicCamera();

    m_pRender->setCamera(m_pCamera);

    CoCone *pCone = new CoCone(CoVec3(0,0,0), 10, 20);

    m_pRender->addNode(pCone);

    w.setQtRenderer(m_pRender);
    w.show();

    return a.exec();
}
