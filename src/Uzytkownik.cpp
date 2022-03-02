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
int Uzytkownik::pobierzID(){
    return ID;
}
string Uzytkownik::pobierzLogin(){
    return login;
}
string Uzytkownik::pobierzHaslo(){
    return haslo;
}
