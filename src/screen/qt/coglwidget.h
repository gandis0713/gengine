#ifndef RMGLWIDGET_H
#define RMGLWIDGET_H

#include "qtheader.h"

class CoGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit CoGLWidget(QWidget *parent = nullptr);
    ~CoGLWidget();

    void resizeGL(int nWidth, int nHeight) override;
    void initializeGL() override;
    void paintGL() override;

signals:
    void signalInitializeGL();
    void signalResizeGL(int nWidth, int nHeight);
    void signalPaintGL();

public slots:
};

#endif // RMGLWIDGET_H
