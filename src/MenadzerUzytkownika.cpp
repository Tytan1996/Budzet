#include "MenadzerUzytkownika.h"


MenadzerUzytkownika::MenadzerUzytkownika(string nazwaPlikuZUzytkownikami):plikZUzytkownikami(nazwaPlikuZUzytkownikami){
    idZalogowanegoUzytkownika=0;
    uzytkownicy=plikZUzytkownikami.wczytajUzytkownikowZPliku();
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
void MenadzerUzytkownika::logowanieUzytkownika(){
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (itr -> pobierzHaslo() == haslo)
                {
                    idZalogowanegoUzytkownika=itr->pobierzID();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return ;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}
bool MenadzerUzytkownika::czyUzytkowikJestZalogowany(){
    if(idZalogowanegoUzytkownika>0)
        return true;
    else
        return false;
}
