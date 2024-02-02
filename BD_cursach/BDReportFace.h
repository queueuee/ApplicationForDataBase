#ifndef BDREPORTFACE_H
#define BDREPORTFACE_H

#include "initReport.h"
#include "TableTemplate.h"

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpacerItem>
#include <QHeaderView>
#include <QGroupBox>
#include <QRadioButton>
#include <QButtonGroup>
#include <QMessageBox>
#include <QObject>
#include <QtSql>

#include <QDebug>
#include <QPushButton>

class BDReportFace: public QObject
{
    Q_OBJECT
private:
    QWidget *tableWidget1;
    QWidget *tableWidget2;
    QWidget *tableWidget3;

    QTableWidget* tableLeft;
    QTableWidget* GetTableLeft() {return tableLeft;}

    QLineEdit *maxLeftPriceLineEdit;
    QLineEdit *minLeftPriceLineEdit;
    QLineEdit *minRightPriceLineEdit;
    QLineEdit *maxRightPriceLineEdit;
    QLineEdit *maxPriceLineEdit;
    QLineEdit *minPriceLineEdit;


    void CreateReport1(initReport);
    void CreateReport2(initReport);
    void CreateReport3(initReport);


    void onApplyFiltersClicked1();
    void onApplyFiltersClicked2();
    void onApplyFiltersClicked3();
public:
    BDReportFace(initReport report1, initReport report2, initReport report3)
    {
        tableWidget1 = new QWidget();
        tableWidget2 = new QWidget();
        tableWidget3 = new QWidget();
        CreateReport1(report1);
        CreateReport2(report2);
        CreateReport3(report3);
    }
    QWidget* GetTableWidget1() {return tableWidget1;}
    QWidget* GetTableWidget2() {return tableWidget2;}
    QWidget* GetTableWidget3() {return tableWidget3;}
signals:
    void applyFiltersClicked1(int minLeft, int maxLeft, int minRight, int maxRight);
    void discardFiltersClicked();
};

#endif // BDREPORTFACE_H
