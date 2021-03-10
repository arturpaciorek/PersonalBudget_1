#include <iostream>
#include <windows.h>
#include "PersonalBudget.h"
using namespace std;

int main()
{
    int idLoggedUser =0;

    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");

    char choiceFromMainManu, choiceFromUserMenu;
    while(true)
    {
        idLoggedUser=personalBudget.loadIdLoggedUser();
        if(idLoggedUser ==0)
        {
            choiceFromMainManu = personalBudget.chooseOptionFromMainMenu();
            switch (choiceFromMainManu)
            {
            case '1':
                personalBudget.userRegistration();

                break;
            case '2':
                personalBudget.logIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << " Nie ma takiej opcji w menu. " << endl << endl;
                system("pause");
                break;
            }

        }
        else
        {
            choiceFromUserMenu = personalBudget.chooseOptionFromUserMenu();
            switch (choiceFromUserMenu)
            {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.showCurrentMonthBalance();
                break;
            case '4':
                personalBudget.showLastMonthBalance();
                break;
            case '5':
                personalBudget.showBalanceFromChoosenPeriod();

                break;

            case '7':
                personalBudget.changePasswordLoggedUser(idLoggedUser);
                 break;
            case '8':
                personalBudget.logOut();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << " Nie ma takiej opcji w menu. " << endl << endl;
                system("pause");
                break;
            }
        }
    }

    return 0;
}
