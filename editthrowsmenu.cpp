#include "editthrowsmenu.h"
#include "ui_editthrowsmenu.h"
#include "datahandler.h"
#include "sqlhandler.h"

EditThrowsMenu::EditThrowsMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditThrowsMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("Edit Throws Menu");
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint);

}

EditThrowsMenu::EditThrowsMenu(QWidget *parent, int gameID, int playID) :
    QDialog(parent),
    ui(new Ui::EditThrowsMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("Edit Throws Menu");
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint);

    this->player = playID;
    this->GID= gameID;

    FillThrowsList();
}



EditThrowsMenu::~EditThrowsMenu()
{
    delete ui;
}

void EditThrowsMenu::on_pushButton_clicked()
{
    this->hide();
}

void EditThrowsMenu::on_Edit_clicked()
{
    if (GID != 0){
        QString path = QDir::currentPath();
        path = path + QString("/DartLeague.db");
        sqlHandler mySql(path);

        QString qNewThrows = this->ui->textEdit_2->toPlainText();
        string newThrows = qNewThrows.toStdString();

        if (player == 0){
            mySql.sqlUpdateP1Throws(GID, newThrows);
        }
        else if (player == 1){
            mySql.sqlUpdateP2Throws(GID, newThrows);
        }
    }
    FillThrowsList();
}

void EditThrowsMenu::FillThrowsList(){
    if (GID != 0){
        DataHandler myD;
        string req = "";

        if (player == 0){
            string sGID = to_string(GID);
            req = sGID + ":gameP1Slings";
        }
        else if (player == 1){
            string sGID = to_string(GID);
            req = sGID + ":gameP2Slings";
        }

        string OSlings = myD.sqlGet(req);
        QString QOSlings = QString::fromStdString(OSlings);

        this->ui->textEdit->setText(QOSlings);
    }
}
