#include "MetodyPomocnicze.h"
char MetodyPomocnicze::wczytajZnak()
{
    string wejscie = "";
    char znak  = {0};

    while (true)
    {
        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}
string MetodyPomocnicze::wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}
int MetodyPomocnicze::wczytajLiczbeCalkowita()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}
float MetodyPomocnicze::wczytajLiczbeZPrzecinkiem(){
    string wejscie = "";
    float liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;

}
string MetodyPomocnicze::pobierzAktualnaDate(){

    stringstream przechowaCzas;
    time_t t = time(nullptr);
    tm tm = *localtime(&t);
    cout.imbue(locale());
    przechowaCzas<<put_time(&tm, "%Y-%m-%d");
    string aktualnaData=przechowaCzas.str();
    return aktualnaData;

}
string MetodyPomocnicze::pobierzDate(){

    map <int, int> dni;
    cout<<"Podaj date od 2000-01-01 (rok-miesiac-dzien)"<<endl;
    int rok, miesiac, dzien;
    string data;
    cout<<"Podaj rok: "<<endl;
    while(true){
        rok=wczytajLiczbeCalkowita();
        if(rok>=2000){
            break;
        }
        system("cls");
        cout<<"Podaj poprawny rok od roku 2000!"<<endl;

    }
    cout<<"Podaj miesiac: "<<endl;
    while(true){
        miesiac=wczytajLiczbeCalkowita();
        if(miesiac>0 && miesiac<13){
            break;
        }
        system("cls");
        cout<<"Podaj poprawny m-ce od 1 do 12!"<<endl;
    }
    dni=pobierzIloscDniWMiesiaciu(rok);
    cout<<"Podaj dzien: "<<endl;
    while(true){
        dzien=wczytajLiczbeCalkowita();
        if(dzien>0 && dzien<=dni[miesiac]){
            break;
        }
        system("cls");
        cout<<"Podaj poprawny dzien od 1 do "<<dni[miesiac]<<"!"<<endl;
    }
    data=to_string(rok)+"-"+to_string(miesiac)+"-"+to_string(dzien);
    return data;

}
map <int,int> MetodyPomocnicze::pobierzIloscDniWMiesiaciu(int rok){
    map<int,int> dniWRoku;
    dniWRoku[1]=31;
    if((rok%4==0 && rok%100!=0) || rok%400==0){
        dniWRoku[2]=29;
    }else{
        dniWRoku[2]=28;
    }
    dniWRoku[3]=31;
    dniWRoku[4]=30;
    dniWRoku[5]=31;
    dniWRoku[6]=30;
    dniWRoku[7]=31;
    dniWRoku[8]=31;
    dniWRoku[9]=30;
    dniWRoku[10]=31;
    dniWRoku[11]=30;
    dniWRoku[12]=31;
    return dniWRoku;
}
string MetodyPomocnicze::ustawDate(){
    char opcja;
    string data;
    cout<<"Jaka date chcesz ustawic?"<<endl;
    cout<<"1- date z dzisiaj"<<endl;
    cout<<"2- inna date"<<endl;
    while(true){
        opcja=wczytajZnak();
        switch(opcja){
        case '1':
            return pobierzAktualnaDate();
            break;
        case '2':
            return pobierzDate();
            break;
        default:
            cout<<"Nie ma takiej opcji"<<endl;
            break;
        }
    }
}
