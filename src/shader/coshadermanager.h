#ifndef COSHADERMANAGER_H
#define COSHADERMANAGER_H

#include <QObject>
#include <QMap>

#include "deshader.h"
#include "coshader.h"

class CoShaderManager
{
public:
    CoShaderManager();
    ~CoShaderManager();


signals:

public slots:

private:
    bool createShaders();

private:
    QMap<EShaderType, CoShader*> m_mapShaders;

};

#endif // COSHADERMANAGER_H
