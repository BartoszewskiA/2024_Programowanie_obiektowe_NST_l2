#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Notatki
{
private:
    string nazwa_pliku;

public:
    Notatki(string nazwa) : nazwa_pliku(nazwa)
    {
        fstream plik;
        plik.open(nazwa_pliku, ios::in);
        if (plik.good())
        {
            plik.close();
            return; // jeżeli plik istniał nic nie robimy
        }
        plik.open(nazwa_pliku, ios::out); // jeżeli nie  - tworzymy pkik
        plik.close();
    }
    void dopisz(string wpis)
    {
        fstream plik;
        plik.open(nazwa_pliku, ios::app);
        plik << wpis << endl;
        plik.close();
    }
    void wypisz()
    {
        fstream plik;
        string s;
        int i = 0;
        plik.open(nazwa_pliku, ios::in);
        while (!plik.eof())
        {
            getline(plik, s);
            cout << ++i << ": " << s << endl;
        }
        plik.close();
    }
};

int main()
{
    Notatki n1("notatka.txt");
    n1.dopisz("aaaaaaaaa");
    n1.dopisz("bbbbbbbbbb bbbbbbb");
    n1.wypisz();
    return 0;
}