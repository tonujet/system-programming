#include <string>
#include <vector>
#include <tuple>
#include "Car.h"

#ifndef LAB2_COMPANY_H

#define LAB2_COMPANY_H

using namespace std;

namespace Company
{
    class TaxiCompany
    {
    private:
        string name;
        int capacity;
        vector<Car *> cars;
        vector<Car *> removedCars;
        vector<Owner *> owners;

        bool isCarAlreadyAdded(int carId);

        Car *deleteFromRemovedCars(int carId);

        tuple<Car *, int> getCarAndPosition(int carId);

        tuple<Car *, int> getRemovedCarAndPosition(int carId);

    public:
        TaxiCompany(string name, int capacity, vector<Owner *> owners);

        Car *addCar(Car *car);

        void addCars(vector<Car *> cars);

        Car *regainCar(int carId);

        Car *deleteCar(int carId);

        Car *getCar(int carId);

        Car *getRemovedCar(int carId);

        Car *changeOwner(Owner *owner, int carId);

        Car *changeOwner(int ownerId, int carId);

        Car *increaseMileageBy(int carId, int additionalMileage);

        string getName() const;

        vector<Car *> *getCars();

        vector<Car *> *getRemovedCars();

        vector<Owner *> *getOwners();

        void setName(string name);

        int getCapacity() const;
    };
}

#endif // LAB2_COMPANY_H
