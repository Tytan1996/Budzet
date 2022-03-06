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
        void ustawName(string noweName);
        void ustawSurname(string noweSurname);
        int pobierzID();
        string pobierzLogin();
        string pobierzHaslo();
        string pobierzName();
        string pobierzSurname();

    protected:

    private:
        int ID;
        string login;
        string haslo;
        string name;
        string surname;
};

#endif // UZYTKOWNIK_H
