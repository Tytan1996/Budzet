#include "PlikZDochodami.h"

PlikZDochodami::PlikZDochodami(string nazwaPlikuZDochodami):Pliki(nazwaPlikuZDochodami){

}
bool PlikZDochodami::dopiszDoPliku(Dochod dochod){
    CMarkup xml;
    cout<<pobierzNazwePliku()<<endl;
    bool fileExists = xml.Load(pobierzNazwePliku());
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

    xml.Save(pobierzNazwePliku());
}
vector <Dochod> PlikZDochodami::wczytajDochodyZalogowaniegoUzytkownika(int idZalogowanieUzytkownika){
    CMarkup xml;
    vector <Dochod> dochody;
    bool fileExists = xml.Load( pobierzNazwePliku() );
    int idDochodu, idUzytkownikaZPliku;
    float kwotaDochodu;
    string dataDochodu, nazwaDochodu;

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("Expenses")){
            xml.FindChildElem();
            idDochodu=atoi(xml.GetChildData().c_str());
            xml.FindChildElem();
            idUzytkownikaZPliku=atoi(xml.GetChildData().c_str());
            xml.FindChildElem();
            dataDochodu=xml.GetChildData();
            xml.FindChildElem();
            nazwaDochodu=xml.GetChildData();
            xml.FindChildElem();
            kwotaDochodu=atof(xml.GetChildData().c_str());
            if(idUzytkownikaZPliku==idZalogowanieUzytkownika){
                Dochod dochod(idDochodu,idUzytkownikaZPliku,dataDochodu,nazwaDochodu,kwotaDochodu);
                dochody.push_back(dochod);
            }
        }

    }
    return dochody;

}
