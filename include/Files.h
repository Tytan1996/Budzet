#ifndef FILES_H
#define FILES_H

#include <iostream>


using namespace std;

class Files
{
    public:
        Files(string nameOfTheFileWithTheUsers);
        bool checkIfTheFileExists();
        string getFilename();


    protected:

    private:
        string FILE_NAME;
};

#endif // FILES_H
