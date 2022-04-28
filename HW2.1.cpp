#include <iostream>
#include <string>
#include "HeaderFiles/LinkedList.h"      // Ziya Karakaya LinkedList v0.5
#include "HeaderFiles/LinkedListQueue.h" // Ziya Karakaya LQueue.h

using namespace std;

class PersonQueue
{
private:
    string queueOwner;
    Queue<string> queueOfSongs;

public:
    PersonQueue() {}
    ~PersonQueue() {}

    void setName(string queueOwnerI)
    {
        queueOwner = queueOwnerI;
    }
    string getName()
    {
        return queueOwner;
    }
    void getList()
    {
        if (!queueOfSongs.isEmpty())
        {
            Queue<string> tempQueue = queueOfSongs;
            for (int i = queueOfSongs.size(); i > 0; i--)
            {
                cout << tempQueue.remove() << "\n";
            }
        }
        else
        {
            cout << "Error: " << queueOwner << "'s song queue is empty!\n\n";
        }
    }
    void eraseSpecificSongFromQueue(string songName)
    {
        if (!queueOfSongs.isEmpty())
        {
            Queue<string> tempQueue = queueOfSongs;
            queueOfSongs.clearQueue();
            for (int i = queueOfSongs.size(); i > 0; i--)
            {
                string tempSongName = tempQueue.remove();
                if (tempSongName != songName)
                {
                    queueOfSongs.add(tempSongName);
                }
            }
            cout << songName << " is deleted from " << queueOwner << "'s list\n\n";
        }
        else
        {
            cout << "Error: List is empty!\n\n";
        }
    }
    void addSongToQueue(string songName)
    {
        queueOfSongs.add(songName);
        cout << songName << " is added to " << queueOwner << "'s list\n\n";
    }
    bool operator==(const PersonQueue &p)
    {
        return queueOwner == p.queueOwner;
    }
    friend ostream &operator<<(ostream &os, const PersonQueue &p)
    {
        os << p.queueOwner << ",";
        return os;
    }
};

int main()
{
    LinkedList<PersonQueue> lists;
    Queue<string> names;
    string name, song;
    PersonQueue temp;
    char command;

    cout << "Hi, there is the usage of program\n"
         << "C <Name> : Creates a person with the name given in the line\n"
         << "S <Name> <Song> : Sets the <Name> likes the <Song>\n"
         << "E <Name> <Song> : Erases the <Name> does not like the <Song>\n"
         << "L <Name> : Lists the songs person <Name> likes.\n"
         << "N : List the names of all of the registered people.\n"
         << "M : List all the songs that are liked by anyone.\n"
         << "Q : Exit the program\n\n\n";
    while (command != 'Q')
    {
        cout << "Enter: ";
        cin >> command;
        switch (command)
        {
        case 'C':
        {
            cin >> name;
            temp.setName(name);

            if (!lists.search(temp))
            {
                lists.insertLast(temp);
                cout << name << "'s list is created!\n\n";
                names.add(name);
            }
            else
            {
                cout << "Error: Exising name!\n\n";
            }

            break;
        }
        case 'S':
        {
            cin >> name;
            getline(cin, song);
            song.erase(0, 1);

            temp.setName(name);
            if (lists.search(temp))
            {
                lists.search(temp)->data.addSongToQueue(song);
            }
            else
            {
                cout << "Error: Name doesn't exist!\n\n";
            }

            break;
        }
        case 'E':
        {
            cin >> name;
            getline(cin, song);
            song.erase(0, 1);

            temp.setName(name);
            if (lists.search(temp))
            {
                lists.search(temp)->data.eraseSpecificSongFromQueue(song);
            }
            else
            {
                cout << "Error: Name doesn't exist!\n\n";
            }

            break;
        }
        case 'L':
        {
            cin >> name;

            temp.setName(name);
            if (lists.search(temp))
            {
                cout << name << "'s song list:\n";
                lists.search(temp)->data.getList();
            }
            else
            {
                cout << "Error: Name doesn't exist!\n\n";
            }

            break;
        }
        case 'N':
        {
            if (!lists.isEmpty())
            {
                cout << "All the names of persons:\n";
                lists.reversePrint();
                cout << "\n\n";
            }
            else
            {
                cout << "Error: List empty!\n\n";
            }

            break;
        }
        case 'M':
        {
            if (!lists.isEmpty())
            {
                for (int i = names.size(); i > 0; i--)
                {
                    string tempName = names.remove();
                    temp.setName(tempName);
                    cout << tempName << "'s song list:\n";
                    lists.search(temp)->data.getList();
                }
            }
            else
            {
                cout << "Error: List empty!\n\n";
            }

            break;
        }
        default:
        {
            cout << "Invalid Input\n\n";
            break;
        }
        }
    }
    return 0;
}