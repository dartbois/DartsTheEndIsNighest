#include <QDir>
#include <sqlhandler.h>
#include "gameaddeditmenu.h"
#include "ui_gameaddeditmenu.h"
#include "matchstartdata.h"

GameAddEditMenu::GameAddEditMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameAddEditMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("Game addintion/Edit ");
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint);
}

GameAddEditMenu::~GameAddEditMenu()
{
    delete ui;
}

void GameAddEditMenu::on_pushButton_clicked()
{
    MatchStartData newGame = initNewGame();

    QString QGID = ui->GameIDAddEdit->text();
    int GID = QGID.toInt();

    QString path = QDir::currentPath();
    path = path + QString("/DartLeague.db");
    sqlHandler mySql(path);

    mySql.sqlAddNewGame(GID, newGame);
    emit refreshGList();
    this->hide();
}

void GameAddEditMenu::on_pushButton_2_clicked()
{
    MatchStartData uGame = initNewGame();

    QString QGID = ui->GameIDAddEdit->text();
    int newGID = QGID.toInt();

    QString path = QDir::currentPath();
    path = path + QString("/DartLeague.db");
    sqlHandler mySql(path);

    mySql.sqlUpdateGame(oGID, newGID, uGame);
    emit refreshGList();
    this->hide();
}

MatchStartData GameAddEditMenu::initNewGame(){
    MatchStartData newGame(0);

    QString QgName, QgDate, QgLocation, QgStartScore, QgMaxMatch, QgMaxLeg, QgP1, QgP2;

    QgName = ui->GameNameAddEdit->text();
    QgDate = ui->DateAddEdit->text();
    QgLocation = ui->LocationAddEdit->text();
    QgStartScore = ui->StartingScoreAddEdit->text();
    QgMaxMatch = ui->MaxNumMatchesAddEdit->text();
    QgMaxLeg = ui->MaxNumLegsAddEdit->text();
    QgP1 = ui->PlayerOneAddEdit->text();
    QgP2 = ui->PlayerTwoAddEdit->text();

    newGame.gameName = QgName.toStdString();
    newGame.gameDate = QgDate.toStdString();
    newGame.gameLocation = QgLocation.toStdString();
    newGame.gameStartScore = QgStartScore.toInt();
    newGame.gameMatches = QgMaxMatch.toInt();
    newGame.gameLegs = QgMaxLeg.toInt();
    newGame.gamePs[0] = QgP1.toInt();
    newGame.gamePs[1] = QgP2.toInt();

    return newGame;
}
