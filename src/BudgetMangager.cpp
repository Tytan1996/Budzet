#include "BudgetMangager.h"

BudgetMangager::BudgetMangager(string expenseFileName,string incomeFileName,int loggedInUserId):fileWithExpense(expenseFileName),fileWithIncome(incomeFileName), NEW_USER_ID(loggedInUserId){
    expenses=fileWithExpense.loadExpenditureOfALoggedInUser(loggedInUserId);
    incomes=fileWithIncome.loadTheIncomeOfTheLoggedInUser(loggedInUserId);
}
void BudgetMangager::addAnExpense(){
    Expense expense;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    expense = provideDetailsOfTheNewExpense();

    expenses.push_back(expense);
    if(fileWithExpense.addToTheFile(expense))
        cout<<"Nowy wydatek zostal dodany" <<endl;
    else
        cout<<"Blad. Nie udalo sie dodac nowego wydatek do pliku. "<<endl;
    system("pause");
}
void BudgetMangager::addIncome(){
    Income income;
    system("cls");
    cout << " >>> DODAWANIE NOWY DOCHOD <<<" << endl << endl;
    income = provideDetailsOfTheNewIncome();
    incomes.push_back(income);
    if(fileWithIncome.addToTheFile(income))
        cout<<"Nowy dodatek zostal dodany" <<endl;
    else
        cout<<"Blad. Nie udalo sie dodac nowego dodatku do pliku. "<<endl;
    system("pause");
}
Expense BudgetMangager::provideDetailsOfTheNewExpense(){
    Expense expense;
    string expenseName,expenseDate;
    float kwota;
    expense.setTheExpenseId(fileWithExpense.getLastExpenseId()+1);
    expense.setTheUserId(NEW_USER_ID);

    cout << "Podaj nazwa wydatku: ";
    expenseName = AuxiliaryMethods::loadLines();

    cout << "Podaj data wydatku: ";
    expenseDate = AuxiliaryMethods::setTheDate();
    cout<< "Podaj kwote wydatku: ";
    kwota = AuxiliaryMethods::loadFloat();

    expense.setTheExpenseName(expenseName);
    expense.setTheExpenseDate(expenseDate);
    expense.setTheExpenseAmount(kwota);

    return expense;
}
Income BudgetMangager::provideDetailsOfTheNewIncome(){
    Income income;
    string nameTheIncome,dateOfIncome;
    float amount;
    int dateInIntFormat;
    income.setIncomeId(fileWithIncome.getIdOfLastIncome()+1);
    income.setTheUserId(NEW_USER_ID);

    cout << "Podaj nazwa dochodu: ";
    nameTheIncome = AuxiliaryMethods::loadLines();

    cout << "Podaj data dochodu: ";
    dateOfIncome = AuxiliaryMethods::setTheDate();
    cout<< "Podaj kwote dochodu: ";
    amount = AuxiliaryMethods::loadFloat();
    dateInIntFormat=AuxiliaryMethods::replaceDateWithStringFromInt(dateOfIncome);
    income.setTheNameOfTheIncome(nameTheIncome);
    income.setTheDateOfIncome(dateOfIncome);
    income.setTheAmountOfIncome(amount);
    income.setTheIncomeDateInIntFormat(dateInIntFormat);

    return income;

}
void BudgetMangager::showTheBalanceSheetForTheCurrentMonth(){
    system("cls");
    amountOfIncome=0;
    amountOfExpense=0;
    if (!expenses.empty() || !incomes.empty())
    {
        cout << ">>> BILANS Z BIEZACEGO MIESIACA <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        SetConsoleTextAttribute(hConsole, 12);
        cout << ">>> WYDATKI <<<"<<endl;
        sort(expenses.begin(), expenses.end());
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            if(checkDate(itr->getExpenseDate())){
                displayExpenseData(*itr);
                amountOfExpense+=itr->getTheAmountOfTheExpense();
            }
        }
        cout <<"Laczna kwota wydatkow: "<<amountOfExpense<<endl;
        SetConsoleTextAttribute(hConsole, 2);
        cout << endl;
        cout << ">>>DOCHODY<<<" << endl;
        sort(incomes.begin(), incomes.end());
        for (vector <Income>::iterator itr=incomes.begin();itr!=incomes.end();itr++){
            if(checkDate(itr->getIncomeDate())){
               displayIncomeData(*itr);
               amountOfIncome+=itr->getTheAmountOfIncome();
            }
        }
        balance=amountOfIncome-amountOfExpense;
        cout<<endl<<"Laczna kwota dochodu: "<<amountOfIncome<<endl;
        if(balance<0){
            SetConsoleTextAttribute(hConsole, 12);
        }
        cout<<endl<<"Bilans: "<<balance<<endl<<endl;
    }
    else
    {
        cout << endl << "Nie ma zadnego rekordu" << endl << endl;
    }
    SetConsoleTextAttribute(hConsole, 7);
    system("pause");
}
void BudgetMangager::showTheBalanceSheetForThePreviousMonth(){
    system("cls");
    amountOfIncome=0;
    amountOfExpense=0;
    if (!expenses.empty() || !incomes.empty())
    {
        cout << ">>> BILANS Z POPRZEDNIEGO MIESIACA <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        SetConsoleTextAttribute(hConsole, 12);
        cout << ">>> WYDATKI <<<"<<endl;
        sort(expenses.begin(), expenses.end());
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            if(checkTheDateOfThePreviousMonth(itr->getExpenseDate())){
                displayExpenseData(*itr);
                amountOfExpense+=itr->getTheAmountOfTheExpense();
            }
        }
        cout <<"Laczna kwota wydatkow: "<<amountOfExpense<<endl;
        cout << endl;
        SetConsoleTextAttribute(hConsole, 2);
        cout << ">>>DOCHODY<<<" << endl;
        sort(incomes.begin(), incomes.end());
        for (vector <Income>::iterator itr=incomes.begin();itr!=incomes.end();itr++){
            if(checkTheDateOfThePreviousMonth(itr->getIncomeDate())){
                displayIncomeData(*itr);
                amountOfIncome+=itr->getTheAmountOfIncome();
            }
        }
        balance=amountOfIncome-amountOfExpense;
        cout<<endl<<"Laczna kwota dochodu: "<<amountOfIncome<<endl;
        if(balance<0){
            SetConsoleTextAttribute(hConsole, 12);
        }
        cout<<endl<<"Bilans: "<<balance<<endl<<endl;
    }
    else
    {
        cout << endl <<"Nie ma zadnego rekordu" << endl << endl;
    }
    SetConsoleTextAttribute(hConsole, 7);
    system("pause");


}
void BudgetMangager::showTheBalanceSheetForASpecificPeriod(){
    system("cls");
    amountOfIncome=0;
    amountOfExpense=0;
    string dataOdPoczatkuBilansu,dataDoKoncaBilasnu;
    cout<<"Podaj date od jakiego czasu chcesz bilans: ";
    dataOdPoczatkuBilansu=AuxiliaryMethods::downloadDate();
    cout<<"Podaj date do jakiego czasu chcesz bilans: ";
    dataDoKoncaBilasnu=AuxiliaryMethods::downloadDate();
    if (!expenses.empty() || !incomes.empty())
    {
        cout << ">>> BILANS Z WYBRANEGO OKRESU <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        SetConsoleTextAttribute(hConsole, 12);
        cout << ">>> WYDATKI <<<"<<endl;
        sort(expenses.begin(), expenses.end());
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            if(checkPeriod(itr->getExpenseDate(),dataOdPoczatkuBilansu,dataDoKoncaBilasnu)){
                displayExpenseData(*itr);
                amountOfExpense+=itr->getTheAmountOfTheExpense();
            }
        }
        cout <<"Laczna kwota wydatkow: "<<amountOfExpense<<endl;
        cout << endl;
        SetConsoleTextAttribute(hConsole, 2);
        cout << ">>>DOCHODY<<<" << endl;
        sort(incomes.begin(), incomes.end());
        for (vector <Income>::iterator itr=incomes.begin();itr!=incomes.end();itr++){
            if(checkPeriod(itr->getIncomeDate(),dataOdPoczatkuBilansu,dataDoKoncaBilasnu)){
                displayIncomeData(*itr);
                amountOfIncome+=itr->getTheAmountOfIncome();
            }
        }
        balance=amountOfIncome-amountOfExpense;
        cout<<endl<<"Laczna kwota dochodu: "<<amountOfIncome<<endl;
        if(balance<0){
            SetConsoleTextAttribute(hConsole, 12);
        }
        cout<<endl<<"Bilans: "<<balance<<endl<<endl;
    }
    else
    {
        cout << endl << "Nie ma zadnego rekordu" << endl << endl;
    }
    SetConsoleTextAttribute(hConsole, 7);
    system("pause");


}
void BudgetMangager::displayExpenseData(Expense expense)
{
    cout << "Nazwa wydatku:         " << expense.getExpenseName()<< endl;
    cout << "Data wydatku:          " << expense.getExpenseDate() << endl;
    cout << "Kwota wydatku:         " << expense.getTheAmountOfTheExpense() << endl;
}
void BudgetMangager::displayIncomeData(Income income)
{
    cout << "Nazwa dochodu:         " << income.getIncomeName()<< endl;
    cout << "Data dochodu:          " << income.getIncomeDate() << endl;
    cout << "Kwota dochodu:         " << income.getTheAmountOfIncome() << endl;
}
bool BudgetMangager::checkDate(string date){
    string currentMonth=AuxiliaryMethods::downloadMonth();
    int itemSearchFragment=date.find(currentMonth);
    if(itemSearchFragment!=string::npos){
        return true;
    }else{
        return false;
    }
}
bool BudgetMangager::checkTheDateOfThePreviousMonth(string date){
    string currentMonth=AuxiliaryMethods::downloadMonth();
    int previousMonth=atoi(currentMonth.substr(5,2).c_str())+1;
    string month="";
    if(previousMonth<10){
        month="0"+to_string(previousMonth);
    }else{
        month=to_string(previousMonth);
    }
    string previousMonth1=currentMonth.replace(5,2,month);
    int itemSearchFragment=date.find(previousMonth1);
    if(itemSearchFragment!=string::npos){
        return true;
    }else{
        return false;
    }
}
bool BudgetMangager::checkPeriod(string date,string from,string toTheEndOfTheBalanceSheet){
    int oneYearFromTheBeginningOfTheBalanceSheet=atoi(from.substr(0,4).c_str());
    int monthFromBalanceStart=atoi(from.substr(5,6).c_str());
    int dayFromTheBeginningOfTheBalance=atoi(from.substr(8,9).c_str());
    int yearToCompleteTheBalanceSheet=atoi(toTheEndOfTheBalanceSheet.substr(0,4).c_str());
    int monthToCompleteBalance=atoi(toTheEndOfTheBalanceSheet.substr(5,6).c_str());
    int dayToTheEnd0fTheBalanceSheet=atoi(toTheEndOfTheBalanceSheet.substr(8,9).c_str());
    int year=atoi(date.substr(0,4).c_str());
    int month=atoi(date.substr(5,6).c_str());
    int day=atoi(date.substr(8,9).c_str());
    if((oneYearFromTheBeginningOfTheBalanceSheet<=year && year<=yearToCompleteTheBalanceSheet) && (monthFromBalanceStart<=month && month<=monthToCompleteBalance)&& (dayFromTheBeginningOfTheBalance<=day && day<=dayToTheEnd0fTheBalanceSheet)){
        return true;
    }else{
        return false;
    }

}
