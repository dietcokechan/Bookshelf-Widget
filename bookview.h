#ifndef BOOKVIEW_H
#define BOOKVIEW_H

#include <QAbstractItemModel>

class BookView : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit BookView(QObject *parent = nullptr);

    struct Book
    {
        QString title;
        QString author;
        int rating;
        QString review;
    };

    const QStringList headers = {"title, author, rating, review"};

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QVector<Book> bookList;
};

#endif // BOOKVIEW_H
