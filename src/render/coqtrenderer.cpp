#include "coglextension.h"
#include "coqtrenderer.h"

#include "nomath.h"

#include "dedefaultvertexshader.h"
#include "dedefaultfragmentshader.h"

#include "coperspectivecamera.h"
#include "coorthographiccamera.h"
#include "conode.h"

#include <QGridLayout>

CoNodeCore::CoNodeCore(CoNode* pNode, CoCamera *pCamera)
    : m_pNode(pNode)
    , m_pCamera(pCamera)
    ,m_pVAO(NULL)
    ,m_pVBO(NULL)
    ,m_pCBO(NULL)
    ,m_pShaderProgram(NULL)
{
    m_eShaderProgramType = m_pNode->getShaderProgramType();
}

CoNodeCore::~CoNodeCore()
{

}

CoDefaultNodeCore::CoDefaultNodeCore(CoNode* pNode, CoCamera *pCamera)
    : CoNodeCore(pNode, pCamera)
{
}


CoDefaultNodeCore::~CoDefaultNodeCore()
{

}

void CoDefaultNodeCore::initialize()
{
    m_pVAO = new CoVertexArrayObject();
    m_pVBO = new CoVertexBufferObject();
    m_pCBO = new CoVertexBufferObject();

    m_pShaderProgram = new CoDefaultShaderProgram();
    m_pShaderProgram->AddShaders(EShaderType::eFragment, strDefaultFragShader);
    m_pShaderProgram->AddShaders(EShaderType::eVertex, strDefaultVertexShader);
    m_pShaderProgram->link();
    m_pShaderProgram->setUniform();
    m_pShaderProgram->setAttribute();

    m_pVBO->gen();
    m_pVBO->bind();
    m_pVBO->setAllocate(&m_pNode->getPoints()[0], m_pNode->getSize() * 3 * sizeof(Gfloat));

    m_pCBO->gen();
    m_pCBO->bind();
    m_pVBO->setAllocate(&m_pNode->getColors()[0], m_pNode->getSize() * 3 * sizeof(Gfloat));

    m_pVAO->gen();
    m_pVAO->bind();

    m_pVBO->bind();
    m_pShaderProgram->enableAttributeArray(m_pShaderProgram->m_nVertexID);
    m_pShaderProgram->setAttributeBuffer(m_pShaderProgram->m_nVertexID, 3, 0);

    m_pCBO->bind();
    m_pShaderProgram->enableAttributeArray(m_pShaderProgram->m_nColorID);
    m_pShaderProgram->setAttributeBuffer(m_pShaderProgram->m_nColorID, 3, 0);

    m_pVAO->release();
}

void CoDefaultNodeCore::paint()
{
    m_pShaderProgram->bind();
    m_pShaderProgram->setUniformMatrix4fv(m_pShaderProgram->m_nMatrixID, m_pCamera->getMatrix() * CoMat4x4());

    m_pVAO->bind();

    m_pNode->draw();
}


CoSplineNodeCore::CoSplineNodeCore(CoNode* pNode, CoCamera *pCamera)
    : CoNodeCore(pNode, pCamera)
{

}
CoSplineNodeCore::~CoSplineNodeCore()
{

}

void CoSplineNodeCore::initialize()
{
}

void CoSplineNodeCore::paint()
{
}

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
    m_pQScreen->updateGL();
}

void CoQtRenderer::setCamera(CoCamera *pCamera)
{
    if(m_pCamera != NULL)
    {
        disconnect(m_pCamera, SIGNAL(signalCameraUpdated()), this, SLOT(slotCameraUpdated()));
    }

    m_pCamera = pCamera;
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
        case EShaderProgramType::eDefault:
        default:
            pNodeObject = new CoDefaultNodeCore(pNode, m_pCamera);
            break;
        case EShaderProgramType::eSpline:
            pNodeObject = new CoSplineNodeCore(pNode, m_pCamera);
            break;
        }

        ret.first->second = pNodeObject;
    }
}
