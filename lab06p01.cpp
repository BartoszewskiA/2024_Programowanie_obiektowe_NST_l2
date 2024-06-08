#include <iostream>
#include <cmath>

using namespace std;

class Prostokat
{
private:
    double a;
    double b;
    void walidacja()
    {
        if (a < 0)
            a = 0;
        if (b < 0)
            b = 0;
    }

public:
    Prostokat(double A = 0, double B = 0) : a(A), b(B)
    {
        walidacja();
    }
    friend ostream &operator<<(ostream &str, Prostokat p);
    friend istream &operator>>(istream &str, Prostokat &p);
    friend Prostokat operator+(Prostokat p1, Prostokat p2); // dodajemy pola pow.
    friend bool operator==(Prostokat p1, Prostokat p2);     // porownujemy pola powierzchni
};
//-----------------------------------------------------------
ostream &operator<<(ostream &str, Prostokat p)
{
    str << "a=" << p.a
        << " b=" << p.b
        << " Pp=" << p.a * p.b;
    return str;
}

istream &operator>>(istream &str, Prostokat &p)
{
    str >> p.a;
    str >> p.b;
    p.walidacja();
    return str;
}

Prostokat operator+(Prostokat p1, Prostokat p2)
{
    double bok = sqrt(p1.a * p1.b + p2.a * p2.b);
    Prostokat wynik(bok, bok);
    return wynik;
}

bool operator==(Prostokat p1, Prostokat p2)
{
    if ((p1.a * p1.b) == (p2.a * p2.b))
        return true;
    else
        return false;
}

int main()
{

    Prostokat p1, p2;
    cout << "Pierwszy: ";
    cin >> p1;
    cout << "Drugi: ";
    cin >> p2;
    if (p1 == p2)
        cout << p1 << " = " << p2;
    else
        cout << p1 << " != " << p2;

    return 0;
}