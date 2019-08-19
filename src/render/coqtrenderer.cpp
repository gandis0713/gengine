#include "coglextension.h"
#include "coqtrenderer.h"

#include "nomath.h"

#include "coperspectivecamera.h"
#include "coorthographiccamera.h"
#include "colinecore.h"
#include "cotexturecore.h"
#include "copolygoncore.h"
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
    CoVec3 vMin(1000000, 1000000, 1000000);
    CoVec3 vMax(-1000000, -1000000, -1000000);

    std::map<CoNode*, CoNodeCore*>::iterator iter;
    for(iter = m_mapNodeObject.begin(); iter != m_mapNodeObject.end(); ++iter)
    {
        CoVec3 vTempMin;
        CoVec3 vTempMax;
        CoShape *pShape = static_cast<CoShape*>(iter->first);
        pShape->getBound(vTempMin, vTempMax);

        if(vMin[0] > vTempMin[0])
        {
            vMin[0] = vTempMin[0];
        }
        if(vMin[1] > vTempMin[1])
        {
            vMin[1] = vTempMin[1];
        }
        if(vMin[2] > vTempMin[2])
        {
            vMin[2] = vTempMin[2];
        }

        if(vMax[0] < vTempMax[0])
        {
            vMax[0] = vTempMax[0];
        }
        if(vMax[1] < vTempMax[1])
        {
            vMax[1] = vTempMax[1];
        }
        if(vMax[2] < vTempMax[2])
        {
            vMax[2] = vTempMax[2];
        }
    }

    Gfloat fMax = vMax[0] - vMin[0];
    if(fMax < vMax[1] - vMin[1])
        fMax = vMax[1] - vMin[1];
    if(fMax < vMax[2] - vMin[2])
        fMax = vMax[2] - vMin[2];

    CoVec3 vHalfSize = (vMax - vMin)/CoVec3(2,2,2);
    CoVec3 vCenter = vMin + vHalfSize;

    m_pCamera->setLeftPosition(vCenter[0] - vHalfSize[0] * 1.5);
    m_pCamera->setRightPosition(vCenter[0] + vHalfSize[0] * 1.5);
    m_pCamera->setTopPosition(vCenter[1] + vHalfSize[1] * 1.5);
    m_pCamera->setBottomPosition(vCenter[1] - vHalfSize[1] * 1.5);

    CoVec3 vPosition = m_pCamera->getPosition();
    vPosition[2] = fMax * 1.5;
    m_pCamera->setPosition(vPosition);
    m_pCamera->setNearPosition(0.f);
    m_pCamera->setFarPosition(fMax * 3);

    m_pCamera->update();
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
            pNodeObject = new CoLineCore(pNode, m_pCamera);
            break;
        case EShaderProgramType::eSpline:
            pNodeObject = new CoCatmullSplineCore(pNode, m_pCamera);
            break;
        case EShaderProgramType::eCircle:
            pNodeObject = new CoCircleCore(pNode, m_pCamera);
            break;
        case EShaderProgramType::ePolygon:
            pNodeObject = new CoPolygonCore(pNode, m_pCamera);
            break;
        case EShaderProgramType::eTexture:
            pNodeObject = new CoTextureCore(pNode, m_pCamera);
            break;
        }

        ret.first->second = pNodeObject;
    }
}
