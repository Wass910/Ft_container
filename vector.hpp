#ifndef VECTOR_HPP
# define VECTOR_HPP


#include <iostream>
#include <memory>
#include <exception>
#include "vectorIterator.hpp"

namespace ft
{

    template <typename T, class Alloc = std::allocator<T> >
    class vector{
        public:

            typedef Alloc												allocator_type;
            typedef size_t												size_type;

            explicit vector (const allocator_type& alloc = allocator_type()) 
            {
                this->_size = 0;
                this->_size_hide = 0;
                this->_myTab = NULL;
            }

            explicit vector (size_type n, const T & val = T(), const allocator_type& alloc = allocator_type()) 
            {
                this->_size = n;
                this->_size_hide = n;
                this->_myTab = this->_tab.allocate(n);
                for (size_t i = 0; i < n; i++) 
                    this->_tab.construct(this->_myTab + i, val);
            }

            template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
            {
                    InputIterator it = first;
                    InputIterator ite = last;
                    int count = 0;
                   
                    if (first > last)
                        throw std::length_error("Error : at out of range error");
                    while (it != ite)
                    {
                        count++;
                        it++;
                    }
                    T tmp[count];
                    count = 0;
                    while (first != last)
                    {
                        tmp[count] = *first;
                        count++;
                        first++;
                    }
                    this->_size = count;
                    this->_size_hide = count;
                    this->_myTab = this->_tab.allocate(count + 1, 0);
                    for(int i = 0; i < count; i++)
                        this->_tab.construct(this->_myTab + i, tmp[i]);
                }

            vector( vector const & src ) : _size(src._size), _size_hide(src._size_hide), _tab(src._tab), _myTab(src._myTab)
            {
                std::cout << "Vector constructor assignation is call." << std::endl;
                return ;
            }

            T & operator[]( unsigned int i ) const
            {
                return this->_myTab[i];
            }

            ft::vector<T> & operator=(ft::vector<T> const & src)
            {
                this->_size = src._size;
                this->_size_hide = src._size_hide;
                this->_myTab = src._myTab;
                this->_tab = src._tab;
                return *this;
            }
            ~vector( void )
            {
                std::cout << "Vector destructor is call." << std::endl;
                std::cout << "size_hide = " << this->_size_hide << "\n";
                this->_tab.deallocate(this->_myTab, this->_size_hide);
                return ;
            }

            
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
                {    
                    ft::vector_iterator<T>   it1(this->_myTab);
                    return it1;
                }
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
                {    
                    ft::vector_iterator<T>   it1(this->_myTab);
                    return it1;
                }
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
                {    
                    ft::vector_const_iterator<T>   it1(this->_myTab);
                    return it1;
                }
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
                {    
                    ft::vector_const_iterator<T>   it1(this->_myTab);
                    return it1;
                }
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
                {    
                    ft::vector_const_reverse_iterator<T>   it1(this->_myTab);
                    return it1;
                }
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
                {    
                    ft::vector_const_reverse_iterator<T>   it1(this->_myTab);
                    return it1;
                }
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
                {    
                    ft::vector_reverse_iterator<T>   it1(this->_myTab);
                    return it1;
                }
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
                {    
                    ft::vector_reverse_iterator<T>   it1(this->_myTab);
                    return it1;
                }
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
                    throw std::out_of_range("Error : at out of range error");
                return this->_myTab[value];
            }

            T   & back( void ) const
            {
                return this->_myTab[this->_size - 1];
            }


