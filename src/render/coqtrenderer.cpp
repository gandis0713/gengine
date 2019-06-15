
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
      m_pQScreen(NULL)
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

    m_nProgramID = glCreateProgram();

    createDefaultShader();

    m_nMatrixID = glGetUniformLocation(m_nProgramID, "perViewModel");
    m_nVertexID = glGetAttribLocation(m_nProgramID, "vertex");
    m_nColorID = glGetAttribLocation(m_nProgramID, "color");


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

    glUseProgram(m_nProgramID);

    glUniformMatrix4fv(m_nMatrixID, 1, GL_FALSE, &m_mat4PerViewModel[0][0]);

    glEnableVertexAttribArray(m_nVertexID);
    glBindBuffer(GL_ARRAY_BUFFER, m_nVerterBuffer);
    glVertexAttribPointer
            (
                m_nVertexID,
                3,
                GL_FLOAT,
                GL_FALSE,
                0,
                (void*)0
                );

    glEnableVertexAttribArray(m_nColorID);
    glBindBuffer(GL_ARRAY_BUFFER, m_mColorbuffer);
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

bool CoQtRenderer::createDefaultShader()
{
    m_mapShaders.clear();

    auto ret = m_mapShaders.insert( { EShaderType::eVertex , nullptr } );
    if (ret.second)
    {
        CoShader *pShader = new CoVertexShader();
        ret.first->second = pShader;
    }

    ret = m_mapShaders.insert( { EShaderType::eFragment , nullptr } );
    if (ret.second)
    {
        CoShader *pShader = new CoFragmentShader();
        ret.first->second = pShader;
    }

    std::map<EShaderType, CoShader*>::iterator iter;
    for(iter = m_mapShaders.begin(); iter != m_mapShaders.end(); ++iter)
    {
        CoShader *pShader = iter->second;
        if(pShader)
        {
            glAttachShader(m_nProgramID, pShader->getID());
        }
    }

    glLinkProgram(m_nProgramID);

    GLint nResult = GL_FALSE;
    int nInfoLogLength;
    // 프로그램 검사
    glGetProgramiv(m_nProgramID, GL_LINK_STATUS, &nResult);
    glGetProgramiv(m_nProgramID, GL_INFO_LOG_LENGTH, &nInfoLogLength);
    if ( nInfoLogLength > 0 ){
        std::vector<char> strProgramErrorMessage(nInfoLogLength + 1);
        glGetProgramInfoLog(m_nProgramID, nInfoLogLength, NULL, &strProgramErrorMessage[0]);
        return false;
    }

    for(iter = m_mapShaders.begin(); iter != m_mapShaders.end(); ++iter)
    {
        CoShader *pShader = iter->second;
        if(pShader)
        {
//            glDetachShader(m_nProgramID, pShader->getID());
//            glDeleteShader(pShader->getID());
        }
    }

    return true;

}
