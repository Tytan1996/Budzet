#include "Expense.h"

Expense::Expense(){}

Expense::Expense(int expenseId,int userId,string expenseName, string expenseDate, float theAmountOfTheExpense,int dateInIntegerFormat){
    this->expenseId=expenseId;
    this->userId=userId;
    this->expenseName=expenseName;
    this->expenseDate=expenseDate;
    this->theAmountOfTheExpense=theAmountOfTheExpense;
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
    theAmountOfTheExpense=newExpenseAmount;
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
    return theAmountOfTheExpense;
}
int Expense::getExpenseDateInIntegerFormat(){
    return expenseDateInIntegerFormat;
}
