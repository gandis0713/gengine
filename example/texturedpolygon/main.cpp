#include <QApplication>

#include "samplewindow.h"
#include "coorthographiccamera.h"
#include "coqtrenderer.h"
#include "cotexturedpolygon.h"
#include "coobjreader.h"
#include "cotexturereader.h"
#include <QFileDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CSampleWindow w;

    CoQtRenderer *m_pRender = new CoQtRenderer(w.getMainWidget());
    CoOrthographicCamera *m_pOrthoCamera = new CoOrthographicCamera();

    CoCamera *m_pCamera = m_pOrthoCamera;
    m_pRender->setCamera(m_pCamera);

    QString strOBJFilePath = QFileDialog::getOpenFileName(&w,
                                         "Select OBJ file",
                                         ".",
                                         "");

    const Gchar *pOBJPath = strOBJFilePath.toLocal8Bit().constData();

    CoOBJReader *pOBJReader = new CoOBJReader();

    std::vector<CoVec3> vecTempVertices;
    std::vector<CoVec2> vecUVCoords;
    std::vector<CoVec3> vecTempVertexNormals;
    CoFaceIndex faceIndices;

    pOBJReader->load(pOBJPath,
                     vecTempVertices,
                     vecUVCoords,
                     vecTempVertexNormals,
                     faceIndices);

    QString strTextureFilePath = QFileDialog::getOpenFileName(&w,
                                         "Select Texture Image file",
                                         ".",
                                         "");

    const Gchar *pTexturePath = strTextureFilePath.toLocal8Bit().constData();

    CoTextureReader *pReader = new CoTextureReader();
    pReader->load(pTexturePath);

    CoTexturedPolygon *pPolygon = new CoTexturedPolygon(vecTempVertices,
                                                        vecTempVertexNormals,
                                                        vecUVCoords,
                                                        faceIndices,
                                                        pReader->getData(),
                                                        pReader->getWidth(),
                                                        pReader->getHeight());

    pPolygon->setColor(CoVec3(0.5, 0.5, 0.5));

    m_pRender->addNode(pPolygon);

    w.setQtRenderer(m_pRender);
    w.show();

    return a.exec();
}
