#ifndef MENADZERBUDZETU_H
#define MENADZERBUDZETU_H

#include <iostream>
#include <vector>
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

    protected:

    private:
        PlikZWydatkami plikZWydatkami;
        PlikZDochodami plikZDochodami;
        const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
        vector <Wydatek> wydatki;
        vector <Dochod> dochody;
        Wydatek podajDaneNowegoWydatku();
        Dochod podajDaneNowegoDochodu();
        int pobierzIdNowegoWydatku();
        int pobierzIdNowegoDochodu();

};

#endif // MENADZERBUDZETU_H
