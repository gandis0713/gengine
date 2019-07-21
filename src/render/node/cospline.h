#ifndef COSPLINE_H
#define COSPLINE_H

#include "conode.h"

class CoSpline : public CoNode
{
public:
    CoSpline();
    ~CoSpline();

    void draw() override;
};

#endif // COSPLINE_H
