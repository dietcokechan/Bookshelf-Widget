#include "addbook.h"
#include "ui_addbook.h"
#include "mainwindow.cpp"

AddBook::AddBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBook)
{
    ui->setupUi(this);
}

AddBook::~AddBook()
{
    delete ui;
}

void AddBook::on_pushButton_clicked()
{
    // SQLite connection
    db.setDatabaseName("C:/Databases/books.db");
    db.open();

    QString title, author;
    title = ui->t_title->text();
    author = ui->t_author->text();

    QSqlQuery query = QSqlQuery(db);;
    query.exec("INSERT INTO BOOKS (TITLE, AUTHOR)"
               "VALUES ('"+title+"', '"+author+"')");

    db.close();
    this->accept();
}
