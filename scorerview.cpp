#include "scorerview.h"
#include "ui_scorerview.h"
#include "audienceview.h"
#include <String>
#include <QDebug>


ScorerView::ScorerView(AudienceView *audienceWindow) :
    //QDialog(parent),
    ui(new Ui::ScorerView)
{
    ui->setupUi(this);
    this->setWindowTitle("Scorer Window");
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint);
    QString scoreString = "                                 ";
    currentThrow = new QString(scoreString);
    lastThrow = new QString(scoreString);
    SlingOneText = ui->SlingOne;
    SlingTwoText = ui ->SlingTwo;
    SlingThreeText = ui->SlineThree;
    currentThrowLabel = ui->CurrentThrowLabel;
    lastThrowLabel = ui->LastThrowLabel;
    audienceWindow->players = &myP;
    audienceDartboard = audienceWindow->audienceDartboard;
    this->scorerDartboard = this->ui->widget;
    m_audienceWindow = audienceWindow;

    //connect the show stats signals to the audience window slots
   connect(this, &ScorerView::sendPlayerOneStats, audienceWindow, &AudienceView::setPlayerOneStatsText);
   connect(this, &ScorerView::sendPlayerTwoStats, audienceWindow, &AudienceView::setPlayerTwoStatsText);
   //connect(this, &ScorerView::sendPlayerOneAndPlayerTwoStats, audienceWindow, &AudienceView::setBothP1AndP2StatsText);
   connect(this, &ScorerView::sendCurrentPlayerStats, audienceWindow, &AudienceView::setCurrentPlayerText);
   connect(this, &ScorerView::sendNumberOf180s, audienceWindow, &AudienceView::setNumberOf180sText);
   connect(this, &ScorerView::sendWinPercentages, audienceWindow, &AudienceView::setWinPercentagesText);
   connect(this, &ScorerView::sendPersonalStats, audienceWindow, &AudienceView::setPersonalStatsText);
   //connect(this, &ScorerView::sendMatchStats, audienceWindow, &AudienceView::setMatchStatsText);
   connect(this, &ScorerView::sendRankedStats, audienceWindow, &AudienceView::setRankedStatsText);
   connect(this, &ScorerView::sendLatestThrow, audienceWindow, &AudienceView::setLatestThrowText);
   connect(this, &ScorerView::sendP1Prediction, audienceWindow, &AudienceView::setP1Prediction);
   connect(this, &ScorerView::sendP2Prediction, audienceWindow, &AudienceView::setP2Prediction);

   connect(this->scorerDartboard, &Widget::scoreSignalOne, this->audienceDartboard, &Widget::mirrorDart);
   connect(this->scorerDartboard, &Widget::scoreSignalTwo, this->audienceDartboard, &Widget::mirrorDart);
   connect(this->scorerDartboard, &Widget::scoreSignalThree, this->audienceDartboard, &Widget::mirrorDart);


   //connect the current score labels on this scorer window, and then connect the current score to the audience view as well
   connect(this, &ScorerView::sendP1CurrentScore, this, &ScorerView::setPlayerOneScoreText);
   connect(this, &ScorerView::sendP2CurrentScore, this, &ScorerView::setPlayerTwoScoreText);
   connect(this, &ScorerView::sendP1CurrentScore, audienceWindow, &AudienceView::setPlayerOneScoreText);
   connect(this, &ScorerView::sendP2CurrentScore, audienceWindow, &AudienceView::setPlayerTwoScoreText);

   //connect the label-clearing undo signals to the audience window slots
   connect(this, &ScorerView::sendRankedStatsUndo, audienceWindow, &AudienceView::undoRankedText);
   //connect(this, &ScorerView::sendMatchStatsUndo, audienceWindow, &AudienceView::undoMatchStatsText);
   connect(this, &ScorerView::sendPlayerOneStatsUndo, audienceWindow, &AudienceView::undoPlayerOneStatsText);
   connect(this, &ScorerView::sendCurrentPlayerStatsUndo, audienceWindow, &AudienceView::undoCurrentPlayerText);
   //connect(this, &ScorerView::sendPlayerOneAndPlayerTwoStatsUndo, audienceWindow, &AudienceView::undoBothP1AndP2StatsText);
   connect(this, &ScorerView::sendNumberOf180sUndo, audienceWindow, &AudienceView::undoNumberOf180sText);
   connect(this, &ScorerView::sendWinPercentagesUndo, audienceWindow, &AudienceView::undoWinPercentagesText);
   connect(this, &ScorerView::sendPersonalStatsUndo, audienceWindow, &AudienceView::undoPersonalStatsText);
   connect(this, &ScorerView::sendPlayerTwoStatsUndo, audienceWindow, &AudienceView::undoPlayerTwoStatsText);
   connect(this, &ScorerView::sendP1CurrentScoreUndo, this, &ScorerView::undoP1CurrentScore);
   connect(this, &ScorerView::sendP2CurrentScoreUndo, this, &ScorerView::undoP2CurrentScore);
   connect(this, &ScorerView::sendP1CurrentScoreUndo, audienceWindow, &AudienceView::undoP1CurrentScore);
   connect(this, &ScorerView::sendP2CurrentScoreUndo, audienceWindow, &AudienceView::undoP2CurrentScore);



}

