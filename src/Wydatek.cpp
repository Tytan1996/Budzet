#include "Wydatek.h"

void Wydatek::ustawIdWydatku(int nowyIdWydatku){
    idWydatku=nowyIdWydatku;
}
void Wydatek::ustawIdUzytkownika(int nowyIdUzytkownika){
    idUzytkownika=nowyIdUzytkownika;
}
void Wydatek::ustawNazweWydatku(string nowaNazwaWydatku){
    nazwaWydatku=nowaNazwaWydatku;
}
void Wydatek::ustawDateWydatku(string nowaDataWydatku){
    dataWydatku=nowaDataWydatku;
}
void Wydatek::ustawKwotewydatku(float nowaKwotaWydatku){
    kwotaWydatku=nowaKwotaWydatku;
}
int Wydatek::pobierzIdWydatku(){
    return idWydatku;
}
int Wydatek::pobierzIdUzytkownika(){
    return idUzytkownika;
}
string Wydatek::pobierzNazweWydatku(){
    return nazwaWydatku;
}
string Wydatek::pobierzDateWydatku(){
    return dataWydatku;
}
float Wydatek::pobierzKwoteWydatku(){
    return kwotaWydatku;
}