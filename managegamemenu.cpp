#include "managegamemenu.h"
#include "ui_managegamemenu.h"
#include "datahandler.h"
#include "gamereviewmenu.h"

ManageGameMenu::ManageGameMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageGameMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("Manage Game Menu");
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint);
    FillGameList();
    gameAddEditMenu = new GameAddEditMenu();
    gameReviewMenu = new GameReviewMenu();

    //experimental
    connect(gameAddEditMenu, SIGNAL(refreshGList()), this, SLOT(refreshGameAdded()));

}

ManageGameMenu::~ManageGameMenu()
{
    delete ui;
}

void ManageGameMenu::FillGameList(){
    //Instance of datahandler
    DataHandler myD;

    //Begin by clearing the list
    ui->listWidget->clear();

    QString header = QString("%1\t%2\t%3\t%4\t%5\t%6\t%7").arg("Game ID", -6).arg("Game Name", -30).arg("Date", -11).arg("Location", -16).arg("Player1 ID", -10).arg("Player2 ID", -10).arg("Completed?", -15);

    ui->listWidget->addItem(header);

    //Return a string of game info from sqlhandler. \n delimited.
    std::string gameInfo;
    gameInfo = myD.sqlGet("1:gameInfoList");
    QString QgameInfo;
    QgameInfo = QString::fromStdString(gameInfo);

    //Split the info by \n
    QStringList gameInfoList = QgameInfo.split('\n');

    //Split by \t to get individual fields
    for (int i = 0; i<gameInfoList.length() - 1; i++){
        QStringList fields = gameInfoList[i].split("\t");

        QString entry = QString("%1\t%2\t%3\t%4\t%5\t%6\t%7\t").arg(fields[0], -6).arg(fields[1], -30).arg(fields[2], -11).arg(fields[3], -16).arg(fields[4], -10).arg(fields[5], -10).arg(fields[6], -11);

        gameInfoList[i] = entry;

    }

    //Add list to listWidget
    ui->listWidget->addItems(gameInfoList);

    ui->listWidget->setCurrentRow(0);
}

void ManageGameMenu::on_GameMenuAdd_clicked()
{
    gameAddEditMenu -> show();
}

void ManageGameMenu::on_GameMenuEdit_clicked()
{
    int gotGID;
    if (ui->listWidget->currentRow() != 0){
        QString currentItem = ui->listWidget->currentItem()->text();
        if (QString::compare(currentItem, "") != 0){
            QStringList currentItemList = currentItem.split(QRegExp("(\\s)+\\t"));
            gotGID = currentItemList[0].toInt();

            gameAddEditMenu->oGID = gotGID;
            gameAddEditMenu -> show();
        }
    }

}

void ManageGameMenu::on_GameMenuRemove_clicked()
{
    if (ui->listWidget->currentRow() != 0 && ui->listWidget->currentRow() != NULL){
        DataHandler myD;

        QString currentItem = ui->listWidget->currentItem()->text();
        if (QString::compare(currentItem, "") != 0){
            QStringList currentItemList = currentItem.split(QRegExp("(\\s)+\\t"));
            currentItem = currentItemList[0];

            string currentItemID = currentItem.toStdString();

            string req = currentItemID + ":removeGame";

            myD.sqlGet(req);

            FillGameList();
        }
    }
}

void ManageGameMenu::refreshGameAdded(){
    FillGameList();
}

void ManageGameMenu::on_GameMenuReview_clicked()
{
    if (ui->listWidget->currentRow() != 0 && ui->listWidget->currentRow() != NULL){
        DataHandler myD;
        int gotGID;
        QString currentItem = ui->listWidget->currentItem()->text();

        if (QString::compare(currentItem, "") != 0){
            QStringList currentItemList = currentItem.split(QRegExp("(\\s)+\\t"));
            gotGID = currentItemList[0].toInt();

            if (currentItemList[6] == "1"){
                gameReviewMenu->oGID = gotGID;
                gameReviewMenu->FillMenu(gotGID);
                gameReviewMenu -> show();
            }

        }
    }
}