ScorerView::~ScorerView()
{
    delete ui;
}

void ScorerView::on_PlayerOneStats_clicked()
{
    if(ui->PlayerOneStats->isChecked())
    {
        emit sendPlayerOneStats();
    }
    else
    {
        emit sendPlayerOneStatsUndo();
    }
}

void ScorerView::on_PlayerTwoStats_clicked()
{
    if(ui->PlayerTwoStats->isChecked())
    {
        emit sendPlayerTwoStats();
    }
    else
    {
        emit sendPlayerTwoStatsUndo();
    }
}

/*void ScorerView::on_PlayerOneAndPlayerTwoStats_clicked()
{
    if(ui->PlayerOneAndPlayerTwoStats->isChecked())
    {
        emit sendPlayerOneAndPlayerTwoStats();
    }
    else
    {
        emit sendPlayerOneAndPlayerTwoStatsUndo();
    }
}*/

void ScorerView::on_CurrentPlayerStats_clicked()
{
    if(ui->CurrentPlayerStats->isChecked())
    {
        emit sendCurrentPlayerStats();
    }
    else
    {
        emit sendCurrentPlayerStatsUndo();
    }
}

void ScorerView::on_NumberOf180s_clicked()
{
    if(ui->NumberOf180s->isChecked())
    {
        emit sendNumberOf180s();
    }
    else
    {
        emit sendNumberOf180sUndo();
    }
}

void ScorerView::on_WinPercentages_clicked()
{
    if(ui->WinPercentages->isChecked())
    {
        emit sendWinPercentages();
    }
    else
    {
        emit sendWinPercentagesUndo();
    }
}

void ScorerView::on_PersonalStats_clicked()
{
    if(ui->PersonalStats->isChecked())
    {
        emit sendPersonalStats();
    }
    else
    {
        emit sendPersonalStatsUndo();
    }
}

/*void ScorerView::on_MatchStats_clicked()
{
    if(ui->MatchStats->isChecked())
    {
        emit sendMatchStats();
    }
    else
    {
        emit sendMatchStatsUndo();
    }
}*/

void ScorerView::on_RankedStats_clicked()
{
    if(ui->RankedStats->isChecked())
    {
        emit sendRankedStats();
    }
    else
    {
        emit sendRankedStatsUndo();
    }
}

void ScorerView::set_SlingOneText(int score)
{
    SlingOneText -> setText(QString::number(score));
    currentThrow->clear();
    currentThrow->append(SlingOneText->text());
    currentThrowLabel->setText(*currentThrow);
}

void ScorerView::set_SlingTwoText(int score)
{
    SlingTwoText -> setText(QString::number(score));
    currentThrow->append('\t');
    currentThrow->append(SlingTwoText->text());
    currentThrowLabel->setText(*currentThrow);
}

