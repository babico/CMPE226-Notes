#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include "HeaderFiles/LinkedList.h"

using namespace std;

class Soru
{
private:
    int soruNo;
    bool yanit = true;
    string soru, cevap;

public:
    Soru(int noI = 0)
    {
        soruNo = noI;
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
    void atama(int noI, string soruI, string cevapI)
    {
        soruNo = noI;
        soru = soruI;
        cevap = cevapI;
    }

    friend ostream &operator<<(ostream &os, const Soru &soru)
    {
        os << soru.soruNo << " " << soru.soru << " " << soru.cevap << endl;

        return os;
    }
    bool operator==(const Soru &soru)
    {
        return this->soruNo == soru.soruNo;
    }

    ~Soru() {}
};

class Sinav
{
public:
    string konu;
    LinkedList<Soru> Sorular;
};

void rastgeleSayiKontrol(int &rastgele, int &kullanilmis, LinkedList<Soru> &obje)
{
    if (rastgele == kullanilmis)
    {
        rastgele = (rand() % obje.length()) + 1;
        rastgeleSayiKontrol(rastgele, kullanilmis, obje);
    }
}

int main()
{
    srand(time(NULL));
    fstream girisDosya("Hw1TextFile.txt", ios::in | ios::out);

    Sinav konular[5];
    int yanlisSoruSayac = 0;

    for (int i = 0; i < 5; i++)
    {
        int soruNo = 1;
        string geciciKonu = "", geciciSoru = "", geciciCevap = "";

        getline(girisDosya, geciciKonu);
        konular[i].konu = geciciKonu;

        while (1)
        {
            Soru gecici;
            getline(girisDosya, geciciSoru);
            if (geciciSoru == "#")
            {
                break;
            }
            getline(girisDosya, geciciCevap);

            gecici.atama(soruNo, geciciSoru, geciciCevap);

            konular[i].Sorular.insertLast(gecici);
            soruNo++;
        }
    }

    cout << "Data Structures Quiz" << endl
         << "Answer the following:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << konular[i].konu << " questions" << endl;
        int kullanilmisSoruSayi = 0;
        for (int j = 1; j <= 2; j++)
        {
            int rastgeleSoruSayi = (rand() % konular[i].Sorular.length()) + 1;
            string cevapI;
            bool bayrak = false;

            rastgeleSayiKontrol(rastgeleSoruSayi, kullanilmisSoruSayi, konular[i].Sorular);

            Soru geciciSoru(rastgeleSoruSayi);
            LLNode<Soru> *geciciNode = konular[i].Sorular.search(geciciSoru);
            kullanilmisSoruSayi = rastgeleSoruSayi;

            cout << j << ".\t" << geciciNode->data.alSoru() << " (T/F): ";
            cin >> cevapI;

            if (cevapI != geciciNode->data.alCevap())
            {
                geciciNode->data.ataYanit();
                yanlisSoruSayac++;
            }
        }
    }

    cout << "Your score: " << 10 - yanlisSoruSayac << "/10" << endl
         << "Incorrectly answered questions:" << endl;

    for (int k = 0; k < 5; k++)
    {
        for (int g = 1; g <= konular[k].Sorular.length(); g++)
        {
            Soru geciciSoru(g);
            LLNode<Soru> *geciciNode = konular[k].Sorular.search(geciciSoru);

            if (!geciciNode->data.alYanit())
            {
                cout << geciciNode->data.alSoru() << " Correct answer: " << ((geciciNode->data.alCevap() == "T") ? "True" : "False") << endl;
            }
        }
    }

    return 0;
}