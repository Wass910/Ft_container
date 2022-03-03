#include <iostream>
#include <typeinfo>

namespace ft{
    template <class T1, class T2>
    class pair{
        public:
            pair( void ) 
            {
                /* if( !(typeid(std::string) == typeid(T1)) ) 
                    this->first = 0;
                if( !(typeid(std::string) == typeid(T2)) ) 
                    this->second = 0;  */
                std::cout << "Pair constructor is call.\n";
                return ;
            }

            pair (const T1 & a, const T2 & b) : first(a), second(b)
            {
                std::cout << "Pair constructor is call.\n";
                return ;
            }

            pair & operator=(const pair& pr)
            {
                std::cout << "Pair constructor assignation is call." << std::endl;
                if (pr.first)
                    this->first = pr.first;
                if (pr.second)
                    this->second = pr.second;
                return ;
            }

            template<class U, class V>
            pair (const pair<U,V>& pr)
            {
                std::cout << "Pair constructor assignation is call." << std::endl;
                *this = pr;
                return ;
            }
            
            ~pair( void )
            {
                std::cout << "Pair destructor is call.\n";
                return ;
            }    

            T1 first;
            T2 second;
};
}