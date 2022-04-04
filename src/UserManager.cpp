#include "UserManager.h"


UserManager::UserManager(string nazwaPlikuZUzytkownikami):fileWithUsers(nazwaPlikuZUzytkownikami){
    loggedInUserId=0;
    users=fileWithUsers.loadUsersFromFile();
}

void UserManager::userRegistration() {

    User user = enterTheDetailsOfTheNewUser();
    users.push_back(user);
    fileWithUsers.addToTheFile(user);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");


}
User UserManager::enterTheDetailsOfTheNewUser() {
    User user;

    user.settingId(getNewUserId());

    string login;

    do {
        cout << "Podaj login: ";
        cin>>login;
        user.loginSetting(login);
    } while (isThereALogin(user.downloadLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin>>password;
    user.passwordSetting(password);
    string name;
    cout<<"Podaj imie: ";
    cin>>name;
    user.nameSetting(name);
    string surname;
    cout<<"Podaj nazwisko: ";
    cin>>surname;
    user.surnameSetting(surname);
    return user;
}
int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().downloadId() + 1;
}
int UserManager::getLoggedInUserId(){

    return loggedInUserId;

}
bool UserManager::isThereALogin(string login){

    for(int i=0;i<users.size();++i){
        if(users[i].downloadLogin()==login){
            cout<<endl<< "Istnieje uzytkownik o takim loginie." <<endl;
            return true;
        }
    }

    return false;
}
void UserManager::userLogin(){
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::loadLines();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> downloadLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                password = AuxiliaryMethods::loadLines();

                if (itr -> downloadPassword() == password)
                {
                    loggedInUserId=itr->downloadId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return ;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}
bool UserManager::whetherTheUserIsLoggedIn(){
    if(loggedInUserId>0)
        return true;
    else
        return false;
}
void UserManager::changingThePasswordOfTheLoggedIInUser(){
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::loadLines();
    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> downloadId() == loggedInUserId)
        {
            itr -> passwordSetting(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.saveAllUsersToFile(users);

}
void UserManager::userLogout(){
    loggedInUserId=0;
}