            void push_back(const T & val)
            {
                T *tmp = NULL;
                if (this->_myTab)
                {    
                    tmp = this->_tab_tmp.allocate(this->_size_hide + 1, 0);
                    for (int i = 0; i < this->_size_hide; i++)
                        this->_tab.construct(tmp + i, this->_myTab[i]); 
                    this->_tab.deallocate(this->_myTab, this->_size_hide);
                }
                this->_myTab = this->_tab.allocate(this->_size + 1, 0);
                if (tmp != NULL)
                {
                    for (int i = 0; i < this->_size; i++)
                        this->_tab.construct(this->_myTab + i, tmp[i]);
                    this->_tab_tmp.deallocate(tmp, this->_size_hide + 1);
                }
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
                T *tmp = this->_tab_tmp.allocate(this->_size_hide + 1, 0);
                for (int i = 0; i < this->_size_hide; i++)
                        this->_tab.construct(tmp + i, this->_myTab[i]); 
                this->_tab.deallocate(this->_myTab, this->_size_hide);
                this->_myTab = this->_tab.allocate(this->_size, 0);
                this->_size--;
                this->_size_hide--;
                for (int i = 0; i < this->_size ; i++)
                    this->_tab.construct(this->_myTab + i, tmp[i]);
                this->_tab_tmp.deallocate(tmp, this->_size_hide + 1);
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
                //this->_myTab = this->_tab.allocate(this->_size, 0);
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

                if (it > ite)
                        throw std::length_error("Error : at out of range error");
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
                //this->_myTab = this->_tab.allocate(this->_size - (to_erase_end - to_erase_begin), 0);
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
            
            template <class InputIterator>
			void insert (InputIterator position, InputIterator first, InputIterator last)
            {
				ft::vector_iterator<T> it1 = this->begin();
                ft::vector_iterator<T> ite1 = this->end();
                int place = 0;
				int temp = 0;
				int count = 0;
                int value_counter = 0;

                if (first > last)
                        throw std::length_error("Error : at out of range error");
				while (first != last )
                {
                    count++;
                    if (count > this->_size_hide)
                        return ;
                    first++;
                }
                T value[count];
				first -=count;
				while (it1 != position)
				{
					it1++;
					place++;
				}
                for (int i = 0;first != last; i++ )
                {
                    value[i] = *first;
                    first++;
                }
				it1 -= place;
                T *tmp = this->_tab_tmp.allocate(this->_size_hide + 1, 0);
                for (int i = 0; i < this->_size_hide; i++)
                        this->_tab.construct(tmp + i, this->_myTab[i]);
                this->_tab.deallocate(this->_myTab, this->_size_hide);
                this->_size +=count;
                this->_size_hide +=count;
                this->_myTab = this->_tab.allocate(this->_size , 0);
                for (int i = 0; i < this->_size  ; i++)
                {  
                    
                    if (i == place)
                    {
                        while (count > 0)
                        {
                            this->_tab.construct(this->_myTab + i, value[value_counter]);
                            i++;
							value_counter++;
                            count--;
                        }
                        i--;
                    }
                    else
                        this->_tab.construct(this->_myTab + i, tmp[temp++]);  
                }
                this->_tab_tmp.deallocate(tmp, this->_size_hide + 1);
			}

            void insert(ft::vector_iterator<T> it, unsigned int n, const T & val)
            {
                ft::vector_iterator<T> it1 = this->begin();
                ft::vector_iterator<T> ite1 = this->end();
                int place = 0;
                int temp = 0;

                while (it1 != it )
                {
                    place++;
                    it1++;
                }
                T *tmp = this->_tab_tmp.allocate(this->_size_hide + 1, 0);
                for (int i = 0; i < this->_size_hide; i++)
                        this->_tab.construct(tmp + i, this->_myTab[i]);
                this->_tab.deallocate(this->_myTab, this->_size_hide);
                this->_size += n;
                this->_size_hide += n;
                this->_myTab = this->_tab.allocate(this->_size , 0);
                for (int i = 0; i < this->_size  ; i++)
                {  
                    
                    if (i == place)
                    {
                        while (n > 0)
                        {
                            this->_tab.construct(this->_myTab + i, val); 
                            i++; 
                            n--;
                        }
                        i--;
                    }
                    else
                        this->_tab.construct(this->_myTab + i, tmp[temp++]);  
                }
                this->_tab_tmp.deallocate(tmp, this->_size_hide + 1);
            }

            ft::vector_iterator<T> insert(ft::vector_iterator<T> it, const T & val)
            {
                ft::vector_iterator<T> it1 = this->begin();
                ft::vector_iterator<T> ite1 = this->end();
                int place = 0;
                int temp = 0;

                while (it1 != it )
                {
                    place++;
                    it1++;
                }
                T *tmp = this->_tab_tmp.allocate(this->_size_hide + 1, 0);
                for (int i = 0; i < this->_size_hide; i++)
                        this->_tab.construct(tmp + i, this->_myTab[i]);
                this->_size++;
                this->_size_hide++;
                this->_tab.deallocate(this->_myTab, this->_size_hide);
                this->_myTab = this->_tab.allocate(this->_size , 0);
                for (int i = 0; i < this->_size  ; i++)
                {  
                    
                    if (i == place)
                        this->_tab.construct(this->_myTab + i, val); 
                    else
                        this->_tab.construct(this->_myTab + i, tmp[temp++]);  
                }
                this->_tab_tmp.deallocate(tmp, this->_size_hide + 1);
                ft::vector_iterator<T> it2 = this->begin();
                while (place > 0)
                {
                    place--;
                    it2++;
                }
                return it2;
            }

            

            void assign(unsigned int n, const T & val)
            {
                if (this->_myTab != NULL)
                    this->_tab.deallocate(this->_myTab, this->_size);
                this->_myTab = this->_tab.allocate(n, 0);
                this->_size = n;
                this->_size_hide = n;
                for (int i = 0; i < n; i++)
                    this->_tab.construct(this->_myTab + i, val); 
                return ;
            }

            template <class InputIterator>
                void assign (InputIterator first, InputIterator last)
                {
                    if (first > last)
                        throw std::length_error("Error : at out of range error");
                    InputIterator it = first;
                    InputIterator ite = last;
                    int count = 0;
                    
                    while (it != ite)
                    {
                        count++;
                        it++;
                    }
                    T tmp[count];
                    count = 0;
                    while (first != last)
                    {
                        tmp[count] = *first;
                        count++;
                        first++;
                    }
                    if (this->_myTab != NULL)
                        this->_tab.deallocate(this->_myTab, this->_size);
                    this->_size = count;
                    this->_size_hide = count;
                    this->_myTab = this->_tab.allocate(count + 1, 0);
                    for(int i = 0; i < count; i++)
                        this->_tab.construct(this->_myTab + i, tmp[i]);
                }

            void swap(ft::vector<T> & src)
            {
                ft::vector<T> temp;
                temp = *this;
                *this = src;
                src = temp;
                return ;
            }

			size_t capacity() const{
				return this->_size;
			}

			void reserve(size_t n){
				if(n <= this->_size)
					return;
				this->_size = n;
				ft::vector_iterator<T> it1 = this->begin();
                ft::vector_iterator<T> ite1 = this->end();
                int temp = 0;
                T *tmp = this->_tab_tmp.allocate(this->_size_hide, 0);
                for (int i = 0; i < this->_size_hide; i++)
                        this->_tab.construct(tmp + i, this->_myTab[i]);
                this->_tab.deallocate(this->_myTab, this->_size_hide);
                this->_myTab = this->_tab.allocate(n , 0);
				for (int i = 0; i < this->_size_hide  ; i++) 
                	this->_tab.construct(this->_myTab + i, tmp[temp++]);
                this->_tab_tmp.deallocate(tmp, this->_size_hide + 1);
				return;
			}

			void resize (size_t n, T val = T()){
				ft::vector_iterator<T> its = this->begin();
				ft::vector_iterator<T> ite = this->end();
				int place = 0;
				if(n < this->size())
				{
					for(int i = 0; i < n ; i++)
					{
						its++;
						place++;
					}
					for((void)its; its != ite; its++)
					{
						this->_tab.destroy(this->_myTab + place);
						place++;
						this->_size_hide--;
					}
				}
				else if (n > this->size())
				{
					if(this->_size > n)
					{
						for (int i = this->_size_hide; i < this->_size  ; i++)
						{
                			this->_tab.construct(this->_myTab + i, val);
							this->_size_hide++;
						}
					}
					else{
               			T *tmp = this->_tab_tmp.allocate(this->_size_hide, 0);
                		for (int i = 0; i < this->_size_hide; i++)
                        	this->_tab.construct(tmp + i, this->_myTab[i]);
                		this->_tab.deallocate(this->_myTab, this->_size_hide);
                		this->_myTab = this->_tab.allocate(n , 0);
						for (int i = 0; i < this->_size_hide  ; i++) 
                			this->_tab.construct(this->_myTab + i, tmp[i]);
						for (int i = this->_size_hide; i < n  ; i++)
						{
                			this->_tab.construct(this->_myTab + i, val);
							this->_size_hide++;
						}
                		this->_tab_tmp.deallocate(tmp, this->_size_hide + 1);
						this->_size = n;
					}
				}
				return;
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
            std::allocator<T>    _tab_tmp;
            T                    *_myTab;
            size_t                 _size;
            size_t                 _size_hide;
            int                     _leaks;
    };
}

#endif //VECTOR_HPP