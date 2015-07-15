#include "Stuff.h"
#include <iostream>
using namespace std;

int main()
{
  ds_list<int> TestList(3);
  
  //TestList.add(6);
  //TestList.add(8);
  cout << TestList.size();
  
  return 0;
}