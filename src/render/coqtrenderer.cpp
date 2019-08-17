#include "coglextension.h"
#include "coqtrenderer.h"

#include "nomath.h"

#include "coperspectivecamera.h"
#include "coorthographiccamera.h"
#include "colinecore.h"
#include "cotexturecore.h"
#include "copolygoncore.h".h"
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

    CoVec3 vDir;
    vDir[0] = vPoint[0] - m_vLastPoint[0];
    vDir[1] = vPoint[1] - m_vLastPoint[1];
    vDir[2] = 0;

    CoVec3 vScreenNormal(0, 0, 1);
    CoVec3 vRotationNormal = vScreenNormal.cross(vDir);

    Gfloat fDegreeX = vRotationNormal.dot(CoVec3(1, 0, 0));
    Gfloat fDegreeY = vRotationNormal.dot(CoVec3(0, 1, 0));

    CoVec3 vCameraPosition = m_pCamera->getPosition();
    CoVec3 vCameraUpNormalized = m_pCamera->getUp().normalize();
    CoVec3 vCameraTarget = m_pCamera->getTarget();

    CoVec3 vCameraToTarget = (vCameraPosition - vCameraTarget);
    CoVec3 vCameraToTargetNormalized = (vCameraPosition - vCameraTarget).normalize();
    CoVec3 vCameraRightNormalized = (vCameraUpNormalized.cross(vCameraToTargetNormalized)).normalize();

    CoMat4x4 matRotateYaw;
    CoMat4x4 matRotatePitch;

    matRotatePitch = matRotatePitch.rotate(-fDegreeX, vCameraRightNormalized);
    vCameraToTarget = matRotatePitch * vCameraToTarget;
    vCameraToTarget += vCameraTarget;

    matRotateYaw = matRotateYaw.rotate(-fDegreeY, vCameraUpNormalized);
    vCameraToTarget = matRotateYaw * vCameraToTarget;
    vCameraToTarget += vCameraTarget;

    vCameraToTargetNormalized = vCameraToTarget;
    vCameraToTargetNormalized.normalize();
    vCameraUpNormalized = (vCameraToTargetNormalized.cross(vCameraRightNormalized)).normalize();

    m_pCamera->setPosition(vCameraToTarget);
    m_pCamera->setUp(vCameraUpNormalized);
    m_pCamera->setTarget(vCameraTarget);

    m_pCamera->update();

    m_vLastPoint[0] = vPoint[0];
    m_vLastPoint[1] = vPoint[1];
}

void CoQtRenderer::mouseReleaseEvent(QMouseEvent* event)
{
    update();
}

void CoQtRenderer::update()
{
    m_pQScreen->updateGL();
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
