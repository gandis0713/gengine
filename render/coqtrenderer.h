#ifndef GQTRENDERER_H
#define GQTRENDERER_H

#include "core/screen/qt/coglwidget.h"

#include "qtheader.h"

#include "core/shader/coshaderloader.h"

#include "/usr/include/glm/glm.hpp"
#include "/usr/include/glm/gtc/matrix_transform.hpp"

class CoQtRenderer : public QObject
{
    Q_OBJECT
public:
    CoQtRenderer(QWidget *pParent);
    ~CoQtRenderer();

private slots:
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();

private:
    void initializeWidget();
    void initializeShader();

private:
    CoGLWidget        *m_pGLWidget;
    QGridLayout       *m_pLayout;
    QWidget           *m_pParent;
    CoShaderLoader    *m_pShaderLoader;

    QOpenGLFunctions_2_1    *m_pGLFunctions;

    GLuint m_nProgramID;
    GLuint m_nMatrixID;
    GLuint m_nVertexID;
    GLuint m_nVerterBuffer;

    glm::mat4 m_mat4PerViewModel;
};

#endif // COQTRENDERER_H
