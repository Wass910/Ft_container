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
                ft::pair<Key, T>    *_myPair;
                _map_node           *next;
                _map_node           *begin;
            }               _map_node;
            _map_node   *_myMap;
            size_t   _size;
            _map_node   *_end;
            
            _map_node  *map_new_end( void )
            {
                _map_node *lst = new _map_node;
                lst->next = NULL;
                lst->begin = this->_myMap;
                lst->_myPair = NULL;
                return lst;
            }

            _map_node  *map_new(Key key, T value)
            {
                _map_node *lst = new _map_node;
                lst->_myPair = new ft::pair<Key, T>();

                *lst->_myPair =  ft::make_pair(key, value);
                lst->begin = this->_end->begin;
                lst->next = this->_end;
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
                    while (lst->next != this->_end)
                    {   
                        lst = lst->next;
                    }lst->next = other;
                }
            }
            
        public:

            typedef Alloc												allocator_type;
            typedef size_t												    size_type;

            map( void ) 
            {
                this->_end = map_new_end();
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
                    iterator(_map_node * x) :p(x) 
                    {
                        return ;
                    }

                    iterator & operator=( iterator const & src) 
                    {
                        this->p = src.p;
                        return *this ;
                    }

                    iterator(iterator const & test) :p(test.p) 
                    {
                        return ;
                    }

                    T & operator*( void ) 
                    {
                        return this->p->_myPair->second;
                    }

                    ft::pair<Key, T> * operator->( void )
                    {
                        return this->p->_myPair;
                    }
                    bool operator==( iterator const & it ) const
                    {
                        if ( it.p->_myPair->first == this->p->_myPair->fist)
                            return true;
                        return false;
                    }

                    bool operator!=( iterator const & ite) const
                    {
                        if (this->p->_myPair == ite.p->_myPair)
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
                        _map_node *temp = this->p->begin ;
                        while (temp->next && temp->next->_myPair != this->p->_myPair)
                        {    
                            temp = temp->next;
                        }
                        this->p = temp;
                        this->p->_myPair = temp->_myPair;
                        return *this;
                    }


                private :
                    _map_node * p;
                    
            };

            class const_iterator : public std::iterator<std::input_iterator_tag, int>{
                public:
                    const_iterator(void) 
                    {
                        return ;
                    }
                    const_iterator(_map_node * x) :p(x)
                    {
                        return ;
                    }

                    const_iterator & operator=( const_iterator const & src) 
                    {
                        this->p = src.p;
                        return *this ;
                    }

                    const_iterator(const_iterator const & test) :p(test.p) 
                    {
                        return ;
                    }

                    T & operator*( void ) const 
                    {
                        return this->p->_myPair->second;
                    }

                    ft::pair<Key, T> * operator->( void )
                    {
                        return this->p->_myPair;
                    }
                    bool operator==( const_iterator const & it ) const
                    {
                        if ( it.p->_myPair->first == this->p->_myPair->fist)
                            return true;
                        return false;
                    }

                    bool operator!=( const_iterator const & ite) const
                    {
                        if (this->p->_myPair == ite.p->_myPair)
                            return false;
                        return true;
                    }

                    const_iterator operator++(int) 
                    {
                        const_iterator  temp = *this;
                        ++*this;
                        return temp;
                    }

                    const_iterator& operator++(void) 
                    {
                        this->p = this->p->next;
                        return *this;
                    }


                    const_iterator operator--(int) 
                    {
                        const_iterator  temp = *this;
                        
                        --*this;
                        return temp;
                    }

                    const_iterator& operator--(void) 
                    {
                        _map_node *temp = this->p->begin ;
                        while (temp->next && temp->next->_myPair != this->p->_myPair)
                        {    
                            temp = temp->next;
                        }
                        this->p = temp;
                        this->p->_myPair = temp->_myPair;
                        return *this;
                    }


                private :
                    _map_node * p;
                    
            };

            iterator    begin( void ) const
            {
                iterator   it(this->_myMap);
                return (it);
            }

            iterator     end( void ) const
            {
                _map_node *temp = this->_myMap;
                iterator   it(this->_end);
                return (it);
            }

            const_iterator    begin( void ) 
            {
                const_iterator   it(this->_myMap);
                return (it);
            }

            const_iterator     end( void ) 
            {
                _map_node *temp = this->_myMap;
                const_iterator   it(this->_end);
                return (it);
            }

            const_iterator    cbegin( void ) const
            {
                const_iterator   it(this->_myMap);
                return (it);
            }

            const_iterator     cend( void ) const
            {
                _map_node *temp = this->_myMap;
                const_iterator   it(this->_end);
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
                    
                    for (int i = 0; temp->next != this->_end ; i++)
                    {
                        if (key == temp->_myPair->first)
                            return (temp->_myPair->second);  
                        temp = temp->next;       
                    }
                }
				T a = T();
                if (this->_size == 0)
                    this->_myMap = map_new(key, a);
                else
                    this->map_back(&this->_myMap, this->map_new(key, a));
                this->_end->begin = this->_myMap;    
                this->_size++;
                temp = this->_myMap;
				for (int i = 0; temp->next != this->_end ; i++) 
                    temp = temp->next;
				return temp->_myPair->second;
            }
            
            bool empty( void ) const
            {
                if (this->_size == 0)   
                    return true;
                return false;
            }

            size_type size( void ) const
            {
                return this->_size;
            }

			void display_map(){
				_map_node *temp = this->_myMap;
				while(temp)
				{
					std::cout << "display_map: " << temp << std::endl;
					temp = temp->next;
				}
                std::cout << "display_map: " <<this->_end << std::endl;
                std::cout << "display_map: " <<this->_end->begin << std::endl;
				return;
			}

			size_type max_size() const{
				std::allocator<struct _map_node> _alloc;
				return _alloc.max_size() ;
			}

			allocator_type get_allocator() const{
				std::allocator<struct _map_node> _new_alloc;
				return _new_alloc;
			}
    };
}

#endif //MAP_HPP