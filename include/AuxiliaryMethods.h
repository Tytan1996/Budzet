#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>

using namespace std;

class AuxiliaryMethods
{
public:
        static char loadCharacter();
        static string loadLines();
        static int loadInteger();
        static float loadFloat();
        static string loadAmount();
        static string floatToString(float number);

};


#endif // AUXILIARYMETHODS_H
