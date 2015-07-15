//ds_list class
#ifndef STUFF_H
#define STUFF_H

template <typename T>
class ds_list
{
  private:
    T Value;
    ds_list* Next;
    /////////////////
    /*void resize(const int Amt)
    {
      T* NewData;
      NewData = new T[size+Amt];
      
      for (int i = 0; i < size; i++)
        NewData[i] = Data[i];
      
      size++;
    }*/
    /////////////////
  public:
    ds_list (const T Val): Value(Val)
    {
      Next = new ds_list;
      Next->Next = 0;
    };
    /////////////////
    /*void add(T Val)
    {
      int* Current = this->Next;
      while (Current != 0)
        Current = Current->Next;
      Current = new ds_list;
      Current->Value = Val;
      Current->Next = new ds_list;
      Current->Next->Next = 0;
    }*/
    /////////////////
    int size() const
    {
      int Size = 0;
      const ds_list* Current = this;
      
      while (Current->Next != 0)
      {
        Current = Current->Next;
        Size++;
      }
      return Size;
    }
};

#endif