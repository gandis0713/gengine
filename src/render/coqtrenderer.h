#ifndef GQTRENDERER_H
#define GQTRENDERER_H

#include <GL/glew.h>
#include "coenginedefine.h"

#include <map>

#include "coshaderprogram.h"
#include "coqscreen.h"
#include "dedatatype.h"

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

    Guint m_nMatrixID;
    Guint m_nVertexID;
    Guint m_nColorID;
    Guint m_nVerterBuffer;
    Guint m_mColorbuffer;

    Gmat4 m_mat4PerViewModel;


public slots:
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
};

#endif // COQTRENDERER_H
