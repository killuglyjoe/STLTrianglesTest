#ifndef VERTEX_H
#define VERTEX_H

#include "stlglobals.h"

namespace STLUtils
{
    class Vertex
    {
    public:
        Vertex();
        Vertex(const Vertex &v2);
        Vertex(const double &x, const double &y, const double &z);
        virtual ~Vertex(){}

        void setVertex(const Vertex &v2);

        void setX(const double &x);
        double x() const;

        void setY(const double &y);
        double y() const;

        void setZ(const double &z);
        double z() const;


        bool operator != (const Vertex &other) const;
        bool operator == (const Vertex &other) const;

    private:
        double m_x, m_y, m_z;

    };
} // namespace STLUtils

#endif // VERTEX_H
