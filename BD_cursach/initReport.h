#ifndef INITREPORT_H
#define INITREPORT_H

#include<QString>

struct initReport
{
    std::pair<QString, QString> tableNames;
    std::pair<std::vector<QString>, std::vector<QString>> headerNames;
    std::pair<QString, QString> queries;
};

#endif // INITREPORT_H
