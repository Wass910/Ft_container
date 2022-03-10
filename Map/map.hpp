#ifndef MAP_HPP
# define MAP_HPP


#include <iostream>
#include <memory>
#include <exception>
#include <iterator>
#include "../utils/make_pair.hpp"

namespace ft
{

    template < class Key, class T, class Compare = std::less<Key>,  
    class Alloc = std::allocator<std::pair<const Key,T> > >    
    class map{

        private:
            typedef struct _map_node{
                ft::pair<Key, T>    _myPair;
                _map_node           *next;
            }               _map_node;
            _map_node   *_myMap;
            size_t   _size;

            _map_node  *map_new(Key key, T value)
            {
                _map_node *lst = new _map_node;

                lst->_myPair = ft::make_pair(key, value);
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
            
        public:

            typedef size_t												    size_type;

            map( void ) 
            {
                this->_size = 0;
                return ;
            }

            ~map( void ) 
            {
                return ;
            }

            class iterator : public std::iterator<std::input_iterator_tag, int>{
                public:
                    iterator(void) 
                    {
                        return ;
                    }
                    iterator(_map_node * x) :p(x) , begin(x), first(x->_myPair.first), second(x->_myPair.second)
                    {
                        return ;
                    }

                    iterator & operator=( iterator const & src) 
                    {
                        this->p = src.p;
                        this->begin = src.begin;
                        this->first = src.first;
                        this->second = src.second;
                        return *this ;
                    }

                    iterator(iterator const & test) :p(test.p) 
                    {
                        return ;
                    }

                    T & operator*( void ) 
                    {
                        return this->second;
                    }

                    bool operator==( iterator const & it ) const
                    {
                        if (it.first == this->first)
                            return true;
                        return false;
                    }

                    bool operator!=( iterator const & ite) const
                    {
                        if (this->first == ite.first)
                            return false;
                        return true;
                    }

                    iterator operator++(int) 
                    {
                        iterator  temp = *this;
                        ++*this;
                        return temp;
                    }

                    iterator& operator++(void) 
                    {
                        this->p = this->p->next;
                        first = this->p->_myPair.first;
                        second = this->p->_myPair.second;
                        return *this;
                    }


                    iterator operator--(int) 
                    {
                        iterator  temp = *this;
                        --*this;
                        return temp;
                    }

                    iterator& operator--(void) 
                    {
                        _map_node *temp = this->begin;
                        while (temp->next && temp->next->_myPair.first != this->first)
                        {    
                            std::cout << this->first << std::endl;
                            temp = temp->next;
                        }
                        this->p = temp;
                        this->first = temp->_myPair.first;
                        this->second = temp->_myPair.second;
                        return *this;
                    }

                    Key first;
                    T   second;

                private :
                    _map_node * p;
                    _map_node * begin;
                    
            };

            iterator   begin( void ) const
            {
                iterator   it(this->_myMap);
                return (it);
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
                if (this->_size != 0)
                {
                    
                    for (int i = 0; temp; i++)
                    {
                        if (key == temp->_myPair.first)
                            return (temp->_myPair.second);  
                        temp = temp->next;       
                    }
                }
				T a = T();
                if (this->_size == 0)
                    this->_myMap = map_new(key, a);
                else
                    this->map_back(&this->_myMap, this->map_new(key, a));
                    
                this->_size++;
                temp = this->_myMap;
				for (int i = 0; temp->next; i++) 
                    temp = temp->next;
				return temp->_myPair.second;
            }

			void display_map(){
				_map_node *temp = this->_myMap;
				while(temp)
				{
					std::cout << "display_map: " << temp->_myPair.second << std::endl;
					temp = temp->next;
				}
				return;
			}

        
    };
}

#endif //MAP_HPP