#include <iostream>
#include "Budzet.h"

using namespace std;

int main()
{
    char wybor;
    Budzet budzet("users.xml");

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
            }
        }else{
            wybor=budzet.wybierzOpcjeZMenuUzytkownika();
        }

    }
    return 0;
}
