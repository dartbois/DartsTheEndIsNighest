#include "manageplayermenu.h"
#include "ui_manageplayermenu.h"
#include "datahandler.h"

ManagePlayerMenu::ManagePlayerMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManagePlayerMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("Manage Player Menu");
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint);
    FillPlayerList();
    playerAddEditMenu = new PlayerAddEditMenu();

    //experimental
    connect(playerAddEditMenu, SIGNAL(refreshList()), this, SLOT(refreshPlayerAdded()));
}

ManagePlayerMenu::~ManagePlayerMenu()
{
    delete ui;
}

void ManagePlayerMenu::FillPlayerList(){
    //Instance of datahandler
    DataHandler myD;

    //Begin by clearing the list
    ui->listWidget->clear();

    QString header = QString("%1\t%2\t%3\t%4\t%5\t%6\t").arg("Player ID", -9).arg("First", -16).arg("Last", -16).arg("Hometown", -22).arg("League Rank", -11).arg("Games Played", -9);

    ui->listWidget->addItem(header);

    //Return a string of game info from sqlhandler. \n delimited.
    std::string playerInfo;
    playerInfo = myD.sqlGet("0:playerInfoList");
    QString QplayerInfo;
    QplayerInfo = QString::fromStdString(playerInfo);

    //Split the info by \n
    QStringList playerInfoList = QplayerInfo.split('\n');

    //Split by \t to get individual fields
    for (int i = 0; i<playerInfoList.length() - 1; i++){
        QStringList fields = playerInfoList[i].split("\t");

        QString entry = QString("%1\t%2\t%3\t%4\t%5\t%6\t").arg(fields[0], -9).arg(fields[1], -16).arg(fields[2], -16).arg(fields[3], -22).arg(fields[4], -11).arg(fields[5], -9);

        playerInfoList[i] = entry;

    }

    //Add list to listWidget
    ui->listWidget->addItems(playerInfoList);

    ui->listWidget->setCurrentRow(0);

}

void ManagePlayerMenu::on_PlayerMenuAdd_clicked()
{
     playerAddEditMenu -> show();
}

void ManagePlayerMenu::on_PlayerMenuEdit_clicked()
{
    int gotPID;
    if (ui->listWidget->currentRow() != 0){
        QString currentItem = ui->listWidget->currentItem()->text();
        if (QString::compare(currentItem, "") != 0){
            QStringList currentItemList = currentItem.split(QRegExp("(\\s)+\\t"), Qt::SkipEmptyParts);
            currentItem = currentItemList[0];
            gotPID = currentItem.toInt();

            playerAddEditMenu->oPID = gotPID;
            playerAddEditMenu -> show();
        }
    }
}

void ManagePlayerMenu::on_PlayerMenuRemove_clicked()
{
    //Row 0 is the header and cannot be removed.
   if (ui->listWidget->currentRow() != 0 && ui->listWidget->currentRow() != NULL){
       DataHandler myD;

       QString currentItem = ui->listWidget->currentItem()->text();
       if (QString::compare(currentItem, "") != 0){
           QStringList currentItemList = currentItem.split(QRegExp("(\\s)+\\t"), Qt::SkipEmptyParts);
           currentItem = currentItemList[0];

           string currentItemID = currentItem.toStdString();

           string req = currentItemID + ":removePlayer";

           myD.sqlGet(req);

           FillPlayerList();
       }
   }
}

void ManagePlayerMenu::refreshPlayerAdded(){
    FillPlayerList();
}

