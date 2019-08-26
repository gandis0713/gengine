#include <QApplication>

#include "samplewindow.h"
#include "coqtrenderer.h"
#include "coorthographiccamera.h"
#include "cotexture.h"
#include "cotexturereader.h"

#include <QFileDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    CSampleWindow w;


    QString strFileName = QFileDialog::getOpenFileName(&w,
                                         "Select image file",
                                         ".",
                                         "");

    CoQtRenderer *m_pRender = new CoQtRenderer(w.getMainWidget());
    CoOrthographicCamera* m_pCamera = new CoOrthographicCamera();

    m_pRender->setCamera(m_pCamera);

    CoTextureReader *pReader = new CoTextureReader();
    pReader->load(strFileName.toLocal8Bit().constData());

    CoTexture *pTexture = new CoTexture(pReader->getData(),
                                        pReader->getWidth(),
                                        pReader->getHeight());
    m_pRender->addNode(pTexture);



    w.setQtRenderer(m_pRender);
    w.show();

    return a.exec();
}
