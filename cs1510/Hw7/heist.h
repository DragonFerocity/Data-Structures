//Ryan Andrews
//CS 1510   Section B

#ifndef HEIST_H
#define HEIST_H

#include <iostream>
#include "Arena.h"
using namespace std;

template <typename T>
class Queue
{
  public:
    T data;
    Queue* next;
    int Size;
    
    Queue():next(NULL), Size(0){};
    
    void enqueue(const T x)
    {
      Queue<T>* tmp;
      tmp = new Queue<T>;
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
      Size++;
    }
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
        Size--;
    }
    const T & front() const
    {
      if (next != NULL)
        return next->next->data;
      else
        return data;
    }
    
    void destroy()
    {
      while (next != NULL)
        dequeue();
    }
};
///////////////////////////////////////////////////////////////////////////

#endif