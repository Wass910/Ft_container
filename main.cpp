#include "vector.hpp"
#include "utils.hpp"
#include <vector>

int main()
{
    ft::pair<int, std::string> P1(10, "salut bg");
    std::cout << P1.second << std::endl;
    ft::pair<int, std::string> P3;
    std::cout << P3.first << std::endl;

    std::pair<int, std::string> P2;
    std::cout << P2.first << std::endl;
    return 1;
}