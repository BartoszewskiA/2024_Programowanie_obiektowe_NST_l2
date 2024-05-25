/*
Napisać klasę, która podaje, ile czasu była aktywna.
Podaje czas pracy w aktualnej sesji (od uruchomienia pragramu), oraz łaczny czas pracy z pragramem.
*/


#include <iostream>
#include <ctime>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

class Podglad
{
private:
    int czas;  //łaczny czas pracy z programem
    int start_sesji;  //start aktualnej sesji
    string nazwa_pliku;
    void wczytanie_pliku()
    {
        fstream plik;
        plik.open(nazwa_pliku, ios::in);
        if (plik.good())
        {
            string s;
            getline(plik, s);
            czas = stoi(s);
            plik.close();
        }
        else
        {
            plik.open(nazwa_pliku, ios::out);
            czas = 0;
            plik << czas;
        }
    }
    void zapis_do_pliku()
    {
        fstream plik;
        plik.open(nazwa_pliku, ios::out);
        int c = czas + getCzasSesjiSekundy();
        plik << c;
        plik.close();
    }

public:
    Podglad() : nazwa_pliku("czas.log")
    {
        start_sesji = time(NULL);
        wczytanie_pliku();
    }
    Podglad(string nazwa) : nazwa_pliku(nazwa)
    {
        start_sesji = time(NULL);
        wczytanie_pliku();
    }

    int getCzasSesjiSekundy()  // czas pracy aktualnej sesji
    {
        return time(NULL) - start_sesji;
    }
    int getSek()
    {
        int aktualny = time(NULL) - start_sesji;
        return aktualny % 60;
    }
    int getMin()
    {
        int aktualny = time(NULL) - start_sesji;
        int minuty = aktualny / 60;
        return minuty % 60;
        // return minuty - getGodz()*60;
    }
    int getGodz()
    {
        int aktualny = time(NULL) - start_sesji;
        int godziny = aktualny / (60 * 60);
        return godziny;
    }
    string getCzasPracy()
    {
        stringstream s;
        s << "Pracowales: "
          << getGodz() << "h "
          << getMin() << "min "
          << getSek() << "sek";
        return s.str();
    }



    ~Podglad()
    {
        zapis_do_pliku();
    }
};

int main()
{
    Podglad szpieg;
    cout << "Poczekaj chwile i nacisnji enter";
    getchar();
    // cout << "Pracowales: " << szpieg.getCzasSesjiSekundy() << " sekund";
    // cout << "Pracowales: "
    //      << szpieg.getGodz() << "h "
    //      << szpieg.getMin() << "min "
    //      << szpieg.getSek() << "sek";
    cout << szpieg.getCzasPracy();
    return 0;
}