#include "applicationmanager.h"

ApplicationManager::ApplicationManager(MainWindow* mainWindow, BDReportFace* createdTables, QSqlDatabase db_)
{
    db = db_;

    connect(createdTables, &TableTemplate::deleteButtonClicked, this, &ApplicationManager::deleteButtonClicked);
    connect(createdTables, &TableTemplate::addButtonClicked, this, &ApplicationManager::addButtonClicked);
    connect(createdTables, &TableTemplate::searchButtonClicked, this, &ApplicationManager::searchButtonClicked);
    connect(createdTables, &TableTemplate::headerClicked, this, &ApplicationManager::headerClicked);

    connect(createdTables, &BDReportFace::applyFiltersClicked1, this, &ApplicationManager::applyFilters1);
    connect(createdTables, &BDReportFace::discardFiltersClicked, this, &ApplicationManager::discardFilters);

    QWidget* centralWidget = new QWidget();
    mainTabWidget = new QTabWidget(centralWidget);
    QWidget* tablesPage = new QWidget(centralWidget);
    QWidget* reportsPage = new QWidget(centralWidget);

    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
    QHBoxLayout *tablesPageLayout = new QHBoxLayout(tablesPage);
    QHBoxLayout *reportsPageLayout = new QHBoxLayout(reportsPage);

    tablesTabWidget = new QTabWidget(tablesPage);
    componentsPage = new QWidget(tablesPage);
    materialsPage = new QWidget(tablesPage);
    product_componentsPage = new QWidget(tablesPage);
    productsPage = new QWidget(tablesPage);
    tech_operationsPage = new QWidget(tablesPage);
    tech_processesPage = new QWidget(tablesPage);


    QHBoxLayout* componentsPageLayout = new QHBoxLayout(componentsPage);
    QHBoxLayout* materialsPageLayout = new QHBoxLayout(materialsPage);
    QHBoxLayout* product_componentsPageLayout = new QHBoxLayout(product_componentsPage);
    QHBoxLayout* productsPageLayout = new QHBoxLayout(productsPage);
    QHBoxLayout* tech_operationsPageLayout = new QHBoxLayout(tech_operationsPage);
    QHBoxLayout* tech_processesPageLayout = new QHBoxLayout(tech_processesPage);


    mainTabWidget->addTab(tablesPage, "Таблицы");
    tablesPageLayout->addWidget(tablesTabWidget);

    tablesTabWidget->addTab(componentsPage, "Комплектующие");
    tablesTabWidget->addTab(materialsPage, "Материалы");
    tablesTabWidget->addTab(product_componentsPage, "Комплектующие изделия");
    tablesTabWidget->addTab(productsPage, "Изделия");
    tablesTabWidget->addTab(tech_operationsPage, "Справочник технологических операций");
    tablesTabWidget->addTab(tech_processesPage, "Техпроцесс");

    QSqlQuery queryForComponents("SELECT * FROM components");
    components.UpdateInfo(queryForComponents);
    componentsPageLayout->addWidget(components.GetWidget());

    QSqlQuery queryForMaterials("SELECT * FROM materials");
    materials.UpdateInfo(queryForMaterials);
    materialsPageLayout->addWidget(materials.GetWidget());

    QSqlQuery queryForProduct_components("SELECT * FROM product_components");
    product_components.UpdateInfo(queryForProduct_components);
    product_componentsPageLayout->addWidget(product_components.GetWidget());

    QSqlQuery queryForProducts("SELECT * FROM products");
    products.UpdateInfo(queryForProducts);
    productsPageLayout->addWidget(products.GetWidget());

    QSqlQuery queryForTech_operations("SELECT * FROM tech_operations");
    tech_operations.UpdateInfo(queryForTech_operations);
    tech_operationsPageLayout->addWidget(tech_operations.GetWidget());

    QSqlQuery queryForTech_processes("SELECT * FROM tech_processes");
    tech_processes.UpdateInfo(queryForTech_processes);
    tech_processesPageLayout->addWidget(tech_processes.GetWidget());


    reportsTabWidget = new QTabWidget(reportsPage);
    reportPage1 = new QWidget(centralWidget);
    reportPage2 = new QWidget(centralWidget);
    reportPage3 = new QWidget(centralWidget);

    mainTabWidget->addTab(reportsPage, "Отчеты");
    reportsPageLayout->addWidget(reportsTabWidget);

    // Компановки
    QHBoxLayout *reportLayout1 = new QHBoxLayout(reportPage1);
    QHBoxLayout *reportLayout2 = new QHBoxLayout(reportPage2);
    QHBoxLayout *reportLayout3 = new QHBoxLayout(reportPage3);

    // Первый отчет
    reportsTabWidget->addTab(reportPage1, "Расчет себестоимости изделий");
    reportLayout1->addWidget(createdTables->GetTableWidget1());


    // Второй отчет
    reportsTabWidget->addTab(reportPage2, "Техпроцесс изделий");
    reportLayout2->addWidget(createdTables->GetTableWidget2());


    // Третий отчет
    reportsTabWidget->addTab(reportPage3, "Расчет прибыли от реализации");
    reportLayout3->addWidget(createdTables->GetTableWidget3());



    mainLayout->addWidget(mainTabWidget);
    mainWindow->setCentralWidget(centralWidget);

}

void ApplicationManager::deleteButtonClicked(int lineIndex)
{
    QString str = DeleteQuery(mainTabWidget->currentIndex(), tablesTabWidget->currentIndex(), reportsTabWidget->currentIndex(), lineIndex);
    QSqlQuery deletequery(str);
    UpdateTable(mainTabWidget->currentIndex(), tablesTabWidget->currentIndex(), reportsTabWidget->currentIndex(), -1, lineIndex, deletequery);
}

void ApplicationManager::addButtonClicked()
{
    QString str = AddQuery(mainTabWidget->currentIndex(), tablesTabWidget->currentIndex(), reportsTabWidget->currentIndex());
    QSqlQuery addquery(str);
    UpdateTable(mainTabWidget->currentIndex(), tablesTabWidget->currentIndex(), reportsTabWidget->currentIndex(), -1, -1, addquery);
}

void ApplicationManager::searchButtonClicked(QString& search)
{
    QString str = SearchQuery(mainTabWidget->currentIndex(), tablesTabWidget->currentIndex(), reportsTabWidget->currentIndex(), search);
    QSqlQuery searchquery(str);
    UpdateTable(mainTabWidget->currentIndex(), tablesTabWidget->currentIndex(), reportsTabWidget->currentIndex(), -1, -1, searchquery);
}

void ApplicationManager::headerClicked(int columnIndex)
{
    QString str = SortQuery(mainTabWidget->currentIndex(), tablesTabWidget->currentIndex(), reportsTabWidget->currentIndex(), columnIndex);
    QSqlQuery searchquery(str);
    UpdateTable(mainTabWidget->currentIndex(), tablesTabWidget->currentIndex(), reportsTabWidget->currentIndex(), columnIndex, -1, searchquery);
}



void ApplicationManager::applyFilters1(int minLeft, int maxLeft, int minRight, int maxRight)
{
    LeftFilter(reportsTabWidget->currentIndex(), minLeft, maxLeft, minRight, maxRight);
    RightFilter(reportsTabWidget->currentIndex(), minLeft, maxLeft, minRight, maxRight);
}

void ApplicationManager::discardFilters()
{

}
