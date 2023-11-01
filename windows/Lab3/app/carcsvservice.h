#ifndef CARCSVSERVICE_H
#define CARCSVSERVICE_H

#include <string>
#include <vector>
#include "car.h"
#include "csvservice.h"

class CarCsvService: public CsvService<Car>
{
public:
    CarCsvService(std::string path);
    std::vector<Car> read() override;
    void write(std::vector<Car *> *cars) override;
    void setOwners(std::vector<Owner *> owners);
    std::vector<Owner *> *getOwners();


private:
    std::vector<Owner *> owners;
    Owner *getOwnerById(int id);
};



#endif // CARCSVSERVICE_H
