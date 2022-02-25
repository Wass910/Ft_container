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
    ft::vector_iterator<int> oui1 = test.erase(it, --ite);
    std::cout << "size = "<< test.size() << std::endl;
    std::cout << "oui of mine = " << *oui1 << std::endl;
    std::cout << "-----------------------------" << std::endl;
    ft::vector_iterator<int> it2 = test.begin();
    ft::vector_iterator<int> ite2 = test.end();

    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        it2++;
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
    std::vector<int>::iterator oui = test1.erase(it3, --ite3);
    std::cout << "size = " << test1.size() << std::endl;
    std::cout << "oui of vector = " << *oui << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::vector<int>::iterator it1 = test1.begin();
    std::vector<int>::iterator ite1 = test1.end();

    while (it1 != ite1)
    {
        std::cout << *it1 << std::endl;
        it1++;
    }
    return 0;
}