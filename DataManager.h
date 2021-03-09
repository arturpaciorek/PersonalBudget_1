#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <iostream>


#include "UserManager.h"


using namespace std;
class DataManager
{
    UserManager userManager;
    AdresatMenedzer *adresatMenedzer;
    int idZalogowanegoUzytkownika;
    const string NAZWA_PLIKU_Z_ADRESATAMI;
public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
        : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
    {
        adresatMenedzer = NULL;
    };
    ~KsiazkaAdresowa()
    {
        delete adresatMenedzer;
        adresatMenedzer=NULL;
    }
    void ;


};

#endif
