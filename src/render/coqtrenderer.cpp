#include "coglextension.h"
#include "coqtrenderer.h"

#include "nomath.h"

#include "coperspectivecamera.h"
#include "coorthographiccamera.h"
#include "colinecore.h"
#include "cotexturecore.h"
#include "copolygoncore.h"
#include "cospherecore.h"
#include "cocylindercore.h"
#include "coconecore.h"
#include "cotexturedpolygoncore.h"
#include "cocirclecore.h"
#include "cocatmullsplinecore.h"
#include "demath.h"
#include "delog.h"

#include <QGridLayout>
#include <QMouseEvent>

CoQtRenderer::CoQtRenderer(QWidget* pParent)
    : m_pParent(pParent),
      m_pLayout(NULL),
      m_pQScreen(NULL),
      m_pCamera(NULL)
{
    initializeWidget();

    m_pCamera = new CoOrthographicCamera();
    connect(m_pCamera, SIGNAL(signalCameraUpdated()), this, SLOT(slotCameraUpdated()), Qt::UniqueConnection);

    m_pLight = new CoLight();
}

CoQtRenderer::~CoQtRenderer()
{
    delete m_pLayout;
    delete m_pQScreen;
}


void CoQtRenderer::initializeWidget()
{
    m_pLayout = new QGridLayout(m_pParent);

    m_pQScreen = new CoQScreen;
    connect(m_pQScreen, SIGNAL(signalInitializeGL()), this, SLOT(initializeGL()));
    connect(m_pQScreen, SIGNAL(signalResizeGL(int, int)), this, SLOT(resizeGL(int, int)));
    connect(m_pQScreen, SIGNAL(signalPaintGL()), this, SLOT(paintGL()));
    connect(m_pQScreen, SIGNAL(signalmousePressEvent(QMouseEvent*)), this, SLOT(mousePressEvent(QMouseEvent*)));
    connect(m_pQScreen, SIGNAL(signalmouseMoveEvent(QMouseEvent*)), this, SLOT(mouseMoveEvent(QMouseEvent*)));
    connect(m_pQScreen, SIGNAL(signalmouseReleaseEvent(QMouseEvent*)), this, SLOT(mouseReleaseEvent(QMouseEvent*)));
    connect(m_pQScreen, SIGNAL(signalMouseWheelEvent(QWheelEvent*)), this, SLOT(mouseWheelEvent(QWheelEvent*)));

    QWidget *pWidget = dynamic_cast<QWidget*>(m_pQScreen);
    m_pLayout->addWidget(pWidget);
}

void CoQtRenderer::initializeGL()
{
    ValueTextLog(version,(char *)(glGetString(GL_VERSION)));
    ValueTextLog(renderer, (char *)(glGetString(GL_RENDERER)));
    ValueTextLog(glsl version, (char *)(glGetString(GL_SHADING_LANGUAGE_VERSION)));

    CoGLExtension::getInstance();

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    std::map<CoNode*, CoNodeCore*>::iterator iter;
    for(iter = m_mapNodeObject.begin(); iter != m_mapNodeObject.end(); ++iter)
    {
        CoNodeCore *pNodeObject = iter->second;

        pNodeObject->initialize();
    }
}

void CoQtRenderer::resizeGL(int nWidth, int nHeight)
{
    m_vScreenSize[0] = nWidth;
    m_vScreenSize[1] = nHeight;

    glViewport(0, 0, m_vScreenSize[0], m_vScreenSize[1]);

    m_pCamera->setViewport(CoVec4(0, 0, m_vScreenSize[0], m_vScreenSize[1]));
}

void CoQtRenderer::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    std::map<CoNode*, CoNodeCore*>::iterator iter;
    for(iter = m_mapNodeObject.begin(); iter != m_mapNodeObject.end(); ++iter)
    {
        CoNodeCore *pNodeObject = iter->second;

        pNodeObject->paint();
    }

}

void CoQtRenderer::slotCameraUpdated()
{
    update();
}

void CoQtRenderer::mousePressEvent(QMouseEvent* event)
{
    m_vLastPoint[0] = -(m_vScreenSize[0]/2  - event->localPos().x());
    m_vLastPoint[1] = (m_vScreenSize[1]/2 - event->localPos().y());
}

void CoQtRenderer::mouseMoveEvent(QMouseEvent* event)
{
    CoVec2 vPoint;
    vPoint[0] = -(m_vScreenSize[0]/2  - event->localPos().x());
    vPoint[1] = (m_vScreenSize[1]/2 - event->localPos().y());


    if(m_eEvent == ePan)
    {
        m_pCamera->move(vPoint, m_vLastPoint);
    }
    else if(m_eEvent == eZoom)
    {
        m_pCamera->zoom(vPoint[1] - m_vLastPoint[1]);
    }
    else
    {
        m_pCamera->orbit(vPoint, m_vLastPoint);
    }

    m_pCamera->update();

    m_vLastPoint[0] = vPoint[0];
    m_vLastPoint[1] = vPoint[1];
}

void CoQtRenderer::mouseReleaseEvent(QMouseEvent* event)
{
    update();
}

void CoQtRenderer::mouseWheelEvent(QWheelEvent* event)
{
    Gfloat fRate = event->angleDelta().y() / 120;
    m_pCamera->zoom(fRate);
    m_pCamera->update();
}

void CoQtRenderer::update()
{
    m_pQScreen->updateGL();
}

