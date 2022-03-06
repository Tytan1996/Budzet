#include "Uzytkownik.h"

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
