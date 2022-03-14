#ifndef WYDATEK_H
#define WYDATEK_H


#include <iostream>

using namespace std;

class Wydatek
{
    public:
        void ustawIdWydatku(int nowyIdWydatku);
        void ustawIdUzytkownika(int nowyIdUzytkownika);
        void ustawNazweWydatku(string nowaNazwaWydatku);
        void ustawDateWydatku(string nowaDataWydatku);
        void ustawKwotewydatku(float nowaKwotaWydatku);
        int pobierzIdWydatku();
        int pobierzIdUzytkownika();
        string pobierzNazweWydatku();
        string pobierzDateWydatku();
        float pobierzKwoteWydatku();

    protected:

    private:
        int idWydatku;
        int idUzytkownika;
        string nazwaWydatku;
        string dataWydatku;
        float kwotaWydatku;
};


#endif // WYDATEK_H
