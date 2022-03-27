#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include "HeaderFiles/LinkedList.h"

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define reset "\e[0m"

using namespace std;

class Soru
{
private:
    int soruNo;
    bool yanit = true;
    string soru, cevap;

public:
    Soru(int noI = 0, string soruI = "", string cevapI = "")
    {
        soruNo = noI;
        soru = soruI;
        cevap = cevapI;
    }

    string alSoru()
    {
        return soru;
    }
    string alCevap()
    {
        return cevap;
    }
    bool alYanit()
    {
        return yanit;
    }
    void ataYanit()
    {
        yanit = false;
    }

    friend ostream &operator<<(ostream &os, const Soru &s)
    {
        os << s.soruNo << " " << s.soru << " " << s.cevap << endl;

        return os;
    }
    bool operator==(const Soru &s)
    {
        return soruNo == s.soruNo;
    }

    ~Soru() {}
};

class Sinav
{
public:
    string konu;
    LinkedList<Soru> Sorular;
};

int main()
{
    srand(time(NULL));
    Sinav konular[5];
    string cevapI = "default for while loop";
    int yanlisSoruSayac = 0, soruSayi = 1;
    fstream girisDosya("Hw1TextFile.txt", ios::in | ios::out);

    if (!girisDosya.is_open())
    {
        cout << "There is no \"Hw1TextFile.txt\" in folder.";
        return 0;
    }

    for (int i = 0; i < 5; i++)
    {
        int soruNo = 1;
        string geciciKonu = "", geciciSoru = "", geciciCevap = "";

        getline(girisDosya, geciciKonu);
        konular[i].konu = geciciKonu;

        while (1)
        {
            getline(girisDosya, geciciSoru);
            if (geciciSoru == "#")
            {
                break;
            }
            getline(girisDosya, geciciCevap);

            konular[i].Sorular.insertLast(Soru(soruNo, geciciSoru, geciciCevap));
            soruNo++;
        }
    }
    girisDosya.close();

    cout << "Data Structures Quiz" << endl
         << "Answer the following:" << endl;
    for (int i = 0; i < 5; i++)
    {
        int kullanilmisSoruSayi = 0, rastgeleSoruSayi = -1;
        cout << konular[i].konu << " questions" << endl;

        for (int j = 1; j <= 2; j++)
        {
            do
            {
                rastgeleSoruSayi = (rand() % konular[i].Sorular.length()) + 1;
            } while (rastgeleSoruSayi == kullanilmisSoruSayi);

            kullanilmisSoruSayi = rastgeleSoruSayi;

            LLNode<Soru> *geciciNode = konular[i].Sorular.search(Soru(rastgeleSoruSayi));

            cout << BLU << soruSayi << ".\t" << reset << geciciNode->data.alSoru() << MAG << " (T/F)" << reset << ": ";
            while (1)
            {
                if (cevapI != "T" && cevapI != "F" && cevapI != "default for while loop")
                {
                    cout << "Enter proper answer like \"T\" or \"F\"!" << endl;
                    cout << BLU << soruSayi << ".\t" << reset << geciciNode->data.alSoru() << MAG << " (T/F)" << reset << ": ";
                }

                cout << CYN;
                cin >> cevapI;
                cout << reset;

                if (cevapI == "T" || cevapI == "F")
                {
                    break;
                }
            }
            soruSayi++;

            if (cevapI != geciciNode->data.alCevap())
            {
                geciciNode->data.ataYanit();
                yanlisSoruSayac++;
            }
        }
        cout << endl;
    }

    cout << "Your score: " << 10 - yanlisSoruSayac << "/10" << endl
         << "Incorrectly answered questions:" << endl;

    for (int k = 0; k < 5; k++)
    {
        for (int g = 1; g <= konular[k].Sorular.length(); g++)
        {
            LLNode<Soru> *geciciNode = konular[k].Sorular.search(Soru(g));

            if (!geciciNode->data.alYanit())
            {
                cout << geciciNode->data.alSoru() << " Correct answer: " << ((geciciNode->data.alCevap() == "T") ? GRN "True" : RED "False") << reset << endl;
            }
        }
    }

    return 0;
}