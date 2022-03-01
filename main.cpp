#include "vector.hpp"
#include <vector>

int main()
{
    ft::vector<int> test;
    
    test.push_back(100);
    test.push_back(100);
    test.push_back(100);
    test.push_back(100);
    test.push_back(100);
    test.pop_back();
    test.pop_back();
    test.pop_back();
    test.push_back(20);
    
    ft::vector_iterator<int> it = test.begin(); 
    ft::vector_iterator<int> ite = test.end();
    test.insert(it, it, ite);
    it = test.begin(); 
    ite = test.end();
    while (it != ite)
    {
        std::cout << *it << std::endl;
        it++;
    }
    std::cout << "------------------------------------\n";
    std::vector<int> test1;
    
    test1.push_back(100);
    test1.push_back(100);
    test1.push_back(100);
    test1.push_back(100);
    test1.push_back(100);
    test1.pop_back();
    test1.pop_back();
    test1.pop_back();
    test1.push_back(20);
    std::vector<int>::iterator ok = test1.begin();
    std::vector<int>::iterator oke = test1.end();
    test1.insert(ok, ok, oke);
    oke = test1.end();
    ok = test1.begin();
    while (ok != oke)
    {
        std::cout << "oui " << *ok << std::endl;
        ok++;
    }
    return 0;
}