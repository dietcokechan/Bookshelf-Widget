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
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Databases/books.db");
    db.open();

    QString title, author, genre;
    title = ui->t_title->text();
    author = ui->t_author->text();
    genre = ui->t_genre->text();

    QSqlQuery query;
    query.exec("INSERT INTO BOOKS (TITLE, AUTHOR, GENRE)"
               "VALUES ('"+title+"', '"+author+"', '"+genre+"')");

    query = QSqlQuery(db);

    db.close();
}
