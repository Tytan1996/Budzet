#ifndef DOCHOD_H
#define DOCHOD_H

#include <iostream>

using namespace std;

class Dochod
{
    public:
        Dochod();
        Dochod(int idDochodu,int idUzytkownika,string nazwaDochodu, string dataDochodu, float kwotaDochodu,int dataWFormacieInt);
        void ustawIdDochodu(int nowyIdDochodu);
        void ustawIdUzytkownika(int nowyIdUzytkownika);
        void ustawNazweDochodu(string nowaNazwaDochodu);
        void ustawDateDochodu(string nowaDataDochodu);
        void ustawKwoteDochodu(float nowaKwotaDochodu);
        void ustawDateDochoduWFormacieInt(int data);
        int pobierzIdDochodu();
        int pobierzIdUzytkownika();
        string pobierzNazweDochodu();
        string pobierzDateDochodu();
        float pobierzKwoteDochodu();
        int pobierzDateDochoduWFormacieInt();
        bool operator < (const Dochod& str) const
        {
            return (dataDochoduWFormacieInt < str.dataDochoduWFormacieInt);
        }

    protected:

    private:
        int idDochodu;
        int idUzytkownika;
        string nazwaDochodu;
        string dataDochodu;
        float kwotaDochodu;
        int dataDochoduWFormacieInt;
};

#endif // DOCHOD_H
