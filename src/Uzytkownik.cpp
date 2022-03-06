#include "Uzytkownik.h"


Uzytkownik::Uzytkownik(){
}

Uzytkownik::Uzytkownik(int id,string login,string haslo,string name,string surname){
    ID=id;
    this->login=login;
    this->haslo=haslo;
    this->name=name;
    this->surname=surname;
}

void Uzytkownik::ustawienieID(int nowyID){
    ID=nowyID;
}
void Uzytkownik::ustawienieLoginu(string nowyLogin){
    login=nowyLogin;
}
void Uzytkownik::ustawienieHaslo(string noweHaslo){
    haslo=noweHaslo;
}
void Uzytkownik::ustawName(string noweName){
    name=noweName;
}
void Uzytkownik::ustawSurname(string noweSurname){
    surname=noweSurname;
}
int Uzytkownik::pobierzID(){
    return ID;
}
string Uzytkownik::pobierzLogin(){
    return login;
}
string Uzytkownik::pobierzHaslo(){
    return haslo;
}
string Uzytkownik::pobierzName(){
    return name;
}
string Uzytkownik::pobierzSurname(){
    return surname;
}
