#ifndef WYDATEK_H
#define WYDATEK_H


#include <iostream>

using namespace std;

class Wydatek
{
    public:
        void ustawIdWydatku(int nowyIdWydatku);
        void ustawNazweWydatku(string nowaNazwaWydatku);
        void ustawDateWydatku(string nowaDataWydatku);
        void ustawKwotewydatku(float nowaKwotaWydatku);
        int pobierzIdWydatku();
        string pobierzNazweWydatku();
        string pobierzDateWydatku();
        float pobierzKwoteWydatku();

    protected:

    private:
        int idWydatku;
        string nazwaWydatku;
        string dataWydatku;
        float kwotaWydatku;
};


#endif // WYDATEK_H
