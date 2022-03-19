#ifndef DOCHOD_H
#define DOCHOD_H

#include <iostream>

using namespace std;

class Dochod
{
    public:
        void ustawIdDochodu(int nowyIdDochodu);
        void ustawIdUzytkownika(int nowyIdUzytkownika);
        void ustawNazweDochodu(string nowaNazwaDochodu);
        void ustawDateDochodu(string nowaDataDochodu);
        void ustawKwoteDochodu(float nowaKwotaDochodu);
        int pobierzIdDochodu();
        int pobierzIdUzytkownika();
        string pobierzNazweDochodu();
        string pobierzDateDochodu();
        float pobierzKwoteDochodu();

    protected:

    private:
        int idDochodu;
        int idUzytkownika;
        string nazwaDochodu;
        string dataDochodu;
        float kwotaDochodu;
};

#endif // DOCHOD_H
