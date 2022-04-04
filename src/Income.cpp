#include "Income.h"

Income::Income(){}
Income::Income(int idIncome,int idUser,string nameOfTheIncome, string dateOfIncome, float amountOfIncome, int dateInIntFormat){
    this->idIncome=idIncome;
    this->idUser=idUser;
    this->nameOfTheIncome=nameOfTheIncome;
    this->dateOfIncome=dateOfIncome;
    this->amountOfIncome=amountOfIncome;
    incomeDateInIntFormat=dateInIntFormat;
}
void Income::setIncomeId(int newIdIncome){
    idIncome=newIdIncome;
}
void Income::setTheUserId(int newIdUser){
    idUser=newIdUser;
}
void Income::setTheNameOfTheIncome(string theNewNameOfTheIncome){
    nameOfTheIncome=theNewNameOfTheIncome;
}
void Income::setTheDateOfIncome(string newIncomeDate){
    dateOfIncome=newIncomeDate;
}
void Income::setTheAmountOfIncome(float theNewAmountOfIncome){
    amountOfIncome=theNewAmountOfIncome;
}
void Income::setTheIncomeDateInIntFormat(int date){
    incomeDateInIntFormat=date;
}
int Income::getIncomeId(){
    return idIncome;
}
int Income::getUserId(){
    return idUser;
}
string Income::getIncomeName(){
    return nameOfTheIncome;
}
string Income::getIncomeDate(){
    return dateOfIncome;
}
float Income::getTheAmountOfIncome(){
    return amountOfIncome;
}
int Income::getIncomeDateInIntFormat(){
    return incomeDateInIntFormat;
}
