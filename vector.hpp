#include <iostream>
#include <memory>

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

            void push_back(const T & val)
            {
                T *tmp = this->_myTab;
                this->_myTab = this->_tab.allocate(_size + 1);
                for (int i = 0; i <= this->_size - 1; i++)
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
                for (int i = 0; i <= this->_size - 1; i++)
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
            int                 _size;
    };
}