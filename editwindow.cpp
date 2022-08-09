#include "editwindow.h"
#include "ui_editwindow.h"

editwindow::editwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editwindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Edit...");
    this->setFixedSize(800, 675);
}

editwindow::~editwindow()
{
    delete ui;
}
