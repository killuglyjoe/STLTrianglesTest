#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vertex.h"

namespace STLUtils
{

    class Triangle
    {
    public:
        Triangle();

        void setNormal(const Vertex &normal);
        Vertex normal() const;

        void setV1(const Vertex &v1);
        Vertex v1() const;

        void setV2(const Vertex &v2);
        Vertex v2() const;

        void setV3(const Vertex &v3);
        Vertex v3() const;

        bool operator != (const Triangle &other) const;
        bool operator == (const Triangle &other) const;

    private:
        Vertex m_normal;
        Vertex m_v1, m_v2, m_v3;
    };

} // namespace STLUtils

#endif // TRIANGLE_H
