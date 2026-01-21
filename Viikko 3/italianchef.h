#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H
#include "chef.h"

using namespace std;

class ItalianChef: public Chef
{

    public:

        ItalianChef(string);
        ~ ItalianChef();
        bool askSecret(string, int, int);

    private:

        string password = "pizza";
        int makepizza(int flour, int water);
        int flour;
        int water;

};

#endif // ITALIANCHEF_H
