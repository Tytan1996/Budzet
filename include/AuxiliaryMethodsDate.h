#ifndef AUXILIARYMETHODSDATE_H
#define AUXILIARYMETHODSDATE_H

#include <iostream>
#include <map>

using namespace std;

class AuxiliaryMethodsDate
{
    public:
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

#endif // AUXILIARYMETHODSDATE_H
