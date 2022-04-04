#include "Files.h"

Files::Files(string nazwaPlikuZUzytkownikami):FILE_NAME(nazwaPlikuZUzytkownikami){

}

string Files::getFilename() {
    return FILE_NAME;
}

bool Files::checkIfTheFileExists(){
    bool pusty = true;
    fstream plikTekstowy;
    plikTekstowy.open(getFilename().c_str(), ios::app);

    if (plikTekstowy.good() == true) {
        plikTekstowy.seekg(0, ios::end);
        if (plikTekstowy.tellg() != 0)
            pusty = false;
    }

    plikTekstowy.close();
    return pusty;
}
