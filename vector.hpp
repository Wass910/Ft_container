#include <iostream>
#include <memory>
#include <exception>
#include <iterator>


namespace ft
{

    template <typename T>
    class vector_iterator : public std::iterator<std::input_iterator_tag, int>{
        public:
            vector_iterator(void) 
            {
                return ;
            }
            vector_iterator(T * x) :p(x) 
            {
                return ;
            }

            vector_iterator & operator=( vector_iterator const & src) 
            {
                this->p = src.p;
                return *this ;
            }

            vector_iterator(vector_iterator const & test) :p(test.p) 
            {
                return ;
            }

            T * getPointeur( void )
            {
                return p;
            }

            T& operator*() 
            {
                return *p;
            }

            vector_iterator operator++(T) 
            {
                vector_iterator  temp = *this;
                ++*this;
                return temp;
            }

            vector_iterator& operator++(void) 
            {
                this->p++;
                return *this;
            }

            vector_iterator operator--(T) 
            {
                vector_iterator  temp = *this;
                --*this;
                return temp;
            }

            vector_iterator& operator--(void) 
            {
                this->p--;
                return *this;
            }

        private :
            T * p;
    };
}

namespace ft
{

    template <typename T, class Alloc = std::allocator<T> >
    class vector{
        public:

            vector( void ) : _size(0)
            {
                std::cout << "Vector constructor is call." << std::endl;
                return ;
            }
            ~vector( void )
            {
                std::cout << "Vector destructor is call." << std::endl;
                return ;
            }

            class emptyTab : public std::exception {
            public:
                virtual const char* what() const throw()
                {
                    return ("Vector is empty.");
                }
            };

            ft::vector_iterator<T>   begin( void )
            {
                if (this->_size == 0)
                    return NULL;
                ft::vector_iterator<T>   it(this->_myTab);
                return (it);
            }

            ft::vector_iterator<T>   end( void )
            {
                if (this->_size == 0)
                    return NULL;
                ft::vector_iterator<T>   it(this->_myTab + this->_size);
                return (it);
            }

            bool empty( void ) const
            {
                if (this->_size == 0)
                    return true;
                return false;
            }

            void size( void ) const
            {
                std::cout << "size is = " << this->_size << std::endl;
                return ;
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
                this->_tab.construct(this->_myTab + _size, val);
                std::cout << "-------------------" << std::endl;
                for (int i = 0; i <= this->_size ; i++)
                    std::cout << this->_myTab[i] << std::endl;
                std::cout << "-------------------" << std::endl;
                _size++;
                return ;
            }

            void pop_back( void )
            {
                if (this->_size == 0)
                    return ;
                T *tmp = this->_myTab;
                this->_myTab = this->_tab.allocate(this->_size, 0);
                this->_size--;
                for (int i = 0; i < this->_size ; i++)
                    this->_tab.construct(this->_myTab + i, tmp[i]);
                std::cout << "-------------------" << std::endl;
                for (int i = 0; i < this->_size ; i++)
                    std::cout << this->_myTab[i] << std::endl;
                std::cout << "-------------------" << std::endl; 
                return ;
            }

            void clear( void )
            {
                if (this->_size == 0)
                    return ;
                this->_myTab = this->_tab.allocate(0);
                this->_size = 0;
                return ;
            }

            size_t max_size() const
            {
                return this->_tab.max_size();
            }

        private:
            std::allocator<T>    _tab;
            T                    *_myTab;
            size_t                 _size;
    };
}