void ScorerView::set_SlingThreeText(int score)
{
    SlingThreeText -> setText(QString::number(score));
    currentThrow->append('\t');
    currentThrow->append(SlingThreeText->text());
    currentThrowLabel->setText(*currentThrow);
}

void ScorerView::on_ValadationYes_clicked()
{
    int winner = 0;
    int slingInt = 0;
    QString slingHolder = "";

    //code to get values from slings 1, 2, 3
    if (myP.active == false) { //if player 1 is active
        slingHolder = SlingOneText->text();
        slingInt = slingHolder.toInt();
        myP.p1Slings.append(slingHolder);
        myP.p1Slings.append("-");

        slingHolder = SlingTwoText->text();
        slingInt += slingHolder.toInt();
        myP.p1Slings.append(slingHolder);
        myP.p1Slings.append("-");

        slingHolder = SlingThreeText->text();
        slingInt += slingHolder.toInt();
        myP.p1Slings.append(slingHolder);
        myP.p1Slings.append("/t");

        if (slingInt == 180) {
            myP.playerMatch180s[0] = myP.playerMatch180s[0] + 1;
        }
        winner = myM.scoreSubtract(0, slingInt);
    }
    else { //if myP.active is true, player2 is active
        slingHolder = SlingOneText->text();
        slingInt = slingHolder.toInt();
        myP.p2Slings.append(slingHolder);
        myP.p2Slings.append("-");

        slingHolder = SlingTwoText->text();
        slingInt += slingHolder.toInt();
        myP.p2Slings.append(slingHolder);
        myP.p2Slings.append("-");

        slingHolder = SlingThreeText->text();
        slingInt += slingHolder.toInt();
        myP.p2Slings.append(slingHolder);
        myP.p2Slings.append("/t");

        if (slingInt == 180) {
            myP.playerMatch180s[1] = myP.playerMatch180s[1] + 1;
        }
        winner = myM.scoreSubtract(1, slingInt);
    }

    emit sendValidateTrue(false);    //sending false will unblock the scoring
    //Show the validated throw on the current throw
    lastThrow->clear();
    lastThrow->append(SlingOneText->text());
    lastThrow->append('\t');
    lastThrow->append(SlingTwoText->text());
    lastThrow->append('\t');
    lastThrow->append(SlingThreeText->text());
    lastThrowLabel->setText(*lastThrow);
    lastThrowLabel->show();
    emit sendLatestThrow(lastThrow);
    currentThrowLabel->clear();
    currentThrow->clear();
    SlingOneText->clear();
    SlingTwoText->clear();
    SlingThreeText->clear();

    if (winner < 2){ //if there was a winner for this leg, send it to legWinner.
        if (winner == 0){
            legWinner(myP.active);
        }
        else if (winner == 1){
            legWinner(!(myP.active));
        }
        //legWinner(winner);
    }
    else{
        //Otherwise, we go to the next leg. Not sure how to implement this exactly.
        //flips a boolean value which controls which player is being affected by all this
        myP.active = !(myP.active);
        qDebug() << "The bool is: " << myP.active;
    }

    int currentPlayerInt = 0;

    if(myP.active == false){
        currentPlayerInt = 0;
    }
    else{
        currentPlayerInt = 1;
    }

    QString currentPlayerPrediction;

    currentPlayerPrediction = QString::fromStdString(myM.winThrowCalc(currentPlayerInt));

    if(myP.active == false){
        emit sendP1Prediction(currentPlayerPrediction);
    }
    else{
         emit sendP2Prediction(currentPlayerPrediction);
    }

    //Clearing the labels forces them to update the text
    emit sendP1CurrentScoreUndo();
    emit sendP2CurrentScoreUndo();
    emit sendCurrentPlayerStatsUndo();

    //Now, set the labels' text
    emit sendP1CurrentScore(myM.currentScore[0]);
    emit sendP2CurrentScore(myM.currentScore[1]);
    if (ui->CurrentPlayerStats->isChecked()){
        emit sendCurrentPlayerStats();
    }
    this->repaint();
}

