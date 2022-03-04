#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <fstream>

#include "Markup.h"
#include "Pliki.h"

using namespace std;

class PlikZUzytkownikami:public Pliki
{
    public:
        virtual void dopiszDoPliku();

    protected:

    private:
};

#endif // PLIKZUZYTKOWNIKAMI_H
