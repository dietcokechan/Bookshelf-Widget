#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QDialog>
#include <QSqlQuery>

namespace Ui {
class AddBook;
}

class AddBook : public QDialog
{
    Q_OBJECT

public:
    explicit AddBook(QWidget *parent = nullptr);
    ~AddBook();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddBook *ui;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
};

#endif // ADDBOOK_H
