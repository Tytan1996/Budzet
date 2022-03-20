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

    string data="";
    while(true){
        cout<<"Podaj date od 2000-01-01 (rok-miesiac-dzien)"<<endl;
        cout<<"Data: ";
        data=wczytajLinie();
        data=dodajZeroDoDaty(data);
        if(sprawdzDate(data)==true){
            return data;
        }
        cout<<"Zla data!"<<endl;
    }


}
string MetodyPomocnicze::dodajZeroDoDaty(string data){
    string zero="0";
    int dlugoscDaty=data.length();
    if(dlugoscDaty==8){
        data.insert(5,zero);
        data.insert(8,zero);
        return data;
    }else if(dlugoscDaty==9){
        if(data[6]=='-'){
            data.insert(5,zero);
        }else{
            data.insert(8,zero);
        }
        return data;
    }else{
        return data;
    }
    return data;
}
bool MetodyPomocnicze::sprawdzDate(string data){
    if(data.length()!=10){
        return false;
    }
    map <int, int> dni;
    int rok, miesiac, dzien;
    rok=atoi(data.substr(0,4).c_str());
    miesiac=atoi(data.substr(5,2).c_str());
    dzien=atoi(data.substr(8,2).c_str());
    dni=pobierzIloscDniWMiesiaciu(rok);
    if(rok>=2000 && (1<=miesiac && miesiac<=12) && (1<=dzien && dzien<=dni[miesiac])){
        return true;
    }else{
        return false;
    }
    return false;
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
string MetodyPomocnicze::pobierzMiesiac(){
    stringstream przechowaCzas;
    time_t t = time(nullptr);
    tm tm = *localtime(&t);
    cout.imbue(locale());
    przechowaCzas<<put_time(&tm, "%Y-%m-");
    string aktualnyMieciac=przechowaCzas.str();
    return aktualnyMieciac;

}
