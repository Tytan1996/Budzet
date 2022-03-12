#include "Budzet.h"

Budzet::Budzet(string nazwaPlikuZUzytkownikami):menadzerUzytkownika(nazwaPlikuZUzytkownikami){

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
}
bool Budzet::czyUzytkownikJestZalogowony(){
    return menadzerUzytkownika.czyUzytkowikJestZalogowany();
}
