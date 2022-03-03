#include <iostream>

namespace ft{
    template <class T1, class T2>
    class pair{
        public:
            pair( void ) : first(), second()
            {
                return ;
            }

            pair (const T1 & a, const T2 & b) : first(a), second(b)
            {
                return ;
            }

            pair & operator=(const pair& pr)
            {
                if (pr.first)
                    this->first = pr.first;
                if (pr.second)
                    this->second = pr.second;
                return *this;
            }

            template<class U, class V>
            pair (const pair<U,V>& pr)
            {
                *this = pr;
                return ;
            }
            
            ~pair( void )
            {
                std::cout << "Pair destructor is call.\n";
                return ;
            }    

            
            friend bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
            { 
                return lhs.first==rhs.first && lhs.second==rhs.second; 
            }
            
            friend bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
            { 
                return !(lhs==rhs); 
            }
            
            friend bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
            { 
                return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); 
            }
        
            friend bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
            { 
                return !(rhs<lhs); 
            }
            
            friend bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
            { 
                return rhs<lhs; 
            }

            friend bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
            { 
                return !(lhs<rhs); 
            }

            T1 first;
            T2 second;
};
}