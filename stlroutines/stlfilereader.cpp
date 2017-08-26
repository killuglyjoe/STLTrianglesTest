#include "stlfilereader.h"

#include <streambuf>
#include <iostream>
#include <fstream>
#include <sstream>

//#include <regex>

namespace STLUtils
{

    static const std::string cSolidStr("solid");
    static const std::string cSolidEndStr("endsolid");

    static const std::string cFacetNormalStr("facet normal");
    static const std::string cEndFacetStr("endfacet");

    static const std::string cVertexStr("vertex");

    static const std::string cOuterLoopStr("outer loop");
    static const std::string cEndLoopStr("end loop");

    const char cDelimiter(' ');

    /**
     * @brief STLFileReader::STLFileReader
     * @param stlFilePath
     */
    STLFileReader::STLFileReader(const std::string &stlFilePath)
    {
        if(stlFilePath.empty()) {
            std::cout << "STL file is empty, further processing impossibla" << std::endl;
            return;
        }

        std::ifstream stlFile(stlFilePath.c_str(), std::ios::in);

        if (!stlFile) {
            std::cout << "ERROR: couldn't read file"  << stlFilePath << std::endl;
            return;
        }

        if(!stlFile.std::ios::good()) {
            std::cout << "ERROR: bad file" << std::endl;
            return;
        }

        if(!isValidASCIISTLFile(stlFile)) {
            std::cout << "ERROR: invalid STL file" << std::endl;
            return;
        }

        if(!parseASCIISTLFile(stlFile)) {
            std::cout << "ERROR: parsing STL file" << std::endl;
            return;
        }

        stlFile.close();
    }
    /**
     * @brief STLFileReader::trinagleList
     * @return
     */
    std::vector<Triangle> STLFileReader::trinagles() const
    {
        return m_triVec;
    }

    /**
     * @brief STLFileReader::isValidASCIISTLFile
     *
     * @param stlFile
     * @return
     */
    bool STLFileReader::isValidASCIISTLFile(std::ifstream &stlFile)
    {
        bool isValidBegin(false), isValidEnd(false);

        std::string line("");
        while (std::getline(stlFile, line))
        {
            std::istringstream iss(line);

            if (!(iss))
                break;

            if(!line.compare(cSolidStr)) {//why you ignored place 'name'?
                isValidBegin=true;
            }

            if(!line.compare(cSolidEndStr)) {
                isValidEnd=true;
            }
//            std::cout << stlFile.tellg() << std::endl;
        }

        stlFile.clear();
        stlFile.seekg(0, std::ios::beg);

        return (isValidBegin && isValidEnd);
    }
    /**
     * @brief STLFileReader::parseASCIISTLFile
     *
     *      |facet normal ni nj nk
     *      |   |outer loop
     *      |   |   vertex v1x v1y v1z
     *      |   |   vertex v2x v2y v2z
     *      |   |   vertex v3x v3y v3z
     *      |   |endloop
     *      |endfacet
     *
     * @param stlFile
     * @return
     */
    bool STLFileReader::parseASCIISTLFile(std::ifstream &stlFile)
    {
        bool success(false);

        std::string line("");

        stlTags stlTg(stlTagFacetNormal);
        Triangle curTri;
        Vertex pt;

        while(std::getline(stlFile, line))
        {
            std::istringstream iss(line);
            if (!iss)
                break; // error

            switch (stlTg)
            {
                case stlTagFacetNormal:
                    {
                        if(!line.find(cFacetNormalStr))
                        {
                            if(getPointFromLine(line, cFacetNormalStr,&pt))
                            {
//                                std::cout << "Got normal "<< std::endl;
                                curTri.setNormal(pt);
                                stlTg = stlTagVertex1;
                                continue;
                            }
                        }
                    }
                    break;

                case stlTagVertex1:
                    {
                        if(!line.find(cVertexStr))
                        {
                            if(getPointFromLine(line, cVertexStr,&pt))
                            {
//                                std::cout << "Got v1 "<<pt<< std::endl;
                                curTri.setV1(pt);
                                stlTg = stlTagVertex2;
                                continue;
                            }
                        }
                    }
                    break;
                case stlTagVertex2:
                    {
                        if(!line.find(cVertexStr))
                        {
                            if(getPointFromLine(line, cVertexStr,&pt))
                            {
//                                std::cout << "Got v2 "<<pt<< std::endl;
                                curTri.setV2(pt);
                                stlTg = stlTagVertex3;
                                continue;
                            }
                        }
                    }
                    break;
                case stlTagVertex3:
                    {
                        if(!line.find(cVertexStr))
                        {
                            if(getPointFromLine(line, cVertexStr,&pt))
                            {
                                curTri.setV3(pt);

                                m_triVec.push_back(curTri);
//                                std::cout << "Got v3 "<<pt<<m_triVec.size()<< std::endl;
                                stlTg = stlTagFacetNormal;
                                success = true; // we have at least one valid triangle
                                continue;
                            }
                        }
                    }
                    break;

                default:
                    continue;
                    break;
            }

//            std::cout << line << std::endl;
        }

        std::cout << "Total trinagles parsed: "<< m_triVec.size() << std::endl;

        return success;
    }

    /**
     * @brief STLFileReader::getPointFromLine
     *
     * @param line
     * @param cutStr
     * @param pt
     * @return
     */
    bool STLFileReader::getPointFromLine(const std::string &line, const std::string &cutStr, Vertex *pt)
    {
        bool success(false);

        std::string storedLine(line);
        std::istringstream s(storedLine.erase(0, cutStr.length()));

        std::string tmp("");
        std::vector<float> vecVals;

        while(std::getline(s, tmp, cDelimiter))
        {
            if(!tmp.empty())
            {
                char * e;
                errno = 0;
                double val(std::strtod(tmp.c_str(), &e));
                if (*e == '\0' ||  // check we didn't consume the entire string
                    errno == 0 )   // check overflow or underflow
                {
                    vecVals.push_back(val);
//                    std::cout << "val: "<< tmp<< std::endl;
                }
            }
        }

        if(vecVals.size() == 3)
        {
            pt->setX(vecVals.at(0));
            pt->setY(vecVals.at(1));
            pt->setZ(vecVals.at(2));

//            std::cout << "Point: "<< pt->x() <<" "<< pt->y()<<" " << pt->z() <<" "<< std::endl;

            success = true;
        }

        return success;
    }

} // namespace STLUtils
