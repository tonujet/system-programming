#ifndef OWNERCSVSERVICE_H
#define OWNERCSVSERVICE_H

#include "csvservice.h"
#include "owner.h"

class OwnerCsvService: CsvService<Owner>
{
public:
    OwnerCsvService(std::string path);
    std::vector<Owner> read() override;
    void write(std::vector<Owner *> *cars) override;
};

#endif // OWNERCSVSERVICE_H
