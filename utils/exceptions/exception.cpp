#include "exception.hpp"

Exception::Exception::Exception(const QString message): m_message(message)
{}

Exception::Exception::~Exception() throw()
{}

QString Exception::Exception::message() const throw()
{
    return m_message;
}

const char* Exception::Exception::what() const throw()
{
    return m_message.toStdString().c_str();
}
