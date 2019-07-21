#include "spline3d.h"

Spline3D::Spline3D()
{

}

Spline3D::~Spline3D()
{

}

void Spline3D::setPoints(const std::vector<CoVec3> &vecPoints)
{
    std::vector<Gfloat> vecXPoints;
    std::vector<Gfloat> vecYPoints;
    std::vector<Gfloat> vecZPoints;

    for(Gint i = 0; i < vecPoints.size(); i++)
    {
        vecXPoints.push_back(vecPoints[i][0]);
        vecYPoints.push_back(vecPoints[i][1]);
        vecZPoints.push_back(vecPoints[i][2]);
    }

    m_XSpline.setPoints(vecXPoints);
    m_YSpline.setPoints(vecYPoints);
    m_ZSpline.setPoints(vecZPoints);
}

CoVec3 Spline3D::getPoints(Gfloat fNormalizedPoint)
{
    CoVec3 vPoint;

    vPoint[0] = m_XSpline.getPoint(fNormalizedPoint);
    vPoint[1] = m_YSpline.getPoint(fNormalizedPoint);
    vPoint[2] = m_ZSpline.getPoint(fNormalizedPoint);

    return vPoint;
}
