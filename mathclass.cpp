#include "datahandler.h"
#include "mathclass.h"


mathClass::mathClass(int scoreStart)
{
    currentScore[0] = scoreStart, currentScore[1] = scoreStart;
    /*legWins[0] = 0;
    legWins[1] = 1;
    matchWins[0] = 0;
    matchWins[1] = 0;
    matchesHeld = 0;
    ties = 0;*/
};

mathClass::mathClass(){
    /*legWins[0] = 0;
    legWins[1] = 1;
    matchWins[0] = 0;
    matchWins[1] = 0;
    matchesHeld = 0;
    ties = 0;*/
}

string mathClass::winnerCalc(){
    string winner;
    int commCountP1 = 0, commCountP2 = 0;

    if (currentScore[0] < 170 && currentScore[1] < 170){
        for (int i = 0; i < winThrows[currentScore[0]].length(); i++) {
            if (winThrows[currentScore[0]][i] == ',')
                commCountP1++;
        }
        for (int i = 0; i < winThrows[currentScore[1]].length(); i++) {
            if (winThrows[currentScore[0]][i] == ',')
                commCountP2++;
        }
        if (commCountP1 < commCountP2) {
            winner = "Player One";
        }
        else if (commCountP1 > commCountP2) {
            winner = "Player Two";
        }
        else winner = "Tied";
    }
    else {
        if (currentScore[0] < currentScore[1])
            winner = "Player One";
        else if (currentScore[0] > currentScore[1])
            winner = "Player Two";
        else winner = "Tied";
    }


    return winner;
};


string mathClass::winThrowCalc(int player){
    int score = currentScore[player];
    string finalWinThrow;
    if(score <= 170 && score >= 0){
        string winThrows[171] = {"Win","None","D1","1, D1","D2","1, D2","D3","1, D3","D4","1, D4","D5","1, D5","D6","1, D6","D7","1, D7","D8","1, D8","D9","1, D9","D10","1, D10","D11","1, D11","D12","1, D12","D13","1, D13","D14","1, D14","D15","1, D15","D16","1, D16","D17","1, D18","D18","1, D18","D19","1, D19","D20","9, D16","10, D16","11, D16","12, D16","13, D16","14, D16","15, D16","16, D16","17, D16","18, D16","19, D16","20, D16","13, D20","14, D20","15, D20","16, D20","17, D20","18, D20","19, D20","20, D20","T15, D8","T10, D16","T13, D12","D16, D16","T15, D10","T10, D18","T17, D8","T16, D10","T19, D6","T18, D8","T13, D16","T20, D6","T19, D8","T14, D16","T15, D15","T20, D8","T15, D16","T14, D18","T13, D20","T16, D16","T15, D18","T14, D20","T17, D16","T20, D12","T15, D20","T18, D16","T17, D18","T16, D20","T19, D16","T18, D18","T17, D20","T20, D16","T19, D18","T18, D20","T15, 18, D16","T20, D18","T19, D20","T20, D19","T19, 10, D16","T20, D20","T17, 18, D16","T20, 10, D16","T20, 11, D16","T18, 18, D16","T20, 13, D16","T20, 14, D16","T19, 18, D16","T20, 16, D16","T20, 17, D16","T20, 18, D16","T20, 19, D16","T20, 20, D16","T20, 13, D20","T20, 14, D20","T20, 15, D20","T20, 16, D20","T20, 17, D20","T20, 18, D20","T19, T10, D16","T20, 20, D20","T20, T15, D8","T18, T20, D4","T19, T16, D9","T20, D16, D16","B, T20, D20","T19, T19, D6","T19, T18, D8","T18, T14, D16","T19, T20, D6","T20, T18, D8","T20, T13, D16","T20, T20, D6","T20, T19, D8","T20, T14, D16","T20, T15, D15","T20, T20, D8","T17, T18, D16","T20, T14, D18","T20, T13, D20","T20, T16, D16","T20, T15, D18","T20, T14, D20","T20, T17, D16","T20, T20, D12","T20, T15, D20","T20, T18, D16","T20, T17, D18","T20, T16, D20","T20, T19, D16","T20, T18, D18","T20, T17, D20","T20, T20, D16","T20, T19, D18","T20, T18, D20","T20, T15, DB","T20, T20, D18","T20, T19, D20","T20, T20, D19","None","T20, T20, D20","T20, T17, DB","None","None","T20, T18, DB","None","None","T20, T19, DB","None","None","T20, T20, DB"};
        finalWinThrow = winThrows[score];
    }
    else{
        finalWinThrow = "";
    }

    return finalWinThrow;

};

//returns 0 if player has not reached 0, 1 if player wins,
//and 2 if player is in the negatives (opponent win).
int mathClass::scoreSubtract(int player, int throwScore){
    int winner = 0;
    int score = currentScore[player];
    score = score - throwScore;
    currentScore[player] = score;
    if (currentScore[player] == 0) { //if the current player hits 0, they win the leg.
        winner = player;
    }
    else if (currentScore[player] < 0){ //if the current player goes past 0, the other player wins the leg.
        if (player == 0) {
            winner = 1;
        }
        else {
            winner = 0;
        }
    }
    else { //otherwise, the match continues as normal.
        winner = 2;
    }
    return winner;
};


bool mathClass::scoreValidator(int remScore) {
    bool check;
    check = (1 <= remScore && remScore <= 20) || (1 <= remScore/3 && remScore/3 <= 20 && remScore%3 == 0) || (1 <= remScore/2 && remScore/2 <= 20 && remScore%2 == 0) || (remScore == 25) || (remScore == 50);
    return check;
};

string mathClass::dataGet(string request) {
    string answer;
    if (request=="score1") {
        answer = to_string(this->currentScore[0]);
    }
    else if (request == "score2") {
        answer = to_string(this->currentScore[1]);
    }
    return answer;
}
