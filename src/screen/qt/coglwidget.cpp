#include "coglwidget.h"

#include <QDebug>

CoGLWidget::CoGLWidget(QWidget *parent) : QGLWidget(parent)
{
    qDebug() << __FUNCTION__;
}

CoGLWidget::~CoGLWidget()
{

}


void CoGLWidget::resizeGL(int nWidth, int nHeight)
{
    emit signalResizeGL(nWidth, nHeight);
    qDebug() << __FUNCTION__;

}

void CoGLWidget::initializeGL()
{
    qDebug() << __FUNCTION__;
    emit signalInitializeGL();
}

void CoGLWidget::paintGL()
{
    emit signalPaintGL();
    qDebug() << __FUNCTION__;
}

