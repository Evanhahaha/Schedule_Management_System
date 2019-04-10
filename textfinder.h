#ifndef TEXTFINDER_H
#define TEXTFINDER_H

#include <QWidget>
#include "preview.h"
#include "tableview.h"
#include <array>
using namespace std;

QT_BEGIN_NAMESPACE
class QComboBox;
class QStringList;
class QHBoxLayout;
class QVBoxLayout;
QT_END_NAMESPACE


class TextFinder : public QWidget
{
    Q_OBJECT

public:
   TextFinder(QWidget *parent = 0);

private slots:
   void createComboBoxGroup();
   void cancelComboBoxGroup();
   void findCurrentText();

private:
   QStringList code0 = {"1001", "1002"};
   QStringList code1 = {"2001", "2002"};
   QStringList code2 = {"3001", "3002"};
   QStringList code3 = {"4001", "4002"};

//   QStringList code0 = {"3002", "3050", "3170"};
//   QStringList code1 = {"2403"};
//   QStringList code2 = {"2002S"};
//   QStringList code3 = {"2001"};

   QComboBox *createComboBox();
   QComboBox *createCodeBox();
   createPreview *preView;
   tableView *table;
   QComboBox *typesBox;
   QComboBox *codesBox;
   QVBoxLayout *layoutV;
   QHBoxLayout *layoutH;
   QVBoxLayout *main;

};

#endif // TEXTFINDER_H
