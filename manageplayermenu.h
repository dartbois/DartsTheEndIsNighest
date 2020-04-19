#ifndef MANAGEPLAYERMENU_H
#define MANAGEPLAYERMENU_H

#include <QtWidgets/QDialog>
#include "playeraddeditmenu.h"

//This is a UI class.
//This is the window where the user makes changes to the list of available players.
//This window is instantiated by ManageChoiceMenu.
//This window instantiates playerAddEditMenu.

namespace Ui {
class ManagePlayerMenu;
}

class ManagePlayerMenu : public QDialog
{
    Q_OBJECT

public:
    //Fills list with players from the database.
    void FillPlayerList(); 
    //constructor and destructor
    explicit ManagePlayerMenu(QWidget *parent = nullptr);
    ~ManagePlayerMenu();

private slots:
    //Functions responding to UI interactions
    void on_PlayerMenuAdd_clicked();

    void on_PlayerMenuEdit_clicked();

    void on_PlayerMenuRemove_clicked();

    //refreshes the list after a player is added or changed.
    void refreshPlayerAdded();

private:
    //UI information and playerAddEditMenu instantiation.
    Ui::ManagePlayerMenu *ui;
     PlayerAddEditMenu* playerAddEditMenu;
};

#endif // MANAGEPLAYERMENU_H
