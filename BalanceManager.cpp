#include "BalanceManager.h"

void BalanceManager::addIncome()
{
    IncomeExpense income;

    system("cls");
    cout << " >>> Dodaj Przychod <<<" << endl << endl;
    income = addInformationAboutIncome();
    incomes.push_back(income);
    incomesFile.addIncomeToFile(income);
    system("pause");
}
IncomeExpense BalanceManager::addInformationAboutIncome()
{
    IncomeExpense income;
    char choice;
    int dateIncome;
    string title, amount;

    income.setIncomeOrExpenseID(incomesFile.downloadLastIncomeID()+ 1);
    income.setUserID(loggedInUserID);

    cout << " Jesli chcesz dodac przychod z dzisiaj, wcisnij 't'. Jesli chcesz dodac przychod z innego dnia, wcisnij 'o'." << endl;
    cin >> choice;

    if (choice == 't')
        dateIncome = date.todaysDate();

    else if (choice == 'o')
        dateIncome = date.otherDate();

    cout << "Wpisz tytul: ";
    cin >> title;

    cout << "Wpisz kwote: ";
    cin >> amount;

    income.setDate(dateIncome);
    income.setTitle(title);
    income.setAmount(AuxiliaryMethods::changeCommaForDot(amount));
    return income;
}
void BalanceManager::addExpense()
{
    IncomeExpense expense;

    system("cls");
    cout << " >>> Dodaj Wydatek <<<" << endl << endl;
    expense = addInformationAboutExpense();

    expenses.push_back(expense);
    expensesFile.addExpenseToFile(expense);
}
IncomeExpense BalanceManager::addInformationAboutExpense()
{
    IncomeExpense expense;
    char choice;
    int dateExpense;
    string title, amount;

    expense.setIncomeOrExpenseID(expensesFile.downloadLastExpenseID()+ 1);
    expense.setUserID(loggedInUserID);

    cout << " Jesli chcesz dodac wydatek z dzisiaj, wcisnij 't'. Jesli chcesz dodac przychod z innego dnia, wcisnij 'o'." << endl;
    cin >> choice;

    if (choice == 't')
        dateExpense = date.todaysDate();

    else if (choice == 'o')
        dateExpense = date.otherDate();

    cout << "Wpisz tytul: ";
    cin >> title;

    cout << "Wpisz kwote: ";
    cin >> amount;

    expense.setDate(dateExpense);
    expense.setTitle(title);
    expense.setAmount(AuxiliaryMethods::changeCommaForDot(amount));

    return expense;
}
vector <IncomeExpense> BalanceManager::loadIncomesOrExpensesFromChoosenPeriod (vector <IncomeExpense> incomes, int dateFrom, int dateTo)
{
    int justDate;
    Date dateDate;
    IncomeExpense incomeOrExpenseFromChoosenPeriod;
    vector <IncomeExpense>incomesOrExpensesFromChoosenPeriod;
    for (vector <IncomeExpense> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        justDate = itr->getDate();

        if ((justDate>= dateFrom) & (justDate<=dateTo))
        {
            incomeOrExpenseFromChoosenPeriod.setIncomeOrExpenseID(itr->getIncomeOrExpenseID());
            incomeOrExpenseFromChoosenPeriod.setDate(itr->getDate());
            incomeOrExpenseFromChoosenPeriod.setTitle(itr->getTitle());
            incomeOrExpenseFromChoosenPeriod.setAmount(itr->getAmount());
            incomesOrExpensesFromChoosenPeriod.push_back(incomeOrExpenseFromChoosenPeriod);
        }
    }
    return incomesOrExpensesFromChoosenPeriod;
}
float BalanceManager::getTotalAmountFromChoosenPeriod (vector <IncomeExpense> simpleVector )
{
    float totalAmount;
    for (vector <IncomeExpense> :: iterator itr = simpleVector.begin(); itr != simpleVector.end(); itr++)
    {
        totalAmount+=itr->getAmount();
    }
    return totalAmount;
}
void BalanceManager::showVectorElements (vector <IncomeExpense> simpleVector)
{
    for (vector <IncomeExpense> :: iterator itr = simpleVector.begin(); itr != simpleVector.end(); itr++)
    {
        cout <<endl;
        cout << "Data: " << date.convertToDateWithDash(itr->getDate()) << endl;
        cout << "Tytul: " << itr->getTitle() << endl;
        cout << "Suma : " << itr->getAmount() << endl;
    }
}
void BalanceManager::showCurrentMonthBalance ()
{
    Date date;
    string monthString = AuxiliaryMethods::convertIntToString(date.currentMonth());
    if (monthString.length() == 1)
        monthString = "0"+monthString;

    string dateFrom = AuxiliaryMethods::convertIntToString(date.currentYear())+monthString+"01";
    string dateTo = AuxiliaryMethods::convertIntToString(date.currentYear())+ monthString+AuxiliaryMethods::convertIntToString(date.howManyDaysHasMonthHave(date.currentMonth(), date.currentYear()));
    int dateFromInt = AuxiliaryMethods::convertStringToInt(dateFrom);
    int dateToInt = AuxiliaryMethods::convertStringToInt(dateTo);
    vector <IncomeExpense> incomesFromCurrentMonth = loadIncomesOrExpensesFromChoosenPeriod (incomes, dateFromInt, dateToInt);
    vector <IncomeExpense> expensesFromCurrentMonth = loadIncomesOrExpensesFromChoosenPeriod (expenses, dateFromInt, dateToInt);
    system ("cls");
    cout << " <<<  ZESTAWIENIE BIEZACEGO MIESIACA:  >>>" << endl << endl << endl;
    cout << "***  PRZYCHODY:  ***" << endl;
    sort (incomesFromCurrentMonth.begin(), incomesFromCurrentMonth.end());
    showVectorElements(incomesFromCurrentMonth);
    cout << endl << "Suma przychodow: " << getTotalAmountFromChoosenPeriod(incomesFromCurrentMonth) << endl << endl;

    cout << endl <<"***  WYDATKI:  ***" << endl;
    sort (expensesFromCurrentMonth.begin(), expensesFromCurrentMonth.end());
    showVectorElements(expensesFromCurrentMonth);
    cout << endl << "Suma wydatkow: " << getTotalAmountFromChoosenPeriod(expensesFromCurrentMonth) << endl << endl;

    cout << "Roznica miedzy przychodami a wydatkami: " << getTotalAmountFromChoosenPeriod(incomesFromCurrentMonth) - getTotalAmountFromChoosenPeriod(expensesFromCurrentMonth) << endl << endl;
    system("pause");
}

