#ifndef COOBJREADER_H
#define COOBJREADER_H

#include "dedatatype.h"
#include "deengine.h"
#include <vector>
#include "covector2.h"
#include "covector3.h"
#include "cofaceindex.h"

class GANDISENGINE CoOBJReader
{
public:
    explicit CoOBJReader();
    ~CoOBJReader();

    Gbool load(const Gchar * path,
               std::vector<CoVec3> &vecVertices,
               std::vector<CoVec2> &vecUVCoords,
               std::vector<CoVec3> &vecVertexNormals,
               CoFaceIndex &faceIndices);

};

#endif // COOBJREADER_H
