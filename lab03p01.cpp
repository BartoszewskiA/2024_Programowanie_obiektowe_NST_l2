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
        s << "Pozycja: x=" << x << " y=" << y;
        return s.str();
    }
};
//-----------------------------------------------------------------------

class Kolo : public Punkt
{
protected:
    int d;

public:
    Kolo(int X, int Y, int R) : Punkt(X, Y), d(2 * R) {}
    double getObwod()
    {
        return 3.14 * d;
    }
    double getPole()
    {
        return 3.14 * (d / 2.0) * (d / 2.0);
    }
    string toString()
    {
        stringstream s;
        // s << "Pozycja: x=" << x << " y=" << y;
        s << Punkt::toString();
        s << " Promien=" << d / 2 << endl;
        s << "Obwod=" << getObwod() << " Pole=" << getPole();
        return s.str();
    }
};

//-----------------------------------------------------------------------
class Kwadrat : public Punkt
{
protected:
    int a;

public:
    Kwadrat(int X, int Y, int A) : Punkt(X, Y), a(A) {}
    double getObwod()
    {
        return 4 * a;
    }
    double getPole()
    {
        return a * a;
    }
    string toString()
    {
        stringstream s;
        // s << "Pozycja: x=" << x << " y=" << y;
        s << Punkt::toString();
        s << " Bok=" << a << endl;
        s << "Obwod=" << getObwod() << " Pole=" << getPole();
        return s.str();
    }
};
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
class Prostokat : public Punkt
{
protected:
    int a;
    int b;

public:
    Prostokat(int X, int Y, int A, int B) : Punkt(X, Y), a(A), b(B) {}
    double getObwod()
    {
        return 2 * a + 2 * b;
    }
    double getPole()
    {
        return a * b;
    }
    string toString()
    {
        stringstream s;
        // s << "Pozycja: x=" << x << " y=" << y;
        s << Punkt::toString();
        s << " Bok a=" << a << " Bok b=" << b << endl;
        s << "Obwod=" << getObwod() << " Pole=" << getPole();
        return s.str();
    }
};
//-----------------------------------------------------------------------

int main()
{
    Prostokat k1(4, 7, 20, 15);
    cout << k1.toString();
    return 0;
}