#include <iostream>
#include <ctime>

using namespace std;

class Dlugosc
{
private:
    double dlugosc_m;

public:
    Dlugosc(double metry) : dlugosc_m(metry) {}
    double getMetry() { return dlugosc_m; }
    double getCm() { return dlugosc_m * 100; }
    double getKm() { return dlugosc_m / 1000; }
};

int main()
{
    srand(time(NULL));
    Dlugosc *tab[10];
    for (int i = 0; i < 10; i++)
    {
        tab[i] = new Dlugosc(rand() % 1000);
    }
    for (int i = 0; i < 10; i++)
    {
        cout << tab[i]->getCm() << " "
             << tab[i]->getMetry() << " "
             << tab[i]->getKm() << endl;
    }
    for (int i = 0; i < 10; i++)
        delete tab[i];
    return 0;
}