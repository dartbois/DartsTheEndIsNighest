#include "gamereviewmenu.h"
#include "ui_gamereviewmenu.h"
#include "datahandler.h"
#include "sqlhandler.h"

GameReviewMenu::GameReviewMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameReviewMenu)
{

    ui->setupUi(this);
    this->setWindowTitle("Game Review  ");
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint);

    FillMenu(oGID);
}

GameReviewMenu::~GameReviewMenu()
{

    delete ui;

}

void GameReviewMenu::on_gameReviewCancel_clicked()
{
    this->hide();
}

void GameReviewMenu::on_EditP1Throws_clicked()
{
    editThrowsMenu = new EditThrowsMenu(this, oGID, 0);
    editThrowsMenu -> show();
}

void GameReviewMenu::on_EditP2Throws_clicked()
{
    editThrowsMenu = new EditThrowsMenu(this, oGID, 1);
    editThrowsMenu -> show();
}

void GameReviewMenu::on_ChangeWinner_clicked()
{
    QString path = QDir::currentPath();
    path = path + QString("/DartLeague.db");
    sqlHandler mySql(path);

    QString qwinner = this->ui->Winner->text();
    int winner = qwinner.toInt();

    mySql.sqlUpdateWinner(oGID, winner);
}

void GameReviewMenu::FillMenu(int GID){
    this->ui->ThrowOneList->clear();
    this->ui->ThrowTwoList->clear();

    if (GID != 0){
        DataHandler myD;
        string sGID = to_string(GID);

        string req = sGID + ":gameP1Slings";
        string P1Slings = myD.sqlGet(req);
        req = sGID + ":gameP2Slings";
        string P2Slings = myD.sqlGet(req);

        QString slings1 = QString::fromStdString(P1Slings);
        QString slings2 = QString::fromStdString(P2Slings);

        QStringList slingsList1 = slings1.split("\\t");
        QStringList slingsList2 = slings2.split("\\t");

        this->ui->ThrowOneList->addItems(slingsList1);
        this->ui->ThrowTwoList->addItems(slingsList2);

        req = sGID + ":gameWinner";
        int winner = stoi(myD.sqlGet(req));
        QString qwinner = QString::number(winner);

        this->ui->Winner->setText(qwinner);

    }
}
