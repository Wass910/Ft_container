#include <iostream>
#include <memory>
#include <exception>

namespace ft
{
    template <typename T>
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
                this->_myTab = this->_tab.allocate(this->_size + 1);
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
                this->_size--;
                this->_myTab = this->_tab.allocate(this->_size);
                for (int i = 0; i < this->_size ; i++)
                    this->_tab.construct(this->_myTab + i, tmp[i]);
                std::cout << "-------------------" << std::endl;
                for (int i = 0; i < this->_size ; i++)
                    std::cout << this->_myTab[i] << std::endl;
                std::cout << "-------------------" << std::endl; 
                return ;
            }

        private:
            std::allocator<T>    _tab;
            T                    *_myTab;
            size_t                 _size;
    };
}