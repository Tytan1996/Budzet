#include "MenadzerBudzetu.h"

MenadzerBudzetu::MenadzerBudzetu(string nazwaPlikuZWydatkami,int idZaloganegoUzytkownika):plikZWydatkami(nazwaPlikuZWydatkami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZaloganegoUzytkownika){
}
void MenadzerBudzetu::dodajWydatek(){
    Wydatek wydatek;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    wydatek = podajDaneNowegoAdresata();

    wydatki.push_back(wydatek);
    if(plikZWydatkami.dopiszDoPliku(wydatek))
        cout<<"Nowy wydatek zostal dodany" <<endl;
    else
        cout<<"Blad. Nie udalo sie dodac nowego wydatek do pliku. "<<endl;
    system("pause");
}
Wydatek MenadzerBudzetu::podajDaneNowegoAdresata(){
    Wydatek wydatek;
    string nazwaWydatku,dataWydatku;
    float kwota;
    wydatek.ustawIdWydatku(1);
    wydatek.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj nazwa wydatku: ";
    nazwaWydatku = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj data wydatku: ";
    dataWydatku = MetodyPomocnicze::wczytajLinie();
    cout<< "Podaj kwote wydatku: ";
    kwota = MetodyPomocnicze::wczytajLiczbeZPrzecinkiem();

    wydatek.ustawNazweWydatku(nazwaWydatku);
    wydatek.ustawDateWydatku(nazwaWydatku);
    wydatek.ustawKwotewydatku(kwota);

    return wydatek;
}
