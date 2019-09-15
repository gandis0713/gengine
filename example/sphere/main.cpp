#include "samplewindow.h"
#include "coqtrenderer.h"
#include "coorthographiccamera.h"
#include "cosphere.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CSampleWindow w;

    CoQtRenderer *m_pRender = new CoQtRenderer(w.getMainWidget());
    CoOrthographicCamera* m_pCamera = new CoOrthographicCamera();

    m_pRender->setCamera(m_pCamera);

    CoSphere *pSphere = new CoSphere();
    pSphere->setColor(CoVec3(1.0, 0.0, 0.0));

    m_pRender->addNode(pSphere);

    w.setQtRenderer(m_pRender);
    w.show();



    return a.exec();
}
