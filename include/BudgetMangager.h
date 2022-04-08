#ifndef BUDGETMANGAGER_H
#define BUDGETMANGAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "FileWithExpense.h"
#include "FileWithIncome.h"

using namespace std;

class BudgetMangager
{
public:
        BudgetMangager(string incomeFileName, string expenseFileName,int idZaloganegoUzytkownika);
        void addAnExpense(); //dodajWydatek
        void addAnIncome(); //dodajDochod
        void showTheBalanceSheetForTheCurrentMonth();//pokazBilansZBiezacegoMiesiaca
        void showTheBalanceSheetForThePrevioustMonth();//pokazBilansZPoprzedniegoMiesiaca
        void showTheNalanceSheetOfASpecificPeriod();//pokazBilansZOkreslonegoOkresu
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    protected:

    private:
        FileWithExpense fileWithExpense;
        FileWithIncome fileWithIncome;
        const int NEW_USER_ID;
        vector <Expense> expenses;
        vector <Income> incomes;
        Expense provideDetailsOfTheNewExpense();
        Income provideDetailsOfTheNewIncome();
        void displayExpenseData(Expense expense);
        void displayIncomeData(Income income);
        bool checkDate(string date);
        bool checkTheDateOfThePreviousMonth(string date);
        bool checkPeriod(string date,string od,string toTheEndOfTheBalanceSheet);
        string downloadDate();
        float amountOfExpense;
        float amountOfIncome;
        float balance;
};

#endif // BUDGETMANGAGER_H
