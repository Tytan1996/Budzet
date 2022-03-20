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
        static map<int,int> pobierzIloscDniWMiesiaciu(int rok);
        static string ustawDate();
        static string pobierzMiesiac();

    protected:

    private:
        static string pobierzAktualnaDate();
        static string pobierzDate();
};

#endif // METODYPOMOCNICZE_H
