#ifndef GQTRENDERER_H
#define GQTRENDERER_H

#include <map>

#include "deengine.h"
#include "coqscreen.h"
#include "dedatatype.h"
#include "corenderer.h"
#include "coshape.h"
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
    enum EEvent
    {
        eRotate,
        eZoom,
        ePan,
    };

    CoQtRenderer(QWidget *pParent);
    ~CoQtRenderer();

    void setCamera(CoCamera* pCamera);
    void addNode(CoNode* pNode);
    void update();

    void fit();
    void setEvent(EEvent eEvent);

private:
    void initializeWidget();

private:
    CoQScreen         *m_pQScreen;
    QGridLayout       *m_pLayout;
    QWidget           *m_pParent;

    CoCamera          *m_pCamera;

    std::map<CoNode*, CoNodeCore*>   m_mapNodeObject;

    CoVec2 m_vLastPoint;
    CoVec2 m_vScreenSize;

    EEvent m_eEvent;

public slots:
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
    void slotCameraUpdated();
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseWheelEvent(QWheelEvent* event);
};

#endif // COQTRENDERER_H
