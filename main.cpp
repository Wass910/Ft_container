#include "vector.hpp"
#include "utils/make_pair.hpp"
#include <vector>

int main()
{
    ft::pair<int, int> P1(10, 100);
    ft::pair<int, int> P3;
    //P1.first++;
    //P3.second++;
    P3 = ft::make_pair<int , char>(10, 'c');
    std::cout << P3.first << std::endl;
    std::cout << P3.second << std::endl;

    std::pair<int, int> P2(10, 100);
    std::pair<int, int> P4;
    //P2.first++;
    //P4.second++;
    P4 = std::make_pair<int , char>(10, 50);
    std::cout << P4.first << std::endl;
    std::cout << P4.second << std::endl;
    return 1;
}