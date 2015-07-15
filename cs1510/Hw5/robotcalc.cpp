//Ryan Andrews
//CS 1510   Section: B

#include "robotcalc.h"
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
  string s1;
  int x;
  Stack<int> Math;
  
  do
  {
    cin >> s1;
    if (s1 == "+")
      Add(Math);
    else if (s1 == "-")
      Minus(Math);
    else if (s1 == "*")
      Multiply(Math);
    else if (s1 == "/")
      Divide(Math);
    else if (s1 == "%")
      Remainder(Math);
    else if (s1 == "!")
      Negate(Math);
    else if (s1 == "sum")
      Sum(Math);
    else if (s1 == "prod")
      Product(Math);
    else if (s1 == "#")
      Print(Math);
    else if (s1 == "$")
      Math.clear();
    else
    {
      x = atoi(s1.c_str());
      Math.push(x);
    }

  } while (s1 != "@");
  
  cout << endl;
  Math.clear();
  
  return 0;
}