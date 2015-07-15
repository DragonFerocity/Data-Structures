//Ryan Andrews
//CS 1510   Section B

#include "heist.h"
#include "person.h"
#include "Arena.h"
using namespace std;

int main()
{
  Arena<char> Map;
  int Wid = 1;
  int Hei = 1;
  //int x;
  int NumArenas = 0;
  Queue< Arena<char> > Blueprint;
  Person Bender;
  
  while (Wid != 0 || Hei != 0)//do
  {
    cin >> Wid;
    cin >> Hei;
    //cout << " -- Width: " << Wid << " -- Height: " << Hei << endl;
    
    if (Wid != 0 && Hei != 0)
    {
      Map.create(Wid, Hei);
      //cout << "Created the arena" << endl;

      char Dummy, Val;
      for (int y = 0; y < Hei; y++)
      {
        cin.get(Dummy);
        for (int x = 0; x < Wid; x++)
        {
          cin.get(Val);
          Map.insert(x, y, Val);
        }
        //cout << endl;
      }
      //cout << "  Arena has been filled" << endl;
      
      Blueprint.enqueue(Map);
      //NumArenas++;
      //Map.print();
      Map.destroy();
      //cout << "  After pointer removal" << endl << endl;
    }
  }
  //cout << "\nAfter all the arena's have been input\n" << endl;
  NumArenas = Blueprint.Size;
  for (int i = 0; i < NumArenas; i++)
  {
    Map.clone(Blueprint.front());
    //cout << "Cloned the blueprint into a new Map " << endl;
    Bender.SetStart(Map);
    //cout << "Set Bender's start postion to (" << Bender.Startx << ", " << Bender.Starty << ")" << endl;
    //cout << "Found the escape hatch at (" << Bender.Endx << ", " << Bender.Endy << ")" << endl;
    
    try
    {
      if (!Bender.Try(Bender.x, Bender.y, Map))
        throw (false);
    }
    catch (bool Worked)
    {
      cout << "Bender lost his mind in the maze..." << endl;
    }
    
    cout << "Map : " << i << endl;
    Map.print();
    cout << endl;
    
    //cout << "Arena has been output" << endl;
    Map.destroy();
    Blueprint.dequeue();
  }
  
  Blueprint.destroy();
  
  return 0;
}