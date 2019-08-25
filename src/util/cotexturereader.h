#ifndef COTEXTUREREADER_H
#define COTEXTUREREADER_H

#include "dedatatype.h"

class QImage;

class CoTextureReader
{
public:
    explicit CoTextureReader();
    ~CoTextureReader();

    void load(const Gchar *pPath);
    Guchar* getData();

private:

    QImage *m_pImage;
};

#endif // COTEXTUREREADER_H
