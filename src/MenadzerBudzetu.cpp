#include "MenadzerBudzetu.h"

MenadzerBudzetu::MenadzerBudzetu(string nazwaPlikuZWydatkami,string nazwaPlikuZDochodami,int idZaloganegoUzytkownika):plikZWydatkami(nazwaPlikuZWydatkami),plikZDochodami(nazwaPlikuZDochodami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZaloganegoUzytkownika){
    wydatki=plikZWydatkami.wczytajWydatkowZalogowaniegoUzytkownika(idZaloganegoUzytkownika);
    dochody=plikZDochodami.wczytajDochodyZalogowaniegoUzytkownika(idZaloganegoUzytkownika);
}
void MenadzerBudzetu::dodajWydatek(){
    Wydatek wydatek;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    wydatek = podajDaneNowegoWydatku();

    wydatki.push_back(wydatek);
    if(plikZWydatkami.dopiszDoPliku(wydatek))
        cout<<"Nowy wydatek zostal dodany" <<endl;
    else
        cout<<"Blad. Nie udalo sie dodac nowego wydatek do pliku. "<<endl;
    system("pause");
}
Wydatek MenadzerBudzetu::podajDaneNowegoWydatku(){
    Wydatek wydatek;
    string nazwaWydatku,dataWydatku;
    float kwota;
    wydatek.ustawIdWydatku(pobierzIdNowegoWydatku());
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
int MenadzerBudzetu::pobierzIdNowegoWydatku() {
    if (wydatki.empty() == true)
        return 1;
    else
        return wydatki.back().pobierzIdWydatku() + 1;
}

