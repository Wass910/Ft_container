#include "vector.hpp"
#include <vector>

int main()
{
    ft::vector<int> test;
    std::vector<int> ok;
    test.size();
    test.push_back(98);
    ok.push_back(98);
    ok.push_back(8);
    test.push_back(2);
    test.push_back(3);
    std::cout << "result of at : " << test.at(2) << std::endl;
    test.size();
    test.push_back(4);
    test.push_back(5);
    std::cout << "result of front : " << test.front() << std::endl;
    std::cout << "result of back : " << test.back() << std::endl;
    test.front() -= 10;
    std::cout << "result of front : " << test.front() << std::endl;
    test.back() += test.front();
    std::cout << "result of back : " << test.back() << std::endl;
    std::cout << "result of data : " << test.data() << std::endl;
    test.pop_back();
    test.push_back(6);
    test.size();
    test.clear();
    /* test.pop_back();
    test.pop_back();
    test.pop_back();
    test.pop_back();
    test.pop_back();
    test.pop_back(); */
    test.push_back(265);
    test.size();
    return 0;
}