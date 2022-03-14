#ifndef MENADZERBUDZETU_H
#define MENADZERBUDZETU_H

#include <iostream>
#include "PlikZWydatkami.h"

using namespace std;

class MenadzerBudzetu
{
    public:
        MenadzerBudzetu(string nazwaPlikuZWydatkami, int idZaloganegoUzytkownika);

    protected:

    private:
        const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
        PlikZWydatkami plikZWydatkami;
};

#endif // MENADZERBUDZETU_H
