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

    void SlotCameraXChanged(int value);
    void SlotCameraYChanged(int value);
    void SlotCameraZChanged(int value);
    void SlotTargetXChanged(int value);
    void SlotTargetYChanged(int value);
    void SlotTargetZChanged(int value);


private:
    void initialize();

private:
    Ui::MainWindow *ui;
    CoQtRenderer *m_pRender;
    CoCamera *m_pCamera;
    CoOrthographicCamera *m_pOrthoCamera;
    CoPerspectiveCamera *m_pPersCamera;

    Gfloat leftvalue;
    Gfloat rightvalue;
    Gfloat bottomvalue;
    Gfloat topvalue;
    Gfloat nearvalue;
    Gfloat farvalue;
};

#endif // MAINWINDOW_H
