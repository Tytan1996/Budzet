#include "Budzet.h"

Budzet::Budzet(string nazwaPlikuZUzytkownikami,string nazwaPlikuZDochodami, string nazwaPlikuZWydatkami):menadzerUzytkownika(nazwaPlikuZUzytkownikami),NAZWA_PLIKU_Z_DOCHODAMI(nazwaPlikuZDochodami),NAZWA_PLIKU_Z_WYDATKAMI(nazwaPlikuZWydatkami){
}
char Budzet::wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor=MetodyPomocnicze::wczytajZnak();

    return wybor;
}
char Budzet::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor=MetodyPomocnicze::wczytajZnak();

    return wybor;
}
void Budzet::rejestracjaUzytkownika(){
    menadzerUzytkownika.rejestracjaUzytkownika();
}
void Budzet::logowanieUzytkownika(){
    menadzerUzytkownika.logowanieUzytkownika();
    if(menadzerUzytkownika.czyUzytkowikJestZalogowany()){
        menadzerBudzetu=new MenadzerBudzetu(NAZWA_PLIKU_Z_WYDATKAMI,NAZWA_PLIKU_Z_DOCHODAMI,menadzerUzytkownika.pobierzIdNowegoUzytkownika());
    }
}
bool Budzet::czyUzytkownikJestZalogowony(){
    return menadzerUzytkownika.czyUzytkowikJestZalogowany();
}
void Budzet::dodajWydatek(){
    menadzerBudzetu->dodajWydatek();
}
void Budzet::dodajDochod(){
    menadzerBudzetu->dodajDochod();
}
void Budzet::pokazBilansZBiezaciegoMiesiaca(){
    menadzerBudzetu->pokazBilansZBiezacegoMiesiaca();
}
void Budzet::pokazBilansZPoprzedniegoMiesiaca(){
    menadzerBudzetu->pokazBilansZPoprzedniegoMiesiaca();
}
