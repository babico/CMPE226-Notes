#include <iostream>
#include <string>
#include "HeaderFiles/LinkedListQueue.h"
#include "HeaderFiles/LinkedList.h"

using namespace std;

class Person
{
private:
  string name;
  Queue<string> playlist;

public:
  Person(){};
  // Assigns person name
  void setName(string &n)
  {
    name = n;
  }
  // Adds item to queue
  void likeSong(string &song)
  {
    playlist.add(song);
  }

  // Creates new queue to reach middle elements
  // Starts loop then adds all elements to new playlist except removed song and assing playlist to this new playlist queue.
  void removeLike(string &song)
  {
    int songCounter = 0;
    Queue<string> updatedQueue;
    while (true)
    {
      if (playlist.isEmpty())
      {
        break;
      }
      string existedSong = playlist.remove();
      // Add all songs to new queue except removed songç
      if (existedSong != song)
      {
        updatedQueue.add(existedSong);
      }
      else
      {
        songCounter++;
      }
    }
    // Check if user has searched song or not
    if (songCounter == 0)
    {
      cout << "User '"
           << name
           << "' does not have that song." << endl;
    }
    else
    {
      cout << "User '"
           << name
           << "' removed like from song " << song << endl;
    }
    playlist = updatedQueue;
  }

  // Creates new queue to reach middle elements.
  // Start loop then prints removed queue data and pushes this removed data to new queue.
  // Assigns new queue to playlist queue.
  void print()
  {
    Queue<string> updatedQueue;
    while (true)
    {
      if (playlist.isEmpty())
        break;
      string existedSong = playlist.remove();
      cout << existedSong << endl;
      updatedQueue.add(existedSong);
    }
    playlist = updatedQueue;
  }

  // Return songs length which player liked
  int playlistSize()
  {
    return playlist.size();
  }

  // Compares person name.
  bool operator==(const Person &p)
  {
    return name == p.name;
  }

  // Prints all of registered people.
  friend ostream &operator<<(ostream &os, Person &p)
  {
    os << p.name << endl;
    return os;
  }
};

// Print instructions to tell user how to make actions
void printInstructions()
{
  cout << "User Commands:" << endl;
  cout << "--------" << endl;
  cout << "C <Name> : Creates a person with the name given in the line" << endl;
  cout << "S <Name> <Song> : Sets the <Name> likes the <Song>" << endl;
  cout << "E <Name> <Song> : Erases the assignment (<Name> does not like the song anymore)." << endl;
  cout << "L <Name> : Lists the songs person <Name> likes." << endl;
  cout << "N : List the names of all of the registered people." << endl;
  cout << "M : List all the songs that are liked by anyone" << endl;
  cout << "--------" << endl;
}

// Creates user with the given name
void createUser(LinkedList<Person> &personData, string name)
{
  Person p;
  LLNode<Person> *node;
  p.setName(name);
  node = personData.search(p);
  // Checks if user name exist or not. If exist i dont add user data to linkedlist.
  if (node == NULL)
  {
    personData.insertLast(p);
    cout << "User Created." << endl;
  }
  else
  {
    cout << "User already exist." << endl;
  }
}

// Add songs to playlist with given name and song
void addSong(LinkedList<Person> &personData, string name, string song)
{
  Person p;
  LLNode<Person> *node;
  p.setName(name);
  node = personData.search(p);
  // Checks if user exist or not.
  // If user does not exist creates new user and add song to playlist otherwise just song liked.
  if (node == NULL)
  {
    p.likeSong(song);
    personData.insertLast(p);
    cout << "User created and liked song " << song << endl;
  }
  else
  {
    node->data.likeSong(song);
    cout << "User "
         << "'" << name << "'"
         << " liked song " << song << endl;
  }
}

// Removes song from user playlist - remove like
void removeSong(LinkedList<Person> &personData, string name, string song)
{
  Person p;
  LLNode<Person> *node;
  p.setName(name);
  node = personData.search(p);
  // Checks if user exist or not.
  // If exist print feedback otherwise remove likes from song.
  // Remove like function also has condition check.
  if (node == NULL)
  {
    cout << "There is no such a user." << endl;
  }
  else
  {
    node->data.removeLike(song);
  }
}

// Shows all song which just one user liked.
void showUserSongs(LinkedList<Person> &personData, string name)
{
  Person p;
  LLNode<Person> *node;
  p.setName(name);
  node = personData.search(p);
  // Checks if user exist or not.
  if (node == NULL)
  {
    cout << "There is no such a user." << endl;
  }
  else
  {
    cout << "List of the songs user "
         << "'" << name << "'"
         << " likes:" << endl;
    // If user does not have any song in playlist send feedback to user.
    if (node->data.playlistSize() == 0)
    {
      cout << "No songs" << endl;
    }
    else
    {
      node->data.print();
    }
  }
}

// Show all songs which anybody likes.
void showAllSongs(LinkedList<Person> &personData)
{
  Person p;
  cout << "List of all songs liked by anyone:" << endl;
  LinkedList<Person> tempData;
  // To reach linked list middle nodes creates new linked list and removes main linkedlist.
  while (true)
  {
    // If all nodes deleted from main linked list stops loop.
    if (personData.isEmpty())
      break;
    p = personData.front();
    p.print();
    tempData.insertLast(p);
    personData.deleteFirst();
  }
  // Assign main linked again because we removed main linked list nodes to print middle nodes.
  personData = tempData;
}

// Show all user names.
void showAllUsers(LinkedList<Person> &personData)
{
  cout << "List of all users:" << endl;
  cout << personData;
}

int main()
{
  LinkedList<Person> personData;
  LLNode<Person> *node;
  printInstructions();
  string name, song;
  string ans;
  do
  {
    cout << "Enter one of the commands above or press (Q) to exit." << endl;
    cin >> ans;
    if (ans == "C" || ans == "c")
    {
      cin >> name;
      createUser(personData, name);
    }
    else if (ans == "S" || ans == "s")
    {
      cin >> name;
      cin.ignore();
      getline(cin, song);
      addSong(personData, name, song);
    }
    else if (ans == "E" || ans == "e")
    {
      cin >> name;
      cin.ignore();
      getline(cin, song);
      removeSong(personData, name, song);
    }
    else if (ans == "L" || ans == "l")
    {
      cin >> name;
      showUserSongs(personData, name);
    }
    else if (ans == "N" || ans == "n")
    {
      showAllUsers(personData);
    }
    else if (ans == "M" || ans == "m")
    {
      showAllSongs(personData);
    }
  } while (ans != "Q" && ans != "q");
}
