#include "PlikZDochodami.h"

PlikZDochodami::PlikZDochodami(string nazwaPlikuZDochodami):Pliki(nazwaPlikuZDochodami){
    idOstatniegoDochodu=0;
}
bool PlikZDochodami::dopiszDoPliku(Dochod dochod){
    CMarkup xml;
    bool fileExists = xml.Load(pobierzNazwePliku());
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("incomeId", dochod.pobierzIdDochodu());
    xml.AddElem("userId", dochod.pobierzIdUzytkownika());
    xml.AddElem("date", dochod.pobierzDateDochodu());
    xml.AddElem("item", dochod.pobierzNazweDochodu());
    xml.AddElem("amount", dochod.pobierzKwoteDochodu());
    idOstatniegoDochodu++;
    xml.Save(pobierzNazwePliku());
}
vector <Dochod> PlikZDochodami::wczytajDochodyZalogowaniegoUzytkownika(int idZalogowanieUzytkownika){
    CMarkup xml;
    vector <Dochod> dochody;
    bool fileExists = xml.Load( pobierzNazwePliku() );
    int idDochodu, idUzytkownikaZPliku,dataWFormacieInt;
    float kwotaDochodu;
    string dataDochodu, nazwaDochodu;

    if (fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("Income")){
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
            dataWFormacieInt=MetodyPomocnicze::zamienDateZStringNaInt(dataDochodu);
            if(idUzytkownikaZPliku==idZalogowanieUzytkownika){
                Dochod dochod(idDochodu,idUzytkownikaZPliku,nazwaDochodu,dataDochodu,kwotaDochodu,dataWFormacieInt);
                dochody.push_back(dochod);
            }
            idOstatniegoDochodu++;
        }

    }
    return dochody;

}
int PlikZDochodami::pobierzIdOstatniegoDochodu(){
    return idOstatniegoDochodu;
}
