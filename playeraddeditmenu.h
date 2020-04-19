#ifndef PLAYERADDEDITMENU_H
#define PLAYERADDEDITMENU_H

#include <QDialog>
#include "player.h"

//This is a UI class.
//This class facilitates the adding and editing of players in the database.
//This class is called by ManagePlayerMenu.

namespace Ui {
class PlayerAddEditMenu;
}

class PlayerAddEditMenu : public QDialog
{
    Q_OBJECT

public:
    //initializes and returns a new player
    player initNewPlayer();
    //constructor/destructor
    int oPID;
    explicit PlayerAddEditMenu(QWidget *parent = nullptr);
    ~PlayerAddEditMenu();

private slots:
    //reacts to the user interacting with the UI
    void on_AddPlayerInfo_clicked();

    void on_EditPlayerInfo_clicked();

signals:
    //refreshes the list after it has been updated
    void refreshList();

private:
    //UI setup
    Ui::PlayerAddEditMenu *ui;
};

#endif // PLAYERADDEDITMENU_H
