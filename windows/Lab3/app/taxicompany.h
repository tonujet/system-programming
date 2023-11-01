#ifndef TAXICOMPANY_H
#define TAXICOMPANY_H
#include "car.h"
#include <string>
#include <vector>
#include <tuple>

class TaxiCompany
{
public:
private:
    std::string name;
    int capacity;
    std::vector<Car *> cars;
    std::vector<Car *> removedCars;
    std::vector<Owner *> owners;

    bool isCarAlreadyAdded(int carId);

    Car *deleteFromRemovedCars(int carId);

    std::tuple<Car *, int> getCarAndPosition(int carId);

    std::tuple<Car *, int> getRemovedCarAndPosition(int carId);


public:
    TaxiCompany();
    TaxiCompany(std::string name, int capacity, std::vector<Owner *> owners);

    Car *addCar(Car *car);
    Car *addRemovedCar(Car *car);

    void addCars(std::vector<Car *> cars);
    void addRemovedCars(std::vector<Car *> cars);

    Car *regainCar(int carId);
    Car *deleteCar(int carId);

    Car *getCar(int carId) const;
    Car *getRemovedCar(int carId) const;

    Car *changeOwner(Owner *owner, int carId);
    Car *changeOwner(int ownerId, int carId);

    Car *increaseMileageBy(int carId, int additionalMileage);
    Car *increaseMileageInRange(int carId, int min, int max);

    std::string getName() const;

    std::vector<Car *> *getCars();
    std::vector<Car *> *getRemovedCars();
    std::vector<Owner *> *getOwners();
    void setName(std::string name);
    int getCapacity() const;
    Owner *getOwner(int id) const;

};

#endif // TAXICOMPANY_H
