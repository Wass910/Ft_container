#include "stack.hpp"
#include <stack>
#include <vector>
#include <map>

 int test_stack()
{
	std::vector<int> mydeque (3,100);          // deque with 3 elements
	std::vector<int> myvector (2,200);        // vector with 2 elements

	std::stack<int> first;                    // empty stack
	std::stack<int, std::vector<int> > second (mydeque);         // stack initialized to copy of deque

	std::stack<int,std::vector<int> > third;  // empty stack using vector
	std::stack<int,std::vector<int> > fourth (myvector);


  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of second: " << second.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';

  return 0;
}

int test_pop()
{
	std::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';

  return 0;
}

int test_top ()
{
  std::stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';

  return 0;
} 

int	main()
{
 test_stack();
	test_pop();
	test_top();  
    std::cout << "ours test \n";
    std::stack<char> trezor;
    std::stack<char> trezor2(trezor);
    

    trezor.push('e');
    trezor2.push('e');
    trezor.push('f');
    trezor.push('l');
    trezor.push('m');
    trezor.push('c');
    trezor.push('l');
    std::cout << trezor.top() + 4 << std::endl;
    std::cout << trezor.size() << std::endl;
    std::cout << trezor2.size() << std::endl;
    trezor.pop();
    //trezor2.pop();
    std::cout << trezor.top() + 4 << std::endl;
    std::cout << trezor.size() << std::endl;
    std::cout << trezor2.size() << std::endl;
	// std::cout << "hellow" << std::endl; 
	return (0);
}