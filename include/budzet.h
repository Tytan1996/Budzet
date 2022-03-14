#ifndef BUDZET_H
#define BUDZET_H

#include <iostream>
#include "MenadzerUzytkownika.h"
#include "MetodyPomocnicze.h"
#include "MenadzerBudzetu.h"



using namespace std;

class Budzet {
public:
    Budzet(string nazwaPlikuZUzytkownikami);
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
};

#endif // BUDZET_H
