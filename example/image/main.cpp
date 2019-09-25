#include <QApplication>

#include "samplewindow.h"
#include "coqtrenderer.h"
#include "cotexture.h"
#include "cotexturereader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CSampleWindow w;

    QString strFileName = "../sample/sample.jpg";

    CoQtRenderer *m_pRender = new CoQtRenderer(w.getMainWidget());

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
