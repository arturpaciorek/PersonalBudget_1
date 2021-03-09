#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"
using namespace std;

class UserManager
{
    int idLoggedUser;
    vector <User> users;

    User setNewUserData();
    int loadIdNewUser();
    bool isLoginExist(string login);
    FileWithUsers fileWithUsers;
    string changeUsersDataToLineWithDataSeparatedByVerticalLines(User user);
    void saveAllUsersToFile();
public:
    UserManager(string nameFileWithUsers) : fileWithUsers(nameFileWithUsers){
    idLoggedUser = 0;
    users = fileWithUsers.loadUserFromFile();

    };
    bool isUserLogged();
    int loggingUser();
    void userRegistration();
    void printAllUsers();
    void changePasswordLoggedUser(int idLoggedUser);
    void  loggOfLoggedUser();
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    int loadIdLoggedUser();

};
#endif
