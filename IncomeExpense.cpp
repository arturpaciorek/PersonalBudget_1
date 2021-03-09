#include "IncomeExpense.h"

void IncomeExpense::setUserID (int newUserID)
{
    if (newUserID >=0)
        userID = newUserID;
}
void IncomeExpense::setIncomeOrExpenseID (int newID)
{
    if (newID >= 0)
        incomeOrExpenseID = newID;
}
void IncomeExpense::setDate (int newDate)
{
    if (newDate >= 20000101)
        date = newDate;
}
void IncomeExpense::setTitle (string newTitle)
{
    title = newTitle;
}
void IncomeExpense::setAmount (float newAmount)
{
    amount = newAmount;
}
int IncomeExpense::getUserID()
{
    return userID;
}
int IncomeExpense::getIncomeOrExpenseID()
{
    return incomeOrExpenseID;
}
int IncomeExpense::getDate()
{
    return date;
}
string IncomeExpense::getTitle()
{
    return title;
}
float IncomeExpense::getAmount()
{
    return amount;
}
bool IncomeExpense::operator < (const IncomeExpense &x)const
{
    return date<x.date;
}
