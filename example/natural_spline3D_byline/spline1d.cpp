#include "spline1d.h"

Spline1D::Spline1D()
{

}

Spline1D::~Spline1D()
{

}

void Spline1D::setPoints(const std::vector<Gfloat> &vecPoints)
{
    m_vecPoints.clear();
    m_vecPoints = vecPoints;

    build();
}

Gfloat Spline1D::getPoint(Gfloat fNormalizedPoint)
{
    fNormalizedPoint = fNormalizedPoint * (m_vecPoints.size() - 1);
    Gint nIndex = std::floor(fNormalizedPoint);
    fNormalizedPoint -= nIndex;

    Gfloat fPoint = (( m_vecCoefA[nIndex] * fNormalizedPoint
                       + m_vecCoefB[nIndex]) * fNormalizedPoint
                       + m_vecCoefC[nIndex]) * fNormalizedPoint
                       + m_vecCoefD[nIndex];

    return fPoint;
}

void Spline1D::build()
{
    Guint nSize = m_vecPoints.size();

    Gfloat *mcC = new Gfloat[nSize];
    Gfloat *mcD = new Gfloat[nSize];
    Gfloat *unD = new Gfloat[nSize];

    mcC[0] = 1.f / 2.f;

    for(Gint i = 1; i < nSize - 1; i++)
    {
        mcC[i] = 1.f / ( 4.f - mcC[ i - 1 ] );
    }

    mcC[nSize - 1] = 1.f / ( 2.f - mcC[nSize - 2] );

    mcD[0] = 3.f * ( m_vecPoints[1] - m_vecPoints[0] ) * mcC[0];

    for(Gint i = 1; i < nSize - 1; i++)
    {
        mcD[i] = ( 3.f * ( m_vecPoints[i + 1] - m_vecPoints[i - 1] ) - mcD[i - 1]) * mcC[i];
    }

    mcD[nSize - 1] = ( 3.f * ( m_vecPoints[nSize - 1] - m_vecPoints[nSize - 2] ) - mcD[nSize - 2] ) * mcC[nSize - 1];

    unD[nSize - 1] = mcD[nSize - 1];

    for(Gint i = nSize - 2; i >= 0; i--)
    {
        unD[i] = mcD[i] - mcC[i] * unD[i + 1];
    }

    for(Gint i = 0; i < nSize - 1; i++)
    {
        m_vecCoefA.push_back(2 * ( m_vecPoints[i] - m_vecPoints[i + 1] ) + unD[i] + unD[i + 1]);
        m_vecCoefB.push_back(3 * ( m_vecPoints[i + 1] - m_vecPoints[i] ) - 2* unD[i] - unD[i + 1]);
        m_vecCoefC.push_back(unD[i]);
        m_vecCoefD.push_back(m_vecPoints[i]);
    }

    m_vecCoefA.push_back(0);
    m_vecCoefB.push_back(0);
    m_vecCoefC.push_back(unD[nSize - 1]);
    m_vecCoefD.push_back(m_vecPoints[nSize - 1]);

    delete[] mcC;
    delete[] mcD;
    delete[] unD;
}

