#include "rect3d.h"

namespace STLUtils
{
    Rect3D::Rect3D(const double &top, const double &bottom, const double &left, const double &right, const double &front, const double &back):
        m_top(top),
        m_bottom(bottom),
        m_left(left),
        m_right(right),
        m_front(front),
        m_back(back)
    {
        updateGeometry();
    }

    void Rect3D::setTop(const double &top)
    {
        m_top = top;
        updateGeometry();
    }

    double Rect3D::top() const
    {
        return m_top;
    }

    void Rect3D::setBottom(const double &bottom)
    {
        m_bottom = bottom;
        updateGeometry();
    }

    double Rect3D::bottom() const
    {
        return m_bottom;
    }

    void Rect3D::setLeft(const double &left)
    {
        m_left = left;
        updateGeometry();
    }

    double Rect3D::left() const
    {
        return m_left;
    }

    void Rect3D::setRight(const double &right)
    {
        m_right = right;
        updateGeometry();
    }

    double Rect3D::right() const
    {
        return m_right;
    }

    void Rect3D::setFront(const double &front)
    {
        m_front = front;
        updateGeometry();
    }

    double Rect3D::front() const
    {
        return m_front;
    }

    void Rect3D::setBack(const double &back)
    {
        m_back = back;
        updateGeometry();
    }

    double Rect3D::back() const
    {
        return m_back;
    }

    double Rect3D::width() const
    {
        return m_width;
    }

    double Rect3D::height() const
    {
        return m_height;
    }

    double Rect3D::depth() const
    {
        return m_depth;
    }

    Vertex Rect3D::center() const
    {
        return m_center;
    }

    bool Rect3D::isValid() const
    {
        return (m_width > 0 && m_height > 0 && m_depth > 0);
    }

    void Rect3D::invalidate()
    {
        m_top = m_bottom = m_right = m_front = m_back = 0;

        updateGeometry();
    }

    void Rect3D::updateGeometry()
    {
        m_width  = m_right - m_left;
        m_height = m_top - m_bottom;
        m_depth  = m_front - m_back;

        m_center = Vertex(m_right - m_width*0.5, m_top - m_height*0.5, m_front - m_depth*0.5);
    }
}
