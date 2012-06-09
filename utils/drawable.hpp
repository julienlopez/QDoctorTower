#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

class QPainter;

class Drawable
{
public:
    virtual void draw(QPainter* painter) const =0;
};

#endif // DRAWABLE_HPP
