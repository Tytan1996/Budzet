#include "AuxiliaryMethods.h"

#include <iomanip>

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
string AuxiliaryMethods::loadAmount() {
    string entry = "";
    int lengthString,itemSearchFragment;
    getline(cin, entry);
    lengthString=entry.size();
    itemSearchFragment=entry.find(".");
    if(itemSearchFragment>=0) {
        if(itemSearchFragment+3<lengthString){
            entry.erase(itemSearchFragment+3,lengthString); //usuwa znaki po drugiej liczbe po przecinku
        }
        return entry;
    }
    itemSearchFragment=entry.find(",");
    if(itemSearchFragment>=0) {
        entry.replace(itemSearchFragment,1, ".");
        if(itemSearchFragment+3<lengthString){
            entry.erase(itemSearchFragment+3,lengthString); //usuwa znaki po drugiej liczbe po przecinku
        }
        return entry;
    }

    return entry;
}
float AuxiliaryMethods::loadFloat(){
    float number=0;
    string entry;
    while (true)
    {
        entry=loadAmount();
        stringstream myStream(entry);
        if (myStream >> number){
            break;
        }
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

string AuxiliaryMethods::floatToString(float number){
    int numberInteger =number*100, lengthInteger;
    string numberString="";
    numberString=to_string(numberInteger);
    lengthInteger=numberString.size();
    numberString.insert(lengthInteger-2,".");
    return numberString;
}
