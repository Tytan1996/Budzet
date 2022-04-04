#include "AuxiliaryMethods.h"

char AuxiliaryMethods::loadCharacter()
{
    string entry = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, entry);

        if (entry.length() == 1)
        {
            sign = entry[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}
string AuxiliaryMethods::loadLines()
{
    string entry = "";
    getline(cin, entry);
    return entry;
}
int AuxiliaryMethods::loadInteger()
{
    string entry = "";
    int number = 0;

    while (true)
    {
        getline(cin, entry);

        stringstream myStream(entry);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}
float AuxiliaryMethods::loadFloat(){
    string entry = "";
    float number = 0;

    while (true)
    {
        getline(cin, entry);

        int itemSearchFragment=entry.find(",");
        if(itemSearchFragment>=0){
            entry.replace(itemSearchFragment,1, ".");
        }
        stringstream myStream(entry);
        if (myStream >> number){
            break;
        }
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}
string AuxiliaryMethods::downloadTheCurrentDate(){

    stringstream storedTime;
    time_t t = time(nullptr);
    tm tm = *localtime(&t);
    cout.imbue(locale());
    storedTime<<put_time(&tm, "%Y-%m-%d");
    string aktualnaData=storedTime.str();
    return aktualnaData;

}
string AuxiliaryMethods::downloadDate(){

    string date="";
    while(true){
        cout<<"Podaj date od 2000-01-01 (rok-miesiac-dzien)"<<endl;
        cout<<"Data: ";
        date=loadLines();
        date=addZeroToDate(date);
        if(checkDate(date)==true){
            return date;
        }
        cout<<"Zla data!"<<endl;
    }
}
int AuxiliaryMethods::replaceDateWithStringFromInt(string date){
    int dateInIntegerFormat;
    date.erase(7,1);
    date.erase(4,1);
    dateInIntegerFormat=atoi(date.c_str());
}
string AuxiliaryMethods::addZeroToDate(string date){
    string zero="0";
    int dlugoscDaty=date.length();
    if(dlugoscDaty==8){
        date.insert(5,zero);
        date.insert(8,zero);
        return date;
    }else if(dlugoscDaty==9){
        if(date[6]=='-'){
            date.insert(5,zero);
        }else{
            date.insert(8,zero);
        }
        return date;
    }else{
        return date;
    }
    return date;
}
bool AuxiliaryMethods::checkDate(string date){
    if(date.length()!=10){
        return false;
    }
    map <int, int> days;
    int year, month, day;
    year=atoi(date.substr(0,4).c_str());
    month=atoi(date.substr(5,2).c_str());
    day=atoi(date.substr(8,2).c_str());
    days=getTheNumberOfDaysInAMonth(year);
    if(year>=2000 && (1<=month && month<=12) && (1<=day && day<=days[month])){
        return true;
    }else{
        return false;
    }
    return false;
}
map <int,int> AuxiliaryMethods::getTheNumberOfDaysInAMonth(int year){
    map<int,int> daysOfTheYear;
    daysOfTheYear[1]=31;
    if((year%4==0 && year%100!=0) || year%400==0){
        daysOfTheYear[2]=29;
    }else{
        daysOfTheYear[2]=28;
    }
    daysOfTheYear[3]=31;
    daysOfTheYear[4]=30;
    daysOfTheYear[5]=31;
    daysOfTheYear[6]=30;
    daysOfTheYear[7]=31;
    daysOfTheYear[8]=31;
    daysOfTheYear[9]=30;
    daysOfTheYear[10]=31;
    daysOfTheYear[11]=30;
    daysOfTheYear[12]=31;
    return daysOfTheYear;
}
string AuxiliaryMethods::setTheDate(){
    char option;
    string date;
    cout<<"Jaka date chcesz ustawic?"<<endl;
    cout<<"1- date z dzisiaj"<<endl;
    cout<<"2- inna date"<<endl;
    while(true){
        option=loadCharacter();
        switch(option){
        case '1':
            return downloadTheCurrentDate();
            break;
        case '2':
            return downloadDate();
            break;
        default:
            cout<<"Nie ma takiej opcji"<<endl;
            break;
        }
    }
}
string AuxiliaryMethods::downloadMonth(){
    stringstream storedTime;
    time_t t = time(nullptr);
    tm tm = *localtime(&t);
    cout.imbue(locale());
    storedTime<<put_time(&tm, "%Y-%m-");
    string currentMonth=storedTime.str();
    return currentMonth;

}
