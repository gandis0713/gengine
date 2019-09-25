#include <QApplication>

#include "samplewindow.h"
#include "coqtrenderer.h"
#include "copolygon.h"
#include "coobjreader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CSampleWindow w;

    CoQtRenderer *m_pRender = new CoQtRenderer(w.getMainWidget());

    QString strOBJFilePath = "../sample/spaceship.obj";

    const Gchar *pPath = strOBJFilePath.toLocal8Bit().constData();

    CoOBJReader *pOBJReader = new CoOBJReader();

    std::vector<CoVec3> vecTempVertices;
    std::vector<CoVec2> vecUVCoords;
    std::vector<CoVec3> vecTempVertexNormals;
    CoFaceIndex faceIndices;

    pOBJReader->load(pPath,
                     vecTempVertices,
                     vecUVCoords,
                     vecTempVertexNormals,
                     faceIndices);

    CoPolygon *pPolygon = new CoPolygon(vecTempVertices,
                                        vecTempVertexNormals,
                                        // vecUVCoords,  // not use
                                        faceIndices);

    pPolygon->setColor(CoVec3(0.5, 0.5, 0.5));

    m_pRender->addNode(pPolygon);


    w.setQtRenderer(m_pRender);
    w.show();

    return a.exec();
}
