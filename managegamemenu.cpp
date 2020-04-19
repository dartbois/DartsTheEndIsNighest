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

    QString header = "Game ID\tGame Name\tDate\tLocation\tPlayer1 ID\tPlayer2 ID\tCompleted?";
    ui->listWidget->addItem(header);

    //Return a string of game info from sqlhandler. \n delimited.
    std::string gameInfo;
    gameInfo = myD.sqlGet("1:gameInfoList");
    QString QgameInfo;
    QgameInfo = QString::fromStdString(gameInfo);

    //Split the info by \n
    QStringList gameInfoList = QgameInfo.split('\n');

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
            QStringList currentItemList = currentItem.split("\t");
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
            QStringList currentItemList = currentItem.split("\t");
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
            QStringList currentItemList = currentItem.split("\t");
            gotGID = currentItemList[0].toInt();

            if (currentItemList[6] == "1"){
                gameReviewMenu->oGID = gotGID;
                gameReviewMenu->FillMenu(gotGID);
                gameReviewMenu -> show();
            }

        }
    }
}
