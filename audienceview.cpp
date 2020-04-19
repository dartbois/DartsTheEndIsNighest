#include "audienceview.h"
#include "ui_audienceview.h"
#include "scorerview.h"
#include "datahandler.h"
#include "player.h"


AudienceView::AudienceView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AudienceView)
{
    ui->setupUi(this);
    this->setWindowTitle("Audience View");
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint);


    QString Stats = "                                 ";
    StatisticsDisplay = ui->StatisticsDisplay;
    Player2Stats = ui->Player2Stats;
    //BothP1AndP2Stats = ui->BothP1AndP2Stats;
    CurrentPlayer = ui->CurrentPlayer;
    NumberOf180s = ui->NumberOf180s;
    WinPercentages = ui->WinPercentages;
    PersonalStats = ui->PersonalStats;
    //MatchStats = ui->MatchStats;
    RankedStats = ui->RankedStats;
    playerCounter = 1;
    this->players = NULL;
    this->audienceDartboard = this->ui->widgetHolder;

    mathClass myMath;

    QString playerOneWin = QString::fromStdString(myMath.winThrowCalc(0));
    QString playerTwoWin = QString::fromStdString(myMath.winThrowCalc(1));

    ui->PlayerOnePredictions->setVisible(true);
    ui->PlayerTwoPredictions->setVisible(true);

    ui->PlayerOnePredictions->setText(playerOneWin);
    ui->PlayerTwoPredictions->setText(playerTwoWin);
}

AudienceView::~AudienceView()
{
    delete ui;
}

void AudienceView::on_StatisticsDisplay_linkActivated(const QString &link)
{

}

void AudienceView::on_Player2Stats_linkActivated(const QString &link)
{

}

/*void AudienceView::on_BothP1AndP2Stats_linkActivated(const QString &link)
{

}
*/
void AudienceView::on_CurrentPlayer_linkActivated(const QString &link)
{

}

void AudienceView::on_NumberOf180s_linkActivated(const QString &link)
{

}

void AudienceView::on_WinPercentages_linkActivated(const QString &link)
{

}

void AudienceView::on_PersonalStats_linkActivated(const QString &link)
{

}

/*void AudienceView::on_MatchStats_linkActivated(const QString &link)
{

}
*/
void AudienceView::on_RankedStats_linkActivated(const QString &link)
{

}

void AudienceView::setPlayerOneStatsText()
{
    DataHandler myD;

    QString stats;
    QString statsName, statsHome, statsRank, statsAvg180s;
    QString temp2;

    statsName = "Name: ";
    string temp = players->playerFirst[0];
    temp2 = QString::fromStdString(temp);
    statsName.append(temp2);
    statsName.append(" ");
    temp = players->playerLast[0];
    temp2 = QString::fromStdString(temp);
    statsName.append(temp2);
    statsName.append("\n");

    statsHome = "Hometown: ";
    temp = players->playerHometown[0];
    temp2 = QString::fromStdString(temp);
    statsHome.append(temp2);
    statsHome.append("\n");

    statsRank = "League Rank: ";
    int tempInt = players->playerRanking[0];
    temp2 = QString::number(tempInt);
    statsRank.append(temp2);
    statsRank.append("\n");

    statsAvg180s = "Average 180s per Match: ";
    float tempFloat = players->playerAvg180s[0];
    temp2 = QString::number(tempFloat);
    statsAvg180s.append(temp2);
    statsAvg180s.append("\n");

    stats = "Player One:\n";
    stats.append(statsName);
    stats.append(statsHome);
    stats.append(statsRank);
    stats.append(statsAvg180s);

    ui->StatisticsDisplay->setText(stats);
}

