//Ryan Andrews
//Section B

#include "tickets.h"
using namespace std;

int main()
{
  int NumPpl = 0;
  int PplProcessed = 0;
  
  int Time;
  string Name;
  int Tickets;
  Person NewPerson;
  int Clock = 1;
  int NextPerson;
  Person* PersonList;
  
  Queue<Person> ArrivalList;
  Queue<Person> TicketLineA;
  Queue<Person> TicketLineB;
  
  cout << "Number of people: ";
  cin >> NumPpl;
  
  PersonList = new Person[NumPpl];
  
  for (int i = 0; i < NumPpl; i++)
  {
    cin >> Time;
    cin >> Name;
    cin >> Tickets;
    PersonList[i].setATime(Time);
    PersonList[i].setName(Name);
    PersonList[i].setNumTickets(Tickets);
    
    //cout << PersonList[i].NumTickets << ":";
    PersonList[i].setPTime(PersonList[i].getNumTickets()*4);
    //cout << PersonList[i].ProcessTime << ":";
    PersonList[i].setDTime(PersonList[i].getATime()+PersonList[i].getPTime());
    ArrivalList.enqueue(PersonList[i]);
    //cout << PersonList[i].DepartureTime << endl;
  }
  cout << endl;
  //cout << ArrivalList.front().Name << endl;
  do
  {
    //cout << "1. " << endl;
    if (!ArrivalList.isEmpty())
    {
      NextPerson = ArrivalList.front().getATime();
    
      if (TicketLineA.isEmpty())
      {
        TicketLineA.enqueue(ArrivalList.front());
        Clock = ArrivalList.front().getATime();
        cout << "At time " << Clock << " " << ArrivalList.front().getName() << " joins line A." << endl;
        //cout << ArrivalList.front().NumTickets << endl;
        ArrivalList.dequeue();
      }
      else if (!TicketLineA.isEmpty() && TicketLineB.isEmpty())
      {
        TicketLineB.enqueue(ArrivalList.front());
        Clock = ArrivalList.front().getATime();
        cout << "At time " << Clock << " " << ArrivalList.front().getName() << " joins line B." << endl;
        //cout << ArrivalList.front().NumTickets << endl;
        ArrivalList.dequeue();
      }
      else if (NextPerson > TicketLineA.front().getDTime() || NextPerson > TicketLineB.front().getDTime())
      {
        //cout << "3. ";
        if (TicketLineA.front().getDTime() <= TicketLineB.front().getDTime())
        {
          Clock = TicketLineA.front().getDTime();
          cout << "At time " << Clock << " " << TicketLineA.front().getName() << " is done!" << endl;
          TicketLineA.dequeue();
          TicketLineA.front().setDTime(TicketLineA.front().getDTime()+Clock);
        }
        else if (TicketLineB.front().getDTime() < TicketLineA.front().getDTime())
        {
          Clock = TicketLineB.front().getDTime();
          cout << "At time " << Clock << " " << TicketLineB.front().getName() << " is done!" << endl;
          TicketLineB.dequeue();
          TicketLineB.front().setDTime(TicketLineB.front().getDTime()+Clock);
        }
      }
      else
      {
        //cout << "2. ";
        Clock = NextPerson;
        cout << "At time " << Clock << " " << ArrivalList.front().getName() << " joins line ";
        if (TicketLineA.Size <= TicketLineB.Size)
        {
          //cout << "2A. " << endl;
          TicketLineA.enqueue(ArrivalList.front());
          ArrivalList.front().setDTime(TicketLineA.front().getDTime()+Clock);
          cout << "A." << endl;
          //cout << ArrivalList.front().NumTickets << endl;
          PplProcessed++;
        }
        else
        {
          //cout << "2B. " << endl;
          TicketLineB.enqueue(ArrivalList.front());
          ArrivalList.front().setDTime(TicketLineB.front().getDTime()+Clock);
          cout << "B." << endl;
          //cout << ArrivalList.front().NumTickets << endl;
          PplProcessed++;
        }
        ArrivalList.dequeue();
      }
    }
    else
    {
      if (!TicketLineA.isEmpty() && !TicketLineB.isEmpty())
      {
        if (TicketLineA.front().getDTime() <= TicketLineB.front().getDTime())
        {
          Clock = TicketLineA.front().getDTime();
          cout << "At time " << Clock << " " << TicketLineA.front().getName() << " is done!" << endl;
          TicketLineA.dequeue();
        }
        else if (TicketLineB.front().getDTime() < TicketLineA.front().getDTime())
        {
          Clock = TicketLineB.front().getDTime();
          cout << "At time " << Clock << " " << TicketLineB.front().getName() << " is done!" << endl;
          TicketLineB.dequeue();
        }
      }
      else if (!TicketLineA.isEmpty() && TicketLineB.isEmpty())
      {
        Clock = TicketLineA.front().getDTime();
        cout << "At time " << Clock << " " << TicketLineA.front().getName() << " is done!" << endl;
        TicketLineA.dequeue();
      }
      else if (TicketLineA.isEmpty() && !TicketLineB.isEmpty())
      {
        Clock = TicketLineB.front().getDTime();
        cout << "At time " << Clock << " " << TicketLineB.front().getName() << " is done!" << endl;
        TicketLineA.dequeue();
      }
    }
    PplProcessed++;
  } while (PplProcessed <= NumPpl*2+3);
  
  TicketLineA.clear();
  TicketLineB.clear();
  ArrivalList.clear();
  
  delete []PersonList;
  
  return 0;
}