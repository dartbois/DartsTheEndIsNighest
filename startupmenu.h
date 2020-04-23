#ifndef STARTUPMENU_H
#define STARTUPMENU_H

#include <QtWidgets/QDialog>
#include <QMainWindow>
#include <QApplication>
#include "managechoicemenu.h"
#include "widget.h"
#include "scorerview.h"
#include "audienceview.h"
#include "gameselectionmenu.h"

//This is a UI class.
//This is the very first window to open when the program begins.

namespace Ui {
class StartupMenu;
}

class StartupMenu : public QDialog
{
    Q_OBJECT

public:
    //Constructor/destructor
    explicit StartupMenu(QWidget *parent = nullptr);
    ~StartupMenu();

public slots:
    //For interfacing with other classes
    void on_pushButton_clicked();
    void changeWindow();
    void on_GameButton_clicked();

private:
    //Various UI and window instantiation elements
    Ui::StartupMenu *ui;
    ManageChoiceMenu* manageChoiceMenu;
    Widget* dartboardWindow;
    GameSelectionMenu* gameSelectionMenu;
    AudienceView* audienceWindow;
    ScorerView* scorerWindow;
};

#endif // STARTUPMENU_H
