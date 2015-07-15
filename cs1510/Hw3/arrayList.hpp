//Ryan Andrews
//Section B
/////////////

#include "arraylist.h"
using namespace std;

template <typename T>
ArrayList<T>::~ArrayList()
{
  m_size = 0;
  m_max = 0;
  //Deallocate DATA
}
template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs)
{
  T* tmp;

  m_size = rhs.m_size;
  m_max = rhs.m_max;
  
  tmp = new T[m_size];
  
  for (int i = 0; i < m_size; i++)
    tmp[i] = rhs.m_data[i];
  
  delete [] m_data;
  
  m_data = tmp;
  
  return *this;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
{
  T* tmp;

  m_size = cpy.m_size;
  m_max = cpy.m_max;
  
  tmp = new T[m_size];
  
  for (int i = 0; i < m_size; i++)
    tmp[i] = cpy.m_data[i];
  
  delete [] m_data;
  
  m_data = tmp;
}

template <typename T>
int ArrayList<T>::size()const
{
  return m_size;
}

template <typename T>
const T& ArrayList<T>::first()const
{
  if (m_size > 0)
    return m_data[0];
  else
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST!!.first()" << endl;
    return m_errobj;
  }
}

template <typename T>
T& ArrayList<T>::operator[](int i)
{
  T* Ref;
  if (i <= m_size && m_size > 0)
  {
    Ref = &m_data[i];
    return *Ref;
  }
  else
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST!!.[]" << endl;
    return m_errobj;
  }
}

template <typename T>
const T& ArrayList<T>::operator[](int i) const
{
  if (i <= m_size && m_size > 0)
    return m_data[i];
  else
  {
    cout << "!-- ERROR : PANIC in ARRAYLIST!!.[]" << endl;
    return m_errobj;
  }
}

template <typename T>
int ArrayList<T>::find(const T& x)
{
  int Pos = -1;
  if (m_size > 0)
  {
    for (int k = 0; k < m_size; k++)
    {
      if (m_data[k] == x && Pos < 0)
        Pos = k;
    }
  }
  return Pos;
}

template <typename T>
void ArrayList<T>::clear()
{
  m_size = 0;
  m_max = 0;
  delete [] m_data;
  m_data = NULL;
}

template <typename T>
void ArrayList<T>::insert_back(const T& x)
{
  if (m_size >= m_max && m_max > 0)
  {
    T* tmp;
    tmp = new T[m_max*2];
    for (int i = 0; i < m_max; i++)
      tmp[i] = m_data[i];
    m_max = m_max*2;
    delete []m_data;
    m_data = tmp;
  }
  if (m_max == 0)
  {
    m_max = 1;
    m_data = new T[m_max];
  }
  m_data[m_size] = x;
  m_size++;
}

template <typename T>
void ArrayList<T>::insert(const T& x, int i)
{
  if (m_size >= m_max)
  {
    T* tmp;
    tmp = new T[m_max*2];
    for (int i = 0; i < m_max; i++)
      tmp[i] = m_data[i];
    m_max *= 2;
    delete []m_data;
    m_data = tmp;
  }
  
  for (int k = m_size; k > i; k--)
    m_data[k] = m_data[k-1];
  m_data[i] = x;
  
  m_size++;
}

template <typename T>
void ArrayList<T>::remove(int i)
{
  if (i >= 0 && i < m_size && m_size > 0)
  {
    for (int k = i; k < m_size-1; k++)
      m_data[k] = m_data[k+1];
    m_size--;
  }
  else
    cout << "!-- ERROR : PANIC in ARRAYLIST!!.remove()" << endl;
  if (m_size < m_max/4)
  {
    T* tmp;
    tmp = new T[m_max/2];
    for (int j = 0; j < m_size; j++)
      tmp[j] = m_data[j];
    m_max /= 2;
    delete []m_data;
    m_data = tmp;
  }
}

template <typename T>
void ArrayList<T>::swap(int i, int k)
{
  if (m_size > 0 && i >= 0 && i < m_size && k >= 0 && k < m_size)
  {
    T tmp = m_data[i];
    m_data[i] = m_data[k];
    m_data[k] = tmp;
  }
  else
    cout << "!-- ERROR : PANIC in ARRAYLIST!!.swap()" << endl;
}

template <typename T>
void ArrayList<T>::append(const ArrayList<T>& alist)
{
  if (m_size + alist.m_size < m_max)
  {
    for (int i = 0; i < alist.m_size; i++)
      m_data[i+m_size] = alist.m_data[i];
    m_size += alist.m_size;
  }
  else
  {
    T* tmp;
    tmp = new T[(m_size+alist.m_size)*2];
    
    for (int i = 0; i < m_size; i++)
      tmp[i] = m_data[i];
    for (int i = 0; i < alist.m_size; i++)
      tmp[i+m_size] = alist.m_data[i];
    
    m_max = (m_size+alist.m_size)*2;
    m_size = m_size+alist.m_size;
    
    delete []m_data;
    m_data = tmp;
  }
}

template <typename T>
void ArrayList<T>::purge()
{
  T* tmp;
  int NewSize = 0;
  bool found = false;
  tmp = new T[m_max];
  
  for (int i = 0; i < m_size; i++)
  {
    found = false;
    for (int j = 0; j < NewSize; j++)
    {
      if (tmp[j] == m_data[i])
        found = true;
    }
    if (!found)
    {
      tmp[NewSize] = m_data[i];
      NewSize++;
    }
  }
  
  delete []m_data;
  m_data = tmp;
  m_size = NewSize;
}