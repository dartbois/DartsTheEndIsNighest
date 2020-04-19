#include "player.h"
#include "datahandler.h"

player::player(int playerID, int playerID2)
{
    active = false; //false is player 1, true is player 2
    p1Slings = ""; //player 1's slings
    p2Slings = ""; //player 2's slings
    playerIDs[0] = playerID;
    playerIDs[1] = playerID2;

    if (playerID == 0 && playerID2 == 0){
        for (int i = 0; i < 2; i++){
            playerFirst[i] = "";
            playerLast[i] = "";
            playerHometown[i] = "";
            playerRanking[i] = 0;
            playerAvg180s[i] = 0;
            playerAvg180Season[i] = 0;
            playerLastWin[i] = 0;
            playerAvgThrow[i] = 0;
            playerAvgThrowSeason[i] = 0;
            playerTurnScoreHi[i] = 0;
            playerTurnScoreLo[i] = 0;
            playerGamesPlayed[i] = 0;
            playerGamesWon[i] = 0;
        }
    }
    else{
        //GET STUFF.
        DataHandler myD;
        string id1 = to_string(playerID);
        string id2 = to_string(playerID2);
        string req;

        //Variables coming from SQLite
        req = id1 + ":playerFirst";
        playerFirst[0] = myD.sqlGet(req);
        req = id2 + ":playerFirst";
        playerFirst[1] = myD.sqlGet(req);
        req = id1 + ":playerLast";
        playerLast[0] = myD.sqlGet(req);
        req = id2 + ":playerLast";
        playerLast[1] = myD.sqlGet(req);
        req = id1 + ":playerHometown";
        playerHometown[0] = myD.sqlGet(req);
        req = id2 + ":playerHometown";
        playerHometown[1] = myD.sqlGet(req);
        req = id1 + ":playerRanking";
        playerRanking[0] = stoi(myD.sqlGet(req));
        req = id2 + ":playerRanking";
        playerRanking[1] = stoi(myD.sqlGet(req));
        req = id1 + ":playerAvg180s";
        playerAvg180s[0] = stof(myD.sqlGet(req));
        req = id2 + ":playerAvg180s";
        playerAvg180s[1] = stof(myD.sqlGet(req));
        req = id1 + ":playerAvg180Season";
        playerAvg180Season[0] = stof(myD.sqlGet(req));
        req = id2 + ":playerAvg180Season";
        playerAvg180Season[1] = stof(myD.sqlGet(req));
        req = id1 + ":playerLastWin";
        playerLastWin[0] = stoi(myD.sqlGet(req));
        req = id2 + ":playerLastWin";
        playerLastWin[1] = stoi(myD.sqlGet(req));
        req = id1 + ":playerAvgThrow";
        playerAvgThrow[0] = stof(myD.sqlGet(req));
        req = id2 + ":playerAvgThrow";
        playerAvgThrow[1] = stof(myD.sqlGet(req));
        req = id1 + ":playerAvgThrowSeason";
        playerAvgThrowSeason[0] = stof(myD.sqlGet(req));
        req = id2 + ":playerAvgThrowSeason";
        playerAvgThrowSeason[1] = stof(myD.sqlGet(req));
        req = id1 + ":playerTurnScoreHi";
        playerTurnScoreHi[0] = stoi(myD.sqlGet(req));
        req = id2 + ":playerTurnScoreHi";
        playerTurnScoreHi[1] = stoi(myD.sqlGet(req));
        req = id1 + ":playerTurnScoreLo";
        playerTurnScoreLo[0] = stoi(myD.sqlGet(req));
        req = id2 + ":playerTurnScoreLo";
        playerTurnScoreLo[1] = stoi(myD.sqlGet(req));
        req = id1 + ":playerGamesPlayed";
        //
        playerGamesPlayed[0] = stoi(myD.sqlGet(req));
        req = id2 + ":playerGamesPlayed";
        playerGamesPlayed[1] = stoi(myD.sqlGet(req));
        req = id1 + ":playerGamesWon";
        playerGamesWon[0] = stoi(myD.sqlGet(req));
        req = id2 + ":playerGamesWon";
        playerGamesWon[1] = stoi(myD.sqlGet(req));
    }

    //Calculated Variables
    for (int i = 0; i<2; i++){
        if (playerGamesPlayed[i] != 0){
            playerWinPercent[i] = (playerGamesWon[i] / playerGamesPlayed[i]) * 100;
        }
        else{
            playerWinPercent[i] = 0;
        }

        playerMatch180s[i] = 0;
        //playerLegsWon[i] = 0;
        //playerMatchesWon[i] = 0;
    }

    return;
}

