#ifndef GQTRENDERER_H
#define GQTRENDERER_H

#include "deengine.h"

#include <map>

#include "coshaderprogram.h"
#include "coqscreen.h"
#include "dedatatype.h"

class CoQScreen;
class QGridLayout;
class CoCamera;
class CoMat4x4;

class GANDISENGINE CoQtRenderer : public QObject
{
    Q_OBJECT
public:
    CoQtRenderer(QWidget *pParent);
    ~CoQtRenderer();

    void setCamera(CoCamera *pCamera);

private:
    void initializeWidget();
    bool createShaderProgram();

private:
    CoQScreen         *m_pQScreen;
    QGridLayout       *m_pLayout;
    QWidget           *m_pParent;

    CoShaderProgram   *m_pShaderProgram;
    CoCamera *m_pCamera;

    Guint m_nMatrixID;
    Guint m_nVertexID;
    Guint m_nColorID;
    Guint m_nVerterBuffer;
    Guint m_mColorbuffer;

    CoMat4x4 m_mat4Model;


public slots:
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
    void slotCameraUpdated();
};

#endif // COQTRENDERER_H
