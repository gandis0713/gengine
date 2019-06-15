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

