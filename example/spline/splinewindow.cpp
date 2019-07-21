#include "splinewindow.h"
#include "ui_splinewindow.h"

#include "coqtrenderer.h"
#include "coorthographiccamera.h"
#include "coline.h"
#include "spline3d.h"

SplineWindow::SplineWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SplineWindow)
{
    ui->setupUi(this);

    CoQtRenderer *m_pRender = new CoQtRenderer(ui->widget);
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
        m_pRender->addNode(pLine);
    }
}

SplineWindow::~SplineWindow()
{
    delete ui;
}
