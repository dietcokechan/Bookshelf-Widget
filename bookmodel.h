#ifndef BOOKMODEL_H
#define BOOKMODEL_H

#include <QAbstractTableModel>

class BookModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit BookModel(QObject *parent = nullptr);

    // populate data
    void populateData(const QList<QString> &title,const QList<QString> &author, const QList<QString> &genre);

    //Header corresponding to attribute (list header)
    const QStringList headers = {"Title", "Author", "Genre"};

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    //Attributes of a Book
    QList<QString> tm_title;
    QList<QString> tm_author;
    QList<QString> tm_genre;
};

#endif // BOOKMODEL_H
