#include "editwindow.h"
#include "ui_editwindow.h"

editwindow::editwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editwindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Add...");
    this->setWindowIcon(QIcon(":/Icons/book (2).png"));
    this->setFixedSize(400, 400);
}

editwindow::~editwindow()
{
    delete ui;
}
