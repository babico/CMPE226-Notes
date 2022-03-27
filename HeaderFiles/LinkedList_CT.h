// MAKING HEADER FILE FOR LINKEDLIST
#include <assert.h>
namespace std
{
    template <typename T>
    struct Node
    {
        T data;
        Node<T> *next;
    };
    
    template <typename T>
    class LinkedList
    {
    protected:
        Node<T> *head, *last;
        int count;

    public:
        LinkedList()
        {
            count = 0;
            head = last = NULL;
        }
        ~LinkedList()
        {
            destroyList();
        }
        T back() // listenin sonundaki nodeun değerini dönüyor
        {
            assert(last != NULL);
            return last->data;
        }
        T front() // listenin başındaki nodeun değerini dönüyor
        {
            assert(head != NULL);
            return head->data;
        }
        int length() // listenin uzunluğunu dönüyor
        {
            return count;
        }
        bool emptyList() // listenin boş olup olmadığını söylüyor
        {
            return (count == 0) ? true : false;
        }
        void destroyList() // listeyi silme
        {
            Node<T> *temp;       // geçici node yaratma
            while (head != NULL) // headin boş olup olmadığını kontrol etme
            {
                temp = head;       // head boş değilken listenin başındaki nodeu geçiciye atama
                head = head->next; // listenin başını gösteren headi bir ileri taşıyor.
                delete temp;       // listenin eski başı olan nodeu siliyor
            }

            count = 0;   // listenin node sayısını sıfırlıyor
            last = NULL; // listenin sonunu göstereni sıfırlıyor
        }
        void insertFirst(const T &item) // listenin başına ekleme yapma
        {
            Node<T> *temp = new Node<T>; // geçici node yaratma

            temp->data = item; // geçici node değerini atama
            temp->next = head; // geçici nodeu listenin başına ekleme

            head = temp;      // geçici nodeu listenin başı yapma
            if (last == NULL) // listede node olup olmadığını kontrol etme
            {
                last = temp; // listede node yoksa last değişkenini atama
            }

            count++; // listenin node sayısını arttırıyor
        }
        void insertLast(const T &item) // listenin sonuna ekleme yapma
        {
            Node<T> *temp = new Node<T>; // geçici node yaratma

            temp->data = item; // geçici node değerini atama
            temp->next = NULL; // geçici node son node olacağı için NULL atama

            if (head != NULL) // listede node olup olmadığını kontrol etme
            {
                last->next = temp; // olan son nodeun sonrasına geçici nodeu atama
                last = temp;       // son nodeu geçici node olarak atama
            }
            else
            {
                head = last = temp; // liste boşsa geçici nodeu atama
            }

            count++; // listenin node sayısını arttırıyor
        }
        void deleteNode(const T &item) // listedeki belirli nodeu silme
        {
            Node<T> *temp, *tempNext; // listede nodeları gösterecek
            bool found = false;

            if (head == NULL) // listenin boş olmadığını kontrol ediyor
            {
                cerr << "List is empty!" << endl; // liste boşsa uyarıyor
            }
            else
            {
                if (head->data == item) // eğer aranan ilk nodeda ise oradan silme // !!!!data bir obje ise "==" operatörünün o objede tanımlı olması gerek!!!!
                {
                    temp = head;       // geçici olarak listenin başındaki nodeu gösterme
                    head = head->next; // listenin başını taşıma
                    delete temp;       // eski liste başını silme
                    count--;           // node sayısını düşürme

                    if (head == NULL) // listede node kaldı mı diye kontrol etme
                    {
                        last = NULL; // listede node kalmadıysa last göstergesini boşa çıkarma;
                    }
                }
                else
                {
                    temp = head;           // geçici olarak listenin başındaki nodeu gösterme
                    tempNext = head->next; // geçici olarak listenin başından sonraki nodeu gösterme

                    while ((tempNext != NULL) && !found) // sonraki node null değilse ve aranan bulunmadıysa diye kontrol etme
                    {
                        if (tempNext->data == item) // sonraki nodeun datasını kontrol etme // !!!!data bir obje ise "==" operatörünün o objede tanımlı olması gerek!!!!
                        {
                            found = true; // sonraki nodeun datası aranan ise bulundu diye işaretleme
                        }
                        else
                        {
                            temp = tempNext;       // aranan bulunmadıysa bir sonraki nodea geçme
                            tempNext = temp->next; // aranan bulunmadıysa bir sonraki nodeun sonrakine geçme
                        }
                    }
                    if (found)
                    {
                        temp->next = tempNext->next; // geçici gösterilen sonraki nodeun önündeki bağı geçici gösterilen nodea taşıma
                        count--;                     // node sayısını düşme
                        if (last == tempNext)        // geçici gösterilen sonraki nodeun listenin sonunda mı diye kontrol etme
                        {
                            last = temp; // sonunda ise listenin sonunu bir geri taşıma
                        }
                        delete tempNext; // arananı silme
                    }
                    else // aranan bulunamazsa hata gösterme
                    {
                        cerr << "Item to be deleted is not in the list." << endl;
                    }
                }
            }
        }
        Node<T> *search(const T &item) // listede aradığını bulma fonksiyonu
        {
            Node<T> *temp;
            temp = head;        // geçici olarak liste başını gösterme
            bool found = false; // aradığını bulduğunda bulduğunu gösterecek boolen

            while ((temp != NULL) && (!found)) // tempin bağlı olduğu nodeun boş olup olmadığını ve aranan şeyin bulunup bulunmadığını kontrol etme
            {
                if (temp->data == item) // !!!!data bir obje ise "==" operatörünün o objede tanımlı olması gerek!!!!
                {
                    found = true; // eğer aranan bulunmadıysa ve tempin gösterdiği node aranana eşitse bulundu olarak atama
                }
                else
                {
                    temp = temp->next; // eğer aranan bulunmadıysa ve tempin gösterdiği node aranana eşit değilse listede sonraki nodea geçmek için atama
                }
            }

            return temp;
        }
        friend ostream &operator<<(ostream &os, const LinkedList<T> &list) // listenin << operatörü
        {
            Node<T> *temp;    // geçici gösterge oluşturma
            temp = list.head; // geçici olarak liste başını gösterme

            while (temp != NULL) // geçiçici gösterge boş mu değil mi kontrol ediyor
            {
                os << temp->data;  // geçici göstergenin gösterdiği değeri yazdırıyor
                temp = temp->next; // geçiçi göstergeyi bir sonraki nodea geçiriyor
            }

            return os; // cout için değer dönüyor
        }
    };
}