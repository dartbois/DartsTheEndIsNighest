#ifndef AUDIENCEVIEW_H
#define AUDIENCEVIEW_H

#include <QDialog>
#include <QLabel>
#include "player.h"
#include "widget.h"

//this is a UI class
//This class controls the window the audience would see.
//--This includes various statistics displays.
//It is instantiated in GameSelectionMenu and interacts often with ScorerView.

namespace Ui {
class AudienceView;
}

class AudienceView : public QDialog
{
    Q_OBJECT

public:
    explicit AudienceView(QWidget *parent = nullptr);
    ~AudienceView();
    int playerCounter;

    //slots can be connected to signals to recieve information
    //broadcast from one instantiated function to another
public slots:

    void on_StatisticsDisplay_linkActivated(const QString &link);

    //The setText slots show the stats on the bottom pane of the audience view
    void setPlayerOneStatsText();
    void setPlayerTwoStatsText();
    //void setBothP1AndP2StatsText();
    void setCurrentPlayerText();
    void setNumberOf180sText();
    void setWinPercentagesText();
    void setPersonalStatsText();
    //void setMatchStatsText();
    void setRankedStatsText();
    void setLatestThrowText(QString *latestThrow);
    void setP1Prediction(QString prediction);
    void setP2Prediction(QString prediction);
    void setPlayerOneScoreText(int score);
    void setPlayerTwoScoreText(int score);

    //The undo signals clear the bottom pane stats labels on the audience view
    void undoRankedText();      //Experimental
    //void undoMatchStatsText();
    void undoPlayerTwoStatsText();
    //void undoBothP1AndP2StatsText();
    void undoCurrentPlayerText();
    void undoNumberOf180sText();
    void undoWinPercentagesText();
    void undoPersonalStatsText();
    void undoPlayerOneStatsText();
    void undoP1CurrentScore();
    void undoP2CurrentScore();
public:
   //initializes the UI
   Ui::AudienceView *ui;
   //set of labels controlling stats displays in the UI
   QLabel *StatisticsDisplay;
   QLabel *Player2Stats;
   //QLabel *BothP1AndP2Stats;
   QLabel *CurrentPlayer;
   QLabel *NumberOf180s;
   QLabel *WinPercentages;
   QLabel *PersonalStats;
   //QLabel *MatchStats;
   QLabel *RankedStats;
   player *players;
   Widget* audienceDartboard;

private slots:
   //when a button is checked in scorerview,
   //these functions make audienceview respond.
   void on_Player2Stats_linkActivated(const QString &link);
   //void on_BothP1AndP2Stats_linkActivated(const QString &link);
   void on_CurrentPlayer_linkActivated(const QString &link);
   void on_NumberOf180s_linkActivated(const QString &link);
   void on_WinPercentages_linkActivated(const QString &link);
   void on_PersonalStats_linkActivated(const QString &link);
   //void on_MatchStats_linkActivated(const QString &link);
   void on_RankedStats_linkActivated(const QString &link);
};

#endif // AUDIENCEVIEW_H
