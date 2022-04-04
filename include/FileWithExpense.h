#ifndef FILEWITHEXPENSE_H
#define FILEWITHEXPENSE_H

#include <iostream>
#include <vector>
#include "Files.h"
#include "Expense.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithExpense:public Files
{
    public:
        FileWithExpense(string expenseFileName);
        bool addToTheFile(Expense expense);
        vector <Expense> loadExpenditureOfALoggedInUser(int loggedInUserId);
        int getLastExpenseId();

    protected:

    private:
        int lastExpenseId;
        Expense expense;
        vector <Expense> expenses;
};

#endif // FILEWITHEXPENSE_H
