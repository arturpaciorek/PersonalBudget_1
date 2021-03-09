#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>

using namespace std;
class User
{
    int id;
    string login;
    string password;
    string name;
    string surname;

public:
    void setId(int noweId);
    void setLogin(string nowyLogin);
    void setPassword(string noweHaslo);
    void setName(string newName);
    void setSurname(string newSurname);


    int getId();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();
};

#endif // USER_H
