#ifndef MENADZERUZYTKOWNIKA_H
#define MENADZERUZYTKOWNIKA_H

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include <vector>

using namespace std;


class MenadzerUzytkownika
{
    vector <Uzytkownik> uzytkownicy;
    public:
        MenadzerUzytkownika();
        void rejestracjaUzytkownika();

    protected:

    private:
        PlikZUzytkownikami plikZUzytkownikami;

        Uzytkownik podajDaneNowegoUzytkownika();
        int pobierzIdNowegoUzytkownika();
        bool czyIstniejeLogin(string login);

};

#endif // MENADZERUZYTKOWNIKA_H
