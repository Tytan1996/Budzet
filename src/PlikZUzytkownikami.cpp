#include "PlikZUzytkownikami.h"

void PlikZUzytkownikami::dopiszDoPliku(Uzytkownik uzytkownik){


    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

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

    xml.Save("users.xml");

}
