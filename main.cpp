#include "vector.hpp"
#include "utils/make_pair.hpp"
#include <vector>

int main()
{
    ft::vector<int> test(10, 0);
    ft::vector<int>::iterator it = test.begin();
    ft::vector<int>::iterator ite = test.end();
    ft::vector<int> test1(it, ite);
    

    return 1;
}