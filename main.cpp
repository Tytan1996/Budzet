#include <iostream>
#include "Budzet.h"

using namespace std;

int main()
{
    char wybor;
    Budzet budzet;

    while(true){
        wybor=budzet.wybierzOpcjeZMenuGlownego();
        switch(wybor){
        case '1':
            budzet.rejestracjaUzytkownika();
            break;
        }
    }
    return 0;
}
