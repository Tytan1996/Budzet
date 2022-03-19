#include "PlikZDochodami.h"

PlikZDochodami::PlikZDochodami(string nazwaPlikuZDochodami):Pliki(nazwaPlikuZDochodami){

}
bool PlikZDochodami::dopiszDoPliku(Dochod dochod){
    CMarkup xml;
    bool fileExists = xml.Load( "incomes.xml");
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Incomes");
    xml.IntoElem();
    xml.AddElem("incomeId", dochod.pobierzIdDochodu());
    xml.AddElem("userId", dochod.pobierzIdUzytkownika());
    xml.AddElem("date", dochod.pobierzDateDochodu());
    xml.AddElem("item", dochod.pobierzNazweDochodu());
    xml.AddElem("amount", dochod.pobierzKwoteDochodu());

    xml.Save("incomes.xml");
}
