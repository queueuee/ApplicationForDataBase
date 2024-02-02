#include "TableTemplate.h"

TableTemplate::TableTemplate(QString& tableName, std::vector<QString>& column_names)
{
    const int MIN_WIDTH_TABLE = 550;
    const int MIN_HEIGHT_TABLE = 400;

    // Создание левой таблицы
    tableWidget = new QWidget();
    QVBoxLayout* leftTableLayout = new QVBoxLayout(tableWidget);
    table= new QTableWidget();
    QLabel* tableLeftLabel = new QLabel();

    // Название таблицы
    tableLeftLabel->setText(tableName);

    // Кол-во столбцов и их названия
    table->setColumnCount(column_names.size());
    QStringList headerLabels;
    for (const QString& header : column_names) {
        headerLabels << header;
    }

    // Устанавливаем названия заголовков в таблицу
    table->setHorizontalHeaderLabels(headerLabels);
    // Настройки таблицы
    table->setMinimumWidth(MIN_WIDTH_TABLE);
    table->setMinimumHeight(MIN_HEIGHT_TABLE);
    table->verticalHeader()->hide();
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->resizeColumnsToContents();
    table->resizeRowsToContents();
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(table->horizontalHeader(), &QHeaderView::sectionClicked, [this](int index) {
        emit headerClicked(index);
    });

    // Строка поиска
    QWidget* searchWidget = new QWidget();
    QHBoxLayout* searchLayout = new QHBoxLayout(searchWidget);
    QLineEdit *searchLineEdit = new QLineEdit(tableWidget);
    searchLineEdit->setPlaceholderText("Поиск...");
    // Кнопка поиска
    QPushButton* searchButton = new QPushButton();
    connect(searchButton, &QPushButton::clicked, [this, searchLineEdit](){
        QString a = searchLineEdit->text();
        emit searchButtonClicked(a);
    });
    searchButton->setText("Найти");
    searchLayout->addWidget(searchLineEdit);
    searchLayout->addWidget(searchButton);

    N = column_names.size();

    // Кнопки
    QWidget* buttonLeftHolderWidget = new QWidget();
    QHBoxLayout* buttonLeftLayout = new QHBoxLayout(buttonLeftHolderWidget);
    QPushButton* deleteButton = new QPushButton("Удалить");
    QPushButton* addButton = new QPushButton("Добавить");
    connect(deleteButton, &QPushButton::clicked, [this](){
        emit deleteButtonClicked(table->currentColumn());
    });
    connect(addButton, &QPushButton::clicked, this, &TableTemplate::addButtonClicked);
    buttonLeftLayout->addWidget(deleteButton);
    buttonLeftLayout->addWidget(addButton);


    leftTableLayout->addWidget(searchWidget);
    leftTableLayout->addWidget(tableLeftLabel);
    leftTableLayout->addWidget(table);
    leftTableLayout->addWidget(buttonLeftHolderWidget);
}

void TableTemplate::UpdateInfo(QSqlQuery& query)
{
    int row = 0;
    while (query.next())
    {
        table->insertRow(row);
        for (int col = 0; col < N; ++col) {
            table->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
        ++row;
    }
}
