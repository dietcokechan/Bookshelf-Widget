#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addbook.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Window Settings
    this->setWindowTitle("Bookshelf");
    this->setWindowIcon(QIcon(":/Icons/bookshelf (2).png"));
    this->setFixedSize(600, 800);

    // SQLite connection
    db = QSqlDatabase::addDatabase("QSQLITE", "SQLite");
    db.setDatabaseName("C:/Databases/books.db");

    if(!db.open())
        qInfo() << "---- Not connected ----";
    else
        qInfo() << "---- Connected ----";

    qDebug()  <<  QSqlDatabase::drivers();

    // View data from database
    QSqlTableModel *bookModel = new QSqlTableModel(this, db);
    bookModel->setTable("Books");
    bookModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    bookModel->select();

    ui->tableView->setModel(bookModel);

    // Hide headers
    ui->tableView->horizontalHeader()->setVisible(false);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->show();

    // Stretches columns
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Disallows editing in table
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAdd_triggered()
{
    AddBook addBook(this);
    addBook.setModal(true);
    addBook.exec();
}

void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionEdit_toggled(bool editMode)
{
    if(editMode)
    {
        ui->tableView->setEditTriggers(QAbstractItemView::AllEditTriggers);
    } else {
        // Disallows editing in table
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
}

void MainWindow::on_actionDelete_triggered()
{
    // TODO IMPLEMENT DELETE
}


void MainWindow::on_pushButton_2_pressed()
{
    ui->tableView->hide();
    ui->tableView->viewport()->repaint();
}

void MainWindow::on_pushButton_2_released()
{
    ui->tableView->show();
}


void MainWindow::on_pushButton_clicked()
{
    // TODO IMPLEMENT SEARCH
}

