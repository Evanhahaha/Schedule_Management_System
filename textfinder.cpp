#include "textfinder.h"
#include "preview.h"
#include "tableview.h"
#include <QtWidgets>
#include <iostream>
#include <array>

using namespace std;
TextFinder::TextFinder(QWidget *parent)
    : QWidget(parent)
{
    preView = new createPreview();
    table = new tableView();

    QGroupBox *group = new QGroupBox(tr("Requirements:"));

    layoutV = new QVBoxLayout;
    TextFinder::createComboBoxGroup();

    QRadioButton *rbutton1 = new QRadioButton("No class at 8:30", this);
    QRadioButton *rbutton2 = new QRadioButton("No class at 13:00/13:30", this);
    QRadioButton *rbutton3 = new QRadioButton("Interval Between any two classes more than 10mins", this);
    QPushButton *btn_minu = new QPushButton("-");
    QPushButton *btn_plus = new QPushButton("+");
    QPushButton *button = new QPushButton("Confirm");

    QButtonGroup *btnGroup = new QButtonGroup();
    btnGroup->addButton(rbutton1);
    btnGroup->addButton(rbutton2);
    btnGroup->addButton(rbutton3);
    btnGroup->setExclusive(false);

    QGridLayout *layoutB = new QGridLayout;
    layoutB->addWidget(rbutton1,0,0);
    layoutB->addWidget(rbutton2,0,1);
    layoutB->addWidget(rbutton3,1,0);
    group->setLayout(layoutB);

    QHBoxLayout *mpLayout = new QHBoxLayout;
    mpLayout->addWidget(btn_plus);
    mpLayout->addWidget(btn_minu);

    QVBoxLayout *main = new QVBoxLayout;
    main->addLayout(layoutV);
    main->addLayout(mpLayout);
    main->addWidget(group);
    main->addStretch();
    main->addWidget(button);
    main->setSpacing(10);

    connect(btn_plus, SIGNAL(clicked()), this, SLOT(createComboBoxGroup()));
    connect(btn_minu, SIGNAL(clicked()), this, SLOT(cancelComboBoxGroup()));
    connect(button, SIGNAL(clicked()), this, SLOT(findCurrentText()));
    //connect(button, &QPushButton::clicked, preView, &createPreview::show);
    connect(button, SIGNAL(clicked()), table, SLOT(show()));

    setWindowTitle(tr("smallTest"));
    setLayout(main);

}

void TextFinder::createComboBoxGroup()
{
    QComboBox *cBox = new QComboBox();
    QComboBox *tBox = createComboBox();
    //connect(tBox, SIGNAL(currentIndexChanged(int)), this, SLOT(infoOnChanged()));
    connect(tBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
        [=](int index){

        cBox -> clear();
        switch(index)
        {
            case 0:
                cBox -> addItems(code0);
            break;
            case 1:
                cBox -> addItems(code1);
            break;
            case 2:
                cBox -> addItems(code2);
            break;
            case 3:
                cBox -> addItems(code3);
            break;
        default:
            break;
        }

        //QString text = tBox->currentText() + cBox->currentText();
        //preView -> setWindowText(text);
    });

    QHBoxLayout *layoutTest = new QHBoxLayout();
    layoutTest -> addWidget(tBox);
    layoutTest -> addWidget(cBox);


    layoutV -> addLayout(layoutTest);
}

void TextFinder::findCurrentText()
{
    //preView -> clearText();

    int count = layoutV->count();
    for (int i = 0; i < count; i++) {
        QLayout *tlayout = layoutV->itemAt(i)->layout();

        QString text = static_cast<QComboBox*> (tlayout->itemAt(0)->widget()) -> currentText();
        text = text + static_cast<QComboBox*> (tlayout->itemAt(1)->widget()) -> currentText();

        preView -> setWindowText(text);
    }

    preView -> show();
}

QComboBox *TextFinder::createComboBox()
{
    QComboBox *comboBox = new QComboBox();

    comboBox->addItems({ "csc", "sta", "mat", "eng"});
//    comboBox->addItems({ "CSC", "GEB", "ENG", "BIO"});
    comboBox->setCurrentIndex(-1);

    //connect(comboBox, SIGNAL(currentIndexChanged(int)), this, [this](QComboBox *comboBox){infoOnChanged(comboBox);});
    //connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(infoOnChanged()));

    return comboBox;
}

void TextFinder::cancelComboBoxGroup()
{
    int num = (layoutV->count())-1;
    if (num == 0) {
        return;
    }

    QLayout *tlayout = layoutV->itemAt(num)->layout();
    int wid_num = tlayout->count();
    for (int i = 0; i < wid_num; i++)
    {
        tlayout->itemAt(i)->widget()->setVisible(false);
    }

    QLayoutItem *child = layoutV->itemAt(num);
    delete child->layout();

    resize(sizeHint());

}

/*
void TextFinder::infoOnChanged()
{


    codesBox -> clear();
    switch(typesBox->currentIndex())
    {
        case 0:
            codesBox -> addItems(code0);
        break;
        case 1:
            codesBox -> addItems(code1);
        break;
        case 2:
            codesBox -> addItems(code2);
        break;
        case 3:
            codesBox -> addItems(code3);
        break;
    }

    QString text = typesBox->currentText() + codesBox->currentText();
    preView -> setWindowText(text);
}
*/
