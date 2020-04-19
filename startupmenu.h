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

namespace Ui {
class StartupMenu;
}

class StartupMenu : public QDialog
{
    Q_OBJECT

public:
    explicit StartupMenu(QWidget *parent = nullptr);
    ~StartupMenu();

public slots:
    void on_pushButton_clicked();
    void changeWindow();
    void on_GameButton_clicked();

private:
    Ui::StartupMenu *ui;
    ManageChoiceMenu* manageChoiceMenu;
    Widget* dartboardWindow;
    GameSelectionMenu* gameSelectionMenu;
    AudienceView* audienceWindow;
    ScorerView* scorerWindow;
};

#endif // STARTUPMENU_H
