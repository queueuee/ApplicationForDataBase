#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H


#include "mainwindow.h"
#include "BDReportFace.h"
#include "TableTemplate.h"
#include "Functions.cpp"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QTabWidget>
#include <QWidget>
#include <QObject>
#include <QLabel>

#include <QtSql>

class ApplicationManager : QObject
{
    Q_OBJECT
private:
    std::vector<std::pair<QString, std::vector<QString>>> tableHeaders = {
        {"Components",{"Код", "Название", "Цена", "Номер техпроцесса"}},
        {"Materials",{"Код", "Название", "Цена"}},
        {"Product_components",{"Код продукта", "Код компонента", "Количество"}},
        {"Products",{"Код", "Название", "Цена"}},
        {"Tech_operations",{"Номер операции", "Стандартные часы", "Цена за стандартный час"}},
        {"Tech_processes",{"Номер техпроцесса", "Код компонента", "Код материала", "Код операции", "Количество материала"}},
};
    QSqlDatabase db;
    QSqlQuery query;
    QString search_line;

    QTabWidget* mainTabWidget;
    QTabWidget* tablesTabWidget;
    QTabWidget* reportsTabWidget;

    QWidget* componentsPage;
    TableTemplate components(tableHeaders[0].first, tableHeaders[0].second);
    QWidget* materialsPage;
    TableTemplate materials(tableHeaders[1].first, tableHeaders[1].second);
    QWidget* product_componentsPage;
    TableTemplate product_components(tableHeaders[2].first, tableHeaders[2].second);
    QWidget* productsPage;
    TableTemplate products(tableHeaders[3].first, tableHeaders[3].second);
    QWidget* tech_operationsPage;
    TableTemplate tech_operations(tableHeaders[4].first, tableHeaders[4].second);
    QWidget* tech_processesPage;
    TableTemplate tech_processes(tableHeaders[5].first, tableHeaders[5].second);

    QWidget *reportPage1;
    QWidget *reportPage2;
    QWidget *reportPage3;
public:
    ApplicationManager(MainWindow*, BDReportFace*, QSqlDatabase);
private slots:
    void deleteButtonClicked(int lineIndex);
    void addButtonClicked();
    void searchButtonClicked(QString& search);
    void headerClicked(int columnIndex);

    void applyFilters1(int minLeft, int maxLeft, int minRight, int maxRight);
    void discardFilters();
};

#endif // APPLICATIONMANAGER_H
