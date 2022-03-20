#ifndef MENADZERUZYTKOWNIKA_H
#define MENADZERUZYTKOWNIKA_H

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "MetodyPomocnicze.h"
#include <vector>

using namespace std;


class MenadzerUzytkownika
{
    public:
        MenadzerUzytkownika(string nazwaPlikuZUzytkownikami);
        void rejestracjaUzytkownika();
        void logowanieUzytkownika();
        bool czyUzytkowikJestZalogowany();
        int pobierzIdNowegoUzytkownika();
        void wylogowanieUzytkownika();

    protected:

    private:
        int idZalogowanegoUzytkownika;
        PlikZUzytkownikami plikZUzytkownikami;
        Uzytkownik podajDaneNowegoUzytkownika();
        bool czyIstniejeLogin(string login);
        vector <Uzytkownik> uzytkownicy;


};

#endif // MENADZERUZYTKOWNIKA_H
