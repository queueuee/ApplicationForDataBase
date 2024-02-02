#include "BDReportFace.h"

void BDReportFace::CreateReport1(initReport report)
{
    QSqlQuery firstQuery(report.queries.first);
    QSqlQuery secondQuery(report.queries.second);

    QHBoxLayout* mainLayout = new QHBoxLayout(tableWidget1);


    // Создание левой таблицы
    QWidget* leftTableWidget = new QWidget();
    QVBoxLayout* leftTableLayout = new QVBoxLayout(leftTableWidget);

    TableTemplate leftTable(report.tableNames.first, report.headerNames.first, firstQuery);

    // Суммарная себестоимость
    QSqlQuery summPriceQuery("SELECT sum(total_cost) FROM products_costs");
    QWidget* summPriceLeftWidget = new QWidget();
    QHBoxLayout* summPriceLeftLayout = new QHBoxLayout(summPriceLeftWidget);
    QLabel* summPriceLeftLabel = new QLabel("Суммарная себестоимость всех изделий");
    QSpacerItem *summPriceLeftSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QLineEdit *summPriceLeftLineEdit = new QLineEdit();
    summPriceLeftLineEdit->setReadOnly(true);
    summPriceLeftLineEdit->setText(summPriceQuery.value(1).toString());

    summPriceLeftLayout->addWidget(summPriceLeftLabel);
    summPriceLeftLayout->addSpacerItem(summPriceLeftSpacer);
    summPriceLeftLayout->addWidget(summPriceLeftLineEdit);


    leftTableLayout->addWidget(leftTable.GetWidget());
    leftTableLayout->addWidget(summPriceLeftWidget);

    QSpacerItem *horizontalSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QSpacerItem *verticalSpacer1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);


    // Создание правой таблицы
    QWidget* rightTableWidget = new QWidget();
    QVBoxLayout* rightTableLayout = new QVBoxLayout(rightTableWidget);

    TableTemplate rightTable(report.tableNames.second, report.headerNames.second, secondQuery);

    rightTableLayout->addWidget(rightTable.GetWidget());


    // Фильтры
    QLabel *filtersLabel = new QLabel();
    filtersLabel->setText("Фильтры");
    QWidget* filtersWidget = new QWidget();
    QVBoxLayout* filtersLayout = new QVBoxLayout(filtersWidget);

    // Левая таблица
    QGroupBox *leftTableGroupBox = new QGroupBox();
    QVBoxLayout* leftTableGroupBoxLayout = new QVBoxLayout(leftTableGroupBox);
    leftTableGroupBox->setTitle(report.tableNames.first);
    QWidget* minLeftWidget = new QWidget();
    QHBoxLayout *minLeftLayout = new QHBoxLayout(minLeftWidget);
    QLabel *minLeftPriceLabel = new QLabel();
    minLeftPriceLabel->setText("Мин. себестоимость ");
    QLineEdit *minLeftPriceLineEdit = new QLineEdit(minLeftWidget);
    minLeftPriceLineEdit->setPlaceholderText("min");
    QWidget* maxLeftWidget = new QWidget();
    QHBoxLayout *maxLeftLayout = new QHBoxLayout(maxLeftWidget);
    QLabel *maxLeftPriceLabel = new QLabel();
    maxLeftPriceLabel->setText("Макс. себестоимость ");
    QLineEdit *maxLeftPriceLineEdit = new QLineEdit(maxLeftWidget);
    maxLeftPriceLineEdit->setPlaceholderText("max");


    minLeftLayout->addWidget(minLeftPriceLabel);
    minLeftLayout->addWidget(minLeftPriceLineEdit);
    maxLeftLayout->addWidget(maxLeftPriceLabel);
    maxLeftLayout->addWidget(maxLeftPriceLineEdit);

    leftTableGroupBoxLayout->addWidget(minLeftWidget);
    leftTableGroupBoxLayout->addWidget(maxLeftWidget);


    // Правая таблица
    QGroupBox *rightTableGroupBox = new QGroupBox();
    QVBoxLayout* rightTableGroupBoxLayout = new QVBoxLayout(rightTableGroupBox);
    rightTableGroupBox->setTitle(report.tableNames.second);
    QWidget* minRightWidget = new QWidget();
    QHBoxLayout *minRightLayout = new QHBoxLayout(minRightWidget);
    QLabel *minRightPriceLabel = new QLabel();
    minRightPriceLabel->setText("Мин. себестоимость ");
    minRightPriceLineEdit = new QLineEdit(minRightWidget);
    minRightPriceLineEdit->setPlaceholderText("min");
    QWidget* maxRightWidget = new QWidget();
    QHBoxLayout *maxRightLayout = new QHBoxLayout(maxRightWidget);
    QLabel *maxRightPriceLabel = new QLabel();
    maxRightPriceLabel->setText("Макс. себестоимость ");
    maxRightPriceLineEdit = new QLineEdit(maxRightWidget);
    maxRightPriceLineEdit->setPlaceholderText("max");

    minRightLayout->addWidget(minRightPriceLabel);
    minRightLayout->addWidget(minRightPriceLineEdit);
    maxRightLayout->addWidget(maxRightPriceLabel);
    maxRightLayout->addWidget(maxRightPriceLineEdit);

    rightTableGroupBoxLayout->addWidget(minRightWidget);
    rightTableGroupBoxLayout->addWidget(maxRightWidget);

    // Применить/сбросить фильтры
    QPushButton* confirmFiltersButton = new QPushButton("Применить");
    QPushButton* discardFiltersButton = new QPushButton("Сбросить");
    connect(confirmFiltersButton, &QPushButton::clicked, this, &BDReportFace::onApplyFiltersClicked1);
    connect(discardFiltersButton, &QPushButton::clicked, this, &BDReportFace::onDiscardFiltersClicked);

    filtersLayout->addWidget(filtersLabel);
    filtersLayout->addWidget(leftTableGroupBox);
    filtersLayout->addWidget(rightTableGroupBox);
    filtersLayout->addSpacerItem(verticalSpacer1);
    filtersLayout->addWidget(confirmFiltersButton);
    filtersLayout->addWidget(discardFiltersButton);

    mainLayout->addWidget(leftTableWidget);
    mainLayout->addSpacerItem(horizontalSpacer1);
    mainLayout->addWidget(rightTableWidget);
    mainLayout->addWidget(filtersWidget);
}


