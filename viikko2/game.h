#ifndef GAME_H
#define GAME_H

class GAME
{
public:

    GAME(int);
    ~GAME();

    void play();

private:

    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;

    void printGameResult();



};

#endif // GAME_H
