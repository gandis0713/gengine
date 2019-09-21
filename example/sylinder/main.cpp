#include "samplewindow.h"
#include "coqtrenderer.h"
#include "coorthographiccamera.h"
#include "cosylinder.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CSampleWindow w;

    CoQtRenderer *m_pRender = new CoQtRenderer(w.getMainWidget());
    CoOrthographicCamera* m_pCamera = new CoOrthographicCamera();

    m_pRender->setCamera(m_pCamera);

    CoSylinder *pSylinder = new CoSylinder();

    m_pRender->addNode(pSylinder);

    w.setQtRenderer(m_pRender);
    w.show();

    return a.exec();
}
