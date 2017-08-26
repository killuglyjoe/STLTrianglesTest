#ifndef STLFILEWRITER_H
#define STLFILEWRITER_H

#include "surface.h"

namespace STLUtils
{

    class STLFileWriter
    {
    public:
        STLFileWriter(const std::string &path, std::vector<std::shared_ptr<Surface> > surfaces);
        ~STLFileWriter(){}

        void writeASCIISTLFile(const std::string &fileName, const Surface *surface);

    private:
        std::string m_path;
    };

} // namespace STLUtils

#endif // STLFILEWRITER_H
