#include "PersonalBudget.h"

void PersonalBudget :: userRegistration()
{
    userManager.userRegistration();

};

void PersonalBudget :: printAllUsers()
{
    userManager.printAllUsers();
}

void PersonalBudget :: logIn()
{
    userManager.loggingUser();
    if (userManager.isUserLogged())
    {
        balanceManager = new BalanceManager (incomesFileName, expensesFileName, userManager.loadIdLoggedUser());
    }
}

void PersonalBudget :: changePasswordLoggedUser(int idloggedUser)
{
    userManager.changePasswordLoggedUser(idloggedUser);
}
void PersonalBudget :: logOut()
{
    userManager.loggOfLoggedUser();
    delete balanceManager;
    balanceManager = NULL;
}

void PersonalBudget :: addIncome()
{
    if (userManager.isUserLogged())
    {
        balanceManager->addIncome();
    }
    else
    {
        cout<< "Aby dodac przychod, nalezy sie najpierw zalogowac ! "<<endl;
        system("pause");
    }

};
void PersonalBudget :: showLastMonthBalance()
{
    if (userManager.isUserLogged())
    {
        balanceManager->showLastMonthBalance();
    }
    else
    {
        cout<< "Aby zobaczyc zestawienie, nalezy sie najpierw zalogowac ! "<<endl;
        system("pause");
    }
};

char PersonalBudget :: chooseOptionFromMainMenu()
{
    return userManager.chooseOptionFromMainMenu();
};
char PersonalBudget :: chooseOptionFromUserMenu()
{
    return userManager.chooseOptionFromUserMenu();
};

int PersonalBudget :: loadIdLoggedUser()
{
    return userManager.loadIdLoggedUser();
};

void PersonalBudget :: addExpense()
{
    if (userManager.isUserLogged())
    {
        balanceManager->addExpense();
    }
    else
    {
        cout<< "Aby dodac wydatek, nalezy sie najpierw zalogowac ! "<<endl;
        system("pause");
    }

};

void PersonalBudget :: showCurrentMonthBalance()
{
 if (userManager.isUserLogged())
    {
        balanceManager->showCurrentMonthBalance();
    }
    else
    {
        cout<< "Aby zobaczyc zestawienie, nalezy sie najpierw zalogowac ! "<<endl;
        system("pause");
    }

};

void PersonalBudget :: showBalanceFromChoosenPeriod()
{
 if (userManager.isUserLogged())
    {
        balanceManager->showBalanceFromChoosenPeriod();
    }
    else
    {
        cout<< "Aby zobaczyc zestawienie, nalezy sie najpierw zalogowac ! "<<endl;
        system("pause");
    }
};


