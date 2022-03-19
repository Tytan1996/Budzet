#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

using namespace std;

class MetodyPomocnicze
{
    public:
        static char wczytajZnak();
        static string wczytajLinie();
        static int wczytajLiczbeCalkowita();
        static float wczytajLiczbeZPrzecinkiem();
        static string pobierzAktualnaDate();

    protected:

    private:
};

#endif // METODYPOMOCNICZE_H
