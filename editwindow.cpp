#include "editwindow.h"
#include "ui_editwindow.h"

editwindow::editwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editwindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Edit...");
    this->setWindowIcon(QIcon(":/Icons/author (2).png"));
    this->setFixedSize(800, 550);
}

editwindow::~editwindow()
{
    delete ui;
}
