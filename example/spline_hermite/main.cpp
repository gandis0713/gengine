#include <QApplication>

#include "samplewindow.h"
#include "coqtrenderer.h"
#include "coorthographiccamera.h"
#include "coline.h"
#include "spline3d.h"

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

    Spline3D spline;
    spline.setPoints(vecPoints);

    Guint nSize = 100;
    std::vector<CoVec3> vecSpline;
    for(Gint i = 0; i <= nSize; i++)
    {
        Gfloat t = i / (Gfloat)nSize;
        vecSpline.push_back(spline.getPoints(t));
    }

    for(Gint i = 0; i < vecSpline.size() - 1; i++)
    {
        CoLine *pLine = new CoLine(vecSpline[i], vecSpline[i+1]);
        pLine->setColor(CoVec3(1.0, 0.0, 0.0));
        m_pRender->addNode(pLine);
    }


    w.setQtRenderer(m_pRender);
    w.show();

    return a.exec();
}
