#include "Wydatek.h"

Wydatek::Wydatek(){}

Wydatek::Wydatek(int idWydatku,int idUzytkownika,string nazwaWydatku, string dataWydatku, float kwotaWydatku,int dataWFormacieInt){
    this->idWydatku=idWydatku;
    this->idUzytkownika=idUzytkownika;
    this->nazwaWydatku=nazwaWydatku;
    this->dataWydatku=dataWydatku;
    this->kwotaWydatku=kwotaWydatku;
    dataWydatkuWFormacieInt=dataWFormacieInt;
}

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
void Wydatek::ustawDateWydatkuWFormieInt(int data){
    dataWydatkuWFormacieInt=data;
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
int Wydatek::pobierzDateWydatkuWFormiacieInt(){
    return dataWydatkuWFormacieInt;
}
