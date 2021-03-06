#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>

#include "Files.h"
#include "User.h"

using namespace std;

class FileWithUsers:public Files
{
    public:
        FileWithUsers(string nameOfTheFileWithTheUsers);
        virtual void addToTheFile(User user);
        vector<User> loadUsersFromFile();
        void saveAllUsersToFile(vector <User> &users);

    protected:

    private:
};

#endif // FILEWITHUSERS_H
