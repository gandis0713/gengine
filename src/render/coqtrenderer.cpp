#include "coglextension.h"
#include "coqtrenderer.h"

#include "comatrix4x4.h"
#include "coperspectivecamera.h"
#include "nomath.h"

#include "delog.h"

#include <QGridLayout>

static const GLfloat g_vertex_buffer_data[] = {
    -1.0f,-1.0f, 0.0f,
     1.0f,-1.0f, 0.0f,
     0.0f, 1.0f, 0.0f,

     1.0f,-1.0f, -2.0f,
     3.0f,-1.0f, -2.0f,
     2.0f, 1.0f, -2.0f,

    -3.0f,-1.0f, -2.0f,
    -1.0f,-1.0f, -2.0f,
    -2.0f, 1.0f, -2.0f,
};

static const GLfloat g_color_buffer_data[] = {
    1.000f,  1.000f,  1.000f,
    1.000f,  1.000f,  1.000f,
    1.000f,  1.000f,  1.000f,

    0.000f,  0.000f,  1.000f,
    0.000f,  0.000f,  1.000f,
    0.000f,  0.000f,  1.000f,

    1.000f,  0.000f,  0.000f,
    1.000f,  0.000f,  0.000f,
    1.000f,  0.000f,  0.000f,
};

CoQtRenderer::CoQtRenderer(QWidget* pParent)
    : m_pParent(pParent),
      m_pLayout(NULL),
      m_pQScreen(NULL),
      m_pShaderProgram(NULL),
      m_pCamera(NULL)
{
    initializeWidget();
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

    createShaderProgram();

    m_nMatrixID = m_pShaderProgram->getUniformLocation("perViewModel");
    m_nVertexID = m_pShaderProgram->getAttribLocation("vertex");
    m_nColorID = m_pShaderProgram->getAttribLocation("color");

    glGenBuffers(1, &m_nVerterBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, m_nVerterBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    glGenBuffers(1, &m_mColorbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, m_mColorbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
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

    m_pShaderProgram->bind();

    CoMat4x4 mat = m_pCamera->getMatrix() * m_mat4Model;

    m_pShaderProgram->setUniformMatrix4fv(m_nMatrixID, mat);

    glBindBuffer(GL_ARRAY_BUFFER, m_nVerterBuffer);
    glEnableVertexAttribArray(m_nVertexID);
    glVertexAttribPointer
            (
                m_nVertexID,
                3,
                GL_FLOAT,
                GL_FALSE,
                0,
                (void*)0
                );


    glBindBuffer(GL_ARRAY_BUFFER, m_mColorbuffer);
    glEnableVertexAttribArray(m_nColorID);
    glVertexAttribPointer
            (
                m_nColorID,
                3,
                GL_FLOAT,
                GL_FALSE,
                0,
                (void*)0
                );


    glDrawArrays(GL_TRIANGLES, 0, 9);

    glDisableVertexAttribArray(m_nVertexID);
    glDisableVertexAttribArray(m_nColorID);
}

void CoQtRenderer::slotCameraUpdated()
{
    m_pQScreen->updateGL();
}

bool CoQtRenderer::createShaderProgram()
{
    if(m_pShaderProgram != NULL)
    {
        delete m_pShaderProgram;
    }

    m_pShaderProgram = new CoShaderProgram();

    return true;

}

void CoQtRenderer::setCamera(CoCamera *pCamera)
{
    if(m_pCamera != NULL)
    {
        disconnect(m_pCamera, SIGNAL(signalUpdated()), this, SLOT(slotCameraUpdated()));
    }

    m_pCamera = pCamera;
    connect(m_pCamera, SIGNAL(signalUpdated()), this, SLOT(slotCameraUpdated()), Qt::UniqueConnection);
}
