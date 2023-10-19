#include <stdexcept>
#include "TaxiCompany.h"

using namespace std;

namespace Company
{

    TaxiCompany::TaxiCompany(string name, int capacity, vector<Owner *> owners)
        : name(name), capacity(capacity), owners(owners)
    {
    }

    Car *TaxiCompany::getCar(int carId)
    {
        for (Car *car : cars)
        {
            if (car->getId() == carId)
                return car;
        }
        return nullptr;
    }

    Car *TaxiCompany::getRemovedCar(int carId)
    {
        for (Car *car : removedCars)
        {
            if (car->getId() == carId)
                return car;
        }
        return nullptr;
    }

    Car *TaxiCompany::addCar(Car *car)
    {
        if (cars.size() >= capacity)
            throw std::length_error("Dont have space for one more car");

        if (isCarAlreadyAdded(car->getId()))
            return car;

        deleteFromRemovedCars(car->getId());
        cars.push_back(car);
        return car;
    }

    void TaxiCompany::addCars(vector<Car *> cars)
    {
        for (Car *car : cars)
        {
            addCar(car);
        }
    }

    Car *TaxiCompany::deleteCar(int carId)
    {
        auto [car, i] = getCarAndPosition(carId);
        if (car == nullptr)
            return nullptr;
        cars.erase(cars.begin() + i);
        removedCars.push_back(car);
        return car;
    }

    Car *TaxiCompany::increaseMileageBy(int carId, int additionalMileage)
    {
        Car *car = getCar(carId);
        if (car != nullptr)
            car->setMileage(car->getMileage() + additionalMileage);
        return car;
    }

    Car *TaxiCompany::changeOwner(Owner *owner, int carId)
    {
        Car *car = getCar(carId);
        if (car != nullptr)
            car->setOwner(owner);
        return car;
    }

    Car *TaxiCompany::changeOwner(int ownerId, int carId)
    {
        for (Owner *owner : owners)
        {
            if (owner->getId() == ownerId)
            {
                return changeOwner(owner, carId);
            }
        }
        return nullptr;
    };

    bool TaxiCompany::isCarAlreadyAdded(int carId)
    {
        Car *car = getCar(carId);
        return car != nullptr;
    }

    Car *TaxiCompany::deleteFromRemovedCars(int carId)
    {
        auto [car, i] = getRemovedCarAndPosition(carId);
        if (car != nullptr)
        {
            removedCars.erase(removedCars.begin() + i);
        }
        return car;
    }

    tuple<Car *, int> TaxiCompany::getCarAndPosition(int carId)
    {
        for (int i = 0; i < cars.size(); i++)
        {
            Car *car = cars[i];
            if (car->getId() == carId)
                return {car, i};
        }
        return tuple{nullptr, -1};
    }

    tuple<Car *, int> TaxiCompany::getRemovedCarAndPosition(int carId)
    {
        for (int i = 0; i < removedCars.size(); i++)
        {
            Car *car = removedCars[i];
            if (car->getId() == carId)
                return {car, i};
        }
        return tuple{nullptr, -1};
    }

    Car *TaxiCompany::regainCar(int carId)
    {
        Car *car = deleteFromRemovedCars(carId);
        if (car != nullptr)
            addCar(car);
        return car;
    }

    string TaxiCompany::getName() const
    {
        return name;
    }

    void TaxiCompany::setName(string name)
    {
        this->name = name;
    }

    int TaxiCompany::getCapacity() const
    {
        return capacity;
    }

    vector<Car *> *TaxiCompany::getCars()
    {
        return &cars;
    };

    vector<Car *> *TaxiCompany::getRemovedCars()
    {
        return &removedCars;
    }

    vector<Owner *> *TaxiCompany::getOwners()
    {
        return &owners;
    }
}