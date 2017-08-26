#ifndef RECT3D_H
#define RECT3D_H

#include "vertex.h"

namespace STLUtils
{
    class Rect3D
    {
    public:
        Rect3D(const double &top=0, const double &bottom=0, const double &left=0,
               const double &right=0, const double &front=0, const double &back=0);

        void setTop(const double &top);
        double top() const;

        void setBottom(const double &bottom);
        double bottom() const;

        void setLeft(const double &left);
        double left() const;

        void setRight(const double &right);
        double right() const;

        void setFront(const double &front);
        double front() const;

        void setBack(const double &back);
        double back() const;

        double width() const;
        double height() const;
        double depth() const;

        Vertex center() const;

        bool isValid() const;
        void invalidate();

        friend std::ostream& operator << (std::ostream& stream, const Rect3D &r)
        {
            stream << "Rect3D(t, b, r, l, f, b, W, H, D): "<< r.top() <<" "<< r.bottom()
                   <<" " << r.right() <<" " << r.left()
                  <<" " << r.front()<<" " << r.back()
                 <<" " << r.width()<<" " << r.height()<<" " << r.depth()<< std::endl;
            return stream;
        }

    protected:
        void updateGeometry();

    private:
        double m_top, m_bottom, m_left, m_right, m_front,  m_back;
        double m_width, m_height, m_depth;
        Vertex m_center;
    };
}

#endif // RECT3D_H
