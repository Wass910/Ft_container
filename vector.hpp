#include <iostream>
#include <memory>
#include <exception>
#include "vectorIterator.hpp"

namespace ft
{

    template <typename T, class Alloc = std::allocator<T> >
    class vector{
        public:

            vector( void ) : _size(0), _size_hide(0)
            {
                std::cout << "Vector constructor is call." << std::endl;
                return ;
            }

            vector( vector const & src ) : _size(src._size), _size_hide(src._size_hide), _tab(src._tab), _myTab(src._myTab)
            {
                std::cout << "Vector constructor is call." << std::endl;
                return ;
            }

            T & operator[]( unsigned int i ) const
            {
                return this->_myTab[i];
            }

            ~vector( void )
            {
                std::cout << "Vector destructor is call." << std::endl;
                return ;
            }

            class outOfRange : public std::exception {
            public:
                virtual const char* what() const throw()
                {
                    return ("Out of range.");
                }
            };

            
            ft::vector_iterator<T>   begin( void ) const
            {
                if (this->_size_hide == 0)
                    return NULL;
                ft::vector_iterator<T>   it(this->_myTab);
                return (it);
            }

            ft::vector_iterator<T>   end( void ) const
            {
                if (this->_size_hide == 0)
                    return NULL;
                ft::vector_iterator<T>   it(this->_myTab + this->_size_hide);
                return (it);
            }

            ft::vector_iterator<T>   begin( void ) 
            {
                if (this->_size_hide == 0)
                    return NULL;
                ft::vector_iterator<T>   it(this->_myTab);
                return (it);
            }

            ft::vector_iterator<T>   end( void )
            {
                if (this->_size_hide == 0)
                    return NULL;
                ft::vector_iterator<T>   it(this->_myTab + this->_size_hide);
                return (it);
            }

            ft::vector_const_iterator<T>   cbegin( void ) const
            {
                if (this->_size_hide == 0)
                    return NULL;
                ft::vector_const_iterator<T>   it(this->_myTab);
                return (it);
            }

            ft::vector_const_iterator<T>   cend( void ) const
            {
                if (this->_size_hide == 0)
                    return NULL;
                ft::vector_const_iterator<T>   it(this->_myTab + this->_size_hide);
                return (it);
            }

            ft::vector_const_iterator<T>   cbegin( void ) 
            {
                if (this->_size_hide == 0)
                    return NULL;
                ft::vector_const_iterator<T>   it(this->_myTab);
                return (it);
            }

            ft::vector_const_iterator<T>   cend( void )
            {
                if (this->_size_hide == 0)
                    return NULL;
                ft::vector_const_iterator<T>   it(this->_myTab + this->_size_hide);
                return (it);
            }
            
            ft::vector_const_reverse_iterator<T>   crbegin( void  )  
            {
                if (this->_size_hide == 0)
                    return NULL;
                ft::vector_const_reverse_iterator<T>   it(this->_myTab + this->_size_hide - 1);
                return (it);
            }

            ft::vector_const_reverse_iterator<T>   crend( void )  
            {
                if (this->_size_hide == 0)
                    return NULL;
                ft::vector_const_reverse_iterator<T>   it(this->_myTab - 1);
                return (it);
            }

            ft::vector_const_reverse_iterator<T>   crbegin( void  )  const
            {
                if (this->_size_hide == 0)
                    return NULL;
                ft::vector_const_reverse_iterator<T>   it(this->_myTab + this->_size_hide - 1);
                return (it);
            }

            ft::vector_const_reverse_iterator<T>   crend( void )  const
            {
                if (this->_size_hide == 0)
                    return NULL;
                ft::vector_const_reverse_iterator<T>   it(this->_myTab - 1);
                return (it);
            }

            ft::vector_reverse_iterator<T>   rbegin( void  )  const
            {
                if (this->_size_hide == 0)
                    return NULL;
                ft::vector_reverse_iterator<T>   it(this->_myTab + this->_size_hide - 1);
                return (it);
            }

            ft::vector_reverse_iterator<T>   rend( void )  const
            {
                if (this->_size_hide == 0)
                    return NULL;
                ft::vector_reverse_iterator<T>   it(this->_myTab - 1);
                return (it);
            }

            ft::vector_reverse_iterator<T>   rbegin( void  )  
            {
                if (this->_size_hide == 0)
                    return NULL;
                ft::vector_reverse_iterator<T>   it(this->_myTab + this->_size_hide - 1);
                return (it);
            }

            ft::vector_reverse_iterator<T>   rend( void )  
            {
                if (this->_size_hide == 0)
                    return NULL;
                ft::vector_reverse_iterator<T>   it(this->_myTab - 1);
                return (it);
            }

            bool empty( void ) const
            {
                if (this->_size_hide == 0)
                    return true;
                return false;
            }

            size_t size( void ) const
            {
                return this->_size_hide;
            }

            T   & front( void ) const
            {
                return this->_myTab[0];
            }
            
            T   * data( void ) const
            {
                if (this->_size == 0)
                    return NULL;
                return &this->_myTab[0];
            }

            T   & at( size_t value ) const
            {
                if (value > this->_size_hide)
                    throw outOfRange();
                return this->_myTab[value];
            }

            T   & back( void ) const
            {
                return this->_myTab[this->_size - 1];
            }


