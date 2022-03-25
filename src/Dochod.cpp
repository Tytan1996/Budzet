#include "Dochod.h"


Dochod::Dochod(){}
Dochod::Dochod(int idDochodu,int idUzytkownika,string nazwaDochodu, string dataDochodu, float kwotaDochodu, int dataWFormacieInt){
    this->idDochodu=idDochodu;
    this->idUzytkownika=idUzytkownika;
    this->nazwaDochodu=nazwaDochodu;
    this->dataDochodu=dataDochodu;
    this->kwotaDochodu=kwotaDochodu;
    dataDochoduWFormacieInt=dataWFormacieInt;
}
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
void Dochod::ustawDateDochoduWFormacieInt(int data){
    dataDochoduWFormacieInt=data;
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
int Dochod::pobierzDateDochoduWFormacieInt(){
    return dataDochoduWFormacieInt;
}
