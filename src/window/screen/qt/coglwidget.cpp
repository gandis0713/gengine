#include "coglwidget.h"

CoGLWidget::CoGLWidget(QWidget *parent) : QGLWidget(parent)
{
}

CoGLWidget::~CoGLWidget()
{

}


void CoGLWidget::resizeGL(int nWidth, int nHeight)
{
    emit signalResizeGL(nWidth, nHeight);

}

void CoGLWidget::initializeGL()
{
    emit signalInitializeGL();
}

void CoGLWidget::paintGL()
{
    emit signalPaintGL();
}

