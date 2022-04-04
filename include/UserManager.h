#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"
#include <vector>

using namespace std;

class UserManager
{
    public:
        UserManager(string nazwaPlikuZUzytkownikami);
        void userRegistration();
        void userLogin();
        bool whetherTheUserIsLoggedIn();
        int getNewUserId();
        int getLoggedInUserId();
        void changingThePasswordOfTheLoggedIInUser();
        void userLogout();

    protected:

    private:
        int loggedInUserId;
        FileWithUsers fileWithUsers;
        User enterTheDetailsOfTheNewUser();
        bool isThereALogin(string login);
        vector <User> users;
};

#endif // USERMANAGER_H
