#include "stlfilewriter.h"

#include <fstream>

namespace STLUtils
{

    STLFileWriter::STLFileWriter(const std::string &path,  std::vector<std::shared_ptr<STLUtils::Surface> > surfaces) :
        m_path(path)
    {
        if(!m_path.empty())
            m_path += "/";

        if(surfaces.empty()) return;

        for (std::shared_ptr<STLUtils::Surface> surface : surfaces)
        {
//            std::cout << "writeASCIISTLFile for surface " << surface->id()
//                      << " tr.size="<<surface->triangles().size()
//                      <<" center " << surface->rect().center() << std::endl;
            writeASCIISTLFile(m_path+"Surface"+std::to_string(surface->id())+".stl", surface.get());
        }
    }

    void STLFileWriter::writeASCIISTLFile(const std::string &fileName, const Surface *surface)
    {
        std::ofstream file(fileName.c_str(), std::ios::out);
        file.setf(std::ios::fixed);
        file.precision(8);

        if(file.is_open())
        {
          file << "solid" << std::endl;

          for(Triangle triangle : surface->triangles())
          {
            file << "facet normal " << triangle.normal().x() << " " << triangle.normal().y() << " " << triangle.normal().z() << std::endl;
            file << "outer loop " << std::endl;
            file << "vertex " << triangle.v1().x() << " " << triangle.v1().y() << " " << triangle.v1().z() << std::endl;
            file << "vertex " << triangle.v2().x() << " " << triangle.v2().y() << " " << triangle.v2().z() << std::endl;
            file << "vertex " << triangle.v3().x() << " " << triangle.v3().y() << " " << triangle.v3().z() << std::endl;
            file << "endloop" << std::endl;
            file << "endfacet" << std::endl;
          }

          file << "endsolid" << std::endl;
          file.close();
//          std::cout << "The file " << fileName << " succcesfully written." << std::endl;
        } else {
          std::cout << "The file " << fileName << " could not be found." << std::endl;
        }
    }

} // namespace STLUtils
