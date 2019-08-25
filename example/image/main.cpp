#include <QApplication>

#include "samplewindow.h"
#include "coqtrenderer.h"
#include "coorthographiccamera.h"
#include "coimage.h"

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

    CoImage *pImage = new CoImage;
    pImage->load(strFileName.toLocal8Bit().constData());
    m_pRender->addNode(pImage);



    w.setQtRenderer(m_pRender);
    w.show();

    return a.exec();
}
