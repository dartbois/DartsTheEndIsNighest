#ifndef GAMESELECTIONMENU_H
#define GAMESELECTIONMENU_H

#include <QDialog>
#include "scorerview.h"
#include "audienceview.h"
#include "matchstartdata.h"

//this is a UI class
//This class allows the user to pick a predefined game
//It then instantiates a scorerview and audienceview for gameplay
//It is instantiated by StartupMenu

namespace Ui {
class GameSelectionMenu;
}

class GameSelectionMenu : public QDialog
{
    Q_OBJECT

public:
    //Populates the list from which you select a game
    void FillGameList();

    //constructor/destructor
    explicit GameSelectionMenu(QWidget *parent = nullptr);
    ~GameSelectionMenu();

signals:
    //sends the information on the game in question to the Scorerview
    void sendScorerViewMSD(MatchStartData myMSD);

private slots:
    //Function reacting to the player interacting with the UI
    void on_pushButton_clicked();  

private:
    //UI info and the two windows it instantiates
    Ui::GameSelectionMenu *ui;
    AudienceView* audienceWindow;
    ScorerView* scorerWindow;
    //void sendScorerViewMSD(int startVal);
public:
    //holds info about the game
    MatchStartData myMSD;
};

#endif // GAMESELECTIONMENU_H
