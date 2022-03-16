#ifndef STACK_HPP
# define STACK_HPP

#include "../Vector/vector.hpp"

namespace ft
{

    template <class T, class Container = ft::vector<T> > 
    class stack : public ft::vector<T>{
        public:

            typedef T                          value_type; 
            typedef size_t                     size_type;
            typedef Container                  container_type;
            
            explicit stack (const container_type& ctnr = container_type()) : _vect(ctnr)
            {
                //this->_vect._mytab = this->_myTab;
                return ;
            }

            ~stack( void )
            {
                return ;
            }

            void push (const value_type& val)
            {
                this->push_back(val);
                return ;
            }

            value_type & top( void )
            {
                return this->_myTab[this->_size_hide - 1];
            }

            const value_type& top() const
            {
                return this->_myTab[this->_size_hide - 1];
            }

            void pop( void )
            {
                this->pop_back();
                return ;
            }

            private :
                ft::vector<T> _vect;

    };
}
#endif