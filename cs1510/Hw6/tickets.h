//Ryan Andrews
//Section B

#ifndef TICKETS_H
#define TICKETS_H

#include <iostream>
#include "abstractqueue.h"
#include "Person.h"
using namespace std;

template <typename T>
class Queue : public AbstractQueue<T>
{
  public:
    T data;
    Queue* next;
    int Size;
    T Fake;
    
    Queue():next(NULL), Size(0){};
    ////////////////////////////////////
    bool isEmpty() const
    {
      if (next == NULL)
        return true;
      else
        return false;
    }
    ////////////////////////////////////
    const T& front() const throw(Oops)
    {
      Oops ErrorMsg("There is no one in line!");
      try
      {
        if (isEmpty())
          throw (ErrorMsg);
        return next->next->data;
      }
      catch (Oops E)
      {
        cout << E.m_errormsg;
        return data;
      }
    }
    T& front() throw(Oops)
    {
      Oops ErrorMsg("There is no one in line!");
      try
      {
        if (isEmpty())
          throw (ErrorMsg);
        return next->next->data;
      }
      catch (Oops E)
      {
        cout << E.m_errormsg;
        return data;
      }
    }
    ////////////////////////////////////
    void enqueue(const T& x)
    {
      Queue<T>* tmp;
      tmp = new Queue<T>();
      tmp->data = x;
      
      if (next != NULL)
      {
        tmp->next = next->next;
        next->next = tmp;
        next = tmp;
      }
      else
      {
        tmp->next = tmp;
        next = tmp;
      }
      Size += 1;
    }
    ////////////////////////////////////
    void dequeue()
    {
      if (next != NULL)
      {
        Queue* tmp;
        tmp = new Queue;
        tmp->next = next->next;
        next->next = tmp->next->next;
        delete tmp->next;
        if (next == tmp->next)
          next = NULL;
        delete tmp;
      }
      if (Size > 0)
        Size -= 1;
    }
    ////////////////////////////////////
    void clear()
    {
      while (!isEmpty())
        dequeue();
    }
};

#endif