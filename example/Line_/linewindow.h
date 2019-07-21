#ifndef LINEWINDOW_H
#define LINEWINDOW_H

#include <QMainWindow>

namespace Ui {
class LineWindow;
}

class LineWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LineWindow(QWidget *parent = 0);
    ~LineWindow();

private:
    Ui::LineWindow *ui;
};

#endif // LINEWINDOW_H