player::player(){

}

void player::postInit(int playerID, int playerID2)
{
    active = false;
    playerIDs[0] = playerID;
    playerIDs[1] = playerID2;

    if (playerID == 0 && playerID2 == 0){
        for (int i = 0; i < 2; i++){
            playerFirst[i] = "";
            playerLast[i] = "";
            playerHometown[i] = "";
            playerRanking[i] = 0;
            playerAvg180s[i] = 0;
            playerAvg180Season[i] = 0;
            playerLastWin[i] = 0;
            playerAvgThrow[i] = 0;
            playerAvgThrowSeason[i] = 0;
            playerTurnScoreHi[i] = 0;
            playerTurnScoreLo[i] = 0;
            playerGamesPlayed[i] = 0;
            playerGamesWon[i] = 0;
        }
    }
    else{
        //GET STUFF.
        DataHandler myD;
        string id1 = to_string(playerID);
        string id2 = to_string(playerID2);
        string req;

        //Variables coming from SQLite
        req = id1 + ":playerFirst";
        playerFirst[0] = myD.sqlGet(req);
        req = id2 + ":playerFirst";
        playerFirst[1] = myD.sqlGet(req);
        req = id1 + ":playerLast";
        playerLast[0] = myD.sqlGet(req);
        req = id2 + ":playerLast";
        playerLast[1] = myD.sqlGet(req);
        req = id1 + ":playerHometown";
        playerHometown[0] = myD.sqlGet(req);
        req = id2 + ":playerHometown";
        playerHometown[1] = myD.sqlGet(req);
        req = id1 + ":playerRanking";
        playerRanking[0] = stoi(myD.sqlGet(req));
        req = id2 + ":playerRanking";
        playerRanking[1] = stoi(myD.sqlGet(req));
        req = id1 + ":playerAvg180s";
        playerAvg180s[0] = stof(myD.sqlGet(req));
        req = id2 + ":playerAvg180s";
        playerAvg180s[1] = stof(myD.sqlGet(req));
        req = id1 + ":playerAvg180Season";
        playerAvg180Season[0] = stof(myD.sqlGet(req));
        req = id2 + ":playerAvg180Season";
        playerAvg180Season[1] = stof(myD.sqlGet(req));
        req = id1 + ":playerLastWin";
        playerLastWin[0] = stoi(myD.sqlGet(req));
        req = id2 + ":playerLastWin";
        playerLastWin[1] = stoi(myD.sqlGet(req));
        req = id1 + ":playerAvgThrow";
        playerAvgThrow[0] = stof(myD.sqlGet(req));
        req = id2 + ":playerAvgThrow";
        playerAvgThrow[1] = stof(myD.sqlGet(req));
        req = id1 + ":playerAvgThrowSeason";
        playerAvgThrowSeason[0] = stof(myD.sqlGet(req));
        req = id2 + ":playerAvgThrowSeason";
        playerAvgThrowSeason[1] = stof(myD.sqlGet(req));
        req = id1 + ":playerTurnScoreHi";
        playerTurnScoreHi[0] = stoi(myD.sqlGet(req));
        req = id2 + ":playerTurnScoreHi";
        playerTurnScoreHi[1] = stoi(myD.sqlGet(req));
        req = id1 + ":playerTurnScoreLo";
        playerTurnScoreLo[0] = stoi(myD.sqlGet(req));
        req = id2 + ":playerTurnScoreLo";
        playerTurnScoreLo[1] = stoi(myD.sqlGet(req));
        req = id1 + ":playerGamesPlayed";
        //
        playerGamesPlayed[0] = stoi(myD.sqlGet(req));
        req = id2 + ":playerGamesPlayed";
        playerGamesPlayed[1] = stoi(myD.sqlGet(req));
        req = id1 + ":playerGamesWon";
        playerGamesWon[0] = stoi(myD.sqlGet(req));
        req = id2 + ":playerGamesWon";
        playerGamesWon[1] = stoi(myD.sqlGet(req));
    }

    //Calculated Variables
    for (int i = 0; i<2; i++){
        if (playerGamesPlayed[i] != 0){
            playerWinPercent[i] = (playerGamesWon[i] / playerGamesPlayed[i]) * 100;
        }
        else{
            playerWinPercent[i] = 0;
        }

        playerMatch180s[i] = 0;
        //playerLegsWon[i] = 0;
        //playerMatchesWon[i] = 0;
    }

    return;
}