void AudienceView::setPlayerTwoStatsText()
{
    DataHandler myD;
    player myP(1,3);

    QString stats;
    QString statsName, statsHome, statsRank, statsAvg180s;
    QString temp2;

    statsName = "Name: ";
    string temp = players->playerFirst[1];
    temp2 = QString::fromStdString(temp);
    statsName.append(temp2);
    statsName.append(" ");
    temp = players->playerLast[1];
    temp2 = QString::fromStdString(temp);
    statsName.append(temp2);
    statsName.append("\n");

    statsHome = "Hometown: ";
    temp = players->playerHometown[1];
    temp2 = QString::fromStdString(temp);
    statsHome.append(temp2);
    statsHome.append("\n");

    statsRank = "League Rank: ";
    int tempInt = players->playerRanking[1];
    temp2 = QString::number(tempInt);
    statsRank.append(temp2);
    statsRank.append("\n");

    statsAvg180s = "Average 180s per Match: ";
    float tempFloat = players->playerAvg180s[1];
    temp2 = QString::number(tempFloat);
    statsAvg180s.append(temp2);
    statsAvg180s.append("\n");

    stats = "Player Two:\n";
    stats.append(statsName);
    stats.append(statsHome);
    stats.append(statsRank);
    stats.append(statsAvg180s);


    ui->Player2Stats->setText(stats);
}

/*void AudienceView::setBothP1AndP2StatsText()
{
    ui->BothP1AndP2Stats->setText("Player One and Player Two Statistics : ");
}*/

void AudienceView::setCurrentPlayerText()
{
    ui->CurrentPlayer->setText("Current Player Statistics : ");

    DataHandler myD;

    QString stats;
    QString statsName, statsHome, statsRank, statsAvg180s;
    QString temp2;

    if(players->active == false)    //current player is player1
    {
        statsName = "Name: ";
        string temp = players->playerFirst[0];
        temp2 = QString::fromStdString(temp);
        statsName.append(temp2);
        statsName.append(" ");
        temp = players->playerLast[0];
        temp2 = QString::fromStdString(temp);
        statsName.append(temp2);
        statsName.append("\n");

        statsHome = "Hometown: ";
        temp = players->playerHometown[0];
        temp2 = QString::fromStdString(temp);
        statsHome.append(temp2);
        statsHome.append("\n");

        statsRank = "League Rank: ";
        int tempInt = players->playerRanking[0];
        temp2 = QString::number(tempInt);
        statsRank.append(temp2);
        statsRank.append("\n");

        statsAvg180s = "Average 180s per Match: ";
        float tempFloat = players->playerAvg180s[0];
        temp2 = QString::number(tempFloat);
        statsAvg180s.append(temp2);
        statsAvg180s.append("\n");

        stats = "Current Player:\n";
        stats.append(statsName);
        stats.append(statsHome);
        stats.append(statsRank);
        stats.append(statsAvg180s);

        ui->CurrentPlayer->clear();
        ui->CurrentPlayer->setText(stats);
        ui->CurrentPlayer->show();
    }
    else        //current player is player2
    {
        statsName = "Name: ";
        string temp = players->playerFirst[1];
        temp2 = QString::fromStdString(temp);
        statsName.append(temp2);
        statsName.append(" ");
        temp = players->playerLast[1];
        temp2 = QString::fromStdString(temp);
        statsName.append(temp2);
        statsName.append("\n");

        statsHome = "Hometown: ";
        temp = players->playerHometown[1];
        temp2 = QString::fromStdString(temp);
        statsHome.append(temp2);
        statsHome.append("\n");

        statsRank = "League Rank: ";
        int tempInt = players->playerRanking[1];
        temp2 = QString::number(tempInt);
        statsRank.append(temp2);
        statsRank.append("\n");

        statsAvg180s = "Average 180s per Match: ";
        float tempFloat = players->playerAvg180s[1];
        temp2 = QString::number(tempFloat);
        statsAvg180s.append(temp2);
        statsAvg180s.append("\n");

        stats = "Current Player:\n";
        stats.append(statsName);
        stats.append(statsHome);
        stats.append(statsRank);
        stats.append(statsAvg180s);

        ui->CurrentPlayer->clear();
        ui->CurrentPlayer->setText(stats);
        ui->CurrentPlayer->show();
    }
}

