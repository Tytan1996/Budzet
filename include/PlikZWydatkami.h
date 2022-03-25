#ifndef PLIKZWYDATKAMI_H
#define PLIKZWYDATKAMI_H


#include <iostream>
#include <vector>
#include "Pliki.h"
#include "Wydatek.h"
#include "Markup.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZWydatkami:public Pliki
{
    public:
        PlikZWydatkami(string nazwaPlikuZWydatkami);
        bool dopiszDoPliku(Wydatek wydatek);
        vector <Wydatek> wczytajWydatkowZalogowaniegoUzytkownika(int idZalogowanieUzytkownika);
        int pobierzIdOstatniegoWydatku();

    protected:

    private:
        int idOstatniegoWydatku;
        Wydatek wydatek;
        vector <Wydatek> wydatki;

};

#endif // PLIKZWYDATKAMI_H
