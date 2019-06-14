
#include "coqtrenderer.h"

#include "shader/covertexshader.h"
#include "shader/cofragmentshader.h"

#include "delog.h"

#include <QGridLayout>

static const GLfloat g_vertex_buffer_data[] = {
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f
};

static const GLfloat g_color_buffer_data[] = {
    1.000f,  1.000f,  1.000f,
    1.000f,  1.000f,  1.000f,
    1.000f,  1.000f,  1.000f,

    1.000f,  1.000f,  1.000f,
    1.000f,  1.000f,  1.000f,
    1.000f,  1.000f,  1.000f,

    1.000f,  1.000f,  1.000f,
    1.000f,  1.000f,  1.000f,
    1.000f,  1.000f,  1.000f,

    1.000f,  0.000f,  0.000f,
    1.000f,  0.000f,  0.000f,
    1.000f,  0.000f,  0.000f,

    1.000f,  0.000f,  0.000f,
    1.000f,  0.000f,  0.000f,
    1.000f,  0.000f,  0.000f,

    1.000f,  0.000f,  0.000f,
    1.000f,  0.000f,  0.000f,
    1.000f,  0.000f,  0.000f,

    0.000f,  1.000f,  0.000f,
    0.000f,  0.000f,  1.000f,
    1.000f,  0.000f,  0.000f,

    0.000f,  1.000f,  0.000f,
    0.000f,  1.000f,  0.000f,
    0.000f,  1.000f,  0.000f,

    0.000f,  1.000f,  0.000f,
    0.000f,  1.000f,  0.000f,
    0.000f,  1.000f,  0.000f,

    0.000f,  0.000f,  1.000f,
    0.000f,  0.000f,  1.000f,
    0.000f,  0.000f,  1.000f,

    0.000f,  0.000f,  1.000f,
    0.000f,  0.000f,  1.000f,
    0.000f,  0.000f,  1.000f,

    0.000f,  0.000f,  1.000f,
    0.000f,  0.000f,  1.000f,
    0.000f,  0.000f,  1.000f,
};

CoQtRenderer::CoQtRenderer(QWidget* pParent)
    : m_pParent(pParent),
      m_pLayout(NULL),
      m_pQScreen(NULL),
      m_pShaderProgram(NULL)
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
    glewInit();
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
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

    glm::mat4 mat4Projection = glm::perspective(glm::radians(45.0f), (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);
    glm::mat4 mat4View = glm::lookAt(glm::vec3(4,4,3),
                                     glm::vec3(0,0,0),
                                     glm::vec3(0,1,0));
    glm::mat4 mat4Model = glm::mat4(1.0f);

    m_mat4PerViewModel = mat4Projection * mat4View * mat4Model;
}

void CoQtRenderer::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    m_pShaderProgram->bind();

    m_pShaderProgram->setUniformMatrix4fv(m_nMatrixID, m_mat4PerViewModel);

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


    glDrawArrays(GL_TRIANGLES, 0, 36);

    glDisableVertexAttribArray(m_nVertexID);
    glDisableVertexAttribArray(m_nColorID);

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
