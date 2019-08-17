#ifndef GQTRENDERER_H
#define GQTRENDERER_H

#include <map>

#include "deengine.h"
#include "coqscreen.h"
#include "dedatatype.h"
#include "corenderer.h"
#include "conode.h"
#include "conodecore.h"
#include "cocamera.h"
#include "covector2.h"

class CoQScreen;
class QGridLayout;
class CoCamera;

class GANDISENGINE CoQtRenderer : public CoRenderer
{
    Q_OBJECT
public:
    CoQtRenderer(QWidget *pParent);
    ~CoQtRenderer();

    void setCamera(CoCamera* pCamera);
    void addNode(CoNode* pNode);
    void update();

private:
    void initializeWidget();

private:
    CoQScreen         *m_pQScreen;
    QGridLayout       *m_pLayout;
    QWidget           *m_pParent;

    CoCamera          *m_pCamera;

    std::map<CoNode*, CoNodeCore*>   m_mapNodeObject;

    CoVec2 vLastPoint;

public slots:
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
    void slotCameraUpdated();
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
};

#endif // COQTRENDERER_H
