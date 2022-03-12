#ifndef WYDATKI_H
#define WYDATKI_H

#include <iostream>

using namespace std;

class Wydatki
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

#endif // WYDATKI_H
