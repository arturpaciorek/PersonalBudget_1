#ifndef FiLEWITHUSERS_H
#define FiLEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>


#include "User.h"
#include "AuxiliaryMethods.h"
#include "TextFile.h"

using namespace std;

class FileWithUsers : public TextFile
{
    User loadUserData(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    FileWithUsers(string nameOfFileWithUsers): TextFile(nameOfFileWithUsers) {};
    void addUserToFile(User user);
    vector <User> loadUserFromFile();
    string changeUserDataToLineWithDataSeparatedByVerticalLines(User user);
    void saveAllUsersToFile(vector <User> user);

};
#endif
