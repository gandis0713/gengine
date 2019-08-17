#include <QApplication>

#include "samplewindow.h"
#include "coorthographiccamera.h"
#include "coqtrenderer.h"
#include "copolygon.h"
#include "coobjreader.h"
#include <QFileDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CSampleWindow w;

    CoQtRenderer *m_pRender;
    CoCamera *m_pCamera;
    CoOrthographicCamera *m_pOrthoCamera;

    m_pRender = new CoQtRenderer(w.getMainWidget());
    m_pOrthoCamera = new CoOrthographicCamera();

    m_pCamera = m_pOrthoCamera;
    m_pRender->setCamera(m_pCamera);

    QString strOBJFilePath = QFileDialog::getOpenFileName(&w,
                                         "Select OBJ file",
                                         ".",
                                         "");

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
                                        vecUVCoords,
                                        faceIndices);

    pPolygon->setColor(CoVec3(0.5, 0.5, 0.5));

    m_pRender->addNode(pPolygon);


    w.setQtRenderer(m_pRender);
    w.show();

    return a.exec();
}
