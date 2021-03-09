#include "FileWithUsers.h"


string FileWithUsers :: changeUserDataToLineWithDataSeparatedByVerticalLines(User user)
{
    string lineWithUserData = "";

    lineWithUserData += AuxiliaryMethods::convertionIntToString(user.getId())+ '|';
    lineWithUserData += user.getLogin() + '|';
    lineWithUserData += user.getPassword() + '|';

    return lineWithUserData;
}

void FileWithUsers :: addUserToFile(User user)
{
    fstream textFile;
    string lineWithUserData = "";
    textFile.open(loadFileName().c_str(), ios::app);

    if (textFile.good() == true)
    {
        lineWithUserData = changeUserDataToLineWithDataSeparatedByVerticalLines(user);

        if (isFileEmpty() == true)
        {
            cout<<"test"<<endl;
            system("pause");
            textFile << lineWithUserData;
        }
        else
        {
            textFile << endl << lineWithUserData ;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << loadFileName() << " i zapisac w nim danych." << endl;
    textFile.close();
}

 vector <User> FileWithUsers :: loadUserFromFile()
 {
     fstream textFile;
    User user;
    vector <User> users;
    string daneJednegoUzytkownikaOddzielonePionowymiKreskami = "";

    textFile.open(loadFileName().c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, daneJednegoUzytkownikaOddzielonePionowymiKreskami))
        {
            user = loadUserData(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
            users.push_back(user);
        }
        textFile.close();
    }
    return users;
 }

 User FileWithUsers :: loadUserData(string daneJednegoUzytkownikaOddzielonePionowymiKreskami)
{
    User user;
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejUzytkownika)
            {
            case 1:
                user.setId(atoi(pojedynczaDanaUzytkownika.c_str()));
                break;
            case 2:
                user.setLogin(pojedynczaDanaUzytkownika);
                break;
            case 3:
                user.setPassword(pojedynczaDanaUzytkownika);
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    return user;
}

void FileWithUsers :: saveAllUsersToFile(vector <User> users)
{
    fstream textFile;
    string liniaZDanymiUzytkownika = "";
    vector <User>::iterator itrKoniec = --users.end();

    textFile.open(loadFileName().c_str(), ios::out);

    if (textFile.good() == true)
    {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
        {
            liniaZDanymiUzytkownika = changeUserDataToLineWithDataSeparatedByVerticalLines(*itr);

            if (itr == itrKoniec)
            {
               textFile << liniaZDanymiUzytkownika;
            }
            else
            {
                textFile << liniaZDanymiUzytkownika << endl;
            }
            liniaZDanymiUzytkownika = "";
        }
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " << loadFileName() << endl;
    }
    textFile.close();
}
