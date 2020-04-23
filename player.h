#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <QString>
using namespace std;

//This is a backend class.
//This class holds all variables for both players in a match.

class player
{
public:
    //Initialization functions.
    player(int playerID, int playerID2);
    player();
    void postInit(int playerID, int PlayerID2);
    //A variety of variables that hold player information.
    int playerIDs[2];
    string playerFirst[2];
    string playerLast[2];
    string playerHometown[2];
    int playerRanking[2];
    float playerAvg180s[2];
    float playerAvg180Season[2];
    int playerLastWin[2];
    float playerAvgThrow[2];
    float playerAvgThrowSeason[2];
    int playerTurnScoreHi[2];
    int playerTurnScoreLo[2];
    int playerGamesPlayed[2];
    int playerGamesWon[2];
    float playerWinPercent[2];
    int playerMatch180s[2];
    //int playerMatchesWon[2];
    //int playerLegsWon[2];

    //Tells us which player is currently active.
    bool active;

    //Slings for each player.
    QString p1Slings;
    QString p2Slings;

    //DataHandler integration.
    string dataGet(string request);

};

#endif // PLAYER_H
