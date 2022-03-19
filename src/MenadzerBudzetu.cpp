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
void MenadzerBudzetu::dodajDochod(){
    Dochod dochod;
    system("cls");
    cout << " >>> DODAWANIE NOWY DOCHOD <<<" << endl << endl;
    dochod = podajDaneNowegoDochodu();

    dochody.push_back(dochod);
    if(plikZDochodami.dopiszDoPliku(dochod))
        cout<<"Nowy dodatek zostal dodany" <<endl;
    else
        cout<<"Blad. Nie udalo sie dodac nowego dodatku do pliku. "<<endl;
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
    dataWydatku = MetodyPomocnicze::ustawDate();
    cout<< "Podaj kwote wydatku: ";
    kwota = MetodyPomocnicze::wczytajLiczbeZPrzecinkiem();

    wydatek.ustawNazweWydatku(nazwaWydatku);
    wydatek.ustawDateWydatku(dataWydatku);
    wydatek.ustawKwotewydatku(kwota);

    return wydatek;
}
Dochod MenadzerBudzetu::podajDaneNowegoDochodu(){
    Dochod dochod;
    string nazwaDochodu,dataDochodu;
    float kwota;
    dochod.ustawIdDochodu(pobierzIdNowegoDochodu());
    dochod.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj nazwa dochodu: ";
    nazwaDochodu = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj data dochodu: ";
    dataDochodu = MetodyPomocnicze::ustawDate();
    cout<< "Podaj kwote dochodu: ";
    kwota = MetodyPomocnicze::wczytajLiczbeZPrzecinkiem();

    dochod.ustawNazweDochodu(nazwaDochodu);
    dochod.ustawDateDochodu(dataDochodu);
    dochod.ustawKwoteDochodu(kwota);

    return dochod;

}
int MenadzerBudzetu::pobierzIdNowegoWydatku() {
    if (wydatki.empty() == true)
        return 1;
    else
        return wydatki.back().pobierzIdWydatku() + 1;
}
int MenadzerBudzetu::pobierzIdNowegoDochodu() {
    if (dochody.empty() == true)
        return 1;
    else
        return dochody.back().pobierzIdDochodu() + 1;
}
