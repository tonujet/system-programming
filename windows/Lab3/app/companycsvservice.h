#ifndef COMPANYCSVSERVICE_H
#define COMPANYCSVSERVICE_H

#include "csvservice.h"
#include "taxicompany.h"


class CompanyCsvService: CsvService<TaxiCompany>
{
public:
    CompanyCsvService((std::string path);
    std::vector<TaxiCom *> *read();
    void write(std::vector<T *> *cars);

};

#endif // COMPANYCSVSERVICE_H
