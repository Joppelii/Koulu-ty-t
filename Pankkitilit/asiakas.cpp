#include "asiakas.h"
#include<iostream>



using namespace std;


Asiakas::Asiakas(string valinta, double asiakasluotto)
    : nimi(valinta),
    kayttotili(valinta),
    luottotili(nimi, asiakasluotto){}



void Asiakas::showSaldo()
{
    cout << "Asiakkaan kayttotilin kate: " << kayttotili.getBalance() << endl;
    cout << "Asiakkaan luottotilin kate: " << luottotili.getBalance() << endl << endl;
    //Tänne tulee sekä pankkitilin, että luottotilin tiedot
}




bool Asiakas::talletus(double summa)
{
    return kayttotili.deposit(summa);
}



bool Asiakas::nosto(double nosto)
{
    return kayttotili.withdraw(nosto);
}




bool Asiakas::luotonMaksu(double palautus)
{
    return luottotili.deposit(palautus);
    //tekee operaatiot luottotilille
}



bool Asiakas::luotonNosto(double summa)
{
    return luottotili.withdraw(summa);
    //tekee operaatiot luottotilille
}

bool Asiakas::tiliSiirto(double siirrettava, Asiakas & ToinenAsiakas)
{
    if(siirrettava <= 0){
        cout << "Siirrettava maara " << siirrettava << " on liian vahan, siirtoa ei voida tehda" << endl;
    return false;
    }

    if(siirrettava > kayttotili.getBalance()){
        cout << "Tilillasi ei ole tarpeekis katetta siirtoon" << endl;
         return false;
    }

    else
    {
        cout << "Siirto: " << siirrettava << " euroa suoritettu onnistuneesti" << endl;

    }

    kayttotili.withdraw(siirrettava);
    ToinenAsiakas.kayttotili.deposit(siirrettava);
    return true;
}
