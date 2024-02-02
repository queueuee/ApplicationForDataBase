#include "applicationmanager.h"

#include <QApplication>
#include <QDebug>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("furniture");
    db.setUserName("postgres");
    db.setPassword("515457");

    if (!db.open()) {
        qDebug() << "Не удалось установить соединение с базой данных.";
        qDebug() << db.lastError().text();
        return 1;
    }

    initReport firstReport, secondReport, thirdReport;
    firstReport.tableNames = {"Изделия", "Компоненты"};
    firstReport.headerNames = {{"Код", "Название", "Себестоимость"},
                               {"Код", "Название", "Себестоимость"}};
    firstReport.queries = {"SELECT * FROM report_1_left where product_code = 3",
                           "SELECT component_code, component_name, total_comp_price FROM report_1_right WHERE product_code = 3"};

    secondReport.tableNames = {"Изделия", "Полный техпроцесс"};
    secondReport.headerNames = {{"Код", "Название"},
                                {"Номер операции", "Компонент", "Материал", "Количество материала"}};
    secondReport.queries = {"SELECT * FROM report_2_left",
                            "SELECT * FROM report_2_right WHERE product_code = 1"};

    thirdReport.tableNames = {"Изделия", "Сводка по цене"};
    thirdReport.headerNames = {{"Код", "Название", "Прибыль"},
                                {"Цена изделия", "Себестоимость", "Прибыль"}};
    thirdReport.queries = {"SELECT * FROM report_3_left",
                            "SELECT * FROM report_3_right WHERE product_code = 1"};

    MainWindow w;
    BDReportFace dezignedTables(firstReport, secondReport, thirdReport);
    ApplicationManager app(&w, &dezignedTables, db);


    w.show();

    db.close();

    return a.exec();
}


