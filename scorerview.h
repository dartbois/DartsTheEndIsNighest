#ifndef SCORERVIEW_H
#define SCORERVIEW_H

#include <QtWidgets/QDialog>
#include "audienceview.h"
#include "mathclass.h"
#include <QLabel>
#include "matchstartdata.h"
#include "player.h"

//this is a UI class
//This class controls the window the scorer would see.
//--This includes various statistics option selections.
//It hosts the dartboard (which is 'widget') and score verification.
//It is instantiated in GameSelectionMenu and interacts often with AudienceView.

namespace Ui {
class ScorerView;
}

class ScorerView : public QDialog
{
    Q_OBJECT

public:
    //constructor/destructor
    explicit ScorerView(AudienceView *audienceWindow);
    ~ScorerView();
    //int legNumber;
    //int matchNumber;

public slots:
    //these react to the user interacting with the UI.
    void on_PlayerOneStats_clicked();

    void on_PlayerTwoStats_clicked();

    //void on_PlayerOneAndPlayerTwoStats_clicked();

    void on_CurrentPlayerStats_clicked();

    void on_RankedStats_clicked();

    //void on_MatchStats_clicked();

    void on_PersonalStats_clicked();

    void on_WinPercentages_clicked();

    void on_NumberOf180s_clicked();

    void set_SlingOneText(int score);

    void set_SlingTwoText(int score);

    void set_SlingThreeText(int score);

    void setPlayerOneScoreText(int score);

    void setPlayerTwoScoreText(int score);

    void undoP1CurrentScore();

    void undoP2CurrentScore();

    //gets a MatchStartData from GameSelectionMenu.
    void getMSD(MatchStartData myMSD);

signals:

    //These signals will show the stats in the audience window
    void sendPlayerOneStats();

    void sendPlayerTwoStats();

    //void sendPlayerOneAndPlayerTwoStats();

    void sendCurrentPlayerStats();

    void sendRankedStats();

    //void sendMatchStats();

    void sendPersonalStats();

    void sendWinPercentages();

    void sendNumberOf180s();

    void sendP1CurrentScore(int score);

    void sendP2CurrentScore(int score);

    //These signals will clear the stats from the audience window
    void sendRankedStatsUndo();

    //void sendMatchStatsUndo();

    void sendPersonalStatsUndo();

    void sendWinPercentagesUndo();

    void sendNumberOf180sUndo();

    void sendPlayerOneStatsUndo();

    void sendPlayerTwoStatsUndo();

    //void sendPlayerOneAndPlayerTwoStatsUndo();

    void sendCurrentPlayerStatsUndo();

    void sendP1CurrentScoreUndo();

    void sendP2CurrentScoreUndo();

    //These signals will be used for validation of the scores
    void sendValidateTrue(bool unblockScore);

    //These signals will be used to send the latest throw string to Audience View
    void sendLatestThrow(QString *latestThrow);

    void sendP1Prediction(QString prediction);

    void sendP2Prediction(QString prediction);

public:
    //various UI elements
    Ui::ScorerView *ui;
    QLabel *StatisticsDisplay;
    QLabel *Player2Stats;
    //QLabel *BothP1AndP2Stats;
    QLabel *CurrentPlayer;
    QLabel *NumberOf180s;
    QLabel *WinPercentages;
    QLabel *PersonalStats;
    //QLabel *MatchStats;
    QLabel *RankedStats;
    QLabel *SlingOneText;
    QLabel *SlingTwoText;
    QLabel *SlingThreeText;
    QLabel *currentThrowLabel;
    QLabel *lastThrowLabel;
    QString *currentThrow;
    QString *lastThrow;
    QString *currentScoreP1;
    QString *currentScoreP2;

private slots:
    void on_ValadationYes_clicked();
    void on_ValadationNo_clicked();
    void on_SlingOne_linkActivated(const QString &link);
    void on_SlingTwo_linkActivated(const QString &link);
    void on_SlineThree_linkActivated(const QString &link);

    void on_zeroSling1_clicked();

    void on_zeroSling2_clicked();

    void on_zeroSling3_clicked();

public:
    mathClass myM;
    //int beginScore;
    player myP;
    void legWinner(bool winnerIndex);
    AudienceView* m_audienceWindow;
    Widget* audienceDartboard;
    Widget* scorerDartboard;
};

#endif // SCORERVIEW_H
