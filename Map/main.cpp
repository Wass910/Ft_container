#include <map>
#include "map.hpp"
#include <iostream>

int	main()
{
    std::map<std::string, int> trezor;
    std::map<std::string, int> trezor_insert;
    trezor_insert["ok"] = 10;
    trezor_insert["b"] = 100;
    trezor["z"] = 15;
    trezor["e"] = 15;
    trezor["c"] = 18;
    trezor["u"] = 15;
    trezor["x"] = 15;
    trezor["c"] = 10;
    trezor["o"] = 15;
    trezor["a"] = 15;
    trezor["b"] = 10;
    trezor["a"] = 15;
    trezor["b"] = 10;
    std::cout <<  trezor["10"] << std::endl;
    trezor_insert.insert(trezor_insert.begin(), std::pair<std::string, int>("y", 100));
    std::map<std::string, int>::iterator it = trezor_insert.begin();
    std::map<std::string, int>::iterator ite = trezor_insert.end();
    while (it != ite)
    {    
        std::cout <<  it->first << " and " << it->second << std::endl;
        it++;
    }
    trezor.clear();
    //std::cout << "find test = " << trezor.find("10")->second << std::endl;
    std::cout << "---------------------our--------------------\n";
    ft::map<std::string, int> trezor1;
    ft::map<std::string, int> trezor1_insert;
    trezor1_insert["ok"] = 10;
    trezor1_insert["b"] = 100;
    trezor1["z"] = 15;
    trezor1["e"] = 15;
    trezor1["c"] = 10;
    trezor1["u"] = 15;
    trezor1["x"] = 15;
    trezor1["c"] = 10;
    trezor1["o"] = 15;
    trezor1["a"] = 15;
    trezor1["b"] = 10;
    std::cout <<  trezor1["10"] << std::endl;
    trezor1_insert.insert(++trezor1_insert.begin(),ft::pair<std::string, int>("y", 100) );
    ft::map<std::string, int>::iterator it1 = trezor1_insert.begin();
    ft::map<std::string, int>::iterator ite1 = trezor1_insert.end();

    while (it1 != ite1)
    {   
        std::cout <<  it1->first << " and " << it1->second << std::endl;
        it1++;
    } 
   // trezor1.display_map();
    return 0;
}