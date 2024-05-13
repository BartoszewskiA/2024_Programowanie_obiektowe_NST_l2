#include <iostream>
#include <ctime>

using namespace std;

class Random
{
    private:
        string kolory[4] = {"Kier", "Trefl", "Karo", "Pik"};
        string wartosci[13] = {
            "2", "3", "4", "5", "6", "7", "8", "9", "10",
            "Walet", "Dama", "Krol", "As"};

    public:
        Random() { srand(time(NULL)); }
        int nextInt()
        {
            return rand();
    }
    int nextInt(int max)
    {
        return rand() % max;
    }
    int nextInt(int min, int max)
    {
        return rand() % (max - min) + min;
    }
    double nextDouble() // 0-0,9999
    {
        return (rand() % 10000) / 10000.0;
    }
    int nextKostka()
    {
        return nextInt(1,7);
    }
    int nextKostka(int ileScian)
    {
        return nextInt(1, ileScian+1);
    }
    string nextKarta() // wylosowana katra jest odkladana do talii
    {
        int wartosc = nextInt(13);
        int kolor = nextInt(4);
        string odpowiedz = "";
        odpowiedz += wartosci[wartosc];
        odpowiedz += "-";
        odpowiedz += kolory[kolor];
        return odpowiedz;
    }
};

int main()
{
    Random random;
    for (int i = 0; i < 20; i++)
    {
        cout << random.nextInt(100) << "\t" << random.nextInt(-100, 50) << "\t" << random.nextDouble() <<"\t"<<random.nextKostka()<<"\t"<<random.nextKarta()<< endl;
    }
    return 0;
}