#include "triangle.h"

namespace STLUtils
{

    Triangle::Triangle() :
        m_normal(Vertex()),
        m_v1(Vertex()),
        m_v2(Vertex()),
        m_v3(Vertex())
    {
    }

    Triangle::Triangle(const Triangle &t):
        m_normal(t.normal()),
        m_v1(t.v1()),
        m_v2(t.v2()),
        m_v3(t.v3())
    {

    }

    void Triangle::setNormal(const Vertex &normal)
    {
        m_normal.setVertex(normal);
    }

    Vertex Triangle::normal() const
    {
        return m_normal;
    }

    void Triangle::setV1(const Vertex &v1)
    {
        m_v1.setVertex(v1);
    }

    Vertex Triangle::v1() const
    {
        return m_v1;
    }

    Vertex Triangle::v1()
    {
        return m_v1;
    }

    void Triangle::setV2(const Vertex &v2)
    {
        m_v2.setVertex(v2);
    }

    Vertex Triangle::v2() const
    {
        return m_v2;
    }

    Vertex Triangle::v2()
    {
        return m_v2;
    }

    void Triangle::setV3(const Vertex &v3)
    {
        m_v3.setVertex(v3);
    }

    Vertex Triangle::v3() const
    {
        return m_v3;
    }

    Vertex Triangle::v3()
    {
        return m_v3;
    }

    bool Triangle::operator != (const Triangle &other) const
    {
        return !operator == (other);
    }

    bool Triangle::operator == (const Triangle &other) const
    {
        return(    (m_v1 == other.v1())
                || (m_v1 == other.v2())
                || (m_v1 == other.v3())

                || (m_v2 == other.v1())
                || (m_v2 == other.v2())
                || (m_v2 == other.v3())

                || (m_v3 == other.v1())
                || (m_v3 == other.v2())
                || (m_v3 == other.v3())
              );
    }

} // namespace STLUtils
