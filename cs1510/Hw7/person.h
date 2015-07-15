//Ryan Andrews
//CS 1510   Section B

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "Arena.h"
using namespace std;

class Person
{
  public:
    int Startx;
    int Starty;
    int x;
    int y;
    int Endx;
    int Endy;
    
    Person() : Startx(0), Starty(0), x(0), y(0), Endx(0), Endy(0) {}
    ////////////////////////////////////////////////////////////
    /*void MoveNorth(int & x, int & y, Arena<char> & Map)
    {
      //Map.insert(x, y, '.');
      y--;
      //cout << " (" << x << ", " << y << ")" << endl;
      //Map.insert(x, y, 'B');
    }
    ////////////////////////////////////////////////////////////
    void MoveEast(int & x, int & y, Arena<char> & Map)
    {
      //Map.insert(x, y, '.');
      x++;
      //cout << " (" << x << ", " << y << ")" << endl;
      //Map.insert(x, y, 'B');
    }
    ////////////////////////////////////////////////////////////
    void MoveSouth(int & x, int & y, Arena<char> & Map)
    {
      //Map.insert(x, y, '.');
      y++;
      //cout << " (" << x << ", " << y << ")" << endl;
      //Map.insert(x, y, 'B');
    }
    ////////////////////////////////////////////////////////////
    void MoveWest(int & x, int & y, Arena<char> & Map)
    {
      //Map.insert(x, y, '.');
      x--;
      //cout << " (" << x << ", " << y << ")" << endl;
      //Map.insert(x, y, 'B');
    }*/
    ////////////////////////////////////////////////////////////
    bool Valid(int x, int y, Arena<char> & Map)
    {
      //switch (Direction)
      //{
        //case 'N': 
          if (Map.getVal(x, y) != '#' && Map.getVal(x, y) != 'T' && x < Map.Width && y < Map.Height
              && Map.getVal(x, y) != '.')// 
            return true;
          else
            return false;
      //return false;
    }
    ////////////////////////////////////////////////////////////
    bool Try (int & x, int & y, Arena<char> & Map)
    {
      //cout << "Trying to find a path..." << endl;
      bool GoodStep = false;
      ////////////////////////NORTH
      if (Valid(x, y-1, Map))
      {
        y--;
        if (Map.getVal(x, y) == 'E')
          return true;
        else
        {
          Map.insert(x, y, '.');
          GoodStep = Try(x, y, Map);
          if (GoodStep)
            return true;
          else
          {
            Map.insert(x, y, ' ');
            y++;
            //return false;
          }
        }
      }
      ////////////////////////EAST
      if (Valid(x+1, y, Map))
      {
        x++;
        if (Map.getVal(x, y) == 'E')
          return true;
        else
        {
          Map.insert(x, y, '.');
          GoodStep = Try(x, y, Map);
          if (GoodStep)
            return true;
          else
          {
            Map.insert(x, y, ' ');
            x--;
            //return false;
          }
        }
      }
      ////////////////////////SOUTH
      if (Valid(x, y+1, Map))
      {
        y++;
        if (Map.getVal(x, y) == 'E')
          return true;
        else
        {
          Map.insert(x, y, '.');
          GoodStep = Try(x, y, Map);
          if (GoodStep)
            return true;
          else
          {
            Map.insert(x, y, ' ');
            y--;
            //return false;
          }
        }
      }
      ////////////////////////WEST
      if (Valid(x-1, y, Map))
      {
        x--;
        if (Map.getVal(x, y) == 'E')
          return true;
        else
        {
          Map.insert(x, y, '.');
          GoodStep = Try(x, y, Map);
          if (GoodStep)
            return true;
          else
          {
            Map.insert(x, y, ' ');
            x++;
            //return false;
          }
        }
      }
      return false;
    }
    ////////////////////////////////////////////////////////////
    void SetStart(Arena<char> & Map)
    {
      for (int k = 0; k < Map.Width; k++)
      {
        for (int j = 0; j < Map.Height; j++)
        {
          //cout << "  Finding position..." << endl;
          if (Map.getVal(k, j)  == 'B')
          {
            x = k;
            y = j;
            Startx = x;
            Starty = y;
            //cout << "   - Found Bender" << endl;
          }
          if (Map.getVal(k, j) == 'E')
          {
            Endx = k;
            Endy = j;
            //cout << "   - Found exit" << endl;
          }
        }
      }
    }
};
     
#endif     