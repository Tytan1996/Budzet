#ifndef FILEWITHINCOME_H
#define FILEWITHINCOME_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "Files.h"
#include "Income.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithIncome:public Files
{
    public:
        FileWithIncome(string incomeFileName);
        bool addToTheFile(Income income);
        vector <Income> loadTheIncomeOfTheLoggedInUser(int loggedInUserId);
        int getIdOfLastIncome();

    protected:

    private:
        int lastIncomeId;
        Income income;
        vector <Income> incomes;
};

#endif // FILEWITHINCOME_H
