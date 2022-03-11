#include <map>
#include "map.hpp"
#include <iostream>

int	main()
{
    std::map<std::string, int> trezor;
    trezor["a"] = 15;
    trezor["b"] = 0;
    trezor["c"] = 10;
    trezor["d"] = 10;
    trezor["e"] = 10;
    trezor["f"] = 10;
    trezor["g"] = 10;
    trezor["h"] = 10;
    trezor["w"] = 10;
    std::map<std::string, int>::iterator it = trezor.begin();
    std::map<std::string, int>::iterator ite = trezor.end();
    while (it != ite)
    {    
        std::cout <<  &ite << std::endl;
        it++;
    }
    std::cout << "---------------------our--------------------\n";
    ft::map<std::string, int> trezor1;
    trezor1["gildas le plus bg"] = 15;
    
    trezor1["wassim trop bg"] = 15;
    
    trezor1["wassim trop "] = 10;
    ft::map<std::string, int>::iterator it1 = trezor1.begin();
    
    ft::map<std::string, int>::iterator ite1 = trezor1.end();
    while (it1 != ite1)
    {   
        std::cout <<  it1.first << std::endl;
        it1++;
    } 
    return 0;
}