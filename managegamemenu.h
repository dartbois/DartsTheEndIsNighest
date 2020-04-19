#ifndef MANAGEGAMEMENU_H
#define MANAGEGAMEMENU_H

#include <QtWidgets/QDialog>
#include "gameaddeditmenu.h"
#include "gamereviewmenu.h"

//this is a UI class.
//This class is the window from which the user manages games.
//--This includes adding, deleting, and editing games.
//It frequently interacts with sqlHandler.
//It is instantiated by ManageChoiceMenu.
//It instantiates GameAddEditMenu.

namespace Ui {
class ManageGameMenu;
}

class ManageGameMenu : public QDialog
{
    Q_OBJECT

public:
    //Function to populate a list of games in the database.
    void FillGameList();
    //Constructor/destructor.
    explicit ManageGameMenu(QWidget *parent = nullptr);
    ~ManageGameMenu();

private slots:
     //Functions that respond when the user interacts with the UI.
    void on_GameMenuAdd_clicked();

    void on_GameMenuEdit_clicked();

    void on_GameMenuRemove_clicked();

    //Refreshes the list when a new game is added.
    void refreshGameAdded();

    void on_GameMenuReview_clicked();

private:
    //UI info and instantiating a gameAddEditMenu
    Ui::ManageGameMenu *ui;
    GameAddEditMenu* gameAddEditMenu;
    GameReviewMenu* gameReviewMenu;

};

#endif // MANAGEGAMEMENU_H
