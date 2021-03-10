#include "UserManager.h"


void UserManager :: userRegistration()
{
    User user = setNewUserData();
    users.push_back(user);
    fileWithUsers.addNewUserToFile(user);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    //system("pause");
    saveAllUsersToFile();
}

User UserManager :: setNewUserData()
{
    User user;

    user.setId(loadIdNewUser());

    string login;
    do
    {
        cout  << "Podaj login: ";
        cin >> login;
        user.setLogin(login);

    } while (isLoginExist(user.getLogin()) == true);

    string name;
    cout << "Imie: ";
    cin >> name;
    user.setName(name);

    string surname;
    cout << "Nazwisko: ";
    cin >> surname;
    user.setSurname(surname);
    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

int UserManager :: loadIdNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager :: isLoginExist(string login)
{
    for(int i = 0; i< users.size();i++)
    {
        if(users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager :: printAllUsers()
{
    for(int i=0; i<users.size();i++)
    {
        cout<<users[i].getId() << endl;
        cout<<users[i].getLogin() <<endl;
        cout<<users[i].getPassword() <<endl;
    }
}


int UserManager :: loggingUser()
{
    //Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr->getLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = AuxiliaryMethods::loadLine();

                if (itr -> getPassword() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idLoggedUser = itr -> getId();
                    return idLoggedUser;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}
void UserManager :: loggOfLoggedUser()
{
  idLoggedUser=0;

}
void UserManager :: changePasswordLoggedUser(int idLoggedUser)
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = AuxiliaryMethods::loadLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == idLoggedUser)
        {
            itr -> setPassword(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            cout<< "nowe haslo: "<<itr->getPassword();
            system("pause");
        }
    }
    saveAllUsersToFile();
    //return 0;
}
void UserManager :: saveAllUsersToFile()
{
    fileWithUsers.saveAllUsersToFile(users);
};

char UserManager :: chooseOptionFromMainMenu()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = AuxiliaryMethods::loadChar();

    return wybor;
}

char UserManager :: chooseOptionFromUserMenu()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = AuxiliaryMethods::loadChar();

    return wybor;
}

bool UserManager :: isUserLogged()
{
    if (idLoggedUser >0 )
    {
        return true;
    }
    else
    return false;
};

int UserManager :: loadIdLoggedUser()
{
    return idLoggedUser;
};

