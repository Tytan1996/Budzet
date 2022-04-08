#ifndef BUDGET_H
#define BUDGET_H

#include <iostream>

#include "UserManager.h"
#include "BudgetMangager.h"

using namespace std;

class Budget{
public:
    Budget(string nameOfTheFileWithTheUsers, string nameOfTheIncomeFile, string nameOfTheExpenseFile);
    char selectOptionsFromTheMainMenu();
    char selectOptionsFromTheMainUser();
    void userRegistration();//rejestracjaUzytkownika
    void userLogin();//logowanieUzytkownika
    bool whetherTheUserIsLoggedIn();//czyUzytkownikJestZalogowony
    void addAnExpense();//dodajWydatek
    void addAnIncome();//dodajDochod
    void showTheBalanceSheetForTheCurrentMonth();//pokazBilansZBiezaciegoMiesiaca
    void showTheBalanceSheetForThePrevioustMonth();//
    void showTheNalanceSheetOfASpecificPeriod();//pokazBilansZOkreslonegoOkresu
    void changeThePasswordOfTheLoggedInUser();//zmianaHaslaZalogowanegoUzytkownika
    void userLogout();//wylogowanieUzytkownika

protected:

private:
    UserManager userManager;
    BudgetMangager *budgetMangager;
    const string FILENAME_WITH_EXPENSES;
    const string INCOME_FILE_NAME;
};


#endif // BUDGET_H
