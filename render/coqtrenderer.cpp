#include "coqtrenderer.h"

static const GLfloat g_vertex_buffer_data[] =
{
    -1.0f, -1.0f, 0.0f, 1.0,
    1.0f, -1.0f, 0.0f, 1.0,
    0.0f,  1.0f, 0.0f, 1.0,
    1.0f, -1.0f, 0.0f, 1.0,
    3.0f, -1.0f, 0.0f, 1.0,
    2.0f,  1.0f, 0.0f, 1.0
};

CoQtRenderer::CoQtRenderer(QWidget* pParent)
    : m_pParent(pParent),
      m_pLayout(NULL),
      m_pGLWidget(NULL),
      m_pGLFunctions(NULL)
{
    initializeWidget();
}

CoQtRenderer::~CoQtRenderer()
{
    delete m_pLayout;
    delete m_pGLWidget;
}


void CoQtRenderer::initializeWidget()
{
    m_pLayout = new QGridLayout(m_pParent);

    m_pGLWidget = new CoGLWidget;
    connect(m_pGLWidget, SIGNAL(signalInitializeGL()), this, SLOT(initializeGL()));
    connect(m_pGLWidget, SIGNAL(signalResizeGL(int, int)), this, SLOT(resizeGL(int, int)));
    connect(m_pGLWidget, SIGNAL(signalPaintGL()), this, SLOT(paintGL()));

    QWidget *pWidget = dynamic_cast<QWidget*>(m_pGLWidget);
    m_pLayout->addWidget(pWidget);
}


void CoQtRenderer::initializeGL()
{
    qDebug() << __FUNCTION__;
    m_pGLFunctions = new QOpenGLFunctions_2_1;
    m_pGLFunctions->initializeOpenGLFunctions();
    m_pGLFunctions->glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    m_nProgramID = m_pGLFunctions->glCreateProgram();

    initializeShader();    

    m_nMatrixID = m_pGLFunctions->glGetUniformLocation(m_nProgramID, "perViewModel");
    m_nVertexID = m_pGLFunctions->glGetAttribLocation(m_nProgramID, "vertex");

    m_pGLFunctions->glGenBuffers(1, &m_nVerterBuffer);
    m_pGLFunctions->glBindBuffer(GL_ARRAY_BUFFER, m_nVerterBuffer);
    m_pGLFunctions->glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}
void CoQtRenderer::resizeGL(int nWidth, int nHeight)
{
    qDebug() << __FUNCTION__;

    GLsizei width = nWidth;
    GLsizei height = nHeight;

    glViewport(0, 0, width, height);

    glm::mat4 mat4Projection = glm::perspective(glm::radians(45.0f), (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);
    glm::mat4 mat4View = glm::lookAt(glm::vec3(0,0,10),
                                     glm::vec3(0,0,0),
                                     glm::vec3(0,1,0));
    glm::mat4 mat4Model = glm::mat4(1.0f);

    m_mat4PerViewModel = mat4Projection * mat4View * mat4Model;
}

void CoQtRenderer::paintGL()
{
    qDebug() << __FUNCTION__;

    m_pGLFunctions->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    m_pGLFunctions->glLoadIdentity();

    m_pGLFunctions->glUseProgram(m_nProgramID);

    m_pGLFunctions->glUniformMatrix4fv(m_nMatrixID, 1, GL_FALSE, &m_mat4PerViewModel[0][0]);
    m_pGLFunctions->glEnableVertexAttribArray(m_nVertexID);
    m_pGLFunctions->glBindBuffer(GL_ARRAY_BUFFER, m_nVerterBuffer);
    m_pGLFunctions->glVertexAttribPointer
            (
                0,
                4,
                GL_FLOAT,
                GL_FALSE,
                0,
                (void*)0
                );

    m_pGLFunctions->glDrawArrays(GL_TRIANGLES, 0, 6);
    m_pGLFunctions->glDisableVertexAttribArray(m_nVertexID);
}

void CoQtRenderer::initializeShader()
{
    m_pShaderLoader = new CoShaderLoader(m_pGLFunctions);

    QString strVertexShaderPath = qApp->applicationDirPath() + "/glsl" + "/vertex.glsl";
    QString strFragShaderPath = qApp->applicationDirPath() + "/glsl" + "/fragment.glsl";

    GLuint nShaderIDs[2];
    nShaderIDs[0] = m_pShaderLoader->ReadShaderCode(GL_VERTEX_SHADER, strVertexShaderPath.toLocal8Bit());
    nShaderIDs[1] = m_pShaderLoader->ReadShaderCode(GL_FRAGMENT_SHADER, strFragShaderPath.toLocal8Bit());

    m_pShaderLoader->ShaderLinking(m_nProgramID, nShaderIDs, 2);
}
