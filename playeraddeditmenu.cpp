#include "playeraddeditmenu.h"
#include "ui_playeraddeditmenu.h"
#include "player.h"
#include "sqlhandler.h"
#include <QDir>
#include "manageplayermenu.h"

PlayerAddEditMenu::PlayerAddEditMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerAddEditMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("Player Addition/Edit");
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint);
}

PlayerAddEditMenu::~PlayerAddEditMenu()
{
    delete ui;
}

void PlayerAddEditMenu::on_AddPlayerInfo_clicked()
{
    player newPlayer = initNewPlayer();

    QString QPID = ui->PlayerIDAddEdit->text();
    int PID = QPID.toInt();

    QString path = QDir::currentPath();
    path = path + QString("/DartLeague.db");
    sqlHandler mySql(path);

    mySql.sqlAddNewPlayer(PID, newPlayer);
    emit refreshList();
    this->hide();
}

void PlayerAddEditMenu::on_EditPlayerInfo_clicked()
{
    player uPlayer = initNewPlayer();

    QString QPID = ui->PlayerIDAddEdit->text();
    int newPID = QPID.toInt();

    QString path = QDir::currentPath();
    path = path + QString("/DartLeague.db");
    sqlHandler mySql(path);

    mySql.sqlUpdatePlayer(oPID, newPID, uPlayer);
    emit refreshList();
    this->hide();
}

player PlayerAddEditMenu::initNewPlayer(){
    player newPlayer(0,0);

    QString QpFirst, QpLast, QpHome, QpRank, QpAv180, QpAv180S, QpLastWin, QpATS, QpATSS, QpTSHi, QpTSLo, QpPlayed, QpWon;

    QpFirst = ui->FirstNameAddEdit->text();
    QpLast = ui->LastNameAddEdit->text();
    QpHome = ui->HometownAddEdit->text();
    QpRank = ui->RankingAddEdit->text();
    QpAv180 = ui->Avg180sAddEdit->text();
    QpAv180S = ui->Avg180sSeasonAddEdit->text();
    QpLastWin = ui->LastGameWinAddEdit->text();
    QpATS = ui->AvgThrowScoreAddEdit->text();
    QpATSS = ui->AvgThrowScoreSeasonAddEdit->text();
    QpTSHi = ui->TurnScoreHighAddEdit->text();
    QpTSLo = ui->TurnScoreLowAddEdit->text();
    QpPlayed = ui->NumOfGamesPlayedAddEdit->text();
    QpWon = ui->NumOfGamesWonAddEdit->text();

    newPlayer.playerFirst[0] = QpFirst.toStdString();
    newPlayer.playerLast[0] = QpLast.toStdString();
    newPlayer.playerHometown[0] = QpHome.toStdString();
    newPlayer.playerRanking[0] = QpRank.toInt();
    newPlayer.playerAvg180s[0] = QpAv180.toFloat();
    newPlayer.playerAvg180Season[0] = QpAv180S.toFloat();
    newPlayer.playerLastWin[0] = QpLastWin.toInt();
    newPlayer.playerAvgThrow[0] = QpATS.toFloat();
    newPlayer.playerAvg180Season[0] = QpATSS.toFloat();
    newPlayer.playerTurnScoreHi[0] = QpTSHi.toInt();
    newPlayer.playerTurnScoreLo[0] = QpTSLo.toInt();
    newPlayer.playerGamesPlayed[0] = QpPlayed.toInt();
    newPlayer.playerGamesWon[0] = QpWon.toInt();

    return newPlayer;
}
