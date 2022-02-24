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

            T& operator*( void ) const
            {
                return *p;
            }

            bool operator==( vector_iterator const & it ) const
            {
                if (it.p == this->p)
                    return true;
                return false;
            }

            bool operator!=( vector_iterator const & ite) const
            {
                if (this->p == ite.p)
                    return false;
                return true;
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

            bool  operator>=( vector_iterator const & src ) const
            {
                if (this->p >= src.p)
                    return true;
                return false;
            }

            bool  operator<=( vector_iterator const & src ) const
            {
                if (this->p <= src.p)
                    return true;
                return false;
            }

            bool  operator>( vector_iterator const & src ) const
            {
                if (this->p > src.p)
                    return true;
                return false;
            }

            bool    operator<( vector_iterator const & src ) const
            {
                if (this->p < src.p)
                    return true;
                return false;
            }

            vector_iterator  operator+( vector_iterator const & src )
            {
                vector_iterator temp;
                temp.p = this->p + src.p; 
                return temp;
            }

            vector_iterator  operator-( vector_iterator const & src )
            {
                vector_iterator temp;
                temp.p = this->p - src.p; 
                return temp;
            }

            vector_iterator  operator/( vector_iterator const & src )
            {
                vector_iterator temp;
                temp.p = this->p / src.p;
                return temp;
            }

            vector_iterator  operator*( vector_iterator const & src )
            {
                vector_iterator temp;
                temp.p= this->p * src.p; 
                return temp ;
            }

        private :
            T * p;
    };
}


namespace ft
{

    template <typename T>
    class vector_const_iterator : public std::iterator<std::input_iterator_tag, int>{
        public:
            vector_const_iterator(void) 
            {
                return ;
            }
            vector_const_iterator(T * x) :p(x) 
            {
                return ;
            }

            vector_const_iterator & operator=( vector_const_iterator const & src) 
            {
                this->p = src.p;
                return *this ;
            }

            vector_const_iterator(vector_const_iterator const & test) :p(test.p) 
            {
                return ;
            }

            T const & operator*( void ) const
            {
                return *p;
            }

            bool operator==( vector_const_iterator const & it ) const
            {
                if (it.p == this->p)
                    return true;
                return false;
            }

            bool operator!=( vector_const_iterator const & ite) const
            {
                if (this->p == ite.p)
                    return false;
                return true;
            }

            vector_const_iterator operator++(T) 
            {
                vector_const_iterator  temp = *this;
                ++*this;
                return temp;
            }

            vector_const_iterator& operator++(void) 
            {
                this->p++;
                return *this;
            }

            vector_const_iterator operator--(T) 
            {
                vector_const_iterator  temp = *this;
                --*this;
                return temp;
            }

            vector_const_iterator& operator--(void) 
            {
                this->p--;
                return *this;
            }

            bool  operator>=( vector_const_iterator const & src ) const
            {
                if (this->p >= src.p)
                    return true;
                return false;
            }

            bool  operator<=( vector_const_iterator const & src ) const
            {
                if (this->p <= src.p)
                    return true;
                return false;
            }

            bool  operator>( vector_const_iterator const & src ) const
            {
                if (this->p > src.p)
                    return true;
                return false;
            }

            bool    operator<( vector_const_iterator const & src ) const
            {
                if (this->p < src.p)
                    return true;
                return false;
            }

            vector_const_iterator const  operator+( vector_const_iterator const & src )
            {
                vector_const_iterator temp;
                temp.p = this->p + src.p; 
                return temp;
            }

            vector_const_iterator  const operator-( vector_const_iterator const & src )
            {
                vector_const_iterator temp;
                temp.p = this->p - src.p; 
                return temp;
            }

            vector_const_iterator const operator/( vector_const_iterator const & src )
            {
                vector_const_iterator temp;
                temp.p = this->p / src.p;
                return temp;
            }

            vector_const_iterator const operator*( vector_const_iterator const & src )
            {
                vector_const_iterator temp;
                temp.p= this->p * src.p; 
                return temp ;
            }

        private :
            T * p;
    };
}

namespace ft
{

    template <typename T>
    class vector_const_reverse_iterator : public std::iterator<std::input_iterator_tag, int>{
        public:
            vector_const_reverse_iterator(void) 
            {
                return ;
            }
            vector_const_reverse_iterator(T * x) :p(x) 
            {
                return ;
            }

            vector_const_reverse_iterator & operator=( vector_const_reverse_iterator const & src) 
            {
                this->p = src.p;
                return *this ;
            }

            vector_const_reverse_iterator(vector_const_reverse_iterator const & test) :p(test.p) 
            {
                return ;
            }

            T const & operator*( void ) const
            {
                return *p;
            }

            bool operator==( vector_const_reverse_iterator const & it ) const
            {
                if (it.p == this->p)
                    return true;
                return false;
            }

