#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include<iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
    static string convertionIntToString(int liczba);
    static string loadLine();
    static int convertionStringToInt(string liczba);
    static int  pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    static int  pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    static string loadNumber(string tekst, int pozycjaZnaku);
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static char loadChar();
    static int loadInteger();

    static string convertIntToString(int number);
    static int convertStringToInt(string number);
    static string convertFloatToString(float amount);
    static float convertStringToFloat(string number);
    static float changeCommaForDot (string amount);


};
#endif
