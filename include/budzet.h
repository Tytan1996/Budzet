#ifndef BUDZET_H
#define BUDZET_H

#include <iostream>
#include "MenadzerUzytkownika.h"
#include "MetodyPomocnicze.h"
#include "MenadzerBudzetu.h"



using namespace std;

class Budzet {
public:
    Budzet(string nazwaPlikuZUzytkownikami, string nazwaPlikuZDochodami, string nazwaPlikuZWydatkami);
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    bool czyUzytkownikJestZalogowony();
    void dodajWydatek();

protected:

private:
    MenadzerUzytkownika menadzerUzytkownika;
    MenadzerBudzetu *menadzerBudzetu;
    const string NAZWA_PLIKU_Z_WYDATKAMI;
    const string NAZWA_PLIKU_Z_DOCHODAMI;
};

#endif // BUDZET_H
