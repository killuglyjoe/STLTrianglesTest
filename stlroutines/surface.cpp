#include "surface.h"

#include <algorithm>

static int surfaceCount;

namespace STLUtils
{

    Surface::Surface(const int &id):
        m_id(id)
    {
        std::cout << "++surfaceCount = " << ++surfaceCount <<std::endl;
    }

    Surface::~Surface()
    {
        std::cout <<"~Surface() - "<< surfaceCount-- <<std::endl;
    }

    void Surface::setID(const int &id)
    {
        m_id = id;
    }

    int Surface::id() const
    {
        return m_id;
    }

    std::vector<Triangle> Surface::triangles() const
    {
        return m_triangles;
    }

    void Surface::clear()
    {
        m_triangles.clear();
        m_bBox.invalidate();
    }

    bool Surface::contains(const Triangle &t)
    {
        Triangle *triangles = &m_triangles[0];
        for(uint i = 0; i < m_triangles.size(); ++i)
        {
            const Triangle *triangle = (triangles+i);
//            std::cout << "Surface::contains \n"<<i<<"\n"<<"t1 " << *triangle
//                      <<"t2 "<< t << std::endl;
            if(*triangle == t)
            {
                return true;
            }
        }

        return false;
    }

    void Surface::moveCenter(const Vertex &center)
    {
        Vertex rectCenter(rect().center());

        if(rectCenter == center)
            return;

        Vertex delta((center.x() - rectCenter.x()),
                      center.y() - rectCenter.y(),
                      center.z() - rectCenter.z()
                     );

        rect().invalidate();
//        std::cout << "Delta " << delta <<"isValid "<<rect()<< std::endl;

        Triangle *triangle = &m_triangles[0];
        for(uint i = 0; i < m_triangles.size(); ++i)
        {
            Triangle *t = (triangle+i);

            t->setV1(t->v1() + delta);
            t->setV2(t->v2() + delta);
            t->setV3(t->v3() + delta);

            updateBBox(*t);
        }
    }

    Rect3D Surface::rect() const
    {
        return m_bBox;
    }

    Rect3D Surface::rect()
    {
        return m_bBox;
    }

    void Surface::addTriangle(const Triangle &t)
    {
        m_triangles.push_back(t);

        updateBBox(t);

//        std::cout << "addTriangle id=" <<id() << " size="<<cnt<<" " << t << std::endl;
    }

    void Surface::updateBBox(const Triangle &t)
    {
        double top(std::max(std::max(std::max(m_bBox.isValid() ? m_bBox.top() : t.v1().y(), t.v1().y()), t.v2().y()), t.v3().y()));
        double bottom(std::min(std::min(std::min(m_bBox.isValid() ? m_bBox.bottom() : t.v1().y(), t.v1().y()), t.v2().y()), t.v3().y()));

        double right(std::max(std::max(std::max(m_bBox.isValid() ? m_bBox.right() : t.v1().x(), t.v1().x()), t.v2().x()), t.v3().x()));
        double left(std::min(std::min(std::min(m_bBox.isValid() ? m_bBox.left() : t.v1().x(), t.v1().x()), t.v2().x()), t.v3().x()));

        double front(std::max(std::max(std::max(m_bBox.isValid() ? m_bBox.front() : t.v1().z(), t.v1().z()), t.v2().z()), t.v3().z()));
        double back(std::min(std::min(std::min(m_bBox.isValid() ? m_bBox.back() : t.v1().z(), t.v1().z()), t.v2().z()), t.v3().z()));

        m_bBox.setTop(top);
        m_bBox.setBottom(bottom);

        m_bBox.setLeft(left);
        m_bBox.setRight(right);

        m_bBox.setFront(front);
        m_bBox.setBack(back);
    }

} // namespace STLUtils
