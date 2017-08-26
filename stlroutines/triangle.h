#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vertex.h"

namespace STLUtils
{

    class Triangle
    {
    public:
        Triangle();
        Triangle(const Triangle &t);

        void setNormal(const Vertex &normal);
        Vertex normal() const;

        void setV1(const Vertex &v1);
        Vertex v1() const;
        Vertex v1();

        void setV2(const Vertex &v2);
        Vertex v2() const;
        Vertex v2();

        void setV3(const Vertex &v3);
        Vertex v3() const;
        Vertex v3();

        bool operator != (const Triangle &other) const;
        bool operator == (const Triangle &other) const;

        friend std::ostream& operator << (std::ostream& stream, const Triangle &t)
        {
            stream << "Triangle(v1,v2,v3): "<< t.v1() <<" "<< t.v2() <<" " << t.v3() << std::endl;
            return stream;
        }

    private:
        Vertex m_normal;
        Vertex m_v1, m_v2, m_v3;
    };

} // namespace STLUtils

#endif // TRIANGLE_H
