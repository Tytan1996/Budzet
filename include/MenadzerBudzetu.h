#ifndef MENADZERBUDZETU_H
#define MENADZERBUDZETU_H

#include <iostream>
#include <vector>
#include "PlikZWydatkami.h"
#include "PlikZDochodami.h"
#include "Wydatek.h"
#include "MetodyPomocnicze.h"

using namespace std;

class MenadzerBudzetu
{
    public:
        MenadzerBudzetu(string nazwaPlikuZWydatkami, string nazwaPlikuZDochodami,int idZaloganegoUzytkownika);
        void dodajWydatek();

    protected:

    private:
        PlikZWydatkami plikZWydatkami;
        PlikZDochodami plikZDochodami;
        const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
        vector <Wydatek> wydatki;
        Wydatek podajDaneNowegoAdresata();

};

#endif // MENADZERBUDZETU_H
