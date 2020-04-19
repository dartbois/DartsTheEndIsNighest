#ifndef MATHCLASS_H
#define MATHCLASS_H
#include <string>
using namespace std;

//This is a backend class.
//This class consists mostly of mathematical functions.
//It determines winning throws and holds both players' scores.

class mathClass
{
public:
    //Constructors
    mathClass(int scoreStart);
    mathClass();
    string winnerCalc(); //calculates the match winner
    string winThrowCalc(int player); //calculates the winning throws
    int scoreSubtract(int player, int throwScore); //subtracts score from total, player is 0 or 1
    string dataGet(string request); //Facilitates data transmission
    bool scoreValidator(int remScore);
    int currentScore[2]; //current score
    int legWins[2];
    int legTotal;
    int matchWins[2];
    int matchTotal;
    int matchesHeld;
    int ties;
    int startScore;
private:

    //every winning throw in string form in an array
    string winThrows[171] = {"Win","None","D1","1, D1","D2","1, D2","D3","1, D3","D4","1, D4","D5","1, D5","D6","1, D6","D7","1, D7","D8","1, D8","D9","1, D9","D10","1, D10","D11","1, D11","D12","1, D12","D13","1, D13","D14","1, D14","D15","1, D15","D16","1, D16","D17","1, D18","D18","1, D18","D19","1, D19","D20","9, D16","10, D16","11, D16","12, D16","13, D16","14, D16","15, D16","16, D16","17, D16","18, D16","19, D16","20, D16","13, D20","14, D20","15, D20","16, D20","17, D20","18, D20","19, D20","20, D20","T15, D8","T10, D16","T13, D12","D16, D16","T15, D10","T10, D18","T17, D8","T16, D10","T19, D6","T18, D8","T13, D16","T20, D6","T19, D8","T14, D16","T15, D15","T20, D8","T15, D16","T14, D18","T13, D20","T16, D16","T15, D18","T14, D20","T17, D16","T20, D12","T15, D20","T18, D16","T17, D18","T16, D20","T19, D16","T18, D18","T17, D20","T20, D16","T19, D18","T18, D20","T15, 18, D16","T20, D18","T19, D20","T20, D19","T19, 10, D16","T20, D20","T17, 18, D16","T20, 10, D16","T20, 11, D16","T18, 18, D16","T20, 13, D16","T20, 14, D16","T19, 18, D16","T20, 16, D16","T20, 17, D16","T20, 18, D16","T20, 19, D16","T20, 20, D16","T20, 13, D20","T20, 14, D20","T20, 15, D20","T20, 16, D20","T20, 17, D20","T20, 18, D20","T19, T10, D16","T20, 20, D20","T20, T15, D8","T18, T20, D4","T19, T16, D9","T20, D16, D16","B, T20, D20","T19, T19, D6","T19, T18, D8","T18, T14, D16","T19, T20, D6","T20, T18, D8","T20, T13, D16","T20, T20, D6","T20, T19, D8","T20, T14, D16","T20, T15, D15","T20, T20, D8","T17, T18, D16","T20, T14, D18","T20, T13, D20","T20, T16, D16","T20, T15, D18","T20, T14, D20","T20, T17, D16","T20, T20, D12","T20, T15, D20","T20, T18, D16","T20, T17, D18","T20, T16, D20","T20, T19, D16","T20, T18, D18","T20, T17, D20","T20, T20, D16","T20, T19, D18","T20, T18, D20","T20, T15, DB","T20, T20, D18","T20, T19, D20","T20, T20, D19","None","T20, T20, D20","T20, T17, DB","None","None","T20, T18, DB","None","None","T20, T19, DB","None","None","T20, T20, DB"};
};

#endif // MATHCLASS_H
