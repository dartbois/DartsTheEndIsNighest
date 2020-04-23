#ifndef SQLHANDLER_H
#define SQLHANDLER_H
#include "player.h"
#include "matchstartdata.h"
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

//This is a backend class.
//This class handles all interfacing with the SQLite database.

class sqlHandler
{
public:
    //Constructor, connection closer, and related variable.
    sqlHandler(const QString& path);
    void sqlCloseConnection();
    QSqlDatabase dartdb;

    //Getting various player information from the database.
    string sqlGetFirstName(int playerID);
    string sqlGetLastName(int playerID);
    string sqlGetHometown(int playerID);
    int sqlGetRanking(int playerID);
    float sqlGetAvg180s(int playerID);
    float sqlGetAvg180sSeason(int playerID);
    int sqlGetLastGameWin(int playerID);
    float sqlGetAvgThrowScore(int playerID);
    float sqlGetAvgThrowScoreSeason(int playerID);
    int sqlGetTurnScoreHi(int playerID);
    int sqlGetTurnScoreLo(int playerID);
    int sqlGetGamesPlayed(int playerID);
    int sqlGetGamesWon(int playerID);

    //Getting various game information from the database.
    string sqlGetGameName(int gameID);
    string sqlGetGameDate(int gameID);
    string sqlGetGameLocation(int gameID);
    int sqlGetGameStartScore(int gameID);
    int sqlGetGameMatches(int gameID);
    int sqlGetGameLegs(int gameID);
    int sqlGetGameP1(int gameID);
    int sqlGetGameP2(int gameID);
    int sqlGetWinner(int gameID);
    string sqlGetP1Slings(int gameID);
    string sqlGetP2Slings(int gameID);

    //Getting a list of the games and players held in the database.
    string sqlGetPlayerList();
    string sqlGetGameList();

    //Updating records at the end of a game.
    void sqlSetPlayerFinal(player Player);
    void sqlSetGameFinal(int gameID, int winnerID, string P1Slings, string P2Slings);

    //Functionality for interfacing with the database outside of a game
    void sqlAddNewPlayer(int playerID, player Player);
    void sqlUpdatePlayer(int playerID, int newPID, player Player);
    void sqlRemovePlayer(int playerID);
    void sqlAddNewGame(int gameID, MatchStartData newGame);
    void sqlUpdateGame(int gameID, int newGID, MatchStartData game);
    void sqlRemoveGame(int gameID);
    void sqlUpdateP1Throws(int gameID, string newThrows);
    void sqlUpdateP2Throws(int gameID, string newThrows);
    void sqlUpdateWinner(int gameID, int winner);

private:
    QSqlDatabase m_db;
};

#endif // SQLHANDLER_H
