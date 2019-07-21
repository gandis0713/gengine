#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "coperspectivecamera.h"
#include "coorthographiccamera.h"

namespace Ui {
class MainWindow;
}


class CoQtRenderer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void SlotLeftChanged(int value);
    void SlotRightChanged(int value);
    void SlotBottomChanged(int value);
    void SlotTopChanged(int value);
    void SlotNearChanged(int value);
    void SlotFarChanged(int value);

    void SlotPersToggle(bool checked);
    void SlotOrthoToggle(bool checked);

private:
    Ui::MainWindow *ui;
    CoQtRenderer *m_pRender;
    CoCamera *m_pCamera;
    CoOrthographicCamera *m_pOrthoCamera;
    CoPerspectiveCamera *m_pPersCamera;

    float leftvalue;
    float rightvalue;
    float bottomvalue;
    float topvalue;
    float nearvalue;
    float farvalue;
};

#endif // MAINWINDOW_H
