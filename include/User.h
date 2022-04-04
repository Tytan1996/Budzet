#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    public:
        User ();
        User (int id,string login,string password,string name,string surname);
        void settingId (int newId);//ustawienieId
        void loginSetting(string newLogin);//ustawienieLoginu
        void passwordSetting(string newPassword);//ustawienieHaslo
        void nameSetting(string newName);
        void surnameSetting(string newSurname);
        int downloadId();
        string downloadLogin();
        string downloadPassword();
        string downloadName();
        string downloadSurname();

    protected:

    private:
        int id;
        string login;
        string password;
        string name;
        string surname;
};

#endif // USER_H
