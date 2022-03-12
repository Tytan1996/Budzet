#include "Wydatki.h"

void Wydatki::ustawIdWydatku(int nowyIdWydatku){
    idWydatku=nowyIdWydatku;
}
void Wydatki::ustawNazweWydatku(string nowaNazwaWydatku){
    nazwaWydatku=nowaNazwaWydatku;
}
void Wydatki::ustawDateWydatku(string nowaDataWydatku){
    dataWydatku=nowaDataWydatku;
}
void Wydatki::ustawKwotewydatku(float nowaKwotaWydatku){
    kwotaWydatku=nowaKwotaWydatku;
}
int Wydatki::pobierzIdWydatku(){
    return idWydatku;
}
string Wydatki::pobierzNazweWydatku(){
    return nazwaWydatku;
}
string Wydatki::pobierzDateWydatku(){
    return dataWydatku;
}
float Wydatki::pobierzKwoteWydatku(){
    return kwotaWydatku;
}
