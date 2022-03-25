#ifndef MENADZERBUDZETU_H
#define MENADZERBUDZETU_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "PlikZWydatkami.h"
#include "PlikZDochodami.h"
#include "Wydatek.h"
#include "Dochod.h"
#include "MetodyPomocnicze.h"

using namespace std;

class MenadzerBudzetu
{
    public:
        MenadzerBudzetu(string nazwaPlikuZDochodami, string nazwaPlikuZWydatkami,int idZaloganegoUzytkownika);
        void dodajWydatek();
        void dodajDochod();
        void pokazBilansZBiezacegoMiesiaca();
        void pokazBilansZPoprzedniegoMiesiaca();
        void pokazBilansZOkreslonegoOkresu();

    protected:

    private:
        PlikZWydatkami plikZWydatkami;
        PlikZDochodami plikZDochodami;
        const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
        vector <Wydatek> wydatki;
        vector <Dochod> dochody;
        Wydatek podajDaneNowegoWydatku();
        Dochod podajDaneNowegoDochodu();
        void wyswietlDaneWydatku(Wydatek wydatek);
        void wyswietlDaneDochodu(Dochod dochod);
        bool sprawdzDate(string data);
        bool sprawdzDatePoprzednegoMiesiaca(string data);
        bool sprawdzOkres(string data,string od,string doKoncaBilansu);
        string pobierzDate();

};

#endif // MENADZERBUDZETU_H
