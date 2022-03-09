#include <map>
#include "map.hpp"
#include <iostream>

int	main()
{
     //std::map<std::string, int> trezor;
    // trezor["wassim trop bg"] = 69;
    //trezor["gildas le plus bg"] = 15;
    ft::map<std::string, int> trezor;
    trezor["gildas le plus bg"] = 15;
    trezor["wassim trop bg"] = 69;
    std::cout << trezor["wassim trop bg"] << std::endl;
	return 0;
}