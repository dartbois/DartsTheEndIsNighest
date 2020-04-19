#include "startupmenu.h"
#include "ui_startupmenu.h"

StartupMenu::StartupMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartupMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("Startup Menu");
    this->setWindowFlag(Qt::WindowMinMaxButtonsHint);
    manageChoiceMenu = new ManageChoiceMenu();
    //audienceWindow = new AudienceView();
    //scorerWindow = new ScorerView(audienceWindow);
    dartboardWindow = new Widget();
    //gameSelectionMenu = new GameSelectionMenu();
}

StartupMenu::~StartupMenu()
{
    delete ui;
}

void StartupMenu::on_pushButton_clicked()
{
    manageChoiceMenu->show();
}

void StartupMenu::changeWindow()
{
    if(manageChoiceMenu->isVisible())
    {
        manageChoiceMenu->hide();
        this->show();
    }
    else
    {
        this->hide();
        manageChoiceMenu->show();
    }
}

void StartupMenu::on_GameButton_clicked()
{
    gameSelectionMenu = new GameSelectionMenu();
    gameSelectionMenu -> show();
    this->hide();
}
