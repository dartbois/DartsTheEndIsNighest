#ifndef MANAGECHOICEMENU_H
#define MANAGECHOICEMENU_H

#include <QtWidgets/QDialog>
#include "managegamemenu.h"
#include "manageplayermenu.h"

//This is a UI class
//This class is the window where the user chooses to manage either players or games.
//This class instantiates a ManageGameMenu and a ManagePlayerMenu
//This class is instantiated by StartupMenu

namespace Ui {
class ManageChoiceMenu;
}

class ManageChoiceMenu : public QDialog
{
    Q_OBJECT

public:
    //constructor/destructor
    explicit ManageChoiceMenu(QWidget *parent = nullptr);
    ~ManageChoiceMenu();


public slots:
    //functions in reaction to the user interacting with the UI
    void on_pushButton_clicked();
    void changeWindow();
    void on_managePlayers_clicked();

private:
    //UI info and the two windows it instantiates
    Ui::ManageChoiceMenu *ui;
    ManageGameMenu* manageGame;
    ManagePlayerMenu* managePlayers;
};

#endif // MANAGECHOICEMENU_H
