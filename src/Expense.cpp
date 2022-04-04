#include "Expense.h"

Expense::Expense(){}

Expense::Expense(int expenseId,int userId,string expenseName, string expenseDate, float kwotaWydatku,int dateInIntegerFormat){
    this->expenseId=expenseId;
    this->userId=userId;
    this->expenseName=expenseName;
    this->expenseDate=expenseDate;
    this->kwotaWydatku=kwotaWydatku;
    expenseDateInIntegerFormat=dateInIntegerFormat;
}

void Expense::setTheExpenseId(int newExpenseId){
    expenseId=newExpenseId;
}
void Expense::setTheUserId(int newUserId){
    userId=newUserId;
}
void Expense::setTheExpenseName(string newNameOfTheExpense){
    expenseName=newNameOfTheExpense;
}
void Expense::setTheExpenseDate(string newExpenseDate){
    expenseDate=newExpenseDate;
}
void Expense::setTheExpenseAmount(float newExpenseAmount){
    kwotaWydatku=newExpenseAmount;
}
void Expense::setTheExpenseDateAsAnInteger(int date){
    expenseDateInIntegerFormat=date;
}
int Expense::getExpenseId(){
    return expenseId;
}
int Expense::getUserId(){
    return userId;
}
string Expense::getExpenseName(){
    return expenseName;
}
string Expense::getExpenseDate(){
    return expenseDate;
}
float Expense::getTheAmountOfTheExpense(){
    return kwotaWydatku;
}
int Expense::getExpenseDateInIntegerFormat(){
    return expenseDateInIntegerFormat;
}
