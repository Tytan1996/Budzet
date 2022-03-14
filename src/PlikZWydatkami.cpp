#include "PlikZWydatkami.h"

PlikZWydatkami::PlikZWydatkami(string nazwaPlikuZWydatkami):Pliki(nazwaPlikuZWydatkami){
}

void PlikZWydatkami::dopiszDoPliku(Wydatek wydatek){

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
    xml.AddElem("date", wydatek.pobierzDateWydatku());
    xml.AddElem("item", wydatek.pobierzNazweWydatku());
    xml.AddElem("amount", wydatek.pobierzKwoteWydatku());

    xml.Save(pobierzNazwePliku());
}
