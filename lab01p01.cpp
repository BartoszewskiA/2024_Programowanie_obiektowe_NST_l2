#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

class Punkt

{
private:
    int x;
    int y;

public:
    Punkt()
    {
        x = rand() % 201 - 100;
        y = rand() % 201 - 100;
    }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    int getX() { return x; }
    int getY() { return y; }
    double getR() { return sqrt(x * x + y * y); }
};

int main()
{
    Punkt tab[100];
    for (int i = 0; i < 100; i++)
        cout << "(" << tab[i].getX() << ";" << tab[i].getY() << ")  ";
    double min = tab[0].getR();
    double max = tab[0].getR();
    for (int i = 0; i < 100; i++)
    {
        if (tab[i].getR() < min)
            min = tab[i].getR();
        if (tab[i].getR() > max)
            max = tab[i].getR();
    }

    cout << endl;
    cout << "min=" << min << endl;
    cout << "max=" << max;

    for (int i = 0; i < 100; i++)
    {
        if (tab[i].getR() == min)
            cout << "\n[" << tab[i].getX() << ";" << tab[i].getY() << "]\n";
    }

    return 0;
}