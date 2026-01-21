#include "italianchef.h"
#include<iostream>
using namespace std;

ItalianChef::ItalianChef(string Kokki) : Chef(Kokki)
{
    chefName = Kokki;
    cout << "Italian kokin nimi: " << chefName << endl;
    cout << endl;
}


ItalianChef::~ItalianChef() {
    cout << endl;
    cout << "Destruktori " << chefName << endl;

}


bool ItalianChef::askSecret(string password2, int flour, int water)
{
    cout << endl;

    cout << "Tehdaan pizzaa!" << endl;

    cout << "paljon jauhoa? " << "| Annettiin taman verran: " << flour << endl;

    cout << "paljon vetta? " << "| Annettiin taman verran: " << water << endl;

    cout << endl;

    cout << "Anna Salasana " << "| Annettu salasana: " << password << endl;



    if(password2 == password){
        cout << "Salasana oikein" << endl;
        makepizza(flour, water);
        return true;
    }
    else {
        cout << "vastaus vaarin!" << endl;
        return false;
    }
}



int ItalianChef::makepizza(int matti, int pekka)
{
    flour = matti;
    water = pekka;

    flour = flour / 5;
    water = water / 5;

    cout << "saimme nain monta pizzaa: " << min(flour, water) << endl;

    return min(flour, water);
}
