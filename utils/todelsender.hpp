#ifndef TODELSENDER_HPP
#define TODELSENDER_HPP

#include <boost/signals.hpp>
#include <boost/bind.hpp>

/**
*
*
*/
template<class T> class ToDelSender
{
public:
    typedef boost::signal<void(T&)> type_signal;

    virtual ~ToDelSender() {}

    type_signal& toDel()
    {
        return m_toDel;
    }

    void emitToDel()
    {
        m_toDel((T&)*this);
    }

    template<typename U> void emitToDelWith1Arg(U&)
    {
        m_toDel((T&)*this);
    }

protected:
    ToDelSender() {}

private:
    type_signal m_toDel;
};

#endif // TODELSENDER_HPP
