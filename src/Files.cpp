#include "Files.h"
#include <fstream>
#include "User.h"

Files::Files(string nameOfTheFileWithTheUsers):FILE_NAME(nameOfTheFileWithTheUsers){

}

string Files::getFilename() {
    return FILE_NAME;
}

bool Files::checkIfTheFileExists(){
    bool empty = true;
    fstream textFile;
    textFile.open(getFilename().c_str(), ios::app);

    if (textFile.good() == true) {
        textFile.seekg(0, ios::end);
        if (textFile.tellg() != 0)
            empty = false;
    }

    textFile.close();
    return empty;
}
