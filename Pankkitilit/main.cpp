#include "asiakas.h"

using namespace std;

int main()
{
    Asiakas armas("Matti", 1500);
    Asiakas Bertta("Bertta", 0);

    armas.talletus(1300);

    armas.nosto(1200);

    armas.luotonNosto(1400);
    armas.luotonMaksu(100);

    armas.showSaldo();

    Bertta.talletus(0);
    Bertta.nosto(0);

    Bertta.luotonNosto(0);
    Bertta.luotonMaksu(0);

    Bertta.showSaldo();

    armas.tiliSiirto(75, Bertta);
     Bertta.showSaldo();
    armas.showSaldo();


    return 0;
}
