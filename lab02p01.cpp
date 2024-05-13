#include <iostream>
#include <ctime>
#include <sstream>
#include <string>

using namespace std;

class Osoba
{
private:
    int ID; // losowe
    string imie;
    string nazwisko;
    int wiek;

public:
    Osoba() : imie("NN"), nazwisko("NN"), wiek(0)
    {
        ID = rand() % 1000;
    }
    Osoba(string im, string nazw, int w) : imie(im), nazwisko(nazw), wiek(w)
    {
        ID = rand() % 1000;
    }
    void setImie(string imie) { this->imie = imie; }
    void setNazwisko(string nazwisko) { this->nazwisko = nazwisko; }
    void setWiek(int wiek) { this->wiek = wiek; }
    string getImie() { return imie; }
    string getNazwisko() { return nazwisko; }
    int getWiek() { return wiek; }
    void przedstawSie()
    {
        cout << "ID: " << ID << " "
             << "Imie: " << imie << " "
             << "Nazwisko: " << nazwisko << " "
             << "Wiek: " << wiek;
    }
    string toString()
    {
        stringstream s;
        s << "ID:\t\t" << ID << endl
          << "Imie:\t\t" << imie << endl
          << "Nazwisko:\t" << nazwisko << endl
          << "Wiek:\t\t" << wiek;
        return s.str();
    }
};
//------------------------------------------------

Osoba lista[100];

void wczytaj(int ile)
{
    string temp;
    for (int i = 0; i < ile; i++)
    {
        cout<<"podaj imie: ";
        getline(cin, temp);
        lista[i].setImie(temp);
        cout << "podaj nazwisko: ";
        getline(cin, temp);
        lista[i].setNazwisko(temp);
        cout << "podaj wiek: ";
        getline(cin, temp);
        lista[i].setWiek(stoi(temp));
    }
}
void wypisz(int ile)
{
    for (int i = 0; i < ile; i++)
        cout << lista[i].toString() << endl;
}

int main()
{
    srand(time(NULL));
    string temp;
    int ile = 0;
    cout << "Ile osob wczytac: ";
    getline(cin, temp);
    ile = stoi(temp);
    wczytaj(ile);
    wypisz(100);
    return 0;
}