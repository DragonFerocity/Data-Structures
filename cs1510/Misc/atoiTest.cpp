#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
  string s1;
  int x;
  
  cout << "\n Enter something:  ";
  cin >> s1;
  cout << atoi(s1.c_str());
  cout << endl;
  
  return 0;
}