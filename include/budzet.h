#ifndef BUDZET_H
#define BUDZET_H

#include <iostream>
#include "MenadzerUzytkownik.h"

using namespace std;

class Budzet
{
    public:
        char wybierzOpcjeZMenuGlownego();
        char wybierzOpcjeZMenuUzytkownika();
        void rejestracjaUzytkownika();

    protected:

    private:
        MenadzerUzytkownik menadzerUzytkownik;
};

#endif // BUDZET_H
