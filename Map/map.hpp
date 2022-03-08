#ifndef MAP_HPP
# define MAP_HPP


#include <iostream>
#include <memory>
#include <exception>
#include <iterator>

namespace ft
{

    template < class Key,                          //map::key_type
	class T,                                       // map::mapped_type
	class Compare = std::less<Key>,                     // map::key_compare
	class Alloc = std::allocator<std::pair<const Key,T> > >    // map::allocator_type
    class map{
        public:
            map( void ) 
            {
                std::cout << "Constructor is called." <<std::endl;
                return ;
            }

            ~map( void ) 
            {
                std::cout << "Destructor is called." <<std::endl;
                return ;
            }


        private:
            struct _map_node{
                Key _key;
                T   _value;
            };
    };
}

#endif //MAP_HPP

//