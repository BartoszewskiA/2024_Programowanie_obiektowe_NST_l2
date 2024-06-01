#include <iostream>
#include <math.h>

using namespace std;

class Portfel
{
protected:
    double kwotaPLN;
    double format(double kwota)
    {
        return round(kwota * 100) / 100.0;
    }

public:
    Portfel() {}
    Portfel(double kwotaStartowa) : kwotaPLN(kwotaStartowa) {}
    double saldo() { return format(kwotaPLN); }
    double przelejPLN(double ile)
    {
        kwotaPLN += ile;
        return format(kwotaPLN);
    }
    double wyplacPLN(double ile)
    {
        kwotaPLN -= ile;
        return format(kwotaPLN);
    }
    double przelejEURO(double ile)
    {
        kwotaPLN = kwotaPLN + ile * 4.28;
        return format(kwotaPLN);
    }
    double wyplacEURO(double ile)
    {
        kwotaPLN = kwotaPLN - ile * 4.28;
        return format(kwotaPLN);
    }
};

//------------------------------------------------------------------------------------
class Portfel_2 : public Portfel
{
public:
    Portfel_2() : Portfel() {}
    Portfel_2(double kwotaStartowa) : Portfel(kwotaStartowa) {}
    double przelejUSD(double ile)
    {
        kwotaPLN = kwotaPLN + ile * 3.94;
        return format(kwotaPLN);
    }
    double wyplacUSD(double ile)
    {
        kwotaPLN = kwotaPLN - ile * 3.94;
        return format(kwotaPLN);
    }
};

//------------------------------------------------------------------------------------

int main()
{
    Portfel *mojPortfel = new Portfel();
    cout << "Aktualny stan konta: " << mojPortfel->przelejPLN(30.9) << endl;
    cout << "Aktualny stan konta: " << mojPortfel->przelejEURO(11.7) << endl;
    cout << "Aktualny stan konta: " << mojPortfel->wyplacEURO(5.9) << endl;
    Portfel_2 portfelik(30);
    delete mojPortfel;
    return 0;
}