void CoQtRenderer::fit()
{

    Gfloat fMaxValue = (std::numeric_limits<Gfloat>::max)();

    CoVec3 vMin(fMaxValue, fMaxValue, fMaxValue);
    CoVec3 vMax(-fMaxValue, -fMaxValue, -fMaxValue);

    std::map<CoNode*, CoNodeCore*>::iterator iter;
    for(iter = m_mapNodeObject.begin(); iter != m_mapNodeObject.end(); ++iter)
    {
        CoVec3 vTempMin;
        CoVec3 vTempMax;
        CoShape *pShape = static_cast<CoShape*>(iter->first);
        pShape->getBound(vTempMin, vTempMax);

        for(Gint nIndex = 0; nIndex < 3; nIndex++)
        {
            if(vMin[nIndex] > vTempMin[nIndex])
                vMin[nIndex] = vTempMin[nIndex];
            if(vMax[nIndex] < vTempMax[nIndex])
                vMax[nIndex] = vTempMax[nIndex];
        }
    }

    Gfloat fMax = vMax[0] - vMin[0];
    if(fMax < vMax[1] - vMin[1])
        fMax = vMax[1] - vMin[1];
    if(fMax < vMax[2] - vMin[2])
        fMax = vMax[2] - vMin[2];

    Gfloat fHalfSize = fMax / 2;
    CoVec3 vCenter = (vMax + vMin)/CoVec3(2,2,2);

    CoOrthographicCamera *pOrtho = dynamic_cast<CoOrthographicCamera*>(m_pCamera);
    if(pOrtho != NULL)
    {
        pOrtho->setLeftPosition(vCenter[0] - fHalfSize * 1.5);
        pOrtho->setRightPosition(vCenter[0] + fHalfSize * 1.5);
        pOrtho->setTopPosition(vCenter[1] + fHalfSize * 1.5);
        pOrtho->setBottomPosition(vCenter[1] - fHalfSize * 1.5);

        CoVec3 vPosition = m_pCamera->getPosition();
        vPosition[2] = fMax;
        pOrtho->setPosition(vPosition);

        pOrtho->setFarPosition(fMax * 2);

        pOrtho->update();
    }

    CoPerspectiveCamera *pPers = dynamic_cast<CoPerspectiveCamera*>(m_pCamera);
    if(pPers != NULL)
    {
        CoVec3 vPosition = m_pCamera->getPosition();
        vPosition[2] = fMax;
        pPers->setPosition(vPosition);

        pPers->setFarPosition(fMax * 2);

        pPers->update();
    }


}

void CoQtRenderer::setEvent(EEvent eEvent)
{
    m_eEvent = eEvent;
}

void CoQtRenderer::setCamera(CoCamera *pCamera)
{
    if(m_pCamera != NULL)
    {
        disconnect(m_pCamera, SIGNAL(signalCameraUpdated()), this, SLOT(slotCameraUpdated()));
    }

    m_pCamera = pCamera;

    std::map<CoNode*, CoNodeCore*>::iterator iter;
    for(iter = m_mapNodeObject.begin(); iter != m_mapNodeObject.end(); ++iter)
    {
        CoNodeCore *pNodeObject = iter->second;

        pNodeObject->setCamera(m_pCamera);
    }

    connect(m_pCamera, SIGNAL(signalCameraUpdated()), this, SLOT(slotCameraUpdated()), Qt::UniqueConnection);
}

void CoQtRenderer::setLight(CoLight *pLight)
{
    if(m_pLight != NULL)
    {
        delete(m_pLight);
    }

    m_pLight = pLight;

    std::map<CoNode*, CoNodeCore*>::iterator iter;
    for(iter = m_mapNodeObject.begin(); iter != m_mapNodeObject.end(); ++iter)
    {
        CoNodeCore *pNodeObject = iter->second;

        pNodeObject->setLight(m_pLight);
    }
}

void CoQtRenderer::addNode(CoNode *pNode)
{
    auto ret = m_mapNodeObject.insert( { pNode , nullptr } );
    if (ret.second)
    {
        CoNodeCore *pNodeObject = NULL;
        switch (pNode->getShaderProgramType())
        {
        case EShaderProgramType::eLine:
        default:
            pNodeObject = new CoLineCore(pNode, m_pCamera, m_pLight);
            break;
        case EShaderProgramType::eSpline:
            pNodeObject = new CoCatmullSplineCore(pNode, m_pCamera, m_pLight);
            break;
        case EShaderProgramType::eCircle:
            pNodeObject = new CoCircleCore(pNode, m_pCamera, m_pLight);
            break;
        case EShaderProgramType::eSphere:
            pNodeObject = new CoSphereCore(pNode, m_pCamera, m_pLight);
            break;
        case EShaderProgramType::eCylinder:
            pNodeObject = new CoCylinderCore(pNode, m_pCamera, m_pLight);
            break;            
        case EShaderProgramType::eCone:
            pNodeObject = new CoConeCore(pNode, m_pCamera, m_pLight);
            break;
        case EShaderProgramType::ePolygon:
            pNodeObject = new CoPolygonCore(pNode, m_pCamera, m_pLight);
            break;
        case EShaderProgramType::eTexturedPolygon:
            pNodeObject = new CoTexturedPolygonCore(pNode, m_pCamera, m_pLight);
            break;
        case EShaderProgramType::eTexture:
            pNodeObject = new CoTextureCore(pNode, m_pCamera, m_pLight);
            break;
        }

        ret.first->second = pNodeObject;
    }
}
