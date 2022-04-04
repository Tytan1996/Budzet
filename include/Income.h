#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
public:
        Income();
        Income(int idIncome,int idUser,string nameOfTheIncome, string dateOfIncome, float amountOfIncome,int dateInIntFormat);
        void setIncomeId(int newIdIncome); //ustawIdWydatku
        void setTheUserId(int newIdUser); //ustawIdUzytkownika
        void setTheNameOfTheIncome(string theNewNameOfTheIncome);//ustawNazweDochodu
        void setTheDateOfIncome(string newIncomeDate);//ustawDateDochodu
        void setTheAmountOfIncome(float theNewAmountOfIncome);//ustawKwoteDochodu
        void setTheIncomeDateInIntFormat(int date);//ustawDateDochoduWFormacieInt
        int getIncomeId();//pobierzIdDochodu
        int getUserId();//pobierzIdUzytkownika
        string getIncomeName();//pobierzNazweDochodu
        string getIncomeDate();//pobierzDateDochodu
        float getTheAmountOfIncome();//pobierzKwoteDochodu
        int getIncomeDateInIntFormat();//pobierzDateDochoduWFormacieInt
        bool operator < (const Income& str) const
        {
            return (incomeDateInIntFormat < str.incomeDateInIntFormat);
        }

    private:
        int idIncome;
        int idUser;
        string nameOfTheIncome;
        string dateOfIncome;
        float amountOfIncome;
        int incomeDateInIntFormat;
};

#endif // INCOME_H
