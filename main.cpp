#include "Vector/vector.hpp"
#include "Map/map.hpp"
#include "stack/stack.hpp"
#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <string>




void test_construtor()
{
  std::cout << "test constructeur" << std::endl;
  ft::vector<int> first;                                // empty vector of ints
  ft::vector<int>  second (4,100);                       // four ints with value 100
  ft::vector<int> third (second.begin(),second.end());  // iterating through second
  ft::vector<int> fourth (third);                       // a copy of third  
  int myints[] = {16,2,77,29};
  ft::vector<int> fistdh (myints, myints + sizeof(myints) / sizeof(int) );
  std::cout << "The contents of fistdh are:";
  for (ft::vector<int>::iterator it = fistdh.begin(); it != fistdh.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}



void test_iterator()
{
 
    // begin
  {
    ft::vector<int> myvector;
    for (int i=1; i<=5; i++) myvector.push_back(i);

    std::cout << "myvector contains:";
    for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
  }

    // end
  {
    ft::vector<int> myvector;
    for (int i=1; i<=5; i++) myvector.push_back(i);

    std::cout << "myvector contains:";
    for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
  }

    // rbegin
  {
    ft::vector<int> myvector (5);  // 5 default-constructed ints

    int i=0;

    ft::vector<int>::reverse_iterator rit = myvector.rbegin();
    for (; rit!= myvector.rend(); ++rit)
      *rit = ++i;

    std::cout << "myvector contains:";
    for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
  }

    // rend
  {
    ft::vector<int> myvector (5);  // 5 default-constructed ints

    ft::vector<int>::reverse_iterator rit = myvector.rbegin();

    int i=0;
    for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
      *rit = ++i;

    std::cout << "myvector contains:";
    for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
  }

    // casting iterators
  {
    ft::vector<int> myvector;
    for (int i=1; i<=5; i++) myvector.push_back(i);

    ft::vector<int>::iterator it = myvector.begin();
    ft::vector<int>::iterator const_it = it;

    std::cout << "myvector contains:";
    for (; const_it != myvector.end(); ++const_it)
      std::cout << ' ' << *const_it;
    std::cout << '\n';
  }

}

 void test_operator()  
{
  ft::vector<int> foo (3,0);
  ft::vector<int> bar (5,0);

  bar = foo;
  foo = ft::vector<int>();

  std::cout << "Size of foo: " << int(foo.size()) << '\n';
  std::cout << "Size of bar: " << int(bar.size()) << '\n';
}

void test_size()
{
    // size
  ft::vector<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<10; i++) myints.push_back(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.insert (myints.end(),10,100);
  std::cout << "2. size: " << myints.size() << '\n';

  myints.pop_back();
  std::cout << "3. size: " << myints.size() << '\n';
}

 void max_size()
{
  ft::vector<int> myvector;

  // set some content in the vector:
  for (int i=0; i<100; i++) myvector.push_back(i);

  std::cout << "size: " << myvector.size() << "\n";
  std::cout << "capacity bg: " << myvector.capacity() << "\n";
  std::cout << "max_size: " << myvector.max_size() << "\n";

  return ;
}


void resize()
{
  ft::vector<int> myvector;

  // set some initial content:
  for (int i=1;i<10;i++) myvector.push_back(i);

  myvector.resize(5);
  myvector.resize(8,100);
  myvector.resize(12);

  std::cout << "myvector contains:";
  for (unsigned i=0;i<myvector.size();i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}

void  capacity()
{
  ft::vector<int> myvector;

  // set some content in the vector:
  for (int i=0; i<100; i++) myvector.push_back(i);

  std::cout << "size: " << (int) myvector.size() << '\n';
  std::cout << "capacity test: " << (int) myvector.capacity() << '\n';
  std::cout << "max_size: " << (int) myvector.max_size() << '\n';
}

void  empty()
{
  ft::vector<int> myvector;
  int sum (0);

  for (int i=1;i<=10;i++) myvector.push_back(i);
    std::cout << "empty = " << myvector.empty() << std::endl;

  while (!myvector.empty())
  {
     sum += myvector.back();
     myvector.pop_back();
  }
    std::cout << "empty = " << myvector.empty() << std::endl;

  std::cout << "total: " << sum << '\n';

}

void  reserve()
{
    ft::vector<int>::size_type sz;

    ft::vector<int> foo;
    sz = foo.capacity();
    std::cout << "making foo grow:\n";
    for (int i=0; i<100; ++i) {
      foo.push_back(i);
    }

    ft::vector<int> bar;
    sz = bar.capacity();
    bar.reserve(100);   // this is the only difference with foo above
    std::cout << "making bar grow:\n";
    for (int i=0; i<100; ++i) {
      bar.push_back(i);
    }
}


 void   operator_croche()
{
  ft::vector<int> myvector (10);   // 10 zero-initialized elements

  ft::vector<int>::size_type sz = myvector.size();

  // assign some values:
  for (unsigned i=0; i<sz; i++) myvector[i]=i;

  // reverse vector using operator[]:
  for (unsigned i=0; i<sz/2; i++)
  {
    int temp;
    temp = myvector[sz-1-i];
    myvector[sz-1-i]=myvector[i];
    myvector[i]=temp;
  }

  std::cout << "myvector contains:";
  for (unsigned i=0; i<sz; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}

void at()
{
    ft::vector<int> myvector (10);   // 10 zero-initialized ints

  // assign some values:
  for (unsigned i=0; i<myvector.size(); i++)
    myvector.at(i)=i;

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector.at(i);
  std::cout << '\n';
}

void  front()
{
  ft::vector<int> myvector;

  myvector.push_back(78);
  myvector.push_back(16);

  // now front equals 78, and back 16

  myvector.front() -= myvector.back();

  std::cout << "myvector.front() is now " << myvector.front() << '\n';

}

void  back()
{
  ft::vector<int> myvector;

  myvector.push_back(10);

  while (myvector.back() != 0)
  {
    myvector.push_back ( myvector.back() -1 );
  }

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size() ; i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
}

 ///////////////     MODIFIERS     ////////////////////////////////////////

int test_assign ()
{
	ft::vector<int> first;
	ft::vector<int> second;
	ft::vector<int> third;

	first.assign (7,100);						// 7 ints with a value of 100

	ft::vector<int>::iterator it = first.begin();
    ft::vector<int>::iterator ite = first.end();
    it+=1;

	second.assign (it, --ite);		// the 5 central values of first
	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);     // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';
	return (0);
}

int test_begin ()
{
	ft::vector<int> myvector;
  for (int i=1; i<=5; i++) myvector.push_back(i);

  std::cout << "myvector contains:";
  for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  return 0;
}

int push_back()
{
  ft::vector<int> myvector;
  myvector.push_back (3);
  myvector.push_back (-2);
  myvector.push_back (5);
  myvector.push_back (7);
  myvector.push_back (42);

  std::cout << "myvector stores " << int(myvector.size()) << " numbers: ";
  for (unsigned int i = 0; i < myvector.size(); i++)
      std::cout << myvector[i] << " ";
  std::cout << std::endl;
	return (0);
}

int pop_back()
{
  ft::vector<int> myvector;
  int sum (0);
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  while (!myvector.empty())
  {
    sum+=myvector.back();
    myvector.pop_back();
  }

  std::cout << "The elements of myvector add up to " << sum << '\n';
	return (0);
}

  int	insert()
{
  ft::vector<int> myvector (3,100);
  ft::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  ft::vector<int> anothervector (2,400);
  it+=2;
  myvector.insert(it,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  std::cout << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';
  return (0);
}

  int erase()
{
  ft::vector<int> myvector;

  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) myvector.push_back(i);

  // erase the 6th element
  ft::vector<int>::iterator it = myvector.begin();
  it+=5;
  myvector.erase (it);

  // erase the first 3 elements:
  it-=2;
  myvector.erase (myvector.begin(),it);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
	return (0);
}

  int swap()
{
  ft::vector<int> foo (3,100);   // three ints with a value of 100
  ft::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';
	return (0);
}

 int clear()
{
  ft::vector<int> myvector;
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  myvector.clear();
  myvector.push_back (1101);
  myvector.push_back (2202);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';
  return (0);
}

  ////////////////     SWAP (vector)         //////////////////////////////

void	print_map(std::map<char,int> &myMap)
{
for (std::map<char,int>::iterator it = myMap.begin(); it !=myMap.end(); it++)
    std::cout << it->first << " => " << it->second << '\n';
}

void	print_map(ft::map<char,int> &myMap)
{
for (ft::map<char,int>::iterator it = myMap.begin(); it !=myMap.end(); it++)
    std::cout << it->first << " => " << it->second << '\n';
}

int test_insert ()
{
  ft::map<char,int> mymap;

  mymap.insert( ft::pair<char,int>('a',100) );
  mymap.insert( ft::pair<char,int>('z',200) );

	std::cout << "first insert function version (single parameter):" << std::endl;
	print_map(mymap);
  ft::pair<ft::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( ft::pair<char,int>('z',500) );
  if (ret.second==false) 
  {
 	std::cout << "element 'z' already existed";
	std::cout << " with a value of " << ret.first->second << '\n';
  }

//   // second insert function version (with hint position):
  ft::map<char,int>::iterator it = mymap.begin();
  mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
  mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting
	std::cout << "second insert function version (with hint position):" << std::endl;
	print_map(mymap);
  // third insert function version (range insertion):
  ft::map<char,int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('c'));

//   // showing contents:
  std::cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}

int test_swap ()
{
  ft::map<char,int> foo,bar;

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  foo.swap(bar);

  std::cout << "foo contains:\n";
  for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}


int test_erase ()
{
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;

  // insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

 it=mymap.find('b');
  mymap.erase (it);                   // erasing by iterator

  mymap.erase ('c');                  // erasing by key

  it=mymap.find ('e');
  mymap.erase ( it, mymap.end() );    // erasing by range

  // show content:
  std::cout << "erase : \n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
	return 0;
}



int test_clear()
{
  ft::map<char,int> mymap;
  mymap['x']=100;
  mymap['y']=200;
  mymap['z']=300;
  std::cout << "mymap contains:\n";
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
  mymap.clear();
  mymap['a']=1101;
  mymap['b']=2202;
  std::cout << "mymap contains:\n";
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
  return 0;
}
int test_find ()
{
  ft::map<char,int> mymap;
  ft::map<char,int>::iterator it;
  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;
  it = mymap.find('b');
  if (it != mymap.end())
    mymap.erase (it);
  // print content:
  std::cout << "elements in mymap:" << '\n';
  std::cout << "a => " << mymap.find('a')->second << '\n';
  std::cout << "c => " << mymap.find('c')->second << '\n';
  std::cout << "d => " << mymap.find('d')->second << '\n';
  return 0;
}
int test_count ()
{
  ft::map<char,int> mymap;
  char c;
  mymap ['a']=101;
  mymap ['c']=202;
  mymap ['f']=303;
  for (c='a'; c<'h'; c++)
  {
    std::cout << c;
    if (mymap.count(c)>0)
      std::cout << " is an element of mymap.\n";
    else 
      std::cout << " is not an element of mymap.\n";
  }
  return 0;
}
int test_lower_bound ()
{
  ft::map<char,int> mymap;
  ft::map<char,int>::iterator itlow,itup;
 mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;
  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)
  // if (itlow == mymap.end())
  // {
  //   std::cout << "THE END" << std::endl;
  //   return 0;
  // }
  std::cout << "itlow : first = " << itlow->first << " second = " << itlow->second << std::endl;
  std::cout << "itup : first = " << itup->first << " second = " << itup->second << std::endl;
  mymap.erase(itlow,itup);        // erases [itlow,itup)
  // print content:
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
  return 0;
}
int test_equal_range ()
{
  ft::map<char,int> mymap;
  mymap['c']=60;
  mymap['d']=80;
  mymap['a']=20;
  mymap['e']=100;
  mymap['b']=40;
  ft::pair<ft::map<char,int>::iterator, ft::map<char,int>::iterator> ret;
  ret = mymap.equal_range('a');
  std::cout << "lower bound points to: ";
  std::cout << ret.first->first << " => " << ret.first->second << '\n';
  std::cout << "upper bound points to: ";
  std::cout << ret.second->first << " => " << ret.second->second << '\n';
  return 0;
}

