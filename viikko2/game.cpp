#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


GAME::GAME(int a)
{
    maxNumber = a;
}

GAME::~GAME()
{
    cout<< "destructor"<<endl;
}


void GAME::play()
{
    numOfGuesses = 0;

    srand(time(0));

    randomNumber = rand() % maxNumber + 1;

    cout<<"anna arvauksesi 1-" << maxNumber<< " valilta" << endl;
    cin >> playerGuess;

    numOfGuesses ++;

    while(1) {

        if(playerGuess > randomNumber){

            numOfGuesses++;
            cout << "luku on liian suuri " << endl;

            cout << "Arvaa luku" << "anna arvauksesi 1-" << maxNumber<< " valilta" << endl;
            cin >> playerGuess;
        }

        else if(playerGuess < randomNumber){

            numOfGuesses++;
            cout << "luku on liian pieni" << endl;

            cout << "Arvaa luku" << "anna arvauksesi 1-" << maxNumber<< " valilta" << endl;
            cin >> playerGuess;

        }

        else{

            cout << "luku oikein" << endl;
            printGameResult();
            break;
        }

    }
}

void GAME::printGameResult()
{
    cout << "oikea vastaus oli numero: " << randomNumber << endl;
    cout << "Arvaustesi maara oli: " << numOfGuesses << endl;

}
