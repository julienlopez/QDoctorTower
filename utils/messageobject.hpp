#ifndef MESSAGEOBJECT_HPP
#define MESSAGEOBJECT_HPP

#include <set>

template<class T> class MessageObject {
public:
    class Handler {
        typedef std::set<MessageObject*> type_set;

        ~Handler() {
            for(type_set::const_iterator i = m_objets.begin(); i != m_objets.end(); ++i)
                (*i)->remove(this);
        }

        virtual void handleNotify(T& t) =0;

        void add(Handler* m) {
            m_objets.insert(m);
        }

        void remove(Handler* m) {
            m_objets.erase(m);
        }

    private:
        type_set m_objets;
    };

    typedef std::set<Handler*> type_set;

    void notify() {
//        for(type_set::const_iterator it = m_handlers.begin(); it != m_handlers.end(); ++it)
//            (*it)->handleNotify(this);
    }

    void add(Handler* m) {
        m_handlers.insert(m);
    }

    void remove(Handler* m) {
        m_handlers.erase(m);
    }

private:
    type_set m_handlers;
};

#endif // MESSAGE_HPP
