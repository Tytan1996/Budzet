#include "FileWithExpense.h"

FileWithExpense::FileWithExpense(string expenseFileName):Files(expenseFileName){
    lastExpenseId=0;
}

bool FileWithExpense::addToTheFile(Expense expense){
    CMarkup xml;
    bool fileExists = xml.Load( getFilename() );
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("expenseId", expense.getExpenseId());
    xml.AddElem("userId", expense.getUserId());
    xml.AddElem("date", expense.getExpenseDate());
    xml.AddElem("item", expense.getExpenseName());
    xml.AddElem("amount", expense.getTheAmountOfTheExpense());
    lastExpenseId++;
    xml.Save(getFilename());
}
vector <Expense> FileWithExpense::loadExpenditureOfALoggedInUser(int loggedInUserId){
    CMarkup xml;
    vector <Expense> expenses;
    bool fileExists = xml.Load( getFilename() );
    int expenseId, userIdFromFile, dateInIntegerFormat;
    float theAmountOfTheExpense;
    string expenseDate, expenseName;

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("Expense")){
            xml.FindChildElem();
            expenseId=atoi(xml.GetChildData().c_str());
            xml.FindChildElem();
            userIdFromFile=atoi(xml.GetChildData().c_str());
            xml.FindChildElem();
            expenseDate=xml.GetChildData();
            xml.FindChildElem();
            expenseName=xml.GetChildData();
            xml.FindChildElem();
            theAmountOfTheExpense=atof(xml.GetChildData().c_str());
            dateInIntegerFormat=AuxiliaryMethods::replaceDateWithStringFromInt(expenseDate);
            if(userIdFromFile==loggedInUserId){
                Expense expense(expenseId,userIdFromFile,expenseName,expenseDate,theAmountOfTheExpense, dateInIntegerFormat);
                expenses.push_back(expense);
            }
            lastExpenseId++;
        }

    }
    return expenses;
}
int FileWithExpense::getLastExpenseId(){
    return lastExpenseId;
}