            void push_back(const T & val)
            {
                T *tmp = this->_myTab;
                this->_myTab = this->_tab.allocate(this->_size + 1, 0);
                for (int i = 0; i < this->_size ; i++)
                    this->_tab.construct(this->_myTab + i, tmp[i]);
                this->_tab.construct(this->_myTab + _size_hide, val);
                if (this->_size <= this->_size_hide)
                    _size++;
                this->_size_hide++;
                return ;
            }

            void pop_back( void )
            {
                if (this->_size_hide == 0)
                    return ;
                T *tmp = this->_myTab;
                this->_myTab = this->_tab.allocate(this->_size, 0);
                this->_size--;
                this->_size_hide--;
                for (int i = 0; i < this->_size ; i++)
                    this->_tab.construct(this->_myTab + i, tmp[i]);
                return ;
            }

            void clear( void )
            {
                size_t len = this->_size;

                for (size_t i = 0; i < len; i++) {
                    this->_tab.destroy(this->_myTab + i);
                    i++;
                }
                this->_size_hide = 0;
            }

            size_t max_size() const
            {
                return this->_tab.max_size();
            }

            template <class Erase>
            Erase   erase( Erase it) 
            {
                Erase it1 = this->begin();
                Erase ite1 = this->end();
                int to_erase = 0;

                while (it1 != it )
                {
                    to_erase++;
                    it1++;
                }
                T *tmp = this->_myTab;
                this->_tab.destroy(this->_myTab + to_erase);
                this->_myTab = this->_tab.allocate(this->_size, 0);
                this->_size_hide--;
                int temp = 0;
                for (int i = 0; i < this->_size ; i++)
                {    
                    if ( i != to_erase)
                    {    
                        this->_tab.construct(this->_myTab + temp, tmp[i]);
                        temp++;
                    }
                }
                this->_size--;
                return (++it1);
            } 

            template <class Poly_erase>
            Poly_erase   erase( Poly_erase it, Poly_erase ite) 
            {
                Poly_erase it1 = this->begin();
                Poly_erase ite1 = this->end();
                int to_erase_begin = 0;
                int to_erase_end = 0;

                while (it1 != ite )
                {
                    to_erase_end++;
                    it1++;
                }
                it1 = this->begin();
                while (it1 != it )
                {
                    to_erase_begin++;
                    it1++;
                }
                T *tmp = this->_myTab;
                for (int i = to_erase_begin; i < to_erase_end; i++ )
                    this->_tab.destroy(this->_myTab + i);
                this->_myTab = this->_tab.allocate(this->_size - (to_erase_end - to_erase_begin), 0);
                this->_size_hide-= (to_erase_end - to_erase_begin);
                int temp = 0;
                for (int i = 0; i < this->_size  ; i++)
                {    
                    if ( i < to_erase_begin || i >= to_erase_end )
                    {    
                        this->_tab.construct(this->_myTab + temp, tmp[i]);
                        temp++;
                    }
                }
                this->_size -= (to_erase_end - to_erase_begin );
                while(to_erase_begin != to_erase_end)
                {
                    it++;
                    to_erase_begin++;
                }
                return (it);
            } 

            

            friend bool operator==(const vector & lhs, const vector & rhs)
            {
                if (lhs.size() == rhs.size())
                {
                    for(int i = 0; i < lhs.size(); i++)
                    {
                        if (lhs.at(i) != rhs.at(i))
                            return false;
                    }
                    return true;
                }
                return false;
            }

            friend bool operator!=(const vector & lhs, const vector & rhs)
            {
                if (lhs.size() == rhs.size())
                {
                    for(int i = 0; i < lhs.size(); i++)
                    {
                        if (lhs.at(i) != rhs.at(i))
                            return true;
                    }
                    return false;
                }
                return true;
            }

            friend bool operator<(const vector & lhs, const vector & rhs)
            {
				size_t len;
				if(lhs.size() > rhs.size())
					len = lhs.size();
				else
					len = rhs.size();
                for(int i = 0; i < len; i++)
                    {
						if(lhs.at(i) > rhs.at(i))
							return false;
                    }
				if(lhs == rhs)
					return false;
                return true;
            }

            friend bool operator<=(const vector & lhs, const vector & rhs)
            {
                size_t len;
				if(lhs.size() > rhs.size())
					len = lhs.size();
				else
					len = rhs.size();
                for(int i = 0; i < len; i++)
                    {
						if(lhs.at(i) > rhs.at(i))
							return false;
                    }
                return true;
            }

            friend bool operator>(const vector & lhs, const vector & rhs)
            {
                size_t len;
				if(lhs.size() > rhs.size())
					len = lhs.size();
				else
					len = rhs.size();
                for(int i = 0; i < len; i++)
                    {
						if(lhs.at(i) > rhs.at(i))
							return true;
                    }
                return false;
            }

            friend bool operator>=(const vector & lhs, const vector & rhs)
            {
                size_t len;
				if(lhs.size() > rhs.size())
					len = lhs.size();
				else
					len = rhs.size();
                for(int i = 0; i < len; i++)
                    {
						if(lhs.at(i) > rhs.at(i))
							return true;
                    }
				if(lhs == rhs)
					return true;
                return false;
            } 

        private:
            std::allocator<T>    _tab;
            T                    *_myTab;
            size_t                 _size;
            size_t                 _size_hide;
    };
}