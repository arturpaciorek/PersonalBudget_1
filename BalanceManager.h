#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include "Date.h"
#include "IncomeExpense.h"
#include "FileWithExpenses.h"
#include "FileWithIncomes.h"
#include "Markup.h"

using namespace std;

class BalanceManager
{
    const int loggedInUserID;
    vector <IncomeExpense> incomes;
    vector <IncomeExpense> expenses;
    FileWithIncomes incomesFile;
    FileWithExpenses expensesFile;
    Date date;

    IncomeExpense addInformationAboutIncome();
    IncomeExpense addInformationAboutExpense();
    int getMonthFromIncomeDate (int incomeDate);
    int getYearFromIncomeDate( int incomeDate);
    vector <IncomeExpense> loadIncomesOrExpensesFromChoosenPeriod (vector <IncomeExpense> incomes, int dateFrom, int dateTo);
    int showIncomeOrExpenseBalance(vector <IncomeExpense> simpleVector);
    void showVectorElements (vector <IncomeExpense> simpleVector);
    float getTotalAmountFromChoosenPeriod (vector <IncomeExpense> simpleVector);

    public:
        BalanceManager(string incomesFileName, string expensesFileName, int LOGGEDINUSERID)
        :incomesFile(incomesFileName), expensesFile(expensesFileName), loggedInUserID (LOGGEDINUSERID)
        {
            incomes = incomesFile.downloadLoggedInUserIncomes(loggedInUserID);
            expenses = expensesFile.downloadLoggedInUserExpenses(loggedInUserID);
        };

    void addIncome();
    void addExpense();
    void showCurrentMonthBalance();
    void showLastMonthBalance();
    void showBalanceFromChoosenPeriod();


};

#endif
