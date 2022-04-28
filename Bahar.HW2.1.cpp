#include <iostream>
#include <string>
#include "HeaderFiles/LinkedList.h"
#include "HeaderFiles/LinkedListQueue.h"

using namespace std;

class Person
{
private:
    string name;

public:
    Person() {}
    Queue<string> song_q;
    string getname()
    {
        return name;
    }
    void setname(string n)
    {
        name = n;
    }
    friend ostream &operator<<(ostream &out, const Person &p)
    {
        out << p.name;
        return out;
    }
    bool operator==(const Person &p2)
    {
        return name == p2.name;
    }
};

int main(int argc, char const *argv[])
{
    string name, song;
    char cmd;
    LinkedList<Person> info;
    LinkedList<string> name_list;
    do
    {
        Person p1;
        cout << "Enter command (enter 'Q' to  exit the program): ";
        cin >> cmd;

        if (cmd == 'C')
        {
            cin >> name;
            p1.setname(name);
            // checking if the name is already exists
            if (info.search(p1))
            {
                cout << "This name already exists in list\n";
            }
            name_list.insertFirst(name);
            // inserting name to the linked list
            info.insertLast(p1);
        }

        else if (cmd == 'S')
        {
            cin >> name;
            getline(cin, song);
            p1.setname(name);
            // creating temporary pointer object to point the song info
            Person *temp = &info.search(p1)->data;
            if (info.search(p1) == NULL)
            {
                cout << "There is no name such " << name << endl;
            }
            else
            {
                // creating temporary queue pointer to point song queue list
                Queue<string> *temp2 = &temp->song_q;
                temp2->add(song);
                cout << name << " likes " << song << endl;
            }
        }

        else if (cmd == 'E')
        {
            cin >> name;
            p1.setname(name);
            getline(cin, song);
            // creating node pointer to point to the node that includes person object data
            LLNode<Person> *temp = info.search(p1);
            // copying queue object
            Queue<string> temp2 = temp->data.song_q;
            Queue<string> temp3;
            while (!temp2.isEmpty())
            {
                string removed = temp2.remove();
                if (removed!=song)
                {
                    temp3.add(removed);
                }
                
            }
            //updating the actual queue
            temp->data.song_q = temp3;
            cout << name << " doesn't like the song anymore\n";
        }

        else if (cmd == 'L')
        {
            cin >> name;
            p1.setname(name);
            // creating node pointer to point to the node that includes Person object data
            LLNode<Person> *temp = info.search(p1);

            // copying queue object for not losing the actual data
            Queue<string> temp2 = temp->data.song_q;

            // checkig if the queue is empty or not
            if (!temp2.isEmpty())
            {
                cout << name << " likes:" << endl;
                for (int i = 0; i <= temp->data.song_q.size(); i++)
                {
                    cout << temp2.remove() << endl;
                }
            }
            else
                cout << "This person have no liked songs\n";
        }

        else if (cmd == 'N')
        {
            LinkedList<Person> other;
            other = info;
            cout << "List of all people:\n";
            while (!other.isEmpty())
            {
                cout << other.front() << endl;
                other.deleteFirst();
            }
        }

        else if (cmd == 'M')
        {
            // checking if the list of names is empty or not
            if (!name_list.isEmpty())
            {
                cout << "All the songs that are liked by anyone: " << endl;
                for (int i = 0; i <= name_list.length(); i++)
                {
                    p1.setname(name_list.front());
                    // creating node pointer to point to the node that includes Person object data
                    LLNode<Person> *temp = info.search(p1);

                    // copying queue object for not losing the actual data
                    Queue<string> temp2 = temp->data.song_q;
                    for (int i = 0; i <= temp->data.song_q.size(); i++)
                    {
                        cout << temp2.remove() << endl;
                    }
                    name_list.deleteFirst();
                }
            }
            else
                cout << "There is no list " << endl;
        }

    } while (cmd != 'Q');

    return 0;
}
