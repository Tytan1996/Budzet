#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <fstream>
#include <vector>

#include "Markup.h"
#include "Pliki.h"
#include "Uzytkownik.h"

using namespace std;

class PlikZUzytkownikami:public Pliki
{
    public:
        virtual void dopiszDoPliku(Uzytkownik uzytkownik);
        vector<Uzytkownik> wczytajUzytkownikowZPliku();

    protected:

    private:
};

#endif // PLIKZUZYTKOWNIKAMI_H
