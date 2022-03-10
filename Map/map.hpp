#ifndef MAP_HPP
# define MAP_HPP


#include <iostream>
#include <memory>
#include <exception>
#include <iterator>

namespace ft
{

    template < class Key, class T, class Compare = std::less<Key>,  
    class Alloc = std::allocator<std::pair<const Key,T> > >    
    class map{
        public:

            typedef size_t												    size_type;

            map( void ) 
            {
                this->_size = 0;
                std::cout << "Constructor is called." <<std::endl;
                return ;
            }

            ~map( void ) 
            {
                std::cout << "Destructor is called." <<std::endl;
                return ;
            }

            map & operator=( const map & src ) 
            {
                this->_myMap = src._myMap;
                this->_size = src._size;
                return *this;
            } 

            T & operator[]( const Key key ) 
            {
                _map_node *temp = this->_myMap;
                for (int i = 0; temp; i++)
                {
                    if (key == temp->key)
                        return (temp->value);  
                    temp = temp->next;       
                }
				T a = T();
                if (!this->_myMap)
                    this->_myMap = map_new(key, a);
                else
                    this->map_back(&this->_myMap, this->map_new(key, a));
                temp = this->_myMap;
				for (int i = 0; temp->next; i++) 
                    temp = temp->next;
				return temp->value;
            }

			void display_map(){
				_map_node *temp = this->_myMap;
				while(temp)
				{
					std::cout << "display_map: " << temp->value << std::endl;
					temp = temp->next;
				}
				return;
			}

            

        private:
            typedef struct _map_node{
                Key         key;
                T           value;
                _map_node   *next;
            }               _map_node;
            _map_node   *_myMap;
            size_type   _size;

            _map_node  *map_new(Key key, T value)
            {
                _map_node *lst = new _map_node;

                lst->key = key;
                lst->value = value;
                lst->next = NULL;
                return lst;
            }

            void map_back(_map_node **alst, _map_node *other)
            {
                _map_node *lst;

                lst = *alst;
                if (alst == NULL)
                    *alst = other;
                else
                {
                    while (lst->next)
                        lst = lst->next;
                    lst->next = other;
                }
            }
    };
}

#endif //MAP_HPP