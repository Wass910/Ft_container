#include "vector.hpp"
#include <vector>

int main()
{
    ft::vector<char> test;
    test.push_back('B');
    test.push_back('A');
    test.push_back('C');
    
    ft::vector<char> cop;
    cop.push_back('B');
    cop.push_back('C');
    cop.push_back('A');
    /* std::vector<char>::iterator    it = cop.begin();
    std::vector<char>::iterator    ite = cop.end();
    std::vector<char>::iterator    its = cop.end();
    its--;
    while ( it != ite)
    {
        std::cout << (*it ) << std::endl;
        it++;
    } */
    std::cout<< std::boolalpha << (test == cop) << std::endl;
    std::vector<char> test1;
    test1.push_back('B');
    test1.push_back('C');
    test1.push_back('A');

    std::vector<char> cop1;
    cop1.push_back('B');
    cop1.push_back('A');
    cop1.push_back('C');
    /* std::vector<char>::iterator    it = cop.begin();
    std::vector<char>::iterator    ite = cop.end();
    std::vector<char>::iterator    its = cop.end();
    its--;
    while ( it != ite)
    {
        std::cout << (*it ) << std::endl;
        it++;
    } */
    std::cout << std::boolalpha << (test1 == cop1) << std::endl;

    return 0;
}