#ifndef RMQSCREEN_H
#define RMQSCREEN_H

#include <QGLWidget>

class CoQScreen : public QGLWidget
{
    Q_OBJECT
public:
    explicit CoQScreen(QWidget *parent = nullptr);
    ~CoQScreen();

    void resizeGL(int nWidth, int nHeight) override;
    void initializeGL() override;
    void paintGL() override;

signals:
    void signalInitializeGL();
    void signalResizeGL(int nWidth, int nHeight);
    void signalPaintGL();

public slots:
};

#endif // RMQSCREEN_H
