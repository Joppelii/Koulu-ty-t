#include "chef.h"
#include<iostream>
using namespace std;

Chef::Chef(string b) {

   chefName = b;
      cout << "Kokin nimi:  " << chefName << endl;

}

Chef::~Chef() {
    cout << "Destruktori " << chefName << endl;
}

int Chef::makeSalad(int salaatti)
{
    cout << "Tehdaan salaattia" << endl;

    salaatti = salaatti/ 5;

    cout << "Saimme nain monta keittoa: " << salaatti << endl;
    cout << endl;
    return salaatti;
}

int Chef::makeSoup(int soppa)
{
    cout << "Tehdaan soppaa" << endl;

    soppa = soppa / 3;

    cout << "Saimme nain monta keittoa: " << soppa << endl;

    return soppa;
}

