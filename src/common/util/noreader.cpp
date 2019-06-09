#include "noreader.h"

#include <fstream>
#include <iostream>

namespace NoReader
{
    bool ReadText(const CbString &strPath, CbString &strtext)
    {
        std::ifstream shaderStream(strPath);

        if(shaderStream.is_open())
        {
            std::stringstream strStream;
            strStream << shaderStream.rdbuf();
            strtext = strStream.str();
            shaderStream.close();
        }
        else
        {
            std::cout << "The text can't be opened." << std::endl;
            return false;
        }

        return true;
    }
}
