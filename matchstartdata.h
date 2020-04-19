#ifndef MATCHSTARTDATA_H
#define MATCHSTARTDATA_H
#include <string>

//This is a backend class.
//This class holds all of the information about the active game.
//It is involved with GameSelectionMenu, ScorerView, and AudienceView.
//It is also connected with Player.

using namespace std;

class MatchStartData
{
public:
    //Initialization
    MatchStartData();
    //Gathers all intitialization info after the class is actually instantiated
    void postInit(int matchID);
    //Initialization overloaded (identical, codewise, to postInit)
    MatchStartData(int matchID);
    //Game statistics
    string gameName;
    string gameDate;
    string gameLocation;
    int gameStartScore;
    int gameLegs;
    int gameMatches;
    int gamePs[2];
    //Facilitates data transmission
    string dataGet(string request);

};



#endif // MATCHSTARTDATA_H
