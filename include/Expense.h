#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense
{
    public:
        Expense();
        Expense(int expenseId,int userId,string expenseName, string expenseDate, float kwotaWydatku, int dateInIntegerFormat);
        void setTheExpenseId(int newExpenseId);
        void setTheUserId(int newUserId);
        void setTheExpenseName(string newNameOfTheExpense);
        void setTheExpenseDate(string newExpenseDate);
        void setTheExpenseAmount(float newExpenseAmount);
        void setTheExpenseDateAsAnInteger(int date);
        int getExpenseId();
        int getUserId();
        string getExpenseName();
        string getExpenseDate();
        float getTheAmountOfTheExpense();
        int getExpenseDateInIntegerFormat();
        bool operator < (const Expense& str) const
        {
            return (expenseDateInIntegerFormat < str.expenseDateInIntegerFormat);
        }

    protected:

    private:
        int expenseId;
        int userId;
        string expenseName;
        string expenseDate;
        float kwotaWydatku;
        int expenseDateInIntegerFormat;
};

#endif // EXPENSE_H
