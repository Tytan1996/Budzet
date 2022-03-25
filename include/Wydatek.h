#ifndef WYDATEK_H
#define WYDATEK_H


#include <iostream>

using namespace std;

class Wydatek
{
    public:
        Wydatek();
        Wydatek(int idWydatku,int idUzytkownika,string nazwaWydatku, string dataWydatku, float kwotaWydatku, int dataWFormacieInt);
        void ustawIdWydatku(int nowyIdWydatku);
        void ustawIdUzytkownika(int nowyIdUzytkownika);
        void ustawNazweWydatku(string nowaNazwaWydatku);
        void ustawDateWydatku(string nowaDataWydatku);
        void ustawKwotewydatku(float nowaKwotaWydatku);
        void ustawDateWydatkuWFormieInt(int data);
        int pobierzIdWydatku();
        int pobierzIdUzytkownika();
        string pobierzNazweWydatku();
        string pobierzDateWydatku();
        float pobierzKwoteWydatku();
        int pobierzDateWydatkuWFormiacieInt();
        bool operator < (const Wydatek& str) const
        {
            return (dataWydatkuWFormacieInt < str.dataWydatkuWFormacieInt);
        }

    protected:

    private:
        int idWydatku;
        int idUzytkownika;
        string nazwaWydatku;
        string dataWydatku;
        float kwotaWydatku;
        int dataWydatkuWFormacieInt;
};


#endif // WYDATEK_H
