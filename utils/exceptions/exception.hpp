#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <QString>

#include <stdexcept>

namespace Exception {

class Exception : public std::exception
{
public:
    Exception(const QString message);

    ~Exception() throw();

    QString message() const throw();

    const char* what() const throw();

private:
    QString m_message;
};

}

#endif // EXCEPTION_HPP
