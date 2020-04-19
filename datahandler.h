#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include <string>
#include "player.h"
#include "mathclass.h"
#include "matchstartdata.h"
#include "scorerview.h"
#include <QDir>
#include <QDebug>

//This is a back-end class.
//This class controls the transfer of data between classes.
//Some data transfer is handled by slots and signals instead.
//--Most of the front end uses slots/signals. Most of the backend uses dataHandler.

using namespace std;


class DataHandler
{
public:
    //initialization
    DataHandler();
    //deprecated versions of current functions
    /*
    string getData(string request);
    string setData(string request);
    */
    //one function for each class that needs to 'talk'
    string sqlGet(string request);
    string mathcGet(string request, mathClass myM);
    string matchstartGet(string request, MatchStartData myS);
    string playerGet(string request, player myP);
};

#endif // DATAHANDLER_H
