#include "FileWithUsers.h"
#include <fstream>
#include <stdio.h>

#include "Markup.h"


FileWithUsers::FileWithUsers(string nameOfTheFileWithTheUsers):Files(nameOfTheFileWithTheUsers){

}

void FileWithUsers::addToTheFile(User user){


    CMarkup xml;

    bool fileExists = xml.Load( getFilename() );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.downloadId());
    xml.AddElem("Login", user.downloadLogin());
    xml.AddElem("Password", user.downloadPassword());
    xml.AddElem("Name", user.downloadName());
    xml.AddElem("Surname", user.downloadSurname());

    xml.Save(getFilename());

}
vector<User> FileWithUsers::loadUsersFromFile()
{
    CMarkup xml;
    vector <User> uzytkownicy;
    bool fileExists = xml.Load( getFilename() );
    int id;
    string login, password, name, surname;

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("User")){
            xml.FindChildElem();
            id=atoi(xml.GetChildData().c_str());
            xml.FindChildElem();
            login=xml.GetChildData();
            xml.FindChildElem();
            password=xml.GetChildData();
            xml.FindChildElem();
            name=xml.GetChildData();
            xml.FindChildElem();
            surname=xml.GetChildData();
            User user(id,login,password,name,surname);
            uzytkownicy.push_back(user);
        }

    }
    return uzytkownicy;
}
void FileWithUsers::saveAllUsersToFile(vector <User> &users){

    CMarkup xml;

    bool fileExists = xml.Load( getFilename() );
    if (fileExists){
        remove(getFilename().c_str());
    }

    for(vector <User>::iterator itr = users.begin(); itr != users.end(); itr++){
        addToTheFile(*itr);
    }

}
