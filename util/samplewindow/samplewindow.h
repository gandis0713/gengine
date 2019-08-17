#ifndef SAMPLEWINDOW_H
#define SAMPLEWINDOW_H

#include "samplewindowglobal.h"
#include "coqtrenderer.h"

#include <QMainWindow>

namespace Ui {
class CSampleWindow;
}

class GANDIS_SAMPLE_WINDOW_EXPORT CSampleWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CSampleWindow(QWidget *parent = 0);
    ~CSampleWindow();

    void setQtRenderer(CoQtRenderer *pQtRenderer);
    QWidget* getMainWidget();

public slots:
    void slotRotateBtnClicked(bool);
    void slotPanBtnClicked(bool);
    void slotZoomBtnClicked(bool);
    void slotFitBtnClicked(bool);

private:
    Ui::CSampleWindow *ui;
    CoQtRenderer *m_pQtRenderer;
};

#endif // SAMPLEWINDOW_H
