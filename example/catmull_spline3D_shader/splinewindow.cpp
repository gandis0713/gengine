#include "splinewindow.h"
#include "ui_splinewindow.h"

#include "coqtrenderer.h"
#include "coorthographiccamera.h"
#include "cocatmullspline.h"

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

    CoCatmullSpline *pSpline = new CoCatmullSpline(vecPoints);
    m_pRender->addNode(pSpline);
}

SplineWindow::~SplineWindow()
{
    delete ui;
}
