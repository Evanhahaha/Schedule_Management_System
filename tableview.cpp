#include "tableview.h"
#include <QtWidgets>
#include <QStandardItemModel>
#include <string>

using namespace std;
tableView::tableView(QWidget *parent)
    : QWidget(parent)
{
    QStringList hlist = tr("Monday,Tuesday,Wednesday,Thursday,Friday").simplified().split(",");
    QStringList vlist = verticalTable();

    QStandardItemModel *model = new QStandardItemModel();

    model -> setHorizontalHeaderLabels(hlist);
    model -> setVerticalHeaderLabels(vlist);

//    QFile file("/Users/evan/Desktop/schedule.txt");
    QStandardItem *newItem = nullptr;
    QString line = "hello";
    QStringList list = {"hello"};
//    if (file.open(QFile::ReadOnly)) {
//        QTextStream stream(&file);
//        while (!stream.atEnd()) {
//            line = stream.readLine();
//            list = line.simplified().split(',');
//            int x = list.at(0).toInt();
//            int y = list.at(1).toInt();
//            newItem = new QStandardItem(list.at(2));
//            newItem -> setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
//            newItem -> setBackground(QBrush(QColor(Qt::magenta)));
//            model -> setItem(x, y, newItem);
//        }

//    }
    newItem = new QStandardItem(line);
    newItem -> setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    model -> setItem(0,0, newItem);

    QTableView *table = new QTableView();

//    table -> setModel(model);
//    table -> setSpan(0, 2, 2, 1);
//    table -> setSpan(0, 4, 2, 1);
//    table -> setSpan(4, 0, 2, 1);
//    table -> setSpan(4, 2, 2, 1);
//    table -> setSpan(2, 0, 2, 1);
//    table -> setSpan(2, 3, 2, 1);
//    table -> setSpan(0, 2, 2, 1);
//    table -> setSpan(0, 4, 2, 1);
//    table -> setSpan(7, 1, 2, 1);
//    table -> setSpan(7, 3, 2, 1);
//    table -> setSpan(7, 2, 2, 1);
//    table -> setSpan(0, 1, 2, 1);
//    table -> setSpan(0, 3, 2, 1);
//    table = setSize(table);
//    table -> resizeRowsToContents();


    QVBoxLayout *layoutV = new QVBoxLayout;
    layoutV ->addWidget(table);

    setLayout(layoutV);

}

QStringList tableView::verticalTable()
{
    QStringList vlist;
    for (int i=8; i < 23; i++) {
        QString s = QString::number(i);
        s = s + ":30";
        vlist.append(s);
    }

    return vlist;
}

QTableView* tableView::setSize(QTableView *table)
{
    int height = 10;
    int width = 10;
    int count_h = table -> verticalHeader() -> count();
    int count_w = table -> horizontalHeader() -> count();

    for (int i = 0; i < count_h; i++) {
        height += table -> verticalHeader() -> sectionSize(i);
    }
    for (int i = 0; i < count_w; i++) {
        width += table -> horizontalHeader() -> sectionSize(i);
    }

    table -> setMinimumSize(width, height);
    return table;
}
