#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>

namespace STLUtils
{
    class Vertex
    {
    public:
        Vertex();
        Vertex(const Vertex &v2);
        Vertex(const double &x, const double &y, const double &z);
        ~Vertex(){}

        void setVertex(const Vertex &v2);

        void setX(const double &x);
        double x() const;

        void setY(const double &y);
        double y() const;

        void setZ(const double &z);
        double z() const;


        bool operator != (const Vertex &other) const;
        bool operator == (const Vertex &other) const;

        Vertex operator - (const Vertex &other);
        Vertex operator +(const Vertex &other);
        void operator -= (const Vertex &other);
        void operator += (const Vertex &other);

        friend std::ostream& operator << (std::ostream& stream, const Vertex &v)
        {
            stream << /*"Vertex(x,y,z): "<<*/ v.x() <<" "<< v.y() <<" " << v.z() << std::endl;
            return stream;
        }

    private:
        double m_x, m_y, m_z;

    };

} // namespace STLUtils

#endif // VERTEX_H
