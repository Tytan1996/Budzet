#ifndef MENADZERBUDZETU_H
#define MENADZERBUDZETU_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>
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
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

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
        float kwotaWydatku;
        float kwotaDochodu;
        float bilans;

};

#endif // MENADZERBUDZETU_H
