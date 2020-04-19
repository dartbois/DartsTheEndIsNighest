#ifndef GAMEADDEDITMENU_H
#define GAMEADDEDITMENU_H

#include <QDialog>
#include "matchstartdata.h"

//this is a UI class
//This is the window that allows a user to add and edit games.
//This class is called by ManageGameMenu.

namespace Ui {
class GameAddEditMenu;
}

class GameAddEditMenu : public QDialog
{
    Q_OBJECT

public:
    //facilitates instantiating a new game
    MatchStartData initNewGame();
    //constructor/deconstructor
    int oGID;
    explicit GameAddEditMenu(QWidget *parent = nullptr);
    ~GameAddEditMenu();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

signals:
    void refreshGList();

private:
    Ui::GameAddEditMenu *ui;
};

#endif // GAMEADDEDITMENU_H
