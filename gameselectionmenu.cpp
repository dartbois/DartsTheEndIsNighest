#include "gameselectionmenu.h"
#include "ui_gameselectionmenu.h"
#include "datahandler.h"
#include "matchstartdata.h"

GameSelectionMenu::GameSelectionMenu(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::GameSelectionMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("Game Selection Menu");
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint);
    audienceWindow = new AudienceView();
    scorerWindow = new ScorerView(audienceWindow);
    FillGameList();
    connect(this, SIGNAL(sendScorerViewMSD(MatchStartData)), scorerWindow, SLOT(getMSD(MatchStartData)));
    ui->listWidget->setCurrentRow(0);
}

GameSelectionMenu::~GameSelectionMenu()
{
    delete ui;
}

void GameSelectionMenu::on_pushButton_clicked()
{
    if (ui->listWidget->currentRow() != 0 && ui->listWidget->currentItem()->text() != ""){
        //get the ID of the selected list item
        //put it in a matchstartdata then send it to scorerview
        QListWidgetItem * myGame = ui->listWidget->currentItem();
        QStringList gameString = myGame->text().split("\t");
        QString gameIDstring = gameString[0].split("", Qt::SkipEmptyParts).first();
        QString completed = gameString[6].split("", Qt::SkipEmptyParts).first();

        if (completed == "0"){

            int gameID = gameIDstring.toInt();
            myMSD.postInit(gameID);
            //myD.matchGSMtoSV(scorerWindow, myMSD.gameStartScore);
            emit sendScorerViewMSD(myMSD);

            scorerWindow->show();
            audienceWindow->show();
            this->hide();
        }
    }
}

void GameSelectionMenu::FillGameList(){
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

        QString entry = QString("%1\t%2\t%3\t%4\t%5\t%6\t%7").arg(fields[0], -6).arg(fields[1], -30).arg(fields[2], -11).arg(fields[3], -16).arg(fields[4], -10).arg(fields[5], -10).arg(fields[6], -11);

        gameInfoList[i] = entry;

    }

    //Add list to listWidget
    ui->listWidget->addItems(gameInfoList);
}

/*
void GameSelectionMenu::sendScorerViewMSD(int startVal){
    //i'm tryin'
    return;
}
*/
