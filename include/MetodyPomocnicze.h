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
        static string pobierzDate();
        static int zamienDateZStringNaInt(string data);

    protected:

    private:
        static string pobierzAktualnaDate();
        static string dodajZeroDoDaty(string data);
        static bool sprawdzDate(string data);

};

#endif // METODYPOMOCNICZE_H
