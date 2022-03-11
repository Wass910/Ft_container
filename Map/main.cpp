#include <map>
#include "map.hpp"
#include <iostream>

int	main()
{
    std::map<std::string, int> trezor;
    trezor["gildas le plus bg"] = 15;
    trezor["wassim trop bg"] = 15;
    trezor["wassim trop "] = 10;
    std::map<std::string, int>::iterator it = trezor.begin();
    std::map<std::string, int>::iterator ite = trezor.begin();
    std::cout << (*it > *ite) << std::endl;
    std::cout << trezor.size() << std::endl;
    std::cout << "---------------------our--------------------\n";
    ft::map<std::string, int> trezor1;
    trezor1["gildas le plus bg"] = 15;
    trezor1["wassim trop bg"] = 15;
    trezor1["wassim trop "] = 10;
    ft::map<std::string, int>::iterator it1 = trezor1.begin();
    ft::map<std::string, int>::iterator ite1 = trezor1.begin();
    std::cout << (*it1 > *ite1) << std::endl;
    std::cout << trezor1.size() << std::endl;
	return 0;
}