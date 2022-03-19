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
    cout<<aktualnaData<<endl;

}
