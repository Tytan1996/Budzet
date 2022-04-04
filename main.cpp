#include <iostream>
#include "Budget.h"

using namespace std;

int main()
{
    char selection;
    Budget budget("users.xml", "incomes.xml", "expenses.xml");
    while(true){
        if (budget.whetherTheUserIsLoggedIn()==false)
            {
            selection=budget.selectOptionsFromTheMainMenu();
            switch(selection){
            case '1':
                budget.userRegistration();
                break;
            case '2':
                budget.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }else{
            selection=budget.selectOptionsFromTheMainUser();
            switch(selection){
            case '1':
                budget.addAnIncome();
                break;
            case '2':
                budget.addAnExpense();
                break;
            case '3':
                budget.showTheBalanceSheetForTheCurrentMonth();
                break;
            case '4':
                budget.showTheBalanceSheetForThePrevioustMonth();
                break;
            case '5':
                budget.showTheNalanceSheetOfASpecificPeriod();
                break;
            case '6':
                budget.changeThePasswordOfTheLoggedInUser();
                break;
            case '7':
                budget.userLogout();
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
