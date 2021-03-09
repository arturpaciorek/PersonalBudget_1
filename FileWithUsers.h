#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"

using namespace std;

class FileWithUsers
{
    string usersFileName;

    bool checkIfFileIsEmpty();
public:
    FileWithUsers(string USERSFILENAME): usersFileName (USERSFILENAME){};
    void addNewUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersToFile(vector <User> users);
    bool fileExist(string fileName);
};

#endif
