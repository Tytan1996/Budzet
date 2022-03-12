#include "PlikZUzytkownikami.h"

PlikZUzytkownikami::PlikZUzytkownikami(string nazwaPlikuZUzytkownikami):Pliki(nazwaPlikuZUzytkownikami){

}

void PlikZUzytkownikami::dopiszDoPliku(Uzytkownik uzytkownik){


    CMarkup xml;

    bool fileExists = xml.Load( pobierzNazwePliku() );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", uzytkownik.pobierzID());
    xml.AddElem("Login", uzytkownik.pobierzLogin());
    xml.AddElem("Password", uzytkownik.pobierzHaslo());
    xml.AddElem("Name", uzytkownik.pobierzName());
    xml.AddElem("Surname", uzytkownik.pobierzSurname());

    xml.Save(pobierzNazwePliku());

}
vector<Uzytkownik> PlikZUzytkownikami::wczytajUzytkownikowZPliku()
{
    CMarkup xml;
    vector <Uzytkownik> uzytkownicy;
    bool fileExists = xml.Load( pobierzNazwePliku() );
    int id;
    string login, haslo, name, surname;

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("User")){
            xml.FindChildElem();
            id=atoi(xml.GetChildData().c_str());
            xml.FindChildElem();
            login=xml.GetChildData();
            xml.FindChildElem();
            haslo=xml.GetChildData();
            xml.FindChildElem();
            name=xml.GetChildData();
            xml.FindChildElem();
            surname=xml.GetChildData();
            Uzytkownik uzytkownik(id,login,haslo,name,surname);
            uzytkownicy.push_back(uzytkownik);
        }

    }
    return uzytkownicy;
}
