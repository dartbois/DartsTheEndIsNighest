#include "managechoicemenu.h"
#include "ui_managechoicemenu.h"

ManageChoiceMenu::ManageChoiceMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageChoiceMenu)
{
    ui->setupUi(this);
    manageGame = new ManageGameMenu();
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint);
    managePlayers = new ManagePlayerMenu();
}

ManageChoiceMenu::~ManageChoiceMenu()
{
    delete ui;
}

void ManageChoiceMenu::on_pushButton_clicked()
{
    manageGame->show();
}

void ManageChoiceMenu::changeWindow()
{
    if(manageGame->isVisible())
    {
        manageGame->hide();
        this->show();
    }
    else
    {
        this->hide();
        manageGame->show();
    }
}

void ManageChoiceMenu::on_managePlayers_clicked()
{
    managePlayers->show();
}
