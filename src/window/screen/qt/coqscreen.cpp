#include "coqscreen.h"

#include "delog.h"

CoQScreen::CoQScreen(QWidget *parent) : QGLWidget(parent)
{
}

CoQScreen::~CoQScreen()
{

}


void CoQScreen::resizeGL(int nWidth, int nHeight)
{
    emit signalResizeGL(nWidth, nHeight);
}

void CoQScreen::initializeGL()
{
    emit signalInitializeGL();
}

void CoQScreen::paintGL()
{
    emit signalPaintGL();
}

void CoQScreen::mousePressEvent(QMouseEvent *event)
{
    emit signalmousePressEvent(event);
}
void CoQScreen::mouseMoveEvent(QMouseEvent *event)
{
    emit signalmouseMoveEvent(event);
}
void CoQScreen::mouseReleaseEvent(QMouseEvent *event)
{
    emit signalmouseReleaseEvent(event);
}


