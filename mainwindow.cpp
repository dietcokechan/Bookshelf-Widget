#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "editwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Bookshelf");
    this->setWindowIcon(QIcon(":/icons/Resources/bookshelf.png"));
    this->setFixedSize(1313, 713);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionEdit_Books_triggered()
{
    editwindow editWin;
    editWin.setModal(true);
    editWin.exec();
}
