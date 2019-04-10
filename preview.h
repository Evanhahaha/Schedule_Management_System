#ifndef PREVIEW_H
#define PREVIEW_H

#include <QObject>
#include <QWidget>

class preView : public QWidget
{
    Q_OBJECT
public:
    explicit preView(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // PREVIEW_H