#include <map>
#include "map.hpp"
#include <iostream>

int	main()
{
    std::map<std::string, int> trezor;
    trezor["gildas le plus bg"] = 15;
    trezor["wassim trop bg"] = 15;
    trezor["wassim trop "] = 10;
    std::map<std::string, int>::const_iterator it = trezor.cbegin();
    std::map<std::string, int>::const_iterator ite = trezor.cend();
    --ite;
    while (it != ite)
    {    
        std::cout <<  (*it < *ite) << std::endl;
        it++;
    }
    ite  =trezor.cbegin();
    trezor.max_size();
    std::cout << trezor.max_size() << std::endl;
    std::cout << "---------------------our--------------------\n";
    ft::map<std::string, int> trezor1;
    trezor1["gildas le plus bg"] = 15;
    trezor1["wassim trop bg"] = 15;
    trezor1["wassim trop "] = 10;
    ft::map<std::string, int>::const_iterator it1 = trezor1.begin();
    ft::map<std::string, int>::const_iterator ite1 = trezor1.end();
    --ite1;
    while (it1 != ite1)
    {   
        std::cout <<  it1->second << std::endl;
        it1++;
    } 
    std::cout << trezor1.max_size() << std::endl;
    trezor1.display_map();
    return 0;
}