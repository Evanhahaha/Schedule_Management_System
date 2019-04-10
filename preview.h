#ifndef PREVIEW_H
#define PREVIEW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QTextEdit;
QT_END_NAMESPACE

class createPreview : public QWidget
{
    Q_OBJECT

public:
    createPreview(QWidget *parent = 0);
    void setWindowText(const QString text);
    void clearText();

private:

    QTextEdit *textEdit;
};

#endif // PREVIEW_H
