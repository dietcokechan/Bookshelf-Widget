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
    QList<QString> genre;

    // Mock data
    title.append("Sharp Objects");
    title.append("Before the Coffee Gets Cold");
    title.append("The Bell Jar");
    author.append("Gillian Flynn");
    author.append("Toshikazu Kawaguchi");
    author.append("Sylvia Plath");
    genre.append("Drama");
    genre.append("Sci-Fi");
    genre.append("Novel");

    // Populate with mock data
    bookModel->populateData(title, author, genre);

    // Shows horizontal header
    ui->tableView->horizontalHeader()->setVisible(true);
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

// Opens editing dialog window
void MainWindow::on_actionAdd_triggered()
{
    editwindow editWin;
    editWin.setModal(true);
    editWin.exec();
}
