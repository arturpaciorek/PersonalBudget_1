#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>


#include "UserManager.h"
#include "BalanceManager.h"

using namespace std;
class PersonalBudget
{
    int idloggedUser;
    BalanceManager *balanceManager;
    const string incomesFileName;
    const string expensesFileName;

    UserManager userManager;




public:
    PersonalBudget(string usersFileName, string INCOMESFILENAME, string EXPENSESFILENAME)
        : userManager(usersFileName), incomesFileName(INCOMESFILENAME),expensesFileName(EXPENSESFILENAME)
    {
        //adresatMenedzer = NULL;
    };
    ~PersonalBudget()
    {
        //delete adresatMenedzer;
       // adresatMenedzer=NULL;
    }
    void userRegistration();
    void showLastMonthBalance();
    void logIn();
    void changePasswordLoggedUser(int idLoggedUser);
    void  logOut();
    void addIncome();
   char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    int loadIdLoggedUser();
    void addExpense();
    void showCurrentMonthBalance();
    void showBalanceFromChoosenPeriod();
    void printAllUsers();
};

#endif
