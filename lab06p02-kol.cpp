#include <iostream>
#include <string>

using namespace std;
class Zdanie
{
protected:
    string tekst;

public:
    Zdanie(string t) : tekst(t) {}
    Zdanie() : tekst("") {}
    void setTekst(string tekst) { this->tekst = tekst; }
    string getTekst() { return tekst; }
    int getLiczbaLiter() { return tekst.length(); }
    int getLiczbeWyrazow()
    {
        int l_spacji = 0;
        for (int i = 0; i < tekst.length(); i++)
            if (tekst[i] == ' ')
                l_spacji++;
        return l_spacji + 1;
    }
    friend Zdanie operator*(Zdanie z, int ile);
};

Zdanie operator*(Zdanie z, int ile)
{
    string s = "";
    for (int i = 0; i < ile; i++)
        s += z.tekst;
    Zdanie wynik(s);
    return wynik;
}

// -------------------------zdanie 2

class Zdanie_2 : public Zdanie
{
public:
    Zdanie_2(string z) : Zdanie(z)
    {
        for (int i = 0; i < tekst.length(); i++)
            tekst[i] = toupper(tekst[i]);
    }
    Zdanie_2() : Zdanie() {}

    void setTekst(string tekst)
    {
        for (int i = 0; i < tekst.length(); i++)
            tekst[i] = toupper(tekst[i]);
        this->tekst = tekst;
    }

    string getTekst()
    {
        string s = tekst;
        // s[0]= toupper(s[0]);
        for (int i = 1; i < s.length(); i++)
            s[i] = tolower(s[i]);
        return s;
    }
};
//-----------------------------------------------------
int main()
{
    Zdanie tab[] = {Zdanie("aaaa"),
                    Zdanie("bbbb bb"),
                    Zdanie("ccc  cccc")};
    //-------------------------------------------------
    Zdanie *tab2[3];
    for (int i = 0; i < 3; i++)
    {
        tab2[i] = new Zdanie("aaaaaaaaaaa");
    }
    for (int i = 0; i < 3; i++)
        delete tab2[i];

    return 0;
}