#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <map>
#include <cstdlib>

using namespace std;

class MetodyPomocnicze
{
    public:
        static char wczytajZnak();
        static string wczytajLinie();
        static int wczytajLiczbeCalkowita();
        static float wczytajLiczbeZPrzecinkiem();
        static string pobierzAktualnaDate();
        static string pobierzDate();
        static map<int,int> pobierzIloscDniWMiesiaciu(int rok);

    protected:

    private:
};

#endif // METODYPOMOCNICZE_H
