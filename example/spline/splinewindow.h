#ifndef SPLINEWINDOW_H
#define SPLINEWINDOW_H

#include <QMainWindow>

namespace Ui {
class SplineWindow;
}

class SplineWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SplineWindow(QWidget *parent = 0);
    ~SplineWindow();

private:
    Ui::SplineWindow *ui;
};

#endif // SPLINEWINDOW_H
