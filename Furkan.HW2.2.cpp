#include <iostream>
#include "HeaderFiles/LinkedList.h"
#include "HeaderFiles/LinkedListQueue.h"

using namespace std;
/////////////////////////////////////////////////////////////////////////////////// Store class
class Store
{
private:
  string name;
  Queue<string> Playlist;

public:
  Store() {} // Default Constructor

  ~Store() {} // Default Destructor

  void setname(string);
  void add(string);
  void Listed();

  string getname();

  bool operator==(const Store &Show)
  {
    return name == Show.name;
  }
};

Store one; // Global object to fix 'song lister' bug

int main()
{ ////// Main part
  LinkedList<Store> Object;

  string name[21];
  string song;
  string func;

  string regpeople[21];

  cout << "Welcome to the music app " << endl;
  cout << "Press C or c for new character" << endl;
  cout << "Press S or s to add music to the person" << endl;
  cout << "Press E or e to delete music" << endl;
  cout << "Press L or l to list the songs belonging to the person" << endl;
  cout << "Press N or n to list all contacts" << endl;
  cout << "Press M or m to list all songs" << endl;
  cout << "Press E or e to exit" << endl;

  int i = 0;
  int j = 0;

top: // goto statement to get out of loop
  cin >> func;

  while (func != "e" || func != "E")
  {

    if (func == "c" || func == "C")
    { // An algorithm to create new person

      cin >> name[i];
      one.setname(name[i]);
      regpeople[i] = name[i];
      j++;
      if (Object.search(one))
      {
        cout << "Attention: Only one person with a given name can exist in storage" << endl;
        goto top;
      }
      else
        Object.insertFirst(one);
      goto top;
    }

    if (func == "s" || func == "S")
    { // An algorithm to set new song to person
      cin >> name[i] >> song;
      one.setname(name[i]);

      if (Object.search(one))
      {
        Object.search(one)->data.add(song);
        goto top;
      }
      else
        cout << "Attention: Consider the case where " << one.getname() << " has not been created before" << endl;
      goto top;
    }

    if (func == "l" || func == "L")
    { // An algorithm to list the songs
      cin >> name[i];
      one.setname(name[i]);

      if (Object.search(one))
      {
        Object.search(one)->data.Listed();
        goto top;
      }
      else
        cout << "Attention: Consider the case where no songs have been assigned to the person" << one.getname() << endl;
      goto top;
    }

    if (func == "n" || func == "N")
    {
    }

    if (func == "m" || func == "M")
    {
      for (j = 0; j < i; j++)
        cout << regpeople[i - 1];
    }

    if (func == "d" || func == "D")
    {
    }
    i++;
  }

  return 0;
}
////////////////////////////////////////////////////////////////////// end of the main
void Store::setname(string _name)
{
  name = _name;
}

void Store::add(string _song)
{
  Playlist.add(_song);
}

void Store::Listed()
{
  Queue<string> Copy = Playlist;
  if (!Copy.isEmpty())
  {
    for (int i = 0; i < Playlist.size(); i++)
    {
      cout << Copy.remove() << endl;
    }
  }
  else
    cout << "Attention: Consider the case where no songs have been assigned to the person " << one.getname() << endl;
}

string Store::getname()
{
  return name;
}
