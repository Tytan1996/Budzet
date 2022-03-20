#include <iostream>
#include "Budzet.h"

using namespace std;

int main()
{
    char wybor;
    Budzet budzet("users.xml", "incomes.xml", "expenses.xml");
    while(true){
        if (budzet.czyUzytkownikJestZalogowony()==false)
            {
            wybor=budzet.wybierzOpcjeZMenuGlownego();
            switch(wybor){
            case '1':
                budzet.rejestracjaUzytkownika();
                break;
            case '2':
                budzet.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }else{
            wybor=budzet.wybierzOpcjeZMenuUzytkownika();
            switch(wybor){
            case '1':
                budzet.dodajDochod();
                break;
            case '2':
                budzet.dodajWydatek();
                break;
            case '3':
                budzet.pokazBilansZBiezaciegoMiesiaca();
                break;
            case '4':
                budzet.pokazBilansZPoprzedniegoMiesiaca();
                break;
            case '5':
                budzet.pokazBilansZOkreslonegoOkresu();
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }

        }

    }
    return 0;
}
