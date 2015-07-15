//Ryan Andrews      Section: 
////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  int NumGrids = 0;
  int** DataGrid = NULL;
  int Width = 0, Height = 0;
  int NumFish = 0;
  
  int PosFishCaught = 0;
  int MaxFishCaught = 0;
  
  int w = 0, h = 0;
  int MaxX, MaxY;
  
  srand(time(NULL));
  
  cin >> NumGrids;
  
  for (int i = 0; i < NumGrids; i++)
  {
    h = 0;
    w = 0;
    ////
    cin >> Width >> Height;
    ////
    DataGrid = new int*[Height];
    ////
    for (int j = 0; j < Height; j++)
      DataGrid[j] = new int[Width];
    ////
    for (int hh = 0; hh < Height; hh++)
    {
      for (int ww = 0; ww < Width; ww++)
      {
        NumFish = rand() % Width;
        DataGrid[hh][ww] = NumFish;
        cout << DataGrid[hh][ww] << " ";
      }
      cout << endl;
    }
    ////Count the number of fish
    do
    {
      for (int k = 0; k < Width; k++)
        PosFishCaught += DataGrid[h][k];
      for (int c = 0; c < Height; c++)
        PosFishCaught += DataGrid[c][w];
       
      PosFishCaught -= DataGrid[h][w];
      ////
      if (PosFishCaught > MaxFishCaught)
      {
        MaxFishCaught = PosFishCaught;
        MaxX = w;
        MaxY = h;
      }
      
      if (w < Width-1)
      {
        w++;
        PosFishCaught = 0;
      }
      else
      {
        w = 0;
        h++;
        PosFishCaught = 0;
      }
    } while (h < Height);
    
    cout << "#" << i << ": (" << MaxX << ", " << MaxY << ") " << MaxFishCaught << endl;
    MaxFishCaught = 0;
    h = 0;
    w = 0;
  }
  for (int j = 0; j < Height; j++)
    delete [] DataGrid[j];
  delete [] DataGrid;
  
  return 0;
}