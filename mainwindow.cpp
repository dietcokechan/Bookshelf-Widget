#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "editwindow.h"
#include "bookmodel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Window Settings
    this->setWindowTitle("Bookshelf");
    this->setWindowIcon(QIcon(":/Icons/bookshelf (2).png"));
    this->setFixedSize(600, 800);

    // Instatiate book model class
    BookModel *bookModel = new BookModel(this);
    ui->tableView->setModel(bookModel);

    // Headers
    QList<QString> title;
    QList<QString> author;

    // Mock data
    title.append("Sharp Objects");
    title.append("Before the Coffee Gets Cold");
    title.append("The Bell Jar");
    author.append("Gillian Flynn");
    author.append("Toshikazu Kawaguchi");
    author.append("Sylvia Plath");

    // Populate with mock data
    bookModel->populateData(title, author);

    // Shows horizontal header
    ui->tableView->horizontalHeader()->setVisible(true);
    ui->tableView->show();

    // Stretches columns
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Opens editing dialog window
void MainWindow::on_actionAdd_triggered()
{
    editwindow editWin;
    editWin.setModal(true);
    editWin.exec();
}
