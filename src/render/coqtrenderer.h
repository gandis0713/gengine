#ifndef GQTRENDERER_H
#define GQTRENDERER_H

#include <map>

#include "deengine.h"
#include "coqscreen.h"
#include "dedatatype.h"
#include "corenderer.h"
#include "conode.h"
#include "cocamera.h"
#include "codefaultshaderprogram.h"
#include "cosplineshaderprogram.h"
#include "covertexarrayobject.h"
#include "covertexbufferobject.h"

class CoQScreen;
class QGridLayout;
class CoCamera;

class CoNodeCore
{
public:
    CoNodeCore(CoNode* pNode, CoCamera *pCamera);
    ~CoNodeCore();

    virtual void initialize() = 0;
    virtual void paint() = 0;

protected:
    CoNode*               m_pNode;
    CoCamera*             m_pCamera;

    CoVertexArrayObject*  m_pVAO;
    CoVertexBufferObject* m_pVBO;
    CoVertexBufferObject* m_pCBO;
    CoDefaultShaderProgram* m_pShaderProgram;
    EShaderProgramType    m_eShaderProgramType;
};

class CoDefaultNodeCore : public CoNodeCore
{
public:
    CoDefaultNodeCore(CoNode* pNode, CoCamera *pCamera);
    ~CoDefaultNodeCore();

    void initialize() override;
    void paint() override;
};

class CoSplineNodeCore : public CoNodeCore
{
public:
    CoSplineNodeCore(CoNode* pNode, CoCamera *pCamera);
    ~CoSplineNodeCore();

    void initialize() override;
    void paint() override;
};

class GANDISENGINE CoQtRenderer : public CoRenderer
{
    Q_OBJECT
public:
    CoQtRenderer(QWidget *pParent);
    ~CoQtRenderer();

    void setCamera(CoCamera* pCamera);
    void addNode(CoNode* pNode);

private:
    void initializeWidget();

private:
    CoQScreen         *m_pQScreen;
    QGridLayout       *m_pLayout;
    QWidget           *m_pParent;

    CoCamera               *m_pCamera;

    std::map<CoNode*, CoNodeCore*>                     m_mapNodeObject;

public slots:
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
    void slotCameraUpdated();
};

#endif // COQTRENDERER_H
