#include <iostream>
#include "Car.h"
using namespace std;

namespace Records
{

    Car::Car(int brandId, int regNumber, int bodyId, int engineId, int mileage, int employeeDriverId,
             int employeeMechanicId, tm *productionDate, tm *lastMaintenance, string specialMarks)
        : id(currentCarId++), brandId(brandId), regNumber(regNumber),
          bodyId(bodyId), engineId(engineId), mileage(mileage),
          employeeDriverId(employeeDriverId), employeeMechanicId(employeeMechanicId),
          productionDate(productionDate), lastMaintenance(lastMaintenance), specialMarks(specialMarks) {}

    string Car::toString()
    {
        return "\n-------------------------------------------------\n"
               "  id: " +
               to_string(id) + "\n  brandId: " + to_string(brandId) +
               "\n  bodyId: " + to_string(bodyId) + "\n  engineId: " + to_string(engineId) +
               "\n  mileage: " + to_string(mileage) +
               "\n  employeeDriverId: " + to_string(employeeDriverId) +
               "\n  productionDate: " + asctime(productionDate) +
               "  lastMaintenance: " + asctime(lastMaintenance) +
               "  specialMarks: " + specialMarks +
               "\n------------------------------------------------\n";
    }

    int Car::getId() const
    {
        return id;
    }

    void Car::setId(int id)
    {
        this->id = id;
    }

    int Car::getBrandId() const
    {
        return brandId;
    }

    void Car::setBrandId(int brandId)
    {
        this->brandId = brandId;
    }

    int Car::getRegNumber() const
    {
        return regNumber;
    }

    void Car::setRegNumber(int regNumber)
    {
        this->regNumber = regNumber;
    }

    int Car::getBodyId() const
    {
        return bodyId;
    }

    void Car::setBodyId(int bodyId)
    {
        this->bodyId = bodyId;
    }

    int Car::getEngineId() const
    {
        return engineId;
    }

    void Car::setEngineId(int engineId)
    {
        this->engineId = engineId;
    }

    int Car::getMileage() const
    {
        return mileage;
    }

    void Car::setMileage(int mileage)
    {
        this->mileage = mileage;
    }

    int Car::getEmployeeDriverId() const
    {
        return employeeDriverId;
    }

    void Car::setEmployeeDriverId(int employeeDriverId)
    {
        this->employeeDriverId = employeeDriverId;
    }

    int Car::getEmployeeMechanicId() const
    {
        return employeeMechanicId;
    }

    void Car::setEmployeeMechanicId(int employeeMechanicId)
    {
        this->employeeMechanicId = employeeMechanicId;
    }

    tm *Car::getProductionDate() const
    {
        return productionDate;
    }

    void Car::setProductionDate(tm *productionDate)
    {
        this->productionDate = productionDate;
    }

    tm *Car::getLastMaintenance() const
    {
        return lastMaintenance;
    }

    void Car::setLastMaintenance(tm *lastMaintenance)
    {
        this->lastMaintenance = lastMaintenance;
    }

    string Car::getSpecialMarks() const
    {
        return specialMarks;
    }

    void Car::setSpecialMarks(string specialMarks)
    {
        this->specialMarks = specialMarks;
    }
}
