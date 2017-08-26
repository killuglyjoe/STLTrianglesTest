#ifndef SURFACESPLITTER_H
#define SURFACESPLITTER_H

#include "surface.h"
#include <vector>

namespace STLUtils
{

    class SurfaceSplitter
    {
    public:
        SurfaceSplitter(const std::vector<Triangle> &triangles);
        ~SurfaceSplitter();

        std::vector<std::shared_ptr<Surface> > &surfaces() ;

        void splitToSurfaces(const std::vector<Triangle> &triangles);

    private:
        std::vector<std::shared_ptr<Surface> > m_surfaces;
    };

} // namespace STLUtils

#endif // SURFACESPLITTER_H
