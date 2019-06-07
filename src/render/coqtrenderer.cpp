#include "coqtrenderer.h"

#include "screen/qt/coglwidget.h"

#include "shader/covertexshader.h"
#include "shader/cofragmentshader.h"

#include <QDebug>

//static const GLfloat g_vertex_buffer_data[] = {
//    -1.0f,-1.0f,-1.0f, // triangle 1 : begin
//    -1.0f,-1.0f, 1.0f,
//    -1.0f, 1.0f, 1.0f, // triangle 1 : end
//    1.0f, 1.0f,-1.0f, // triangle 2 : begin
//    -1.0f,-1.0f,-1.0f,
//    -1.0f, 1.0f,-1.0f, // triangle 2 : end
//    1.0f,-1.0f, 1.0f,
//    -1.0f,-1.0f,-1.0f,
//    1.0f,-1.0f,-1.0f,
//    1.0f, 1.0f,-1.0f,
//    1.0f,-1.0f,-1.0f,
//    -1.0f,-1.0f,-1.0f,
//    -1.0f,-1.0f,-1.0f,
//    -1.0f, 1.0f, 1.0f,
//    -1.0f, 1.0f,-1.0f,
//    1.0f,-1.0f, 1.0f,
//    -1.0f,-1.0f, 1.0f,
//    -1.0f,-1.0f,-1.0f,
//    -1.0f, 1.0f, 1.0f,
//    -1.0f,-1.0f, 1.0f,
//    1.0f,-1.0f, 1.0f,
//    1.0f, 1.0f, 1.0f,
//    1.0f,-1.0f,-1.0f,
//    1.0f, 1.0f,-1.0f,
//    1.0f,-1.0f,-1.0f,
//    1.0f, 1.0f, 1.0f,
//    1.0f,-1.0f, 1.0f,
//    1.0f, 1.0f, 1.0f,
//    1.0f, 1.0f,-1.0f,
//    -1.0f, 1.0f,-1.0f,
//    1.0f, 1.0f, 1.0f,
//    -1.0f, 1.0f,-1.0f,
//    -1.0f, 1.0f, 1.0f,
//    1.0f, 1.0f, 1.0f,
//    -1.0f, 1.0f, 1.0f,
//    1.0f,-1.0f, 1.0f
//};

static const GLfloat g_vertex_buffer_data[] = {
    -1.0f,-1.0f,-1.0f, // triangle 1 : begin
    -1.0f,-1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f, // triangle 1 : end
    1.0f, 1.0f,-1.0f, // triangle 2 : begin
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f, // triangle 2 : end
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
    1.0f,-1.0f, 1.0f,
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

//    0.000f,  1.000f,  0.000f,
//    0.000f,  1.000f,  0.000f,
//    0.000f,  1.000f,  0.000f,

//    0.000f,  1.000f,  0.000f,
//    0.000f,  1.000f,  0.000f,
//    0.000f,  1.000f,  0.000f,

//    0.000f,  1.000f,  0.000f,
//    0.000f,  1.000f,  0.000f,
//    0.000f,  1.000f,  0.000f,

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

//    0.000f,  1.000f,  0.000f,
//    0.000f,  1.000f,  0.000f,
//    0.000f,  1.000f,  0.000f,

//    0.000f,  1.000f,  0.000f,
//    0.000f,  1.000f,  0.000f,
//    0.000f,  1.000f,  0.000f,

//    0.000f,  1.000f,  0.000f,
//    0.000f,  1.000f,  0.000f,
//    0.000f,  1.000f,  0.000f,

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

//static const GLfloat g_color_buffer_data[] = {
//    1.000f,  1.000f,  1.000f,
//    1.000f,  1.000f,  1.000f,
//    1.000f,  1.000f,  1.000f,
//    1.000f,  1.000f,  1.000f,
//    0.435f,  0.602f,  0.223f,
//    0.310f,  0.747f,  0.185f,
//    0.597f,  0.770f,  0.761f,
//    0.559f,  0.436f,  0.730f,
//    0.359f,  0.583f,  0.152f,
//    0.483f,  0.596f,  0.789f,
//    0.559f,  0.861f,  0.639f,
//    0.195f,  0.548f,  0.859f,
//    0.014f,  0.184f,  0.576f,
//    0.771f,  0.328f,  0.970f,
//    0.406f,  0.615f,  0.116f,
//    0.676f,  0.977f,  0.133f,
//    0.971f,  0.572f,  0.833f,
//    0.140f,  0.616f,  0.489f,
//    0.997f,  0.513f,  0.064f,
//    0.945f,  0.719f,  0.592f,
//    0.543f,  0.021f,  0.978f,
//    0.279f,  0.317f,  0.505f,
//    0.167f,  0.620f,  0.077f,
//    0.347f,  0.857f,  0.137f,
//    0.055f,  0.953f,  0.042f,
//    0.714f,  0.505f,  0.345f,
//    0.783f,  0.290f,  0.734f,
//    0.722f,  0.645f,  0.174f,
//    0.302f,  0.455f,  0.848f,
//    0.225f,  0.587f,  0.040f,
//    0.517f,  0.713f,  0.338f,
//    0.053f,  0.959f,  0.120f,
//    0.393f,  0.621f,  0.362f,
//    0.673f,  0.211f,  0.457f,
//    0.820f,  0.883f,  0.371f,
//    0.982f,  0.099f,  0.879f
//};

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

    m_pGLFunctions->glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    m_pGLFunctions->glDepthFunc(GL_LESS);

    m_nProgramID = m_pGLFunctions->glCreateProgram();

    createDefaultShader();

    m_nMatrixID = m_pGLFunctions->glGetUniformLocation(m_nProgramID, "perViewModel");
    m_nVertexID = m_pGLFunctions->glGetAttribLocation(m_nProgramID, "vertex");
    m_nColorID = m_pGLFunctions->glGetAttribLocation(m_nProgramID, "color");

    m_pGLFunctions->glGenBuffers(1, &m_nVerterBuffer);
    m_pGLFunctions->glBindBuffer(GL_ARRAY_BUFFER, m_nVerterBuffer);
    m_pGLFunctions->glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    m_pGLFunctions->glGenBuffers(1, &m_mColorbuffer);
    m_pGLFunctions->glBindBuffer(GL_ARRAY_BUFFER, m_mColorbuffer);
    m_pGLFunctions->glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);

}

