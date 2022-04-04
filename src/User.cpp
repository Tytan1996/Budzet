#include "User.h"


User::User(){
}

User::User(int id,string login,string password,string name,string surname){
    this->id=id;
    this->login=login;
    this->password=password;
    this->name=name;
    this->surname=surname;
}

void User::settingId(int newId){
    id=newId;
}
void User::loginSetting(string newLogin){
    login=newLogin;
}
void User::passwordSetting(string newPassword){
    password=newPassword;
}
void User::nameSetting(string newName){
    name=newName;
}
void User::surnameSetting(string newSurname){
    surname=newSurname;
}
int User::downloadId(){
    return id;
}
string User::downloadLogin(){
    return login;
}
string User::downloadPassword(){
    return password;
}
string User::downloadName(){
    return name;
}
string User::downloadSurname(){
    return surname;
}