string player::dataGet(string request) {
    string myAns;

    if (request == "playerFirst0"){
        myAns = this->playerFirst[0];
    }
    else if (request == "playerFirst1"){
        myAns = this->playerFirst[1];
    }
    else if (request == "playerLast0"){
        myAns = this->playerLast[0];
    }
    else if (request == "playerLast1"){
        myAns = this->playerLast[1];
    }
    else if (request == "playerHometown0"){
        myAns = this->playerHometown[0];
    }
    else if (request == "playerHometown1"){
        myAns = this->playerHometown[1];
    }
    else if (request == "leagueRank0"){
        myAns = to_string(this->playerRanking[0]);
    }
    else if (request == "leagueRank1"){
        myAns = to_string(this->playerRanking[1]);
    }
    else if (request == "playerAvg180s0"){
        myAns = to_string(this->playerAvg180s[0]);
    }
    else if (request == "playerAvg180s1"){
        myAns = to_string(this->playerAvg180s[1]);
    }
    else if (request == "playerAvg180Season0"){
        myAns = to_string(this->playerAvg180Season[0]);
    }
    else if (request == "playerAvg180Season1"){
        myAns = to_string(this->playerAvg180Season[1]);
    }
    else if (request == "playerAvgThrow0"){
        myAns = to_string(this->playerAvgThrow[0]);
    }
    else if (request == "playerAvgThrow1"){
        myAns = to_string(this->playerAvgThrow[1]);
    }
    else if (request == "playerAvgThrowSeason0"){
        myAns = to_string(this->playerAvgThrowSeason[0]);
    }
    else if (request == "playerAvgThrowSeason1"){
        myAns = to_string(this->playerAvgThrowSeason[1]);
    }
    else if (request == "playerMatch180s0"){
        myAns = to_string(this->playerMatch180s[0]);
    }
    else if (request == "playerMatch180s1"){
        myAns = to_string(this->playerMatch180s[1]);
    }
    else if (request == "playerLastWin0"){
        myAns = to_string(this->playerLastWin[0]);
    }
    else if (request == "playerLastWin1"){
        myAns = to_string(this->playerLastWin[1]);
    }
    else if (request == "playerTurnScoreHi0"){
        myAns = to_string(this->playerTurnScoreHi[0]);
    }
    else if (request == "playerTurnScoreHi1"){
        myAns = to_string(this->playerTurnScoreHi[1]);
    }
    else if (request == "playerTurnScoreLo0"){
        myAns = to_string(this->playerTurnScoreLo[0]);
    }
    else if (request == "playerTurnScoreLo1"){
        myAns = to_string(this->playerTurnScoreLo[1]);
    }
    else if (request == "playerGamesPlayed0"){
        myAns = to_string(this->playerGamesPlayed[0]);
    }
    else if (request == "playerGamesPlayed1"){
        myAns = to_string(this->playerGamesPlayed[1]);
    }
    else if (request == "playerGamesWon0"){
        myAns = to_string(this->playerGamesWon[0]);
    }
    else if (request == "playerGamesWon1"){
        myAns = to_string(this->playerGamesWon[1]);
    }
    else if (request == "playerWinPercent0"){
        myAns = to_string(this->playerWinPercent[0]);
    }
    else if (request == "playerWinPercent"){
        myAns = to_string(this->playerWinPercent[1]);
    }

    return myAns;
}