void CoQtRenderer::resizeGL(int nWidth, int nHeight)
{
    GLsizei width = nWidth;
    GLsizei height = nHeight;

    m_pGLFunctions->glViewport(0, 0, width, height);

    glm::mat4 mat4Projection = glm::perspective(glm::radians(45.0f), (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);
    glm::mat4 mat4View = glm::lookAt(glm::vec3(4,4,3),
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
                m_nVertexID,
                3,
                GL_FLOAT,
                GL_FALSE,
                0,
                (void*)0
                );

    m_pGLFunctions->glEnableVertexAttribArray(m_nColorID);
    m_pGLFunctions->glBindBuffer(GL_ARRAY_BUFFER, m_nVerterBuffer);
//    m_pGLFunctions->glBindBuffer(GL_ARRAY_BUFFER, m_mColorbuffer);
    m_pGLFunctions->glVertexAttribPointer
            (
                m_nColorID,
                3,
                GL_FLOAT,
                GL_FALSE,
                0,
                (void*)432
//                (void*)0
                );

    m_pGLFunctions->glDrawArrays(GL_TRIANGLES, 0, 36);

    m_pGLFunctions->glDisableVertexAttribArray(m_nVertexID);
    m_pGLFunctions->glDisableVertexAttribArray(m_nColorID);

}

bool CoQtRenderer::createDefaultShader()
{
    m_mapShaders.clear();

    auto ret = m_mapShaders.insert( { EShaderType::eVertex , nullptr } );
    if (ret.second)
    {
        CoShader *pShader = new CoVertexShader(m_pGLFunctions);
        ret.first->second = pShader;
    }

    ret = m_mapShaders.insert( { EShaderType::eFragment , nullptr } );
    if (ret.second)
    {
        CoShader *pShader = new CoFragmentShader(m_pGLFunctions);
        ret.first->second = pShader;
    }

    std::map<EShaderType, CoShader*>::iterator iter;
    for(iter = m_mapShaders.begin(); iter != m_mapShaders.end(); ++iter)
    {
        CoShader *pShader = iter->second;
        if(pShader)
        {
            m_pGLFunctions->glAttachShader(m_nProgramID, pShader->getID());
        }
    }

    m_pGLFunctions->glLinkProgram(m_nProgramID);

    GLint nResult = GL_FALSE;
    int nInfoLogLength;
    // 프로그램 검사
    m_pGLFunctions->glGetProgramiv(m_nProgramID, GL_LINK_STATUS, &nResult);
    m_pGLFunctions->glGetProgramiv(m_nProgramID, GL_INFO_LOG_LENGTH, &nInfoLogLength);
    if ( nInfoLogLength > 0 ){
        std::vector<char> strProgramErrorMessage(nInfoLogLength + 1);
        m_pGLFunctions->glGetProgramInfoLog(m_nProgramID, nInfoLogLength, NULL, &strProgramErrorMessage[0]);
//        std::cout << "The error message from progream : " << &strProgramErrorMessage[0] << std::endl;
        return false;
    }

    for(iter = m_mapShaders.begin(); iter != m_mapShaders.end(); ++iter)
    {
        CoShader *pShader = iter->second;
        if(pShader)
        {
            m_pGLFunctions->glDetachShader(m_nProgramID, pShader->getID());
            m_pGLFunctions->glDeleteShader(pShader->getID());
        }
    }

    return true;

}
