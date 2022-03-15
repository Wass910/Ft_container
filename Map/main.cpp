#include <map>
#include "map.hpp"
#include <iostream>

#include <iostream>
#include <map>

int main ()
{
  std::map<char,int> mymap;
  std::map<char,int>::const_iterator itlow,itup;

  mymap['a']=20;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;

  itlow=mymap.upper_bound ('0');  // itlow points to b
    std::cout << "itlow = " << itlow->first << " => " << itlow->second << '\n';

  // print content:
  for (std::map<char,int>::const_iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

    std::cout << "--------------------------------our-------------------------------------\n";

    ft::map<char,int> mymap1;
  ft::map<char,int>::iterator itlow1,itup1;

  mymap1['a']=20;
  mymap1['c']=60;
  mymap1['d']=80;
  mymap1['e']=100;

  itlow1 = mymap1.lower_bound('0');  // itlow points to b
    std::cout << "itlow = " << itlow1->first << " => " << itlow1->second << '\n';

  // print content:
  for (ft::map<char,int>::const_iterator it=mymap1.cbegin(); it!=mymap1.cend(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
  return 0;
}