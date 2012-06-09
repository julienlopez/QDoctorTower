#include "exception.hpp"

Exception::Exception(const QString message): m_message(message)
{}

Exception::~Exception() throw()
{}

QString Exception::message() const throw()
{
    return m_message;
}

const char* Exception::what() const throw()
{
    return m_message.toStdString().c_str();
}
