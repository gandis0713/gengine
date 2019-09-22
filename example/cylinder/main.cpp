#include "samplewindow.h"
#include "coqtrenderer.h"
#include "coorthographiccamera.h"
#include "cocylinder.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CSampleWindow w;

    CoQtRenderer *m_pRender = new CoQtRenderer(w.getMainWidget());
    CoOrthographicCamera* m_pCamera = new CoOrthographicCamera();

    m_pRender->setCamera(m_pCamera);

    CoCylinder *pCylinder = new CoCylinder(CoVec3(0,0,0), 10, 30);

    m_pRender->addNode(pCylinder);

    w.setQtRenderer(m_pRender);
    w.show();

    return a.exec();
}
