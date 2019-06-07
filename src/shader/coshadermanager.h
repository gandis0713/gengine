#ifndef COSHADERMANAGER_H
#define COSHADERMANAGER_H

#include <QObject>
#include <QMap>
#include <QOpenGLFunctions_2_1>

#include "deshader.h"
#include "coshader.h"

class CoShaderManager
{
public:
    CoShaderManager(QOpenGLFunctions_2_1 *pGLFunctions);
    ~CoShaderManager();


signals:

public slots:

private:
    bool createShaders();

private:
    QMap<EShaderType, CoShader*> m_mapShaders;
    QOpenGLFunctions_2_1        *m_pGLFunctions;

};

#endif // COSHADERMANAGER_H
