#include "vector.hpp"
#include <vector>

int main()
{
    ft::vector<int> test;
    std::vector<int> ok;
    test.size();
    test.push_back(98);
    ok.push_back(98);
    ok.push_back(8);
    test.push_back(2);
    test.push_back(3);
    std::cout << "result of at : " << test.at(2) << std::endl;
    test.size();
    test.push_back(4);
    test.push_back(5);
    std::cout << "result of front : " << test.front() << std::endl;
    std::cout << "result of back : " << test.back() << std::endl;
    test.front() -= 10;
    std::cout << "result of front : " << test.front() << std::endl;
    test.back() += test.front();
    std::cout << "result of back : " << test.back() << std::endl;
    std::cout << "result of data : " << test.data() << std::endl;
    test.pop_back();
    test.push_back(6);
    test.size();
    //test.clear();
    /* test.pop_back();
    test.pop_back();
    test.pop_back();
    test.pop_back();
    test.pop_back();
    test.pop_back(); */
    test.push_back(265);
    test.size();
    std::cout << "result of max size : " << test.max_size() << std::endl;
    ft::vector_iterator<int>  it = test.begin();
    ft::vector_iterator<int>  itE = test.end();
    --itE;
    std::cout << "iterator de  0 : " << *it << std::endl;
    std::cout << "iterator de  end : " << *itE << std::endl;
    it++;
    std::cout << "iterator de  1 : " << *it << std::endl;
    std::cout << "iterator de  2 : " << *++it << std::endl;
    std::vector<int>::iterator  it2 = ok.begin();
    std::cout << "iterator de  2 : " << *it << std::endl;
    return 0;
}