void AudienceView::setNumberOf180sText()
{
    ui->NumberOf180s->setText("Number of 180s : ");
    DataHandler myD;

    QString stats;
    QString statsName, statsHome, statsRank, statsAvg180s;
    QString temp2;

    QString playerOneData;
    QString playerTwoData;
    QString playersData = "Number of 180s:\n";

    playerOneData = "Name: \t";
    string temp = players->playerFirst[0];
    temp2 = QString::fromStdString(temp);
    playerOneData.append(temp2);
    playerOneData.append(" ");
    temp = players->playerLast[0];
    temp2 = QString::fromStdString(temp);
    playerOneData.append(temp2);
    playerOneData.append("\t");

    playerOneData.append("Average 180s per Match: ");
    float tempFloat = players->playerAvg180s[0];
    temp2 = QString::number(tempFloat);
    playerOneData.append(temp2);
    playerOneData.append("\n");

    playerTwoData = "Name: \t";
    temp = players->playerFirst[1];
    temp2 = QString::fromStdString(temp);
    playerTwoData.append(temp2);
    playerTwoData.append(" ");
    temp = players->playerLast[1];
    temp2 = QString::fromStdString(temp);
    playerTwoData.append(temp2);
    playerTwoData.append("\t");

    playerTwoData.append("Average 180s per Match: ");
    tempFloat = players->playerAvg180s[1];
    temp2 = QString::number(tempFloat);
    playerTwoData.append(temp2);

    playersData.append(playerOneData);
    playersData.append("\n");
    playersData.append(playerTwoData);

    ui->NumberOf180s->setText(playersData);
}

void AudienceView::setWinPercentagesText()
{
    ui->WinPercentages->setText("Win Percentages : ");
    DataHandler myD;

    QString stats;
    QString statsName, statsHome, statsRank, statsAvg180s;
    QString temp2;

    QString playerOneData;
    QString playerTwoData;
    QString playersData = "Win Percentages:\n";

    playerOneData = "Name: \t";
    string temp = players->playerFirst[0];
    temp2 = QString::fromStdString(temp);
    playerOneData.append(temp2);
    playerOneData.append(" ");
    temp = players->playerLast[0];
    temp2 = QString::fromStdString(temp);
    playerOneData.append(temp2);
    playerOneData.append("\t");

    playerOneData.append("Win Percentages: ");
    float tempFloat = players->playerWinPercent[0];
    temp2 = QString::number(tempFloat);
    playerOneData.append(temp2);
    playerOneData.append("\n");

    playerTwoData = "Name: \t";
    temp = players->playerFirst[1];
    temp2 = QString::fromStdString(temp);
    playerTwoData.append(temp2);
    playerTwoData.append(" ");
    temp = players->playerLast[1];
    temp2 = QString::fromStdString(temp);
    playerTwoData.append(temp2);
    playerTwoData.append("\t");

    playerTwoData.append("Win Percentages: ");
    tempFloat = players->playerWinPercent[1];
    temp2 = QString::number(tempFloat);
    playerTwoData.append(temp2);

    playersData.append(playerOneData);
    playersData.append("\n");
    playersData.append(playerTwoData);

    ui->WinPercentages->setText(playersData);
}

void AudienceView::setPersonalStatsText()
{
    ui->PersonalStats->setText("Personal Statistics : ");

    DataHandler myD;
    QString stats;
    QString statsName, statsHome, statsRank, statsAvg180s;
    QString temp2;

    QString playerOneData;
    QString playerTwoData;
    QString playersData = "Personal Statistics:\n";

    playerOneData = "Name: \t";
    string temp = players->playerFirst[0];
    temp2 = QString::fromStdString(temp);
    playerOneData.append(temp2);
    playerOneData.append(" ");
    temp = players->playerLast[0];
    temp2 = QString::fromStdString(temp);
    playerOneData.append(temp2);
    playerOneData.append("\t");

    playerOneData.append("Hometown: ");
    temp = players->playerHometown[0];
    temp2 = QString::fromStdString(temp);
    playerOneData.append(temp2);
    playerOneData.append("\n");

    playerTwoData = "Name: \t";
    temp = players->playerFirst[1];
    temp2 = QString::fromStdString(temp);
    playerTwoData.append(temp2);
    playerTwoData.append(" ");
    temp = players->playerLast[1];
    temp2 = QString::fromStdString(temp);
    playerTwoData.append(temp2);
    playerTwoData.append("\t");

    playerTwoData.append("Hometown: ");
    temp = players->playerHometown[1];
    temp2 = QString::fromStdString(temp);
    playerTwoData.append(temp2);
    playerTwoData.append("\n");

    playersData.append(playerOneData);
    playersData.append("\n");
    playersData.append(playerTwoData);

    ui->PersonalStats->setText(playersData);
}

