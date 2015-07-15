//Ryan Andrews
//Section B

#ifndef PERSON_H
#define PERSON_H
#include <cstring>

using namespace std;

class Person
{ 
  private:
    int ArrivalTime;
    string Name;
    int NumTickets;
    int ProcessTime;
    int DepartureTime;
    
  public:
    Person():ArrivalTime(0), Name(""), NumTickets(0), ProcessTime(0), DepartureTime(0){} //:ArrivalTime(0), NumTickets(0), Name(""), DepartureTime(0)
    
    int getATime() const
    {
      return ArrivalTime;
    }
    void setATime(int Time)
    {
      ArrivalTime = Time;
    }
    
    string getName() const
    {
      return Name;
    }
    void setName(string NewName)
    {
      Name = NewName;
    }
    
    int getNumTickets() const
    {
      return NumTickets;
    }
    void setNumTickets(int TicketNum)
    {
      NumTickets = TicketNum;
    }
    
    int getPTime() const
    {
      return ProcessTime;
    }
    void setPTime(int Time)
    {
      ProcessTime = Time;
    }
    
    int getDTime() const
    {
      return DepartureTime;
    }
    void setDTime(int Time)
    {
      DepartureTime = Time;
    }
};

#endif