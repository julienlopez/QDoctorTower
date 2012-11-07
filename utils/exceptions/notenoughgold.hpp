#ifndef NOTENOUGHGOLD_HPP
#define NOTENOUGHGOLD_HPP

#include "exception.hpp"

namespace Exception {

class NotEnoughGold : public Exception
{
public:
    NotEnoughGold(quint32 needed, quint32 available);
};

}

#endif // NOTENOUGHGOLD_HPP
