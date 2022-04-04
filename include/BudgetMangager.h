#ifndef BUDGETMANGAGER_H
#define BUDGETMANGAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>
#include "FileWithExpense.h"
#include "FileWithIncome.h"
#include "Expense.h"
#include "Income.h"
#include "AuxiliaryMethods.h"

using namespace std;

class BudgetMangager
{
public:
        BudgetMangager(string nazwaPlikuZDochodami, string expenseFileName,int idZaloganegoUzytkownika);
        void addAnExpense(); //dodajWydatek
        void addIncome(); //dodajDochod
        void showTheBalanceSheetForTheCurrentMonth();//pokazBilansZBiezacegoMiesiaca
        void showTheBalanceSheetForThePreviousMonth();//pokazBilansZPoprzedniegoMiesiaca
        void showTheBalanceSheetForASpecificPeriod();//pokazBilansZOkreslonegoOkresu
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
