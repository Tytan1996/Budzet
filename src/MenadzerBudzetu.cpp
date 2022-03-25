#include "MenadzerBudzetu.h"

MenadzerBudzetu::MenadzerBudzetu(string nazwaPlikuZWydatkami,string nazwaPlikuZDochodami,int idZaloganegoUzytkownika):plikZWydatkami(nazwaPlikuZWydatkami),plikZDochodami(nazwaPlikuZDochodami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZaloganegoUzytkownika){
    wydatki=plikZWydatkami.wczytajWydatkowZalogowaniegoUzytkownika(idZaloganegoUzytkownika);
    dochody=plikZDochodami.wczytajDochodyZalogowaniegoUzytkownika(idZaloganegoUzytkownika);
}
void MenadzerBudzetu::dodajWydatek(){
    Wydatek wydatek;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    wydatek = podajDaneNowegoWydatku();

    wydatki.push_back(wydatek);
    if(plikZWydatkami.dopiszDoPliku(wydatek))
        cout<<"Nowy wydatek zostal dodany" <<endl;
    else
        cout<<"Blad. Nie udalo sie dodac nowego wydatek do pliku. "<<endl;
    system("pause");
}
void MenadzerBudzetu::dodajDochod(){
    Dochod dochod;
    system("cls");
    cout << " >>> DODAWANIE NOWY DOCHOD <<<" << endl << endl;
    dochod = podajDaneNowegoDochodu();
    dochody.push_back(dochod);
    if(plikZDochodami.dopiszDoPliku(dochod))
        cout<<"Nowy dodatek zostal dodany" <<endl;
    else
        cout<<"Blad. Nie udalo sie dodac nowego dodatku do pliku. "<<endl;
    system("pause");
}
Wydatek MenadzerBudzetu::podajDaneNowegoWydatku(){
    Wydatek wydatek;
    string nazwaWydatku,dataWydatku;
    float kwota;
    wydatek.ustawIdWydatku(plikZWydatkami.pobierzIdOstatniegoWydatku()+1);
    wydatek.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj nazwa wydatku: ";
    nazwaWydatku = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj data wydatku: ";
    dataWydatku = MetodyPomocnicze::ustawDate();
    cout<< "Podaj kwote wydatku: ";
    kwota = MetodyPomocnicze::wczytajLiczbeZPrzecinkiem();

    wydatek.ustawNazweWydatku(nazwaWydatku);
    wydatek.ustawDateWydatku(dataWydatku);
    wydatek.ustawKwotewydatku(kwota);

    return wydatek;
}
Dochod MenadzerBudzetu::podajDaneNowegoDochodu(){
    Dochod dochod;
    string nazwaDochodu,dataDochodu;
    float kwota;
    int dataWInt;
    dochod.ustawIdDochodu(plikZDochodami.pobierzIdOstatniegoDochodu()+1);
    dochod.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj nazwa dochodu: ";
    nazwaDochodu = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj data dochodu: ";
    dataDochodu = MetodyPomocnicze::ustawDate();
    cout<< "Podaj kwote dochodu: ";
    kwota = MetodyPomocnicze::wczytajLiczbeZPrzecinkiem();
    dataWInt=MetodyPomocnicze::zamienDateZStringNaInt(dataDochodu);
    dochod.ustawNazweDochodu(nazwaDochodu);
    dochod.ustawDateDochodu(dataDochodu);
    dochod.ustawKwoteDochodu(kwota);
    dochod.ustawDateDochoduWFormacieInt(dataWInt);

    return dochod;

}
void MenadzerBudzetu::pokazBilansZBiezacegoMiesiaca(){
    system("cls");
    if (!wydatki.empty() || !dochody.empty())
    {
        cout << ">>> BILANS Z BIEZACEGO MIESIACA <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        sort(wydatki.begin(), wydatki.end());
        for (vector <Wydatek> :: iterator itr = wydatki.begin(); itr != wydatki.end(); itr++)
        {
            if(sprawdzDate(itr->pobierzDateWydatku())){
                wyswietlDaneWydatku(*itr);
            }
        }
        cout << endl;
        cout << "Dochody" << endl;
        cout << endl;
        sort(dochody.begin(), dochody.end());
        for (vector <Dochod>::iterator itr=dochody.begin();itr!=dochody.end();itr++){
            if(sprawdzDate(itr->pobierzDateDochodu())){
               wyswietlDaneDochodu(*itr);
            }
        }
    }
    else
    {
        cout << endl << "Nie ma zadnego rekordu" << endl << endl;
    }
    system("pause");
}
void MenadzerBudzetu::pokazBilansZPoprzedniegoMiesiaca(){
    system("cls");
    if (!wydatki.empty())
    {
        cout << ">>> BILANS Z POPRZEDNIEGO MIESIACA <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Wydatek> :: iterator itr = wydatki.begin(); itr != wydatki.end(); itr++)
        {
            if(sprawdzDatePoprzednegoMiesiaca(itr->pobierzDateWydatku())){
                wyswietlDaneWydatku(*itr);
            }
        }
        cout << endl;
        for (vector <Dochod>::iterator itr=dochody.begin();itr!=dochody.end();itr++){
            if(sprawdzDatePoprzednegoMiesiaca(itr->pobierzDateDochodu())){
                wyswietlDaneDochodu(*itr);
            }
        }
    }
    else
    {
        cout << endl <<"Nie ma zadnego rekordu" << endl << endl;
    }
    system("pause");


}
void MenadzerBudzetu::pokazBilansZOkreslonegoOkresu(){
    system("cls");
    string dataOdPoczatkuBilansu,dataDoKoncaBilasnu;
    cout<<"Podaj date od jakiego czasu chcesz bilans: ";
    dataOdPoczatkuBilansu=MetodyPomocnicze::pobierzDate();
    cout<<"Podaj date do jakiego czasu chcesz bilans: ";
    dataDoKoncaBilasnu=MetodyPomocnicze::pobierzDate();
    if (!wydatki.empty())
    {
        cout << ">>> BILANS Z POPRZEDNIEGO MIESIACA <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Wydatek> :: iterator itr = wydatki.begin(); itr != wydatki.end(); itr++)
        {
            if(sprawdzOkres(itr->pobierzDateWydatku(),dataOdPoczatkuBilansu,dataDoKoncaBilasnu)){
                wyswietlDaneWydatku(*itr);
            }
        }
        cout << endl;
        for (vector <Dochod>::iterator itr=dochody.begin();itr!=dochody.end();itr++){
            if(sprawdzOkres(itr->pobierzDateDochodu(),dataOdPoczatkuBilansu,dataDoKoncaBilasnu)){
                wyswietlDaneDochodu(*itr);
            }
        }
    }
    else
    {
        cout << endl << "Nie ma zadnego rekordu" << endl << endl;
    }
    system("pause");


}
void MenadzerBudzetu::wyswietlDaneWydatku(Wydatek wydatek)
{
    cout << endl << "Id wydatku:    " << wydatek.pobierzIdWydatku()<< endl;
    cout << "Nazwa wydatku:         " << wydatek.pobierzNazweWydatku()<< endl;
    cout << "Data wydatku:          " << wydatek.pobierzDateWydatku() << endl;
    cout << "Kwota wydatku:         " << wydatek.pobierzKwoteWydatku() << endl;
}
void MenadzerBudzetu::wyswietlDaneDochodu(Dochod dochod)
{
    cout << endl << "Id dochodu:    " << dochod.pobierzIdDochodu()<< endl;
    cout << "Nazwa dochodu:         " << dochod.pobierzNazweDochodu()<< endl;
    cout << "Data dochodu:          " << dochod.pobierzDateDochodu() << endl;
    cout << "Kwota dochodu:         " << dochod.pobierzKwoteDochodu() << endl;
}
bool MenadzerBudzetu::sprawdzDate(string data){
    string aktualnyMiesiac=MetodyPomocnicze::pobierzMiesiac();
    int pozycjaSzukaniegoFragemtu=data.find(aktualnyMiesiac);
    if(pozycjaSzukaniegoFragemtu!=string::npos){
        return true;
    }else{
        return false;
    }
}
bool MenadzerBudzetu::sprawdzDatePoprzednegoMiesiaca(string data){
    string aktualnyMiesiac=MetodyPomocnicze::pobierzMiesiac();
    int poprzednyMiesica=atoi(aktualnyMiesiac.substr(5,2).c_str())+1;
    string miesiac="";
    if(poprzednyMiesica<10){
        miesiac="0"+to_string(poprzednyMiesica);
    }else{
        miesiac=to_string(poprzednyMiesica);
    }
    string poprzednyMiesiac=aktualnyMiesiac.replace(5,2,miesiac);
    int pozycjaSzukaniegoFragemtu=data.find(poprzednyMiesiac);
    if(pozycjaSzukaniegoFragemtu!=string::npos){
        return true;
    }else{
        return false;
    }
}
bool MenadzerBudzetu::sprawdzOkres(string data,string od,string doKoncaBilansu){
    int rokOdPoczatkuBilansu=atoi(od.substr(0,4).c_str());
    int miesiacOdPoczatkuBilansu=atoi(od.substr(5,6).c_str());
    int dzienOdPoczatkuBilansu=atoi(od.substr(8,9).c_str());
    int rokDoKoncaBilansu=atoi(doKoncaBilansu.substr(0,4).c_str());
    int miesiacDoKoncaBilansu=atoi(doKoncaBilansu.substr(5,6).c_str());
    int dzienDoKoncaBilansu=atoi(doKoncaBilansu.substr(8,9).c_str());
    int rok=atoi(data.substr(0,4).c_str());
    int miesiac=atoi(data.substr(5,6).c_str());
    int dzien=atoi(data.substr(8,9).c_str());
    if((rokOdPoczatkuBilansu<=rok && rok<=rokDoKoncaBilansu) && (miesiacOdPoczatkuBilansu<=miesiac && miesiac<=miesiacDoKoncaBilansu)&& (dzienOdPoczatkuBilansu<=dzien && dzien<=dzienDoKoncaBilansu)){
        return true;
    }else{
        return false;
    }

}

