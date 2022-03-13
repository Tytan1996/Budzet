#ifndef PLIKZWYDATKAMI_H
#define PLIKZWYDATKAMI_H


#include <iostream>
#include "Pliki.h"
#include "Wydatek.h"
#include "Markup.h"

using namespace std;

class PlikZWydatkami:public Pliki
{
    public:
        PlikZWydatkami(string nazwaPlikuZWydatkami);
        virtual void dopiszDoPliku(Wydatek wydatek);

    protected:

    private:
};

#endif // PLIKZWYDATKAMI_H
