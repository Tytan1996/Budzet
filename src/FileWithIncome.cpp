#include "FileWithIncome.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "AuxiliaryMethodsDate.h"

FileWithIncome::FileWithIncome(string incomeFileName):Files(incomeFileName){
    lastIncomeId=0;
}
bool FileWithIncome::addToTheFile(Income income){
    CMarkup xml;
    bool fileExists = xml.Load(getFilename());
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("incomeId", income.getIncomeId());
    xml.AddElem("userId", income.getUserId());
    xml.AddElem("date", income.getIncomeDate());
    xml.AddElem("item", income.getIncomeName());
    xml.AddElem("amount", AuxiliaryMethods::floatToString(income.getTheAmountOfIncome()));
    lastIncomeId++;
    xml.Save(getFilename());
}
vector <Income> FileWithIncome::loadTheIncomeOfTheLoggedInUser(int loggedInUserId){
    CMarkup xml;
    vector <Income> incomes;
    bool fileExists = xml.Load( getFilename() );
    int idIncome, userIdFromFile,dateInIntegerFormat;
    float amountOfIncome;
    string dateOfIncome, nameOfTheIncome;

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("Income")){
            xml.FindChildElem();
            idIncome=atoi(xml.GetChildData().c_str());
            xml.FindChildElem();
            userIdFromFile=atoi(xml.GetChildData().c_str());
            xml.FindChildElem();
            dateOfIncome=xml.GetChildData();
            xml.FindChildElem();
            nameOfTheIncome=xml.GetChildData();
            xml.FindChildElem();
            amountOfIncome=atof(xml.GetChildData().c_str());
            dateInIntegerFormat=AuxiliaryMethodsDate::replaceDateWithStringFromInt(dateOfIncome);
            if(userIdFromFile==loggedInUserId){
                Income income(idIncome,userIdFromFile,nameOfTheIncome,dateOfIncome,amountOfIncome,dateInIntegerFormat);
                incomes.push_back(income);
            }
            lastIncomeId++;
        }

    }
    return incomes;

}
int FileWithIncome::getIdOfLastIncome(){
    return lastIncomeId;
}
