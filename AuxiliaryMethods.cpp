#include "AuxiliaryMethods.h"

string AuxiliaryMethods :: convertionIntToString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}
string AuxiliaryMethods :: loadNumber(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}
string AuxiliaryMethods :: loadLine()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}
int AuxiliaryMethods ::  convertionStringToInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}
int AuxiliaryMethods :: pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = AuxiliaryMethods::convertionStringToInt(AuxiliaryMethods::loadNumber(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

int AuxiliaryMethods :: pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = convertionStringToInt(loadNumber(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

string AuxiliaryMethods :: zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

char AuxiliaryMethods :: loadChar()
{
    string wejscie = "";
    char znak  = {0};

    while (true)
    {

        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}

int AuxiliaryMethods :: loadInteger()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}

string AuxiliaryMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
int AuxiliaryMethods::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;
    return numberInt;
}
string AuxiliaryMethods::convertFloatToString(float amount)
{
    ostringstream ss;
    ss << amount;
    string amountString=ss.str();
    return amountString;
}
float AuxiliaryMethods::convertStringToFloat(string number)
{
    float numberInt;
    istringstream iss(number);
    iss >> numberInt;
    return numberInt;
}
float AuxiliaryMethods::changeCommaForDot (string amount)
{
    float correctAmount = 0;
    string correctAmountString = "";

    for (int i=0; i<amount.length(); i++)
    {
        if (amount[i] == ',')
            correctAmountString+= '.';
        else
            correctAmountString += amount[i];
    }
    correctAmount = convertStringToFloat(correctAmountString);
    return correctAmount;
}

