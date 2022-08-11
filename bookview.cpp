#include "bookview.h"

BookView::BookView(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant BookView::headerData(int section, Qt::Orientation orientation, int role) const
{
}

int BookView::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    return bookList.size();
}

int BookView::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    return headers.size();
}

QVariant BookView::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch(role)
    {
        case Qt::DisplayRole:
            switch(index.column())
            {
            case 0:
                return bookList[index.row()].title;
                break;
            case 1:
                return bookList[index.row()].author;
                break;
            case 2:
                return bookList[index.row()].rating;
                break;
            case 3:
                return bookList[index.row()].review;
                break;
            default:
                return QVariant();
                break;
            }
            break;

    case Qt::TextAlignmentRole:
        return Qt::AlignCenter;
        break;
    default:
        return QVariant();
        break;
    }

    return QVariant();
}
