#ifndef TABLETEMPLATE_H
#define TABLETEMPLATE_H

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

class TableTemplate : public QObject
{
    Q_OBJECT
private:
    QWidget* tableWidget;
    QTableWidget* table;
    int N;
public:
    TableTemplate(QString&, std::vector<QString>&);
    QWidget* GetWidget() {return tableWidget;}
    void UpdateInfo(QSqlQuery&);
signals:
    void deleteButtonClicked(int lineIndex);
    void addButtonClicked();
    void searchButtonClicked(QString& search);
    void headerClicked(int columnIndex);
};

#endif // TABLETEMPLATE_H
