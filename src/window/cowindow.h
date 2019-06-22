#ifndef COWINDOW_H
#define COWINDOW_H


class CoWindow
{
public:
    explicit CoWindow();
    ~CoWindow();

    virtual void initialize();
    virtual void createWindow();
};

#endif // COWINDOW_H
