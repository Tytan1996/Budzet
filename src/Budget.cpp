#include "Budget.h"

Budget::Budget(string nameOfTheFileWithTheUsers,string nameOfTheIncomeFile, string nameOfTheExpenseFile):userManager(nameOfTheFileWithTheUsers),INCOME_FILE_NAME(nameOfTheIncomeFile),FILENAME_WITH_EXPENSES(nameOfTheExpenseFile){
}
char Budget::selectOptionsFromTheMainMenu()
{
    char selection;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    selection=AuxiliaryMethods::loadCharacter();

    return selection;
}
char Budget::selectOptionsFromTheMainUser()
{
    char selection;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    selection=AuxiliaryMethods::loadCharacter();

    return selection;
}
void Budget::userRegistration(){
    userManager.userRegistration();
}
void Budget::userLogin(){
    userManager.userLogin();
    if(userManager.whetherTheUserIsLoggedIn()){
        budgetMangager=new BudgetMangager(FILENAME_WITH_EXPENSES,INCOME_FILE_NAME,userManager.getLoggedInUserId());
    }
}
bool Budget::whetherTheUserIsLoggedIn(){
    return userManager.whetherTheUserIsLoggedIn();
}
void Budget::addAnExpense(){
    budgetMangager->addAnExpense();
}
void Budget::addAnIncome(){
    budgetMangager->addIncome();
}
void Budget::showTheBalanceSheetForTheCurrentMonth(){
    budgetMangager->showTheBalanceSheetForTheCurrentMonth();
}
void Budget::showTheBalanceSheetForThePrevioustMonth(){
    budgetMangager->showTheBalanceSheetForThePreviousMonth();
}
void Budget::showTheNalanceSheetOfASpecificPeriod(){
    budgetMangager->showTheBalanceSheetForASpecificPeriod();
}
void Budget::changeThePasswordOfTheLoggedInUser(){
    userManager.changingThePasswordOfTheLoggedIInUser();
}
void Budget::userLogout(){
    userManager.userLogout();
    delete budgetMangager;
    budgetMangager=NULL;
}