void BDReportFace::CreateReport2(initReport report)
{
    QSqlQuery firstQuery(report.queries.first);
    QSqlQuery secondQuery(report.queries.second);

    QHBoxLayout* mainLayout = new QHBoxLayout(tableWidget2);


    // Создание левой таблицы
    QWidget* leftTableWidget = new QWidget();
    QVBoxLayout* leftTableLayout = new QVBoxLayout(leftTableWidget);

    TableTemplate leftTable(report.tableNames.first, report.headerNames.first, firstQuery);

    leftTableLayout->addWidget(leftTable.GetWidget());

    QSpacerItem *horizontalSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QSpacerItem *verticalSpacer1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);


    // Создание правой таблицы
    QWidget* rightTableWidget = new QWidget();
    QVBoxLayout* rightTableLayout = new QVBoxLayout(rightTableWidget);

    TableTemplate rightTable(report.tableNames.second, report.headerNames.second, secondQuery);

    rightTableLayout->addWidget(rightTable.GetWidget());


    // Фильтры
    QLabel *filtersLabel = new QLabel();
    filtersLabel->setText("Фильтры");
    QWidget* filtersWidget = new QWidget();
    QVBoxLayout* filtersLayout = new QVBoxLayout(filtersWidget);

    // Левая таблица
    QGroupBox *leftTableGroupBox = new QGroupBox();
    QVBoxLayout* leftTableGroupBoxLayout = new QVBoxLayout(leftTableGroupBox);
    leftTableGroupBox->setTitle(report.tableNames.first);
    QWidget* minLeftWidget = new QWidget();
    QHBoxLayout *minLeftLayout = new QHBoxLayout(minLeftWidget);
    QLabel *minLeftPriceLabel = new QLabel();
    minLeftPriceLabel->setText("Мин. код ");
    QLineEdit *minLeftPriceLineEdit = new QLineEdit(minLeftWidget);
    minLeftPriceLineEdit->setPlaceholderText("min");
    QWidget* maxLeftWidget = new QWidget();
    QHBoxLayout *maxLeftLayout = new QHBoxLayout(maxLeftWidget);
    QLabel *maxLeftPriceLabel = new QLabel();
    maxLeftPriceLabel->setText("Макс. код ");
    QLineEdit *maxLeftPriceLineEdit = new QLineEdit(maxLeftWidget);
    maxLeftPriceLineEdit->setPlaceholderText("max");


    minLeftLayout->addWidget(minLeftPriceLabel);
    minLeftLayout->addWidget(minLeftPriceLineEdit);
    maxLeftLayout->addWidget(maxLeftPriceLabel);
    maxLeftLayout->addWidget(maxLeftPriceLineEdit);

    leftTableGroupBoxLayout->addWidget(minLeftWidget);
    leftTableGroupBoxLayout->addWidget(maxLeftWidget);


    // Правая таблица
    QGroupBox *rightTableGroupBox = new QGroupBox();
    QVBoxLayout* rightTableGroupBoxLayout = new QVBoxLayout(rightTableGroupBox);
    rightTableGroupBox->setTitle(report.tableNames.second);
    QWidget* minRightWidget = new QWidget();
    QHBoxLayout *minRightLayout = new QHBoxLayout(minRightWidget);
    QLabel *minRightPriceLabel = new QLabel();
    minRightPriceLabel->setText("Мин. кол-во материалов ");
    QLineEdit *minRightPriceLineEdit = new QLineEdit(minRightWidget);
    minRightPriceLineEdit->setPlaceholderText("min");
    QWidget* maxRightWidget = new QWidget();
    QHBoxLayout *maxRightLayout = new QHBoxLayout(maxRightWidget);
    QLabel *maxRightPriceLabel = new QLabel();
    maxRightPriceLabel->setText("Макс. кол-во материалов ");
    QLineEdit *maxRightPriceLineEdit = new QLineEdit(maxRightWidget);
    maxRightPriceLineEdit->setPlaceholderText("max");

    minRightLayout->addWidget(minRightPriceLabel);
    minRightLayout->addWidget(minRightPriceLineEdit);
    maxRightLayout->addWidget(maxRightPriceLabel);
    maxRightLayout->addWidget(maxRightPriceLineEdit);

    rightTableGroupBoxLayout->addWidget(minRightWidget);
    rightTableGroupBoxLayout->addWidget(maxRightWidget);

    // Применить/сбросить фильтры
    QPushButton* confirmFiltersButton = new QPushButton("Применить");
    QPushButton* discardFiltersButton = new QPushButton("Сбросить");
    connect(confirmFiltersButton, &QPushButton::clicked, this, &BDReportFace::onApplyFiltersClicked1);
    connect(discardFiltersButton, &QPushButton::clicked, this, &BDReportFace::onDiscardFiltersClicked);



    filtersLayout->addWidget(filtersLabel);
    filtersLayout->addWidget(leftTableGroupBox);
    filtersLayout->addWidget(rightTableGroupBox);
    filtersLayout->addSpacerItem(verticalSpacer1);
    filtersLayout->addWidget(confirmFiltersButton);
    filtersLayout->addWidget(discardFiltersButton);

    mainLayout->addWidget(leftTableWidget);
    mainLayout->addSpacerItem(horizontalSpacer1);
    mainLayout->addWidget(rightTableWidget);
    mainLayout->addWidget(filtersWidget);
}


