#include "MenadzerUzytkownika.h"


MenadzerUzytkownika::MenadzerUzytkownika(){

}

void MenadzerUzytkownika::rejestracjaUzytkownika() {

    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();
    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszDoPliku(uzytkownik);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");


}
Uzytkownik MenadzerUzytkownika::podajDaneNowegoUzytkownika() {
    Uzytkownik uzytkownik;

    uzytkownik.ustawienieID(pobierzIdNowegoUzytkownika());

    string login;

    do {
        cout << "Podaj login: ";
        cin>>login;
        uzytkownik.ustawienieLoginu(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin>>haslo;
    uzytkownik.ustawienieHaslo(haslo);
    string name;
    cout<<"Podaj imie: ";
    cin>>name;
    uzytkownik.ustawName(name);
    string surname;
    cout<<"Podaj nazwisko: ";
    cin>>surname;
    uzytkownik.ustawSurname(surname);
    return uzytkownik;
}
int MenadzerUzytkownika::pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzID() + 1;
}
bool MenadzerUzytkownika::czyIstniejeLogin(string login){

    for(int i=0;i<uzytkownicy.size();++i){
        if(uzytkownicy[i].pobierzLogin()==login){
            cout<<endl<< "Istnieje uzytkownik o takim loginie." <<endl;
            return true;
        }
    }

    return false;

}
