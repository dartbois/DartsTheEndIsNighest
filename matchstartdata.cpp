#include "matchstartdata.h"
#include "datahandler.h"

//Constructor
MatchStartData::MatchStartData(int matchID)
{
    DataHandler myD;
    //If no matchID given, init to all zeroes/nulls
    if (matchID == 0){
        gameName = "";
        gameDate = "";
        gameLocation = "";
        gameStartScore = 0;
        gameMatches = 0;
        gameLegs = 0;
        gamePs[0] = 0;
        gamePs[1] = 0;
        gameID = 0;
    }
    //Otherwise, pull info from the database.
    else{
        string id = to_string(matchID);
        string req;
        req = id + ":gameName";
        gameName = myD.sqlGet(req);
        req = id + ":gameDate";
        gameDate = myD.sqlGet(req);
        req = id + ":gameLocation";
        gameLocation = myD.sqlGet(req);
        req = id + ":gameStartScore";
        gameStartScore = stoi(myD.sqlGet(req));
        req = id + ":gameMatches";
        gameMatches = stoi(myD.sqlGet(req));
        req = id + ":gameLegs";
        gameLegs = stoi(myD.sqlGet(req));
        req = id + ":gameP1";
        gamePs[0] = stoi(myD.sqlGet(req));
        req = id + ":gameP2";
        gamePs[1] = stoi(myD.sqlGet(req));
        gameID = matchID;
    }

}


//Overloaded constructor.
MatchStartData::MatchStartData()
{
    gameName = "";
    gameDate = "";
    gameLocation = "";
    gameStartScore = NULL;
    gameMatches = NULL;
    gameLegs = NULL;
    gamePs[0] = 0;
    gamePs[1] = 0;
    gameID = 0;
}

//Effectively an overloaded constructor; identical to that shown above.
void MatchStartData::postInit(int matchID){
    if (matchID == 0){
        gameName = "";
        gameDate = "";
        gameLocation = "";
        gameStartScore = 0;
        gameMatches = 0;
        gameLegs = 0;
        gamePs[0] = 0;
        gamePs[1] = 0;
        gameID = 0;
    }
    else{
        DataHandler myD;
        string id = to_string(matchID);
        string req;
        req = id + ":gameName";
        gameName = myD.sqlGet(req);
        req = id + ":gameDate";
        gameDate = myD.sqlGet(req);
        req = id + ":gameLocation";
        gameLocation = myD.sqlGet(req);
        req = id + ":gameStartScore";
        gameStartScore = stoi(myD.sqlGet(req));
        req = id + ":gameMatches";
        gameMatches = stoi(myD.sqlGet(req));
        req = id + ":gameLegs";
        gameLegs = stoi(myD.sqlGet(req));
        req = id + ":gameP1";
        gamePs[0] = stoi(myD.sqlGet(req));
        req = id + ":gameP2";
        gamePs[1] = stoi(myD.sqlGet(req));
        gameID = matchID;
    }
    return;
}

//Interfaces with dataHandler.
string MatchStartData::dataGet(string request){
    string answer;
    if (request == "gameName"){
        answer = gameName;
    }
    else if (request == "gameDate"){
        answer = gameDate;
    }
    else if (request == "gameLocation"){
        answer = gameLocation;
    }
    if (request == "gameStartScore"){
        answer = to_string(gameStartScore);
    }
    else if (request == "gameLegs"){
        answer = to_string(gameLegs);
    }
    else if (request == "gameMatches"){
        answer = to_string(gameMatches);
    }
    else if (request == "gameP1"){
        answer = to_string(gamePs[0]);
    }
    else if (request == "gameP2"){
        answer = to_string(gamePs[1]);
    }
    return answer;
}
