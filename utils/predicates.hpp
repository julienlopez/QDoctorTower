#ifndef PREDICATES_HPP
#define PREDICATES_HPP

template<typename T> class ComparePtr : std::unary_function<T, bool>
{
public:
    ComparePtr(T* ptr)
    {
        m_ptr = ptr;
    }

    bool operator()(const boost::shared_ptr<T>& sp) const
    {
        return sp.get() == m_ptr;
    }

private:
    T* m_ptr;
};

#endif // PREDICATES_HPP
