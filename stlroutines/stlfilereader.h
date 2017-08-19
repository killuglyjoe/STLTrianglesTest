#ifndef STLFILEREADER_H
#define STLFILEREADER_H

#include <string>
#include <vector>

#include "triangle.h"

namespace STLUtils
{

    enum stlTags
    {
        stlTagSolidName = 0,
            stlTagFacetNormal,
                stlOuterloop,
                    stlTagVertex1,
                    stlTagVertex2,
                    stlTagVertex3,
                stlEndloop,
            stlTagEndFacet,
        stlTagSolidEnd
    };


    class STLFileReader
    {
    public:
        STLFileReader(const std::string &stlFilePath = "");

        std::vector<Triangle> trinagleList() const;

    protected:
        bool isValidASCIISTLFile(std::ifstream &stlFile);
        bool parseASCIISTLFile(std::ifstream &stlFile);
        bool getPointFromLine(const std::string &line, const std::string &cutStr, Vertex *pt);

    private:
        std::vector<Triangle>   m_triVec;
    };

} // namespace STLUtils

#endif // STLFILEREADER_H
