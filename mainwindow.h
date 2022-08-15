#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QDebug>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

private slots:
    void on_actionAdd_triggered();

    void on_actionQuit_triggered();

    void on_actionEdit_toggled(bool editMode);

    void on_actionDelete_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

private:
    Ui::MainWindow *ui;
    bool editMode;

};
#endif // MAINWINDOW_H
