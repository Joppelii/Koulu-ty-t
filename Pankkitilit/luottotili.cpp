#include "luottotili.h"
#include <iostream>


Luottotili::Luottotili(string nimi, double luottoRaja)  // Tilin omistajan nimi ja luottoraja

        : Pankkitili(nimi), luottoRaja(luottoRaja){}





bool Luottotili::deposit(double summa)
{


    if (summa >= 0){
         cout << "Luottovelan maksu: " << summa << " euroa " << "suoritettu" << endl;
        return true;
    }

    else{
        cout << "Epaonnistui, laittamasi maara: " << summa << " euroa on liian pieni" << endl;
        return false;

    }
    //Toteutus luottovelan maksulle
}




bool Luottotili::withdraw(double luotonNosto)
{
    if (luotonNosto <= 0){
         cout << "Luoton nosto: " << luotonNosto << " euroa " <<  "epaonnistui, yritit nostaa liikaa!" << endl;
        return false;
    }

    if (saldo - luotonNosto < - (luottoRaja)){
        cout << "Luoton nosto: " << luotonNosto << " euroa " <<  "epaonnistui, yritit nostaa liikaa!!" << endl;
        return false;
    }

    else{
        (saldo =  saldo - luotonNosto);

        cout << "Luottoraja: " << luottoRaja << " euroa " << "riitti!" << endl;
        return true;
    }
    //Toteutus luottotililtä nostolle
}
