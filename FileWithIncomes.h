#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include "IncomeExpense.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"
#include "Date.h"

using namespace std;

class FileWithIncomes
{
    const string incomeFileName;
    int lastIncomeID;

    bool fileExists (const string& fileName);

public:
    FileWithIncomes(string INCOMESFILENAME):
    incomeFileName(INCOMESFILENAME) {
    lastIncomeID = 0;
    }
    vector <IncomeExpense> downloadLoggedInUserIncomes(int loggedInUserID);
    void addIncomeToFile(IncomeExpense income);
    int downloadLastIncomeID();
};

#endif
