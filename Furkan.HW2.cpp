#include <iostream>
#include <string>
#include "HeaderFiles/LinkedList.h"
#include "HeaderFiles/LinkedListQueue.h"

using namespace std;

class Store
{
private:
  string name;
  Queue<string> Playlist;

public:
  void setname(string _name)
  {
    name = _name;
  }
  string getname()
  {
    return name;
  }

  void add(string _song)
  {
    Playlist.add(_song);
  }

  void Listed()
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
      cout << "boş mk" << endl;
  }

  bool operator==(const Store &Show)
  {
    return name == Show.name;
  }
};
int main()
{
  LinkedList<Store> N;
  Store one;

  one.setname("Ali");
  one.add("fkdsfkds");
  one.add("dsafaf");

  cout << one.getname() << endl;
  one.Listed();

  N.insertFirst(one);
  N.front().Listed();
  
  // create fun.
  string name;
  cin >> name;
  Store two;
  two.setname(name);
  if (N.search(two))
  {
    cout << "error" << endl;
  }
  else
    N.insertFirst(two);

  // set
  string song;

  cin >> name >> song;

  two.setname(name);

  if (N.search(two))
  {
    N.search(two)->data.add(song);
  }
  else
    cout << "error" << endl;

  // list
  cin >> name;

  two.setname(name);
  if (N.search(two))
  {
    N.search(two)->data.Listed();
  }
  else
    cout << "error" << endl;
  return 0;
}
