#include "vector.hpp"
#include <vector>

int main()
{
    ft::vector<int> test;
    ft::vector<int> test3;

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
	ft::vector_const_iterator<int> selec1 = test.cbegin();
	ft::vector_const_iterator<int> selec2 = test.cbegin();
	selec2 += 3;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        it++;
    }
    it = test.begin();
    it++;
    it++;
    it++;
	it++;
    std::cout << "-----------------------------" << std::endl;
    test.insert(it, selec1, selec2);
    ite = test.end();
	it = test.begin();
    while (it != ite)
    {
        std::cout << *it << std::endl;
        it++;
    }
    test3.swap(test);
    ite = test3.end();
	it = test3.begin();
    std::cout << "-----------------------------" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        it++;
    }
    std::cout << "-----------------------------" << std::endl;
    ite = test.end();
	it = test.begin();
    while (it != ite)
    {
        std::cout << *it << std::endl;
        it++;
    }
    std::cout << "------------REAL VECTOR-----------------" << std::endl;
    std::vector<int> test1;
    std::vector<int> test2;

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
    std::vector<int>::const_iterator select1 = test1.cbegin();
	std::vector<int>::const_iterator select2 = test1.cbegin();
	select2 += 3;

    while (it3 != ite3)
    {
        std::cout << *it3 << std::endl;
        it3++;
    }
    it3 = test1.begin();
    it3++;
    it3++;
    it3++;
	it3++;
    std::cout << "-----------------------------" << std::endl;
    test1.insert(it3, select1, select2);
    ite3 = test1.end();
	it3 = test1.begin();
    while (it3 != ite3)
    {
        std::cout << *it3 << std::endl;
        it3++;
    }
    test2.swap(test1);
    ite3 = test2.end();
	it3 = test2.begin();
    std::cout << "-----------------------------" << std::endl;
    while (it3 != ite3)
    {
        std::cout << *it3 << std::endl;
        it3++;
    }
    std::cout << "-----------------------------" << std::endl;
    ite3 = test1.end();
	it3 = test1.begin();
    while (it3 != ite3)
    {
        std::cout << *it3 << std::endl;
        it3++;
    }
    return 0;
}