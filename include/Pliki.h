#ifndef PLIKI_H
#define PLIKI_H

#include <iostream>
#include <fstream>

using namespace std;

class Pliki
{
    public:
        virtual void dopiszDoPliku()=0;
        virtual void wyciagnijOdPliku()=0;
        virtual void poprawDanieWPliku()=0;
        bool sprawdzCzyPlikIstnieje();
        string pobierzNazwePliku();


    protected:

    private:
        const string NAZWA_PLIKU;
};

#endif // PLIKI_H
