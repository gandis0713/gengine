#ifndef COORTHOGRAPHICCAMERA_H
#define COORTHOGRAPHICCAMERA_H

#include "cocamera.h"
#include "deengine.h"

class GANDISENGINE CoOrthographicCamera : public CoCamera
{
public:
    explicit CoOrthographicCamera();
    virtual ~CoOrthographicCamera();

    void update() override;
};

#endif // COORTHOGRAPHICCAMERA_H
