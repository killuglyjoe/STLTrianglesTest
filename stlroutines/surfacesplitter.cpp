#include "surfacesplitter.h"

//#include <sys/time.h>
#include <algorithm>
#include <iostream>
#include <iomanip>

namespace STLUtils
{

    SurfaceSplitter::SurfaceSplitter(const std::vector<Triangle> &triangles)
    {
        if(!triangles.size()) return;

        splitToSurfaces(triangles);
    }

    SurfaceSplitter::~SurfaceSplitter()
    {
        m_surfaces.clear();
    }

    std::vector<std::shared_ptr<Surface> >&SurfaceSplitter::surfaces()
    {
        return m_surfaces;
    }
    /**
     * @brief SurfaceSplitter::splitToSurfaces
     * @param triangles
     */
    void SurfaceSplitter::splitToSurfaces(const std::vector<Triangle> &triangles)
    {
        if(!triangles.size()) return;

        m_surfaces.clear();

//        struct timespec tm1, tm2;
//        clock_gettime(CLOCK_REALTIME, &tm1);

        const Triangle *triangle = &triangles[0];
        int trianglesCount(triangles.size());

        int curID(1);

        for(int i = 0; i != trianglesCount; ++i)
        {
            const Triangle *rootTr = (triangle+i);

            if(!m_surfaces.size())
            {
                std::shared_ptr<Surface> surface = std::shared_ptr<Surface>(new Surface(curID));
                surface->addTriangle(*rootTr);

                m_surfaces.push_back(surface);
            }
            else
            {
                int id(-1);

                for(std::shared_ptr<Surface> surface : m_surfaces)
                {
                    bool isContainsRoot(surface->contains(*rootTr));

                    if(isContainsRoot)
                    {
                        id = surface->id();

                        surface->addTriangle(*rootTr);
                        continue;
                    }
                }

                if(-1 == id)
                {
                    std::shared_ptr<Surface> surface = std::shared_ptr<Surface>(new Surface(++curID));
                    surface->addTriangle(*rootTr);

                    m_surfaces.push_back(surface);
                }
//                            std::cout << "Same: "<<"id=" << id <<" curID=" << curID <<" " <<rootTr<<" " <<childTr<<"i ="<< i <<" j=" << j << std::endl;
            }
        }


//        clock_gettime(CLOCK_REALTIME, &tm2);

//        double t1 = 1000.0 * tm1.tv_sec + tm1.tv_nsec / (1000.0 * 1000);
//        double t2 = 1000.0 * tm2.tv_sec + tm2.tv_nsec / (1000.0 * 1000);
//        std::cout << "splitToSurfaces time = " << std::setprecision(5) << t2 -t1 << " ms, total surfaces = " << m_surfaces.size() << std::endl;
          std::cout << "splitToSurfaces total surfaces = " << m_surfaces.size() << std::endl;
    }

} // namespace STLUtils
