#ifndef BUDZET_H
#define BUDZET_H

#include <iostream>
#include "MenadzerUzytkownika.h"
#include "MetodyPomocnicze.h"


using namespace std;

class Budzet {
public:
    Budzet(string nazwaPlikuZUzytkownikami);
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    bool czyUzytkownikJestZalogowony();

protected:

private:
    MenadzerUzytkownika menadzerUzytkownika;
};

#endif // BUDZET_H
