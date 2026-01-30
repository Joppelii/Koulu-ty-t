#include "pankkitili.h"
#include <iostream>


Pankkitili::Pankkitili(string nimi)
{
    cout << "hihhei" << endl;
}

double Pankkitili::getBalance()
{
    return saldo;


    //getteri muuttujalle saldo
}





bool Pankkitili::deposit(double talletus)
{

    if (talletus <= 0){
        cout << "Pankkitalletus: " << talletus << " euroa " << "epaonnistui, ei ole mitaan mita tallettaa" << endl;
            return false;

    }

    else{
        saldo += talletus;
        cout << "Pankkitalletus: " << talletus << " euroa " << "onnistui" << endl;
        return true;
    }

    //Tallettaa rahaa tilille
}






bool Pankkitili::withdraw(double nosto)
{
    if (nosto <= 0){
        cout << "Pankkinosto: " << nosto << " euroa " << "epaonnistui, et ole mahdollista nostaa 0 euroa!" << endl;
        return false;

    }

    if(nosto > saldo){
        cout << "Pankkinosto: " << nosto << " euroa " << "epaonnistui" << endl;
        return false;
    }

    else{
        saldo = saldo - nosto;
        cout << "Pankkinosto: " << nosto << " euroa " <<  "onnistui!" << endl;
        return true;
    }
    //Nostaa rahat tililtä
}