void AudienceView::setRankedStatsText()
{
    ui->RankedStats->setText("Ranked Statistics : ");
    DataHandler myD;

    QString stats;
    QString statsName, statsHome, statsRank, statsAvg180s;
    QString temp2;

    QString playerOneData;
    QString playerTwoData;
    QString playersData = "Ranked Statistics:\n";

    playerOneData = "Name: \t";
    string temp = players->playerFirst[0];
    temp2 = QString::fromStdString(temp);
    playerOneData.append(temp2);
    playerOneData.append(" ");
    temp = players->playerLast[0];
    temp2 = QString::fromStdString(temp);
    playerOneData.append(temp2);
    playerOneData.append("\t");

    playerOneData.append("League Rank: ");
    int tempInt = players->playerRanking[0];
    temp2 = QString::number(tempInt);
    playerOneData.append(temp2);
    playerOneData.append("\n");

    playerTwoData = "Name: \t";
    temp = players->playerFirst[1];
    temp2 = QString::fromStdString(temp);
    playerTwoData.append(temp2);
    playerTwoData.append(" ");
    temp = players->playerLast[1];
    temp2 = QString::fromStdString(temp);
    playerTwoData.append(temp2);
    playerTwoData.append("\t");

    playerTwoData.append("League Rank: ");
    tempInt = players->playerRanking[1];
    temp2 = QString::number(tempInt);
    playerTwoData.append(temp2);
    playerTwoData.append("\n");

    playersData.append(playerOneData);
    playersData.append("\n");
    playersData.append(playerTwoData);

    ui->RankedStats->setText(playersData);
}

void  AudienceView::setP1Prediction(QString prediction)
{
    this -> ui -> PlayerOnePredictions -> setText(prediction);
}

void  AudienceView::setP2Prediction(QString prediction)
{
    this -> ui -> PlayerTwoPredictions -> setText(prediction);
}

void AudienceView::setPlayerOneScoreText(int score)
{
    this->ui->PlayerOneCurrentScore->setText(QString::number(score));
}

void AudienceView::setPlayerTwoScoreText(int score)
{
    this->ui->PlayerTwoCurrentScore->setText(QString::number(score));
}

void AudienceView::undoP1CurrentScore()
{
    this->ui->PlayerOneCurrentScore->clear();
}

void AudienceView::undoP2CurrentScore()
{
    this->ui->PlayerTwoCurrentScore->clear();
}

void AudienceView::undoRankedText()         //Experimental
{
    ui->RankedStats->clear();
}

/*void AudienceView::undoMatchStatsText()
{
    ui->MatchStats->clear();
}*/


void AudienceView::undoPlayerTwoStatsText()
{
    ui->Player2Stats->clear();
}

/*void AudienceView::undoBothP1AndP2StatsText()
{
    ui->BothP1AndP2Stats->clear();
}*/


void AudienceView::undoCurrentPlayerText()
{
    ui->CurrentPlayer->clear();
}

void AudienceView::undoNumberOf180sText()
{
    ui->NumberOf180s->clear();
}

void AudienceView::undoWinPercentagesText()
{
    ui->WinPercentages->clear();
}

void AudienceView::undoPersonalStatsText()
{
    ui->PersonalStats->clear();
}

void AudienceView::undoPlayerOneStatsText()
{
    ui->StatisticsDisplay->clear();
}

void AudienceView::setLatestThrowText(QString *latestThrow)
{
    if(playerCounter % 2 == 1)
    {
        ui->PlayerOneLastThrowLabel->setText(*latestThrow);
    }
    else
    {
        ui->PlayerTwoLastThrowLabel->setText(*latestThrow);
    }
    playerCounter++;
}
