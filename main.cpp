#include "vector.hpp"
#include <vector>

int main()
{
    ft::vector<int> test;

    test.push_back(0);
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);
    test.push_back(6);
    test.push_back(7);
    test.push_back(8);
    ft::vector_iterator<int> it = test.begin();
    ft::vector_iterator<int> ite = test.end();

    while (it != ite)
    {
        std::cout << *it << std::endl;
        it++;
    }
    it = test.begin();
    it++;
    it++;
    it++;
    std::cout << "-----------------------------" << std::endl;
    it = test.insert(it ,  10);
    ite = test.end();
    while (it != ite)
    {
        std::cout << *it << std::endl;
        it++;
    }
    std::cout << "------------REAL VECTOR-----------------" << std::endl;
    std::vector<int> test1;

    test1.push_back(0);
    test1.push_back(1);
    test1.push_back(2);
    test1.push_back(3);
    test1.push_back(4);
    test1.push_back(5);
    test1.push_back(6);
    test1.push_back(7);
    test1.push_back(8);
    std::vector<int>::iterator it3 = test1.begin();
    std::vector<int>::iterator ite3 = test1.end();

    while (it3 != ite3)
    {
        std::cout << *it3 << std::endl;
        it3++;
    }
    it3 = test1.begin();
    it3 += 3;
    std::cout << "-----------------------------" << std::endl;
    it3 = test1.insert(it3,10);
    ite3 = test1.end();
    while (it3 != ite3)
    {
        std::cout << *it3 << std::endl;
        it3++;
    }
    return 0;
}