#include <iostream>
#include <algorithm>

#include "stlroutines/stlfilereader.h"
#include "utils/comandlineparser.h"

int main(int argc, char *argv[])
{
    ComandLineParser parser(argc, argv);

    std::string stlFPath(parser.stlFilePath());

    if(stlFPath.empty()) {
        std::cout << "Not specified STL file path" << std::endl;
        return -1;
    }

    STLUtils::STLFileReader stlFReader(stlFPath);

    std::vector<STLUtils::Triangle> triVec(stlFReader.trinagleList());
    if(triVec.empty()) {
        std::cout << "We didn't parse any tringle" << std::endl;
        return -1;
    }

    if(std::adjacent_find(triVec.begin(), triVec.end(), std::equal_to<STLUtils::Triangle>()) == triVec.end())
    {
        std::cout << "All elements are equal each other" << std::endl;
    }
    else
    {
        std::cout << "All elements are not equal each other" << std::endl;
    }

    return 0;
}
