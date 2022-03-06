#ifndef PLIKI_H
#define PLIKI_H

#include <iostream>
#include <fstream>
#include "Uzytkownik.h"

using namespace std;

class Pliki
{
    public:
        virtual void dopiszDoPliku(Uzytkownik uzytkownik)=0;
        bool sprawdzCzyPlikIstnieje();
        string pobierzNazwePliku();


    protected:

    private:
        const string NAZWA_PLIKU;
};

#endif // PLIKI_H
