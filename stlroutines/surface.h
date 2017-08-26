#ifndef SURFACE_H
#define SURFACE_H

#include <thread>
#include <vector>

#include "triangle.h"
#include "rect3d.h"

namespace STLUtils
{
    class Surface
    {
    public:
        Surface(const int &id = 0);
        ~Surface();

        void setID(const int &id);
        int id() const;

        void clear();
        bool contains(const Triangle &t);
        std::vector<Triangle> triangles() const;
        void addTriangle(const Triangle &t);

        void moveCenter(const Vertex &center);

        Rect3D rect() const;
        Rect3D rect();

    protected:
        void updateBBox(const Triangle &t);

    private:
            int                     m_id;
            std::vector<Triangle>   m_triangles;
            Rect3D                  m_bBox;
    };

} // namespace STLUtils

#endif // SURFACE_H
