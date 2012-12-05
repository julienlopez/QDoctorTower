#ifndef PCC_HPP
#define PCC_HPP

/**
 * \brief the Polymorphic Copy Constructor is a handy little pattern to allow virtual clone method without having to write it in every derived classes.
 *
 *
 */
template<class DERIVED, class BASE> class PCC : public BASE
{
public:
    virtual BASE* clone() const
    {
        return new DERIVED(static_cast<DERIVED const&>(*this));
    }
};

#endif // PCC_HPP