void BDReportFace::CreateReport3(initReport report)
{
    QSqlQuery firstQuery(report.queries.first);
    QSqlQuery secondQuery(report.queries.second);

    QHBoxLayout* mainLayout = new QHBoxLayout(tableWidget3);


    // Создание левой таблицы
    QWidget* leftTableWidget = new QWidget();
    QVBoxLayout* leftTableLayout = new QVBoxLayout(leftTableWidget);

    TableTemplate leftTable(report.tableNames.first, report.headerNames.first, firstQuery);

    leftTableLayout->addWidget(leftTable.GetWidget());

    QSpacerItem *horizontalSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QSpacerItem *verticalSpacer1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);


    // Создание правой таблицы
    QWidget* rightTableWidget = new QWidget();
    QVBoxLayout* rightTableLayout = new QVBoxLayout(rightTableWidget);

    TableTemplate rightTable(report.tableNames.second, report.headerNames.second, secondQuery);

    rightTableLayout->addWidget(rightTable.GetWidget());


    // Фильтры
    QLabel *filtersLabel = new QLabel();
    filtersLabel->setText("Фильтры");
    QWidget* filtersWidget = new QWidget();
    QVBoxLayout* filtersLayout = new QVBoxLayout(filtersWidget);

    // Левая таблица
    QGroupBox *leftTableGroupBox = new QGroupBox();
    QVBoxLayout* leftTableGroupBoxLayout = new QVBoxLayout(leftTableGroupBox);
    leftTableGroupBox->setTitle(report.tableNames.first);
    QWidget* minLeftWidget = new QWidget();
    QHBoxLayout *minLeftLayout = new QHBoxLayout(minLeftWidget);
    QLabel *minLeftPriceLabel = new QLabel();
    minLeftPriceLabel->setText("Мин. цена ");
    minLeftPriceLineEdit = new QLineEdit(minLeftWidget);
    minLeftPriceLineEdit->setPlaceholderText("min");
    QWidget* maxLeftWidget = new QWidget();
    QHBoxLayout *maxLeftLayout = new QHBoxLayout(maxLeftWidget);
    QLabel *maxLeftPriceLabel = new QLabel();
    maxLeftPriceLabel->setText("Макс. цена ");
    maxLeftPriceLineEdit = new QLineEdit(maxLeftWidget);
    maxLeftPriceLineEdit->setPlaceholderText("max");

    QWidget* minWidget = new QWidget();
    QHBoxLayout *minLayout = new QHBoxLayout(minWidget);
    QLabel *minPriceLabel = new QLabel();
    minPriceLabel->setText("Мин. прибыль ");
    minPriceLineEdit = new QLineEdit(minWidget);
    minPriceLineEdit->setPlaceholderText("min");
    QWidget* maxWidget = new QWidget();
    QHBoxLayout *maxLayout = new QHBoxLayout(maxWidget);
    QLabel *maxPriceLabel = new QLabel();
    maxPriceLabel->setText("Макс. прибыль ");
    maxPriceLineEdit = new QLineEdit(maxWidget);
    maxPriceLineEdit->setPlaceholderText("max");

    minLeftLayout->addWidget(minLeftPriceLabel);
    minLeftLayout->addWidget(minLeftPriceLineEdit);
    maxLeftLayout->addWidget(maxLeftPriceLabel);
    maxLeftLayout->addWidget(maxLeftPriceLineEdit);
    minLayout->addWidget(minPriceLabel);
    minLayout->addWidget(minPriceLineEdit);
    maxLayout->addWidget(maxPriceLabel);
    maxLayout->addWidget(maxPriceLineEdit);

    leftTableGroupBoxLayout->addWidget(minLeftWidget);
    leftTableGroupBoxLayout->addWidget(maxLeftWidget);
    leftTableGroupBoxLayout->addWidget(minWidget);
    leftTableGroupBoxLayout->addWidget(maxWidget);


    // Применить/сбросить фильтры
    QPushButton* confirmFiltersButton = new QPushButton("Применить");
    QPushButton* discardFiltersButton = new QPushButton("Сбросить");
    connect(confirmFiltersButton, &QPushButton::clicked, this, &BDReportFace::onApplyFiltersClicked1);
    connect(discardFiltersButton, &QPushButton::clicked, this, &BDReportFace::onDiscardFiltersClicked);


    filtersLayout->addWidget(filtersLabel);
    filtersLayout->addWidget(leftTableGroupBox);
    filtersLayout->addSpacerItem(verticalSpacer1);
    filtersLayout->addWidget(confirmFiltersButton);
    filtersLayout->addWidget(discardFiltersButton);

    mainLayout->addWidget(leftTableWidget);
    mainLayout->addSpacerItem(horizontalSpacer1);
    mainLayout->addWidget(rightTableWidget);
    mainLayout->addWidget(filtersWidget);
}

void BDReportFace::onApplyFiltersClicked1()
{
    int minLeft = minLeftPriceLineEdit->text().toInt();
    int maxLeft = maxLeftPriceLineEdit->text().toInt();
    int minRight = minPriceLineEdit->text().toInt();
    int maxRight = maxPriceLineEdit->text().toInt();

    emit applyFiltersClicked1(minLeft, maxLeft, minRight, maxRight);
}
