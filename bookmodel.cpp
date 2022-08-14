#include "bookmodel.h"

BookModel::BookModel(QObject *parent)
    : QAbstractTableModel(parent)
{

}

void BookModel::populateData(const QList<QString> &title,const QList<QString> &author, const QList<QString> &genre)
{
    tm_title.clear();
    tm_title = title;
    tm_author.clear();
    tm_author = author;
    tm_genre.clear();
    tm_genre = genre;
    return;
}

int BookModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return tm_title.length();
}

int BookModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3;
}

QVariant BookModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }
    if (index.column() == 0) {
        return tm_title[index.row()];
    } else if (index.column() == 1) {
        return tm_author[index.row()];
    } else if(index.column() == 2) {
        return tm_genre[index.row()];
    }
    return QVariant();
}

QVariant BookModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("Title");
        } else if (section == 1) {
            return QString("Author");
        } else if (section == 2) {
            return QString("Genre");
        }
    }
    return QVariant();
}