void ScorerView::on_ValadationNo_clicked()
{
    SlingOneText->clear();
    SlingTwoText->clear();
    SlingThreeText->clear();
    currentThrowLabel->clear();
    currentThrow->clear();
    emit sendValidateTrue(false);    //sending false will unblock the scoring
}

void ScorerView::on_SlingOne_linkActivated(const QString &link)
{

}

void ScorerView::on_SlingTwo_linkActivated(const QString &link)
{

}

void ScorerView::on_SlineThree_linkActivated(const QString &link)
{

}

void ScorerView::setPlayerOneScoreText(int score)
{
    this->ui->PlayerOneScore->setText(QString::number(score));
}

void ScorerView::setPlayerTwoScoreText(int score)
{
    this->ui->PlayerTwoScore->setText(QString::number(score));
}

void ScorerView::undoP1CurrentScore()
{
    this->ui->PlayerOneScore->clear();
}

void ScorerView::undoP2CurrentScore()
{
    this->ui->PlayerTwoScore->clear();
}

void ScorerView::getMSD(MatchStartData myMSD){
    myM.currentScore[0] = myMSD.gameStartScore;
    myM.currentScore[1] = myMSD.gameStartScore;
    myM.startScore = myMSD.gameStartScore;
    myM.legTotal = myMSD.gameLegs;
    myM.matchTotal = myMSD.gameMatches;
    myP.postInit(myMSD.gamePs[0], myMSD.gamePs[1]);

    //Clearing the labels forces them to update the text
    emit sendP1CurrentScoreUndo();
    emit sendP2CurrentScoreUndo();

    //Now, set the labels' text
    emit sendP1CurrentScore(myM.currentScore[0]);
    emit sendP2CurrentScore(myM.currentScore[1]);
}

void ScorerView::legWinner(bool winnerIndex) {
    int victoryIndex = 3; //0 for players index 0, 1 for player index 1, 2 for tie, 3 for no winner yet
    //verify leg winner! do a window or something
    if(winnerIndex == false)
    {
        myM.legWins[1] += 1;
    }
    else if (winnerIndex == true)
    {
        myM.legWins[0] += 1;
    }

    myM.currentScore[0] = myM.startScore;
    myM.currentScore[1] = myM.startScore;
    myP.p1Slings.append("\n");
    myP.p2Slings.append("\n");

    //it is impossible to tie on legs, so total number of legs is just total number of leg victories.
    if ((myM.legWins[0] + myM.legWins[1]) == myM.legTotal){
        //This match is complete!
        if (myM.legWins[0] > myM.legWins[1]) { //p1 has more LEG wins
            myM.matchWins[0] += 1;
        }
        else if (myM.legWins[1] > myM.legWins[0]){ //p2 has more LEG wins
            myM.matchWins[1] += 1;
        }
        else { //in case of a tie
            myM.ties += 1;
        }
        myM.matchesHeld += 1; //update matches held : 3
        if (myM.matchesHeld == myM.matchTotal) {
            //THA GAME IS DONE>
            if (myM.matchWins[0] > myM.matchWins[1]){ //p1 has more MATCH wins
                victoryIndex = 0;
            }
            else if (myM.matchWins[1] > myM.matchWins[0]){ //p2 has more MATCH wins
                victoryIndex = 1;
            }
            else { //tie
                victoryIndex = 2;
            }
            //we will boot up a sqlhandler and YEET THAT INFO INTO THE DB.
        }
    }
}

void ScorerView::on_zeroSling1_clicked()
{
    this->SlingOneText->setText(QString::number(0));
    this->repaint();
}

void ScorerView::on_zeroSling2_clicked()
{
    this->SlingTwoText->setText(QString::number(0));
    this->repaint();
}

void ScorerView::on_zeroSling3_clicked()
{
    this->SlingThreeText->setText(QString::number(0));
    this->repaint();
}
