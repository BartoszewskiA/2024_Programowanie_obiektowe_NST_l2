#include <iostream>
#include <string>

using namespace std;

class Zwierze
{
private:
    string imie;
    string rasa;
    double waga;

public:
    Zwierze(string im, string ra, int w) : imie(im), waga(w)
    {
        for (int i = 0; i < ra.length(); i++)
            ra[i] = tolower(ra[i]);

        if (ra == "pies" || ra == "kot")
            rasa = ra;
        else
            rasa = "inna";
    }
};

int main()
{
    string imie,rasa, waga;
    Zwierze * kartoteka[100]; //tablica wskażników
    for(int i=0; i<3; i++)
    {
        cout<<"Imie: ";
        getline(cin,imie);
        cout <<"Rasa: ";
        getline(cin,rasa);
        cout<<"waga: ";
        getline(cin,waga);
        kartoteka[i] =  new Zwierze(imie, rasa, stod(waga));
    }
    for (int i = 0; i < 3; i++)
    delete kartoteka[i];
        return 0;
}