            bool operator!=( vector_const_reverse_iterator const & ite) const
            {
                if (this->p == ite.p)
                    return false;
                return true;
            }

            vector_const_reverse_iterator operator++(T) 
            {
                vector_const_reverse_iterator  temp = *this;
                ++*this;
                return temp;
            }

            vector_const_reverse_iterator& operator++(void) 
            {
                this->p--;
                return *this;
            }

            vector_const_reverse_iterator operator--(T) 
            {
                vector_const_reverse_iterator  temp = *this;
                --*this;
                return temp;
            }

            vector_const_reverse_iterator& operator--(void) 
            {
                this->p++;
                return *this;
            }

            bool  operator>=( vector_const_reverse_iterator const & src ) const
            {
                if (this->p >= src.p)
                    return true;
                return false;
            }

            bool  operator<=( vector_const_reverse_iterator const & src ) const
            {
                if (this->p <= src.p)
                    return true;
                return false;
            }

            bool  operator>( vector_const_reverse_iterator const & src ) const
            {
                if (this->p > src.p)
                    return true;
                return false;
            }

            bool    operator<( vector_const_reverse_iterator const & src ) const
            {
                if (this->p < src.p)
                    return true;
                return false;
            }

            vector_const_reverse_iterator const operator+( vector_const_reverse_iterator const & src )
            {
                vector_const_reverse_iterator temp;
                temp.p = this->p + src.p; 
                return temp;
            }

            vector_const_reverse_iterator const operator-( vector_const_reverse_iterator const & src )
            {
                vector_const_reverse_iterator temp;
                temp.p = this->p - src.p; 
                return temp;
            }

            vector_const_reverse_iterator const operator/( vector_const_reverse_iterator const & src )
            {
                vector_const_reverse_iterator temp;
                temp.p = this->p / src.p;
                return temp;
            }

            vector_const_reverse_iterator const operator*( vector_const_reverse_iterator const & src )
            {
                vector_const_reverse_iterator temp;
                temp.p= this->p * src.p; 
                return temp ;
            }

        private :
            T * p;
    };
}

namespace ft
{

    template <typename T>
    class vector_reverse_iterator : public std::iterator<std::input_iterator_tag, int>{
        public:
            vector_reverse_iterator(void) 
            {
                return ;
            }
            vector_reverse_iterator(T * x) :p(x) 
            {
                return ;
            }

            vector_reverse_iterator & operator=( vector_reverse_iterator const & src) 
            {
                this->p = src.p;
                return *this ;
            }

            vector_reverse_iterator(vector_reverse_iterator const & test) :p(test.p) 
            {
                return ;
            }

            T& operator*( void ) 
            {
                return *p;
            }

            bool operator==( vector_reverse_iterator const & it ) 
            {
                if (it.p == this->p)
                    return true;
                return false;
            }

            bool operator!=( vector_reverse_iterator const & ite) 
            {
                if (this->p == ite.p)
                    return false;
                return true;
            }

            vector_reverse_iterator operator++(T) 
            {
                vector_reverse_iterator  temp = *this;
                ++*this;
                return temp;
            }

            vector_reverse_iterator& operator++(void) 
            {
                this->p--;
                return *this;
            }

            vector_reverse_iterator operator--(T) 
            {
                vector_reverse_iterator  temp = *this;
                --*this;
                return temp;
            }

            vector_reverse_iterator& operator--(void) 
            {
                this->p++;
                return *this;
            }

            bool  operator>=( vector_reverse_iterator const & src ) const
            {
                if (this->p >= src.p)
                    return true;
                return false;
            }

            bool  operator<=( vector_reverse_iterator const & src ) const
            {
                if (this->p <= src.p)
                    return true;
                return false;
            }

            bool  operator>( vector_reverse_iterator const & src ) const
            {
                if (this->p > src.p)
                    return true;
                return false;
            }

            bool    operator<( vector_reverse_iterator const & src ) const
            {
                if (this->p < src.p)
                    return true;
                return false;
            }

            vector_reverse_iterator  operator+( vector_reverse_iterator const & src )
            {
                vector_reverse_iterator temp;
                temp.p = this->p + src.p; 
                return temp;
            }

            vector_reverse_iterator  operator-( vector_reverse_iterator const & src )
            {
                vector_reverse_iterator temp;
                temp.p = this->p - src.p; 
                return temp;
            }

            vector_reverse_iterator  operator/( vector_reverse_iterator const & src )
            {
                vector_reverse_iterator temp;
                temp.p = this->p / src.p;
                return temp;
            }

            vector_reverse_iterator  operator*( vector_reverse_iterator const & src )
            {
                vector_reverse_iterator temp;
                temp.p= this->p * src.p; 
                return temp ;
            }
        private :
            T * p;
    };
}
