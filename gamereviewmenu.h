#ifndef GAMEREVIEWMENU_H
#define GAMEREVIEWMENU_H

#include <QDialog>
#include "editthrowsmenu.h"

namespace Ui {
class GameReviewMenu;
}

class GameReviewMenu : public QDialog
{
    Q_OBJECT

public:
    explicit GameReviewMenu(QWidget *parent = nullptr);
    ~GameReviewMenu();
    int oGID = 0;

    void FillMenu(int GID);

private slots:

    void on_gameReviewCancel_clicked();

    void on_EditP1Throws_clicked();

    void on_EditP2Throws_clicked();

    void on_ChangeWinner_clicked();

private:
    Ui::GameReviewMenu *ui;
    EditThrowsMenu *editThrowsMenu;
};

#endif // GAMEREVIEWMENU_H
