#include "FileWithExpenses.h"

void FileWithExpenses::addExpenseToFile(IncomeExpense expense)
{
    CMarkup xml;
    Date date;

    if (fileExists(expenseFileName.c_str()) == false)
    {
        xml.AddElem( "EXPENSES" );
        xml.IntoElem();
        xml.AddElem( "EXPENSE" );
        xml.IntoElem();
        xml.AddElem( "USERID", expense.getUserID());
        xml.AddElem( "EXPENSEID", expense.getIncomeOrExpenseID());
        xml.AddElem( "DATE", date.convertToDateWithDash(expense.getDate()));
        xml.AddElem( "TITLE", expense.getTitle());
        xml.AddElem( "AMOUNT", AuxiliaryMethods::convertFloatToString(expense.getAmount()));
        xml.OutOfElem();
        xml.Save( expenseFileName.c_str() );
    }
    else
    {
        xml.Load(expenseFileName.c_str());
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem( "EXPENSE" );
        xml.IntoElem();
        xml.AddElem( "USERID", expense.getUserID());
        xml.AddElem( "EXPENSEID", expense.getIncomeOrExpenseID());
        xml.AddElem( "DATE", date.convertToDateWithDash(expense.getDate()));
        xml.AddElem( "TITLE", expense.getTitle());
        xml.AddElem( "AMOUNT", AuxiliaryMethods::convertFloatToString(expense.getAmount()));
        xml.OutOfElem();
        xml.Save( expenseFileName.c_str() );
    }
    lastExpenseID++;

    system("pause");
}
vector <IncomeExpense> FileWithExpenses::downloadLoggedInUserExpenses(int loggedInUserID)
{
    CMarkup xml;
    IncomeExpense expense;
    Date date;
    vector <IncomeExpense> expenses;
    int userid;

    xml.Load(expenseFileName.c_str());
    xml.FindElem("EXPENSES");
    xml.IntoElem();

    while (xml.FindElem("EXPENSE"))
    {
        xml.IntoElem();
        xml.FindElem("USERID");
        userid = atoi( MCD_2PCSZ(xml.GetData()));

        if (userid == loggedInUserID)
        {
            expense.setUserID(userid);
            xml.FindElem( "EXPENSEID" );
            expense.setIncomeOrExpenseID(atoi( MCD_2PCSZ(xml.GetData())));
            xml.FindElem( "DATE" );
            expense.setDate(date.convertDateToDateWithoutDash( MCD_2PCSZ(xml.GetData())));
            xml.FindElem( "TITLE" );
            expense.setTitle(MCD_2PCSZ(xml.GetData())) ;
            xml.FindElem( "AMOUNT" );
            expense.setAmount(atof (MCD_2PCSZ(xml.GetData())));

            expenses.push_back(expense);
        }
         xml.OutOfElem();
    }
     if (fileExists(expenseFileName.c_str())== false || expenses.size() == 0)
    {
         lastExpenseID = 0;
    }
    else if (fileExists(expenseFileName.c_str())== true)
    {
        lastExpenseID = expenses.back().getIncomeOrExpenseID();
    }

    return expenses;
}
bool FileWithExpenses::fileExists (const string &fileName)
{
    fstream plik;
    plik.open(fileName.c_str(), ios::in);
    if ( plik.is_open() )
    {
        plik.close();
        return true;
    }
    plik.close();
    return false;
}
int FileWithExpenses::downloadLastExpenseID()
{
    return lastExpenseID;
}
