#ifndef FILES_H
#define FILES_H

#include <iostream>
#include <fstream>
#include "User.h"

using namespace std;

class Files
{
    public:
        Files(string nazwaPlikuZUzytkownikami);
        bool checkIfTheFileExists();
        string getFilename();


    protected:

    private:
        string FILE_NAME;
};

#endif // FILES_H
