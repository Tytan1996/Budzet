#include "Dochod.h"

void Dochod::ustawIdDochodu(int nowyIdDochodu){
    idDochodu=nowyIdDochodu;
}
void Dochod::ustawIdUzytkownika(int nowyIdUzytkownika){
    idUzytkownika=nowyIdUzytkownika;
}
void Dochod::ustawNazweDochodu(string nowaNazwaDochodu){
    nazwaDochodu=nowaNazwaDochodu;
}
void Dochod::ustawDateDochodu(string nowaDataDochodu){
    dataDochodu=nowaDataDochodu;
}
void Dochod::ustawKwoteDochodu(float nowaKwotaDochodu){
    kwotaDochodu=nowaKwotaDochodu;
}
int Dochod::pobierzIdDochodu(){
    return idDochodu;
}
int Dochod::pobierzIdUzytkownika(){
    return idUzytkownika;
}
string Dochod::pobierzNazweDochodu(){
    return nazwaDochodu;
}
string Dochod::pobierzDateDochodu(){
    return dataDochodu;
}
float Dochod::pobierzKwoteDochodu(){
    return kwotaDochodu;
}
