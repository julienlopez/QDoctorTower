#ifndef LIST_HPP
#define LIST_HPP

#include "traits/parametertrait.hpp"

#include <list>
#include <stdexcept>

template<typename T> class List
{
public:
    typedef std::list<T> type_list;
    typedef typename type_list::iterator iterator;
    typedef typename type_list::const_iterator const_iterator;

    List()
    {}

    int indexOf(typename Select<IsPointer<T>::value, T, const T&>::type t) const
    {
        int res = 0;
        for(typename type_list::const_iterator i = m_data.begin(); i != m_data.end(); ++i, ++res)
            if(*i == t) return res;
        return -1;
    }

    void erase(iterator i) { m_data.erase(i); }

    bool empty() const { return m_data.empty(); }

    typename Select<IsPointer<T>::value, T, const T&>::type last() const { return m_data.back(); }

    List<T>& operator<<(typename Select<IsPointer<T>::value, T, const T&>::type t)
    {
        m_data.push_back(t);
        return *this;
    }

    T& operator[](int index) throw(std::invalid_argument)
    {
        int res = 0;
        for(typename type_list::iterator i = m_data.begin(); i != m_data.end(); ++i, ++res)
            if(res == index) return *i;
        throw std::invalid_argument("index out of bounds");
    }

    iterator begin() { return m_data.begin(); }
    const_iterator begin() const { return m_data.begin(); }
    iterator end() { return m_data.end(); }
    const_iterator end() const { return m_data.end(); }

private:
    type_list m_data;
};

#endif // LIST_HPP
