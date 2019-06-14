#ifndef GQTRENDERER_H
#define GQTRENDERER_H

#include <GL/glew.h>
#include "coenginedefine.h"

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include <map>

#include "coshaderprogram.h"
#include "coqscreen.h"

class CoQScreen;
class QGridLayout;

class GANDISENGINE CoQtRenderer : public QObject
{
    Q_OBJECT
public:
    CoQtRenderer(QWidget *pParent);
    ~CoQtRenderer();

private:
    void initializeWidget();
    bool createShaderProgram();

private:
    CoQScreen         *m_pQScreen;
    QGridLayout       *m_pLayout;
    QWidget           *m_pParent;

    CoShaderProgram   *m_pShaderProgram;

    GLuint m_nMatrixID;
    GLuint m_nVertexID;
    GLuint m_nColorID;
    GLuint m_nVerterBuffer;
    GLuint m_mColorbuffer;

    glm::mat4 m_mat4PerViewModel;


public slots:
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
};

#endif // COQTRENDERER_H
