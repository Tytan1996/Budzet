#ifndef MENADZERUZYTKOWNIK_H
#define MENADZERUZYTKOWNIK_H

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include <vector>

using namespace std;


class MenadzerUzytkownik
{
    vector <Uzytkownik> uzytkownicy;
    public:
        void rejestracjaUzytkownika();

    protected:

    private:
        PlikZUzytkownikami plikZUzytkownikami;

        Uzytkownik podajDaneNowegoUzytkownika();
        int pobierzIdNowegoUzytkownika();
        bool czyIstniejeLogin(string login);

};

#endif // MENADZERUZYTKOWNIK_H
