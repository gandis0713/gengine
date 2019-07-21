#include "coglextension.h"
#include "coqtrenderer.h"

#include "nomath.h"

#include "dedefaultvertexshader.h"
#include "dedefaultfragmentshader.h"

#include "coperspectivecamera.h"
#include "coorthographiccamera.h"
#include "conode.h"

#include <QDebug>
#include <QGridLayout>

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

static const Gfloat av1[] = {1.0, 1.0, 0.0,   0.0, -1.0, 0.0};
static const Gfloat ac1[] = {1.0, 0.0, 0.0,   1.0, 0.0, 0.0};

#include <iostream>
void CoQtRenderer::initializeGL()
{
    CoGLExtension::getInstance();

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    createShaderProgram();

    std::map<CoNode*, SNodeObject*>::iterator iter;
    for(iter = m_mapNodeObject.begin(); iter != m_mapNodeObject.end(); ++iter)
    {
        CoNode *pNode = iter->first;
        SNodeObject *pNodeObject = iter->second;

        pNodeObject->vbo->gen();
        pNodeObject->vbo->bind();
        pNodeObject->vbo->setAllocate(&pNode->GetPoints()[0], pNode->GetSize() * 3 * sizeof(Gfloat));

        pNodeObject->cbo->gen();
        pNodeObject->cbo->bind();
        pNodeObject->vbo->setAllocate(&pNode->GetColors()[0], pNode->GetSize() * 3 * sizeof(Gfloat));

        pNodeObject->vao->gen();
        pNodeObject->vao->bind();

        pNodeObject->vbo->bind();
        m_pShaderProgram->enableAttributeArray(m_nVertexID);
        m_pShaderProgram->setAttributeBuffer(m_nVertexID, 3, 0);

        pNodeObject->cbo->bind();
        m_pShaderProgram->enableAttributeArray(m_nColorID);
        m_pShaderProgram->setAttributeBuffer(m_nColorID, 3, 0);

        pNodeObject->vao->release();
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

    std::map<CoNode*, SNodeObject*>::iterator iter;
    for(iter = m_mapNodeObject.begin(); iter != m_mapNodeObject.end(); ++iter)
    {
        CoNode *pNode = iter->first;
        SNodeObject *pNodeObject = iter->second;

        m_pShaderProgram->bind();
        m_pShaderProgram->setUniformMatrix4fv(m_nMatrixID, m_pCamera->getMatrix() * CoMat4x4());

        pNodeObject->vao->bind();

//        glDrawArrays(GL_LINE_LOOP, 0, pNode->GetSize());
        glDrawArrays(GL_LINE_STRIP, 0, pNode->GetSize());
    }

}

void CoQtRenderer::slotCameraUpdated()
{
    m_pQScreen->updateGL();
}

void CoQtRenderer::createShaderProgram()
{
    m_pShaderProgram = new CoShaderProgram();
    m_pShaderProgram->AddShaders(EShaderType::eFragment, strDefaultFragShader);
    m_pShaderProgram->AddShaders(EShaderType::eVertex, strDefaultVertexShader);
    m_pShaderProgram->link();

    m_nMatrixID = m_pShaderProgram->getUniformLocation("perViewModel");
    m_nVertexID = m_pShaderProgram->getAttribLocation("vertex");
    m_nColorID = m_pShaderProgram->getAttribLocation("color");
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
        SNodeObject *pNodeObject = new SNodeObject();
        pNodeObject->vao = new CoVertexArrayObject();
        pNodeObject->vbo = new CoVertexBufferObject();
        pNodeObject->cbo = new CoVertexBufferObject();
        ret.first->second = pNodeObject;
    }
}
