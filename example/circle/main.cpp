#include "samplewindow.h"
#include "coqtrenderer.h"
#include "coorthographiccamera.h"
#include "cocircle.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CSampleWindow w;

    CoQtRenderer *m_pRender = new CoQtRenderer(w.getMainWidget());
    CoOrthographicCamera* m_pCamera = new CoOrthographicCamera();

    m_pRender->setCamera(m_pCamera);

    CoCircle *pCircle = new CoCircle(CoVec3(0, 0, 0), 10);
    pCircle->setColor(CoVec3(1.0, 1.0, 0.0));

    m_pRender->addNode(pCircle);

    w.setQtRenderer(m_pRender);
    w.show();



    return a.exec();
}
