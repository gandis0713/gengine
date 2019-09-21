#include "coobjreader.h"

CoOBJReader::CoOBJReader()
{

}

CoOBJReader::~CoOBJReader()
{

}

Gbool CoOBJReader::load(const Gchar * pPath,
                        std::vector<CoVec3> &vecVertices,
                        std::vector<CoVec2> &vecUVCoords,
                        std::vector<CoVec3> &vecVertexNormals,
                        CoFaceIndex &faceIndices)
{

    FILE *pFile = fopen(pPath, "r");
    if( pFile == NULL )
    {
        return false;
    }

    Gint count = 0;
    while( true )
    {
        Gchar lineHeader[128];
        // read the first word of the line
        Gint res = fscanf(pFile, "%s", lineHeader);
        if (res == EOF)
        {
            break; // EOF = End Of File. Quit the loop.
        }

        count++;
        // else : parse lineHeader

        if ( strcmp( lineHeader, "v" ) == 0 )
        {
            CoVec3 vertex;
            fscanf(pFile, "%f %f %f\n", &vertex[0], &vertex[1], &vertex[2] );
            vecVertices.push_back(vertex);
        }
        else if ( strcmp( lineHeader, "vt" ) == 0 )
        {
            CoVec2 uv;
            fscanf(pFile, "%f %f\n", &uv[0], &uv[1] );
            uv[1] = 1 - uv[1]; // Invert V coordinate since we will only use DDS texture, which are inverted. Remove if you want to use TGA or BMP loaders.
            vecUVCoords.push_back(uv);
        }
        else if ( strcmp( lineHeader, "vn" ) == 0 )
        {
            CoVec3 normal;
            fscanf(pFile, "%f %f %f\n", &normal[0], &normal[1], &normal[2] );
            vecVertexNormals.push_back(normal);
        }
        else if ( strcmp( lineHeader, "f" ) == 0 )
        {
            Guint vertexIndex[3], uvIndex[3], normalIndex[3];
            if(vecVertexNormals.size() == 0)
            {

                Gint matches = fscanf(pFile,
                                      "%d/%d %d/%d %d/%d\n",
                                      &vertexIndex[0],
                                      &uvIndex[0],
                                      &vertexIndex[1],
                                      &uvIndex[1],
                                      &vertexIndex[2],
                                      &uvIndex[2]);
                if (matches != 6)
                {
                    fclose(pFile);
                    return false;
                }

                faceIndices.addVertexIndices(vertexIndex[0]);
                faceIndices.addVertexIndices(vertexIndex[1]);
                faceIndices.addVertexIndices(vertexIndex[2]);
                faceIndices.addUICoordIndices(uvIndex[0]);
                faceIndices.addUICoordIndices(uvIndex[1]);
                faceIndices.addUICoordIndices(uvIndex[2]);
            }
            else  if(vecUVCoords.size() == 0)
            {
                Gint matches = fscanf(pFile,
                                      "%d//%d %d//%d %d//%d\n",
                                      &vertexIndex[0],
                                      &normalIndex[0],
                                      &vertexIndex[1],
                                      &normalIndex[1],
                                      &vertexIndex[2],
                                      &normalIndex[2]);
                if (matches != 6)
                {
                    fclose(pFile);
                    return false;
                }

                faceIndices.addVertexIndices(vertexIndex[0]);
                faceIndices.addVertexIndices(vertexIndex[1]);
                faceIndices.addVertexIndices(vertexIndex[2]);
                faceIndices.addVertexNormalIndices(normalIndex[0]);
                faceIndices.addVertexNormalIndices(normalIndex[1]);
                faceIndices.addVertexNormalIndices(normalIndex[2]);
            }
            else
            {
                Gint matches = fscanf(pFile,
                                      "%d/%d/%d %d/%d/%d %d/%d/%d\n",
                                      &vertexIndex[0],
                                      &uvIndex[0],
                                      &normalIndex[0],
                                      &vertexIndex[1],
                                      &uvIndex[1],
                                      &normalIndex[1],
                                      &vertexIndex[2],
                                      &uvIndex[2],
                                      &normalIndex[2] );
                if (matches != 9)
                {
                    fclose(pFile);
                    return false;
                }


                faceIndices.addVertexIndices(vertexIndex[0]);
                faceIndices.addVertexIndices(vertexIndex[1]);
                faceIndices.addVertexIndices(vertexIndex[2]);
                faceIndices.addUICoordIndices(uvIndex[0]);
                faceIndices.addUICoordIndices(uvIndex[1]);
                faceIndices.addUICoordIndices(uvIndex[2]);
                faceIndices.addVertexNormalIndices(normalIndex[0]);
                faceIndices.addVertexNormalIndices(normalIndex[1]);
                faceIndices.addVertexNormalIndices(normalIndex[2]);
            }

        }
        else
        {
            // Probably a comment, eat up the rest of the line
            Gchar stupidBuffer[1000];
            fgets(stupidBuffer, 1000, pFile);
        }

    }

    fclose(pFile);
    return true;
}
