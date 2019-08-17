#include "samplewindow.h"
#include "coorthographiccamera.h"
#include "cocatmullspline.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CSampleWindow w;

    CoQtRenderer *m_pRender = new CoQtRenderer(w.getMainWidget());
    CoOrthographicCamera* m_pCamera = new CoOrthographicCamera();

    m_pRender->setCamera(m_pCamera);

    std::vector<CoVec3> vecPoints;
    vecPoints.push_back(CoVec3( 0, 3.0, 1));
    vecPoints.push_back(CoVec3( 3, 1.0, 2));
    vecPoints.push_back(CoVec3( -2, -3.0, -3));
    vecPoints.push_back(CoVec3( 2, 1.0, -2));
    vecPoints.push_back(CoVec3( 3, 3.0, 1));

    CoCatmullSpline *pSpline = new CoCatmullSpline(vecPoints);
    m_pRender->addNode(pSpline);

    w.setQtRenderer(m_pRender);
    w.show();

    return a.exec();
}
