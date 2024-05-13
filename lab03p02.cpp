#include <iostream>
#include <sstream>

using namespace std;

class Punkt
{
protected:
    int x;
    int y;

public:
    Punkt(int px, int py) : x(px), y(py) {}
    void przesun(int dx, int dy)
    {
        x += dx;
        y += dy;
    }
    string toString()
    {
        stringstream s;
        s << "[x=" << x << " y=" << y << "]";
        return s.str();
    }
};
//-----------------------------------------------------------------------

class Wektor // - brak dziedziczenia
{
private:
    Punkt p1; // obiekt jako część składowa "większej" klasy
    Punkt p2;

public:
    Wektor(Punkt P1, Punkt P2) : p1(P1), p2(P2) {}
    string toString()
    {
        stringstream s;
        s << "Poczatek "
          << p1.toString() << endl
          << "Koniec "
          << p2.toString();
        return s.str();
    }
    void przesun(int dx, int dy)
    {
        p1.przesun(dx,dy);
        p2.przesun(dx,dy);
    }
};
//-----------------------------------------------------------------------
int main()
{
    // Pierwsza metoda
    Punkt pocz(3, 7);
    Punkt koniec(32, -8);
    Wektor wektor_01(pocz, koniec);
    // Druga metoda
    Wektor wektor_02(Punkt(3, 7), Punkt(98, 4));
    wektor_02.przesun(10,-10);
    cout << wektor_02.toString();
    return 0;
}