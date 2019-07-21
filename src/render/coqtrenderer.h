#ifndef GQTRENDERER_H
#define GQTRENDERER_H

#include <map>

#include "deengine.h"
#include "coqscreen.h"
#include "dedatatype.h"
#include "coshaderprogram.h"
#include "covertexarrayobject.h"
#include "covertexbufferobject.h"

class CoQScreen;
class QGridLayout;
class CoCamera;
class CoNode;

struct SNodeObject
{
    CoVertexArrayObject*  vao;
    CoVertexBufferObject* vbo;
    CoVertexBufferObject* cbo;
};

class GANDISENGINE CoQtRenderer : public QObject
{
    Q_OBJECT
public:
    CoQtRenderer(QWidget *pParent);
    ~CoQtRenderer();

    void setCamera(CoCamera* pCamera);
    void addNode(CoNode* pNode);

private:
    void initializeWidget();
    void createShaderProgram();

private:
    CoQScreen         *m_pQScreen;
    QGridLayout       *m_pLayout;
    QWidget           *m_pParent;

    CoShaderProgram     *m_pShaderProgram;
    CoCamera            *m_pCamera;

    std::map<CoNode*, SNodeObject*> m_mapNodeObject;

    Guint m_nMatrixID;
    Guint m_nVertexID;
    Guint m_nColorID;

public slots:
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
    void slotCameraUpdated();
};

#endif // COQTRENDERER_H
