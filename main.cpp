#include <iostream>

#include "utils/comandlineparser.h"
#include "stlroutines/stlfilereader.h"
#include "stlroutines/surfacesplitter.h"
#include "stlroutines/stlfilewriter.h"

int main(int argc, char *argv[])
{

    ComandLineParser parser(argc, argv);

    std::string stlFPath(parser.stlFilePath());

    if(stlFPath.empty()) {
        std::cout << "Not specified STL file path" << std::endl;
        return -1;
    }

    STLUtils::STLFileReader stlFReader(stlFPath);

    std::vector<STLUtils::Triangle> triangles(stlFReader.trinagles());
    if(triangles.empty()) {
        std::cout << "We didn't parse any tringle" << std::endl;
        return -1;
    }

    STLUtils::SurfaceSplitter splitter(triangles);

    std::vector<std::shared_ptr<STLUtils::Surface> > surfaces(splitter.surfaces());
    if(surfaces.empty()) {
        std::cout << "We didn't parse any surface" << std::endl;
        return -1;
    }

    for(std::shared_ptr<STLUtils::Surface> surface : splitter.surfaces()) {
//        std::cout << "surface rect " << surface->rect() << std::endl;
//        std::cout << "origin surface center " << surface->rect().center() << std::endl;
        surface->moveCenter(STLUtils::Vertex(0.0, 0.0, 0.0));
    }

    STLUtils::STLFileWriter stlFWriter(parser.writePath(), surfaces);

    return 0;
}
