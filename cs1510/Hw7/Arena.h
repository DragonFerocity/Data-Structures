//Ryan Andrews
//CS 1510   Section B

#ifndef ARENA_H
#define ARENA_H

#include <iostream>
using namespace std;

template <typename T>
class Arena
{
  public:
    int Width;
    int Height;
    T** Map;
    
    Arena() : Width(0), Height(0), Map(NULL) {}
    ///////////////////////////////////////////////
    Arena(const Arena<T> & copy)
    {
      create(copy.Width, copy.Height);
      for (int x = 0; x < Width; x++)
      {
        for (int y = 0; y < Height; y++)
          insert(x, y, copy.getVal(x, y));
      }
    }
    ///////////////////////////////////////////////
    void create(const int & W, const int & H)
    {
      Width = W;
      Height = H;
      
      Map = new T*[Width];
      for (int i = 0; i < Width; i++)
        Map[i] = new T[Height];
    }
    ///////////////////////////////////////////////
    void insert(int x, int y, T Val)
    {
      Map[x][y] = Val;
    }
    ///////////////////////////////////////////////
    const T getVal(int x, int y) const
    {
      return Map[x][y];
    }
    ///////////////////////////////////////////////
    void clone(const Arena<T> & Blueprint)
    {
      create(Blueprint.Width, Blueprint.Height);
      
      for (int x = 0; x < Width; x++)
      {
        for (int y = 0; y < Height; y++)
          insert(x, y, Blueprint.getVal(x, y));
      }
    }
    ///////////////////////////////////////////////
    void print()
    {
      for (int y = 0; y < Height; y++)
      {
        for (int x = 0; x < Width; x++)
          cout << Map[x][y];
        cout << endl;
      }
    }
    ///////////////////////////////////////////////
    void destroy()
    {
      for (int i = 0; i < Width; i++)
        delete [] Map[i];
      delete [] Map;
      
      Width = 0;
      Height = 0;
    }
    ///////////////////////////////////////////////
};

#endif