int test_empty ()
{
  ft::map<char,int> mymap;
  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;
  while (!mymap.empty())
  {
    std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    mymap.erase(mymap.begin());
  }
  return 0;
}
int test_operator_map ()
{
  ft::map<char,int> first;
  ft::map<char,int> second;
  first['x']=8;
  first['y']=16;
  first['z']=32;
  std::cout << "first:" << std::endl;
  print_map(first);
  second=first;                // second now contains 3 ints
  first = ft::map<char,int>(); // and first is now empty
  std::cout << "second:" << std::endl;
   print_map(first);
  std::cout << "Size of first: " << first.size() << '\n';
  std::cout << "Size of second: " << second.size() << '\n';
  return 0;
}
bool fncomp (char lhs, char rhs) {return lhs<rhs;}
struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};
int test_constructeur()
{
  ft::map<char,int> first;
  first['a']=10;
  first['b']=30;
  first['c']=50;
  first['d']=70;
  ft::map<char,int> second (first.begin(),first.end());
  ft::map<char, int> test;
std::cout << "first:" << std::endl;
	print_map(first);
  ft::map<char,int> third (test);
  ft::map<char,int,classcomp> fourth;                 // class as Compare
  bool(*fn_pt)(char,char) = fncomp;
  ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
  return 0;
}
 int test_begin_map ()
{
  ft::map<char,int> mymap;
  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;
  // show content:
  for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
  return 0;
}
int test_rbegin_map()
{
  ft::map<char,int> mymap;
  mymap['x'] = 100;
  mymap['y'] = 200;
  mymap['z'] = 300;
  // show content:
//   ft::map<char,int>::reverse_iterator rit = mymap.rbegin();
  ft::map<char,int>::reverse_iterator rit ;
  for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
    std::cout << rit->first << " => " << rit->second << '\n';
  return 0;
}
int test_size_map ()
{
  ft::map<char,int> mymap;
  mymap['a']=101;
  mymap['b']=202;
  mymap['c']=302;
  std::cout << "mymap.size() is " << mymap.size() << '\n';
  return 0;
}
int test_max ()
{
  int i;
  ft::map<int,int> mymap;
  if (mymap.max_size()>1000)
  {
    for (i=0; i<1000; i++) mymap[i]=0;
    std::cout << "The map contains 1000 elements.\n";
  }
  else std::cout << "The map could not hold 1000 elements.\n";
  return 0;
}
int test_operator_croche()
{
  ft::map<char,std::string> mymap;
  mymap['a']="an element";
  mymap['b']="another element";
  mymap['c'] = mymap['b'];
  std::cout << "mymap['a'] is " << mymap['a'] << '\n';
  std::cout << "mymap['b'] is " << mymap['b'] << '\n';
  std::cout << "mymap['c'] is " << mymap['c'] << '\n';
  std::cout << "mymap['d'] is " << mymap['d'] << '\n';
  std::cout << "mymap now contains " << mymap.size() << " elements.\n";
  return 0;
}
int test_key_comp ()
{
  ft::map<char,int> mymap;
  ft::map<char,int>::key_compare mycomp = mymap.key_comp();
  mymap['a']=100;
  mymap['b']=200;
  mymap['c']=300;
  std::cout << "mymap contains:\n";
  char highest = mymap.rbegin()->first;     // key value of last element
  ft::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mycomp((*it++).first, highest) );
  std::cout << '\n';
  return 0;
}
int test_value ()
{
  ft::map<char,int> mymap;
  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;
  std::cout << "mymap contains:\n";
ft::pair<char,int> highest = *mymap.rbegin();          // last element
  ft::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, highest) );
  return 0;
}
int test_pair () 
{
  ft::pair <int,int> foo;
  ft::pair <int,int> bar;
  foo = ft::make_pair(10,20);
  bar = ft::make_pair (10,45); // ok: implicit conversion from ft::pair<double,char>
  std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
  std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
  return 0;
}

