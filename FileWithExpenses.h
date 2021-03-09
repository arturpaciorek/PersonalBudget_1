#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "IncomeExpense.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"
#include "Date.h"

using namespace std;

class FileWithExpenses
{
    const string expenseFileName;
    int lastExpenseID;
    bool fileExists (const string& fileName);

public:
    FileWithExpenses(string EXPENSESFILENAME):
    expenseFileName(EXPENSESFILENAME) {
    lastExpenseID = 0;
    };
    vector <IncomeExpense> downloadLoggedInUserExpenses(int loggedInUserID);
    void addExpenseToFile(IncomeExpense income);
    int downloadLastExpenseID();
};

#endif
