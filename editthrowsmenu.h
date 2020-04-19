#ifndef EDITTHROWSMENU_H
#define EDITTHROWSMENU_H

#include <QDialog>

namespace Ui {
class EditThrowsMenu;
}

class EditThrowsMenu : public QDialog
{
    Q_OBJECT

public:
    explicit EditThrowsMenu(QWidget *parent = nullptr);
    EditThrowsMenu(QWidget *parent, int GID, int player);
    ~EditThrowsMenu();

    void FillThrowsList();

    int player = 0;
    int GID = 0;

private slots:
    void on_pushButton_clicked();

    void on_Edit_clicked(); 

private:
    Ui::EditThrowsMenu *ui;
};

#endif // EDITTHROWSMENU_H
