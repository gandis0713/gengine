#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}


class CoQtRenderer;
class CoPerspectiveCamera;

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

private:
    Ui::MainWindow *ui;
    CoQtRenderer *m_pRender;
    CoPerspectiveCamera *m_pCamera;
};

#endif // MAINWINDOW_H
