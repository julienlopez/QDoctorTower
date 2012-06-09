#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "singleton.hpp"
#include "defaultfactoryerrorpolicy.hpp"

#include <map>

class QPoint;
class QPointF;

template<	class AbstractProduct,
			class IdentifierType,
			class ProductCreator = AbstractProduct*(*)(),
			template<typename, class> class FactoryErrorPolicy = DefaultFactoryErrorPolicy
			>
class Factory : public FactoryErrorPolicy<IdentifierType, AbstractProduct>, public Singleton<Factory<AbstractProduct, IdentifierType, ProductCreator, FactoryErrorPolicy> >
{
public:
    typedef FactoryErrorPolicy<IdentifierType, AbstractProduct> error_policy;

    AbstractProduct* create(typename ParameterTrait<IdentifierType>::const_reference id)
	{
		typename AssocMap::const_iterator i = m_associations.find(id);
        if(i != m_associations.end()) return (i->second)();
        return onUnknownType(id);
	}

    AbstractProduct* create(typename ParameterTrait<IdentifierType>::const_reference id, const QPoint& p)
    {

        typename AssocMap::const_iterator i = m_associations.find(id);
        if(i != m_associations.end()) return (i->second)(p);
        return onUnknownType(id);
    }

    AbstractProduct* create(typename ParameterTrait<IdentifierType>::const_reference id, const QPointF& p)
    {

        typename AssocMap::const_iterator i = m_associations.find(id);
        if(i != m_associations.end()) return (i->second)(p);
        return onUnknownType(id);
    }
	
    bool registerProduct(typename ParameterTrait<IdentifierType>::const_reference id, ProductCreator creator)
	{
        return m_associations.insert(typename AssocMap::value_type(id, creator)).second;
	}
	
    bool unregisterProduct(typename ParameterTrait<IdentifierType>::const_reference id)
	{
		return m_associations.erase(id) == 1;
	}
	
private:
    typedef std::map<IdentifierType, ProductCreator> AssocMap;
	AssocMap m_associations;
};

#endif
