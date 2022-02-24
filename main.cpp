#include "vector.hpp"
#include <vector>


int main()
{
    ft::vector<int> test;
    test.push_back(98);
    test.push_back(2);
    test.push_back(3);
    test.push_back(9);
    test.push_back(10);
    test.push_back(1);
    test.push_back(202);
    test.push_back(221);
    test.push_back(323);
    test.push_back(4);
    test.push_back(5);
    test.push_back(5679);
    test.push_back(6);
    test.push_back(265);
    ft::vector_const_reverse_iterator<int>    it = test.crbegin();
    ft::vector_const_reverse_iterator<int>   ite = test.crend();

    while ( it != ite)
    {
        std::cout << *it << std::endl;
        it++;
    }
     
    return 0;
}