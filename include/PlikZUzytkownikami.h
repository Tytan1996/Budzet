#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>

#include "Markup.h"
#include "Pliki.h"
#include "Uzytkownik.h"

using namespace std;

class PlikZUzytkownikami:public Pliki
{
    public:
        PlikZUzytkownikami(string nazwaPlikuZUzytkownikami);
        virtual void dopiszDoPliku(Uzytkownik uzytkownik);
        vector<Uzytkownik> wczytajUzytkownikowZPliku();
        void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);

    protected:

    private:
};

#endif // PLIKZUZYTKOWNIKAMI_H
