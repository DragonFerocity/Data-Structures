//Ryan Andrews
//CS 1510   Section: B

#ifndef ROBOTCALC_H
#define ROBOTCALC_H

#include <iostream>
#include "abstractstack.h"
using namespace std;

template <class T> 
class Stack : public AbstractStack<T>
{
  public:
    T data;
    Stack* next;
////////////////////////////////////////////
    Stack():next(NULL){};
////////////////////////////////////////////
    bool isEmpty() const
    {
      if (next == NULL)
        return true;
      else
        return false;
    }
////////////////////////////////////////////
    const T& top() const throw(Oops)
    {
      Oops Error("The stack is empty!");
      
      try
      {
        if (isEmpty())
          throw (Error);
        return data;
      }
      catch (Oops E)
      {
        cout << E.m_errormsg;
      }
    }
////////////////////////////////////////////
    void push(const T & x)
    {
      Stack* tmp;
      tmp = new Stack;
      tmp->data = data;
      tmp->next = next;
    
      data = x;
      next = tmp;
    }
////////////////////////////////////////////
    void pop()
    {
      Stack* tmp = next;
      
      if (tmp != NULL)
      {
        data = tmp->data;
        next = tmp->next;
      }

      delete tmp;
      
      //return Val;
    }
////////////////////////////////////////////
    void clear()
    {
      while (!isEmpty())
        pop();
    }
  private:
};

template <typename T>
void Add(Stack<T> & Math)
{
  int x = Math.top();
  Math.pop();
  int y = Math.top();
  Math.pop();
  
  const int Sum = x+y;
  
  Math.push(Sum);
}

template <typename T>
void Minus(Stack<T> & Math)
{
  int x = Math.top();
  Math.pop();
  int y = Math.top();
  Math.pop();
  
  const int Diff = x-y;
  
  Math.push(Diff);
}

template <typename T>
void Multiply(Stack<T> & Math)
{
  int x = Math.top();
  Math.pop();
  int y = Math.top();
  Math.pop();
  
  const int Prod = x*y;
  
  Math.push(Prod);
}

template <typename T>
void Divide(Stack<T> & Math)
{
  int x = Math.top();
  Math.pop();
  int y = Math.top();
  Math.pop();
  
  const int Quo = y/x;
  
  Math.push(Quo);
}

template <typename T>
void Remainder(Stack<T> & Math)
{
  int x = Math.top();
  Math.pop();
  int y = Math.top();
  Math.pop();
  
  const int Rem = x%y;
  
  Math.push(Rem);
}

template <typename T>
void Negate(Stack<T> & Math)
{
  int x = Math.top();
  Math.pop();
  
  Math.push(-x);
}

template <typename T>
void Sum(Stack<T> & Math)
{
  int Sum = 0;
  while (!Math.isEmpty())
  {
    Sum += Math.top();
    Math.pop();
  }
  
  Math.push(Sum);
}

template <typename T>
void Product(Stack<T> & Math)
{
  int Prod = 1;
  while (!Math.isEmpty())
  {
    Prod *= Math.top();
    Math.pop();
  }
  
  Math.push(Prod);
}

template <typename T>
void Print(Stack<T> & Math)
{
  Stack<T> *Run = &Math;
  
  cout << "[ ";
  while (Run->next != NULL)
  {
    cout << Run->data << ", ";
    Run = Run->next;
  }
  cout << "\b\b ]";
}
  

#endif