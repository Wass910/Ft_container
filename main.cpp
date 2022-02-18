#include "vector.hpp"
#include <vector>

int main()
{
    ft::vector<int> test;
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);
    test.pop_back();
    test.push_back(6);
    test.pop_back();
    test.pop_back();
    test.pop_back();
    test.pop_back();
    test.pop_back();
    test.pop_back();
    return 0;
}