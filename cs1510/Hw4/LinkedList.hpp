//Ryan Andrews
//Section B

#include "linkedlist.h"
using namespace std;

template <typename T>
const LinkedList<T>& LinkedList<T>::operator= (const LinkedList<T> & rhs)
{
  const LinkedList<T>* Runner;
  Runner = &rhs;
  
  LinkedList<T>* Current;
  Current = this;
  
  //clear();

  while (Runner->m_next != NULL)
  {
    Current->m_data = Runner->m_data;
    Current->m_next = new LinkedList<T>;
    Current = Current->m_next;
    Runner = Runner->m_next;
  }
  
  return *this;
}

template <typename T>
LinkedList<T>::LinkedList (const LinkedList<T> & rhs)
{
  const LinkedList<T>* Runner;
  Runner = &rhs;
  
  LinkedList<T>* Current;
  Current = this;
  
  //clear();

  while (Runner->m_next != NULL)
  {
    Current->m_data = Runner->m_data;
    Current->m_next = new LinkedList<T>;
    Current = Current->m_next;
    Runner = Runner->m_next;
  }
}

template <typename T>
int LinkedList<T>::size() const
{
  int Size = 0;
  const LinkedList<T>* Runner;
  Runner = this;
  
  while (Runner->m_next != NULL)
  {
    Size++;
    Runner = Runner->m_next;
  }
  
  return Size;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
  bool isEmpty = true;
  int Size = size();
  
  if (Size > 0)
    isEmpty = false;
    
  return isEmpty;
}

template <typename T>
LinkedList<T>* LinkedList<T>::getFirstPtr()
{
  LinkedList<T>* Ptr;
  
  if (size() > 0)
    Ptr = m_next;
  else
  {
    cout << "!!-- ERROR : PANIC in LINKEDLIST.getFirstPtr() - empty list" << endl;
    Ptr = NULL;
  }
  
  return Ptr;
}

template <typename T>
LinkedList<T>* LinkedList<T>::getLastPtr()
{
  LinkedList<T>* Ptr;
  LinkedList<T>* Runner;
  Runner = this;
  
  if (this->size() > 0)
  {
    while (Runner->m_next->m_next != NULL)
    {
      Runner = Runner->m_next;
    }
    Ptr = Runner;
  }
  else
  {
    Ptr = NULL;
    cout << "!!-- ERROR : PANIC in LINKEDLIST.getLastPtr() - empty list" << endl;
  }
  
  return Ptr;
}

template <typename T>
LinkedList<T>* LinkedList<T>::getAtPtr(int i)
{
  LinkedList<T>* Ptr;
  LinkedList<T>* Runner;
  Runner = this;
  
  if (size() >= i)
  {
    for (int k = 0; k < i; k++)
    {
      Runner = Runner->m_next;
    }
    Ptr = Runner;
  }
  else
  {
    Ptr = NULL;
    cout << "!!-- ERROR : PANIC in LINKEDLIST.getAtPtr() - invalid index" << endl;
  }
  
  return Ptr;
}

template <typename T>
void LinkedList<T>::clear()
{
  LinkedList<T>* Runner;
  Runner = this->m_next;
  LinkedList<T>* Remove;
  Remove = Runner;
  //cout << "0" << endl;
  while (Runner->m_next != NULL)
  {
    //cout << "a ";
    Runner = Runner->m_next;
    //cout << "b ";
    delete Remove;
    //cout << "c ";
    Remove = Runner;
    //cout << "d " << endl;
  }
  this->m_next = NULL;
}

template <typename T>
void LinkedList<T>::insert_front(const T& x)
{
  LinkedList<T>* NewPtr;
  NewPtr = new LinkedList<T>;
  if (size() == 0)
  {
    m_data = x;
    m_next = new LinkedList<T>;
    m_next->m_next = NULL;
  }
  else
  {
    NewPtr->m_data = m_data;
    NewPtr->m_next = m_next;
    m_data = x;
    m_next = NewPtr;
  }
}

template <typename T>
void LinkedList<T>::insert(const T& x, LinkedList<T>* pos)
{
  LinkedList<T>* NewPtr;
  NewPtr = new LinkedList<T>;
  
  NewPtr->m_next = pos->m_next;
  NewPtr->m_data = pos->m_data;
  
  pos->m_data = x;
  pos->m_next = NewPtr; 
}

template <typename T>
void LinkedList<T>::remove(LinkedList<T>* pos)
{
  LinkedList* tmp = pos->m_next;
  pos->m_data = tmp->m_data;
  pos->m_next = tmp->m_next;
  
  delete tmp;
}

template <typename T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const
{
  const LinkedList<T>* Current;
  Current = this;
  const LinkedList<T>* Ptr;
  Ptr = &rhs;
  
  while (Ptr->m_next != NULL)
  {
    if (Current->m_data == Ptr->m_data)
    {
      Ptr = Ptr->m_next;
      Current = Current->m_next;
    }
    else
      return false;
  }
  return true;
}

template <typename T>
LinkedList<T>* LinkedList<T>::find(const T& x)
{
  LinkedList<T>* Runner = this;
  while (Runner->m_next != NULL)
  {
    if (Runner->m_data == x)
      return Runner;
    Runner = Runner->m_next;
  }
  
  return NULL;
}

template <typename T>
void LinkedList<T>::reverse()
{
  LinkedList<T> tmp;
  tmp = *this;
  LinkedList<T>* Runner;
  Runner = this;
  
  int Size = tmp.size();
  int Num = Size;
  
  while (Num > 0)
  {
    Runner->m_data = tmp.getAtPtr(Num)->m_data;
    Num--;
    Runner = Runner->m_next;
  }
}

template <typename T>
void LinkedList<T>::append(const LinkedList<T>& xlist)
{
  const LinkedList<T>* Runner;
  Runner = &xlist;
  LinkedList<T>* Current;
  Current = getLastPtr();
  
  while (Runner->m_next != NULL)
  {    
    Current->m_next = new LinkedList<T>;
    Current = Current->m_next;
    Current->m_data = Runner->m_data;
    
    Runner = Runner->m_next;
  }
  Current->m_next = NULL;
}