#include "PlikZWydatkami.h"

PlikZWydatkami::PlikZWydatkami(string nazwaPlikuZWydatkami):Pliki(nazwaPlikuZWydatkami){
}

bool PlikZWydatkami::dopiszDoPliku(Wydatek wydatek){
    CMarkup xml;
    bool fileExists = xml.Load( pobierzNazwePliku() );
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expenses");
    xml.IntoElem();
    xml.AddElem("expenseId", wydatek.pobierzIdWydatku());
    xml.AddElem("userId", wydatek.pobierzIdUzytkownika());
    xml.AddElem("date", wydatek.pobierzDateWydatku());
    xml.AddElem("item", wydatek.pobierzNazweWydatku());
    xml.AddElem("amount", wydatek.pobierzKwoteWydatku());

    xml.Save(pobierzNazwePliku());
}
vector <Wydatek> PlikZWydatkami::wczytajWydatkowZalogowaniegoUzytkownika(int idZalogowanieUzytkownika){
    CMarkup xml;
    vector <Wydatek> wydatki;
    bool fileExists = xml.Load( pobierzNazwePliku() );
    int idWydatku, idUzytkownikaZPliku;
    float kwotaWydatku;
    string dataWydatku, nazwaWydatku;

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("Expenses")){
            xml.FindChildElem();
            idWydatku=atoi(xml.GetChildData().c_str());
            xml.FindChildElem();
            idUzytkownikaZPliku=atoi(xml.GetChildData().c_str());
            xml.FindChildElem();
            dataWydatku=xml.GetChildData();
            xml.FindChildElem();
            nazwaWydatku=xml.GetChildData();
            xml.FindChildElem();
            kwotaWydatku=atof(xml.GetChildData().c_str());
            if(idUzytkownikaZPliku==idZalogowanieUzytkownika){
                Wydatek wydatek(idWydatku,idUzytkownikaZPliku,dataWydatku,nazwaWydatku,kwotaWydatku);
                wydatki.push_back(wydatek);
            }
        }

    }
    return wydatki;
}
