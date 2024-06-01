#include <iostream>

using namespace std;

class Osoba
{
private:
    string imie;
    string nazwisko;

public:
    Osoba(string im, string nazw) : imie(im), nazwisko(nazw) {}
    string getImie() { return imie; }
    string getNazwisko() { return nazwisko; }
    friend int porownaj(Osoba osoba01, Osoba osoba02);
    // -1 => osoba01 > osoba02
    //  0 => równe
    //  1 => osoba01 < osoba02
};

int porownaj(Osoba osoba01, Osoba osoba02)
{
    if (osoba01.nazwisko > osoba02.nazwisko)
        return -1;
    if (osoba01.nazwisko < osoba02.nazwisko)
        return 1;
    if (osoba01.imie > osoba02.imie)
        return -1;
    if (osoba01.imie < osoba02.imie)
        return 1;
    return 0;
}

int main()
{
    Osoba ktos("Jan", "Kowalski");
    Osoba ktos2("Jan", "Kowalski");
    cout<< porownaj(ktos, ktos2);
    return 0;
}