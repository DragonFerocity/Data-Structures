//Ryan Andrews  Section: B
//////////////////////////

#include "intbox.h"
using namespace std;

IntBox::IntBox(int s, int a)
{
  if (s > 0)
  {
    m_ints = new int [s];
    m_boxsize = s;
    
    for (int i = 0; i < s; i++)
      m_ints[i] = a;
  }
}

IntBox::~IntBox()
{
  delete [] IntBox::m_ints;
}

const IntBox& IntBox::operator= (const IntBox& rhs)
{
  int* tmp;
  m_boxsize = rhs.m_boxsize;
  tmp = new int[m_boxsize];
  for (int i = 0; i < m_boxsize; i++)
    tmp[i] = rhs.m_ints[i];
  
  delete [] m_ints;
  
  m_ints = tmp;
  
  return *this;
}

IntBox::IntBox (const IntBox& rhs)
{
  int* tmp;
  m_boxsize = rhs.m_boxsize;
  tmp = new int[m_boxsize];
  
  for (int i = 0; i < m_boxsize; i++)
    tmp[i] = rhs.m_ints[i];
  
  //delete [] m_ints;
  
  m_ints = tmp;
}

void IntBox::set(int i, int x)
{
  if (i > 0 && i < m_boxsize)
  {
    m_ints[i] = x;
  }
}

std::ostream& operator<<(std::ostream& out, const IntBox& box)
{
  out << "[ ";
  for (int i = 0; i < box.m_boxsize; i++)
  {
    out << box.m_ints[i] << ", ";
  }
  out << "]";
  
  return out;
}