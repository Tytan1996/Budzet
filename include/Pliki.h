#ifndef PLIKI_H
#define PLIKI_H

#include <iostream>

using namespace std;

class Pliki
{
    public:
        virtual void dopiszDoPliku()=0;
        virtual void wyciagnijOdPliku()=0;
        virtual void poprawDanieWPliku()=0;

    protected:

    private:
};

#endif // PLIKI_H
