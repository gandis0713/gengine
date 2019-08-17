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
#include <QDebug>
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
    GLsizei width = nWidth;
    GLsizei height = nHeight;

    glViewport(0, 0, width, height);
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
    vLastPoint[0] = -(291 - event->localPos().x());
    vLastPoint[1] = (271 - event->localPos().y());
    Vec2Log(vLastPoint);
}

void CoQtRenderer::mouseMoveEvent(QMouseEvent* event)
{
    CoVec3 v_camera_position = m_pCamera->getPosition();
    CoVec3 v_camera_up_normalized = m_pCamera->getUp().normalize();
    CoVec3 v_camera_target = m_pCamera->getTarget();

    CoVec3 v_camera_to_target = (v_camera_position - v_camera_target);
    CoVec3 v_camera_to_target_normalized = (v_camera_position - v_camera_target).normalize();
    CoVec3 v_camera_right_normalized = (v_camera_up_normalized.cross(v_camera_to_target_normalized)).normalize();

    CoMat4x4 mat_rotate_yaw;
    CoMat4x4 mat_rotate_pitch;

    mat_rotate_pitch = mat_rotate_pitch.rotate(-1, v_camera_right_normalized);
    v_camera_to_target = mat_rotate_pitch * v_camera_to_target;
    v_camera_to_target += v_camera_target;

    mat_rotate_yaw = mat_rotate_yaw.rotate(-1, v_camera_up_normalized);
    v_camera_to_target = mat_rotate_yaw * v_camera_to_target;
    v_camera_to_target += v_camera_target;

    v_camera_to_target_normalized = v_camera_to_target;
    v_camera_to_target_normalized.normalize();
    v_camera_up_normalized = (v_camera_to_target_normalized.cross(v_camera_right_normalized)).normalize();

    m_pCamera->setPosition(v_camera_to_target);
    m_pCamera->setUp(v_camera_up_normalized);
    m_pCamera->setTarget(v_camera_target);
    Vec3Log(v_camera_to_target);
    Vec3Log(v_camera_right_normalized);
    Vec3Log(v_camera_up_normalized);
    Vec3Log(v_camera_target);

    m_pCamera->update();

//    vLastPoint[0] = vPoint[0];
//    vLastPoint[1] = vPoint[1];

    qDebug() << "\n";
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
