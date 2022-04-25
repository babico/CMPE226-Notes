#include <iostream>
#include <string>
#include "HeaderFiles/LinkedList.h"
#include "HeaderFiles/LinkedListQueue.h"

using namespace std;

class Kisi
{
private:
    string isim;
    Queue<string> muzikListe;

public:
    Kisi() {}
    ~Kisi() {}

    void setIsim(string isim)
    {
        this->isim = isim;
    }
    string getIsim()
    {
        return isim;
    }
    bool muzikListeBosMu()
    {
        return muzikListe.isEmpty();
    }
    void muzikEkle(string muzik_)
    {
        muzikListe.add(muzik_);
    }
    void muzikListeYazdir()
    {
        Queue<string> gecici = muzikListe;
        for (int i = 0; i < muzikListe.size(); i++)
        {
            cout << gecici.remove() << endl;
        }
    }
    void muzikSil(string muzik_)
    {
        if (!muzikListeBosMu())
        {
            Queue<string> geciciMuzikListe1 = muzikListe;
            int listeBoyut = muzikListe.size();
            muzikListe.clearQueue();

            for (int i = 0; i < listeBoyut; i++)
            {
                string geciciMuzik = geciciMuzikListe1.front();
                geciciMuzikListe1.remove();

                if (muzik_ == geciciMuzik)
                {
                    continue;
                }
                else
                {
                    muzikListe.add(geciciMuzik);
                }
            }
        }
        else
        {
            cout << "There is no music in playlist." << endl;
        }
    }
    bool operator==(const Kisi &k)
    {
        return isim == k.isim;
    }
};

int main()
{
    string isim, muzik, komut, isimler[100];
    int isimlerCount = 0;

    LinkedList<Kisi> kisiListe;
    Kisi gecici;

    cout << "Press Q for exit the program." << endl;
    do
    {
        cout << "Enter: ";
        cin >> komut;
        if ((komut == "C") || (komut == "S") || (komut == "E") || (komut == "L"))
        {
            cin >> isim;
            gecici.setIsim(isim);
        }
        if ((komut == "S") || (komut == "E"))
        {
            getline(cin, muzik);
        }
        if (komut == "C")
        {
            if (!kisiListe.search(gecici))
            {
                cout << isim << " created" << endl;
                kisiListe.insertLast(gecici);
                isimler[isimlerCount++] = isim;
            }
            else
            {
                cout << "This person already exists." << endl;
            }
        }
        else if (komut == "S")
        {
            if (kisiListe.search(gecici))
            {
                kisiListe.search(gecici)->data.muzikEkle(muzik);
                cout << muzik << " is added to " << isim << endl;
            }
            else
            {
                cout << "There is no such a person." << endl;
            }
        }
        else if (komut == "E")
        {
            if (kisiListe.search(gecici))
            {
                kisiListe.search(gecici)->data.muzikSil(muzik);
                cout << muzik << " is deleted from " << isim << endl;
            }
            else
            {
                cout << "There is no such a person." << endl;
            }
        }
        else if (komut == "L")
        {

            if (kisiListe.search(gecici))
            {
                if (!kisiListe.search(gecici)->data.muzikListeBosMu())
                {
                    kisiListe.search(gecici)->data.muzikListeYazdir();
                }
                else
                {
                    cout << "There is no music in playlist." << endl;
                }
            }
            else
            {
                cout << "There is no such a person." << endl;
            }
        }
        else if (komut == "N")
        {
            if (isimlerCount == 0)
            {
                cout << "There is no list." << endl;
            }
            else
            {
                for (int i = 0; i < isimlerCount; i++)
                {
                    cout << isimler[i] << endl;
                }
            }
        }
        else if (komut == "M")
        {
            if (isimlerCount == 0)
            {
                cout << "There is no list." << endl;
            }
            else
            {
                for (int i = 0; i < isimlerCount; i++)
                {
                    gecici.setIsim(isimler[i]);
                    kisiListe.search(gecici)->data.muzikListeYazdir();
                }
            }
        }
    } while (komut != "Q");

    return 0;
}