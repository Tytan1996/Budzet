#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>


using namespace std;

class Uzytkownik
{
    public:
        void ustawienieID (int nowyID);
        void ustawienieLoginu(string nowyLogin);
        void ustawienieHaslo(string noweHaslo);
        int pobierzID();
        string pobierzLogin();
        string pobierzHaslo();

    protected:

    private:
        int ID;
        string login;
        string haslo;
};

#endif // UZYTKOWNIK_H
