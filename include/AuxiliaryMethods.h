#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <map>
#include <cstdlib>
#include <string>

using namespace std;

class AuxiliaryMethods
{
public:
        static char loadCharacter();
        static string loadLines();
        static int loadInteger();
        static float loadFloat();
        static map<int,int>getTheNumberOfDaysInAMonth(int year);
        static string setTheDate();
        static string downloadMonth();
        static string downloadDate();
        static int replaceDateWithStringFromInt(string date);


    private:
        static string downloadTheCurrentDate();
        static string addZeroToDate(string date);
        static bool checkDate(string date);
};

#endif // AUXILIARYMETHODS_H
