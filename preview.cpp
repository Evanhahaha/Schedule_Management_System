#include "preview.h"
#include <QtWidgets>

createPreview::createPreview(QWidget *parent)
    : QWidget(parent)
{

    textEdit = new QTextEdit();
    textEdit -> setReadOnly(true);
    textEdit -> setWordWrapMode(QTextOption::NoWrap);
    textEdit -> setWindowTitle("No Schedule Matched");

    textEdit -> append("CSC3170 & ENG2002S conflict");


    QPushButton *pushButton = new QPushButton("Quit");
    connect(pushButton, SIGNAL(clicked()), this, SLOT(close()));

    QVBoxLayout *layoutV = new QVBoxLayout();
    layoutV -> addWidget(textEdit);
    layoutV -> addWidget(pushButton);


    setLayout(layoutV);

}

void createPreview::setWindowText(const QString text)
{
    textEdit -> append(text);
}

void createPreview::clearText()
{
    textEdit -> clear();
}
