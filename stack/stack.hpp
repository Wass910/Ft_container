#ifndef STACK_HPP
# define STACK_HPP

#include "../Vector/vector.hpp"

namespace ft
{

    template <class T, class Container = ft::vector<T> > 
    class stack {
        public:

            typedef T                          value_type; 
            typedef size_t                     size_type;
            typedef Container                  container_type;
            
            explicit stack (const container_type& ctnr = container_type()) 
            {
                this->_vect = new Container;
                *this->_vect = ctnr;
                //this = ctnr;
                //this->_vect._mytab = this->_myTab;
                return ;
            }

            ~stack( void )
            {
                return ;
            }

            void push (const value_type& val)
            {
                this->_vect->push_back(val);
                return ;
            }

            bool empty( void )
            {
                return this->_vect->empty();
            }
            
            size_type   size( void )
            {
                return this->_vect->size();
            }
            value_type & top( void )
            {
                return this->_vect[(this->_vect->size()) - 1];
            }

            /* const value_type& top() const
            {
                return this->_vect[(this->_vect->size()) - 1];
            }
 */
            void pop( void )
            {
                this->_vect->pop_back();
                return ;
            }

            private :
                ft::vector<T> *_vect;

    };
}
#endif