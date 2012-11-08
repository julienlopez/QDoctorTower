#ifndef NETWORKHANDLER_HPP
#define NETWORKHANDLER_HPP

#include <utils/updateable.hpp>
#include <utils/drawable.hpp>

#include <boost/shared_ptr.hpp>
#include <QtGlobal>

class Tower;
class NetworkHandlerImplBasique;

class NetworkHandler : public Updateable, public Drawable
{
public:
    typedef NetworkHandlerImplBasique type_impl;

    NetworkHandler();

    void addTowerToNetwork(Tower* tower, quint8 x, quint8 y);

    virtual void update(double dt);

    virtual void draw(QPainter* painter) const;

private:
    boost::shared_ptr<type_impl> pimpl; //only shared_ptr to use with partial definition of type_impl
};

#endif // NETWORKHANDLER_HPP
