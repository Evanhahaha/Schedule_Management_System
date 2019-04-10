#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QWidget>
#include <QtWidgets>

class tableView : public QWidget
{
    Q_OBJECT

private:
    QStringList verticalTable();
    QTableView* setSize(QTableView *table);

public:
    explicit tableView(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // TABLEVIEW_H
