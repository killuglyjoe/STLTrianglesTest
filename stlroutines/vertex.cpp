#include "vertex.h"

#include <iostream>
#include <cmath>

namespace STLUtils
{
    static const double cEpsilon(0.0001);

    Vertex::Vertex() :
        m_x(0.0), m_y(0.0), m_z(0.0)
    {

    }

    Vertex::Vertex(const Vertex &v2):
        m_x(v2.x()), m_y(v2.y()), m_z(v2.z())
    {

    }

    Vertex::Vertex(const double &x, const double &y, const double &z) :
        m_x(x), m_y(y), m_z(z)
    {

    }

    void Vertex::setVertex(const Vertex &v2)
    {
        setX(v2.x());
        setY(v2.y());
        setZ(v2.z());
    }

    void Vertex::setX(const double &x)
    {
        m_x = x;
    }
    double Vertex::x() const
    {
        return m_x;
    }

    void Vertex::setY(const double &y)
    {
        m_y = y;
    }
    double Vertex::y() const
    {
        return m_y;
    }

    void Vertex::setZ(const double &z)
    {
        m_z = z;
    }
    double Vertex::z() const
    {
        return m_z;
    }

    bool Vertex::operator != (const Vertex &other) const
    {
        return !operator == (other);
    }

    bool Vertex::operator == (const Vertex &other) const
    {
        double diffX(std::abs(m_x - other.x()));
        double diffY(std::abs(m_y - other.y()));
        double diffZ(std::abs(m_z - other.z()));

        bool isXTolerate(diffX <= cEpsilon);
        bool isYTolerate(diffY <= cEpsilon);
        bool isZTolerate(diffZ <= cEpsilon);

        bool ret(isXTolerate && isYTolerate && isZTolerate);

        return ret;
    }

    Vertex Vertex::operator - (const Vertex &other)
    {
        return (Vertex( m_x - other.x(),
                        m_y - other.y(),
                        m_z - other.z())
                );
    }

    Vertex Vertex::operator + (const Vertex &other)
    {
        return (Vertex( m_x + other.x(),
                        m_y + other.y(),
                        m_z + other.z())
                );
    }
    void Vertex::operator -= (const Vertex &other)
    {
        m_x -= other.x();
        m_y -= other.y();
        m_z -= other.z();
    }

    void Vertex::operator += (const Vertex &other)
    {
        m_x += other.x();
        m_y += other.y();
        m_z += other.z();
    }


} // namespace STLUtils
