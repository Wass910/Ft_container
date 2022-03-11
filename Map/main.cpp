#include <map>
#include "map.hpp"
#include <iostream>

int	main()
{
    std::map<std::string, int> trezor;
    trezor["a"] = 15;
    trezor["b"] = 15;
    trezor["c"] = 10;
	std::map<std::string, int> seeker;
	seeker["d"] = 1;
	seeker["e"] = 2;
	std::map<std::string, int>::iterator it = trezor.begin();
    std::map<std::string, int>::iterator ite = trezor.end();
    while (it != ite)
    {    
        std::cout << "before swap: " << it->second << std::endl;
        it++;
    }
    seeker.swap(trezor);
	it = trezor.begin();
    ite = trezor.end();
    while (it != ite)
    {    
        std::cout << "after swap: " << it->second << std::endl;
        it++;
    }

    std::cout << "---------------------our--------------------\n";

    ft::map<std::string, int> trezor1;
    trezor1["a"] = 15;
    trezor1["b"] = 15;
    trezor1["c"] = 10;
	ft::map<std::string, int> seeker1;
    seeker1["d"] = 1;
    seeker1["e"] = 2;
    ft::map<std::string, int>::const_iterator it1 = trezor1.cbegin();
    ft::map<std::string, int>::const_iterator ite1 = trezor1.cend();
    while (it1 != ite1)
    {   
        std::cout << "before swap: " << it1->second << std::endl;
        it1++;
    }
	seeker1.swap(trezor1);
	it1 = trezor1.cbegin();
    ite1 = trezor1.cend();
    while (it1 != ite1)
    {   
        std::cout <<  "after swap: " << it1->second << std::endl;
        it1++;
    }
    return 0;
}