void BalanceManager::showLastMonthBalance ()
{
    string monthString = AuxiliaryMethods::convertIntToString(date.currentMonth()-1);
    if (monthString.length() == 1)
        monthString = "0"+ monthString;
    int year = date.currentYear();
    if (monthString == "01")
        year = year-1;

    string dateFrom = AuxiliaryMethods::convertIntToString(year)+monthString+"01";
    string dateTo = AuxiliaryMethods::convertIntToString(year)+ monthString+AuxiliaryMethods::convertIntToString(date.howManyDaysHasMonthHave(date.currentMonth()-1, date.currentYear()));
    int dateFromInt = AuxiliaryMethods::convertStringToInt(dateFrom);
    int dateToInt = AuxiliaryMethods::convertStringToInt(dateTo);
    vector <IncomeExpense> incomesFromLastMonth = loadIncomesOrExpensesFromChoosenPeriod (incomes, dateFromInt, dateToInt);
    vector <IncomeExpense> expensesFromLastMonth = loadIncomesOrExpensesFromChoosenPeriod (expenses, dateFromInt, dateToInt);
    system ("cls");
    cout << " <<<  ZESTAWIENIE POPRZEDNIEGO MIESIACA:  >>>" << endl << endl;
    cout << "***  PRZYCHODY:  ***" << endl;
    sort (incomesFromLastMonth.begin(), incomesFromLastMonth.end());
    showVectorElements(incomesFromLastMonth);
    cout << endl << "Suma przychodow:  " << getTotalAmountFromChoosenPeriod(incomesFromLastMonth) << endl << endl;

    cout << "***  WYDATKI:  ***" << endl;
    sort (expensesFromLastMonth.begin(), expensesFromLastMonth.end());
    showVectorElements(expensesFromLastMonth);
    cout << endl << "Suma wydatkow:  " << getTotalAmountFromChoosenPeriod(expensesFromLastMonth) << endl << endl << endl;

    cout << "Roznica miedzy przychodami a wydatkami: " << getTotalAmountFromChoosenPeriod(incomesFromLastMonth) - getTotalAmountFromChoosenPeriod(expensesFromLastMonth) << endl << endl;
    system("pause");

}
void BalanceManager::showBalanceFromChoosenPeriod()
{
    Date correctDate;
    int dateFrom, dateTo;
    string dateFromString, dateToString;
    system ("cls");
    cout << " <<<  ZESTAWIENIE Z WYBRANEGO OKRESU:  >>>" << endl << endl;
    cout << "Podaj date z poczatku zestawienia  w formacie rrrr-mm-dd : " << endl;
    do
    {
        dateFromString = "";
        cin >> dateFromString;
    }
    while (correctDate.isTheDateCorrect(dateFromString) == false);

    cout << "Podaj date z konca zestawienia  w formacie rrrr-mm-dd :: " << endl;
    do
    {
        dateToString = "";
        cin >> dateToString;
    }
    while (correctDate.isTheDateCorrect(dateToString) == false);

    dateFrom = date.convertDateToDateWithoutDash(dateFromString);
    dateTo = date.convertDateToDateWithoutDash(dateToString);
    vector <IncomeExpense> incomesFromChoosenPeriod = loadIncomesOrExpensesFromChoosenPeriod (incomes, dateFrom, dateTo);
    vector <IncomeExpense> expensesFromChoosenPeriod = loadIncomesOrExpensesFromChoosenPeriod (expenses, dateFrom, dateTo);

    cout << " <<<  ZESTAWIENIE Z WYBRANEGO OKRESU:  >>>" << endl << endl;
    cout << "***  PRZYCHODY:  ***" << endl;
    sort (incomesFromChoosenPeriod.begin(), incomesFromChoosenPeriod.end());
    showVectorElements(incomesFromChoosenPeriod);
    cout << endl << "Suma przychodow: " << getTotalAmountFromChoosenPeriod(incomesFromChoosenPeriod) << endl << endl;

    cout << "***  WYDATKI:  ***" << endl;
    sort (expensesFromChoosenPeriod.begin(), expensesFromChoosenPeriod.end());
    showVectorElements(expensesFromChoosenPeriod);
    cout << endl << "Suma wydatkow: " << getTotalAmountFromChoosenPeriod(expensesFromChoosenPeriod) << endl << endl << endl;

    cout << "Roznica miedzy przychodami a wydatkami:  " << getTotalAmountFromChoosenPeriod(incomesFromChoosenPeriod) - getTotalAmountFromChoosenPeriod(expensesFromChoosenPeriod) << endl << endl;
    system("pause");
}