//////////////////////////////// STACK //////////////////////////////////////////

int test_stack()
{
	ft::vector<int> mydeque (3,100);          // deque with 3 elements
	ft::vector<int> myvector (2,200);        // vector with 2 elements

	ft::stack<int> first;                    // empty stack
	ft::stack<int, ft::vector<int> > second (mydeque);         // stack initialized to copy of deque

	ft::stack<int,ft::vector<int> > third;  // empty stack using vector
	ft::stack<int,ft::vector<int> > fourth (myvector);


  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of second: " << second.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';

  return 0;
}

int test_pop()
{
	ft::stack<int> mystack;

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
  ft::stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';

  return 0;
} 

int	main()
{
    std::cout << "--------------TEST-VECTOR------------------\n\n";
     test_iterator();
      test_operator();
     test_size();
     max_size();
     resize();
     capacity();
     empty();
     reserve();
     operator_croche();
     at();
     front();
     back();
	     test_assign();
	     test_begin();
     push_back();
     pop_back();
     insert();
     erase();
     swap();
     clear();
	  std::cout << "\n--------------TEST-MAP---------------------\n\n";

    test_erase();
	 test_insert();
	 test_clear();
	 test_find();
   test_count();
   test_lower_bound();
   test_equal_range();
   test_empty();
   test_operator();
   test_swap();
	 test_constructeur();
	 test_begin_map();
	 test_rbegin_map();
	 test_size ();
	 test_max();
	 test_operator_croche();
	 test_key_comp();
	 test_value();
	test_pair();

    std::cout << "\n--------------TEST-STACK-------------------\n\n";

    test_stack();
	  test_pop();
	  test_top();  
    ft::stack<char> trezor;
    ft::stack<char> trezor2(trezor);
    

    trezor.push('e');
    trezor.push('a');
    trezor2.push('e');
    trezor2.push('z');
    std::cout << std::boolalpha << (trezor > trezor2) << std::endl;

    std::cout << "ours test \n";

    ft::stack<char> trezor3;
    ft::stack<char> trezor4(trezor3);
    

    trezor3.push('e');
    trezor3.push('a');
    trezor4.push('e');
    trezor4.push('z');
    std::cout << std::boolalpha << (trezor3 > trezor4) << std::endl;

	return 0;
}