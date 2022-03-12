#include "Pliki.h"

Pliki::Pliki(string nazwaPlikuZUzytkownikami):NAZWA_PLIKU(nazwaPlikuZUzytkownikami){

}

string Pliki::pobierzNazwePliku() {
    return NAZWA_PLIKU;
}

bool Pliki::sprawdzCzyPlikIstnieje(){
    bool pusty = true;
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);

    if (plikTekstowy.good() == true) {
        plikTekstowy.seekg(0, ios::end);
        if (plikTekstowy.tellg() != 0)
            pusty = false;
    }

    plikTekstowy.close();
    return pusty;
}

