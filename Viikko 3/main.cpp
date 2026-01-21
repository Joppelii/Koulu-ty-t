#include <iostream>
#include "chef.h"
#include "italianchef.h"

using namespace std;

int main()
{
    ItalianChef kokki("Pekka");
    kokki.makeSalad(28);
    kokki.makeSoup(30);
    kokki.askSecret("pizza", 6, 5);

    return 0;
}
