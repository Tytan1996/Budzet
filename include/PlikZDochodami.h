#ifndef PLIKZDOCHODAMI_H
#define PLIKZDOCHODAMI_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "Pliki.h"
#include "Dochod.h"

using namespace std;

class PlikZDochodami:public Pliki
{
    public:
        PlikZDochodami(string nazwaPlikuZDochodami);
        bool dopiszDoPliku(Dochod dochod);
        vector <Dochod> wczytajDochodyZalogowaniegoUzytkownika(int idZalogowanieUzytkownika);

    protected:

    private:
        Dochod dochod;
        vector <Dochod> dochody;

};

#endif // PLIKZDOCHODAMI_H
