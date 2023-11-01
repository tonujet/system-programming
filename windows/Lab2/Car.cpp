#include "Car.h"


namespace Company {

    int Car::currId = 0;

    Car::Car(int regNumber, Owner *owner, int mileage, string companyName, string carName, tm *productionDate)
            :
            id(currId++), regNumber(regNumber), owner(owner), mileage(mileage), companyName(companyName),
            productionDate(productionDate), carName(carName) {}

    int Car::getId() const {
        return this->id;
    }

    int Car::getMileage() const {
        return mileage;
    }

    int Car::getRegNumber() const {
        return regNumber;
    }

    Owner *Car::getOwner() const {
        return owner;
    }

    string Car::getCompanyName() const {
        return companyName;
    }

    string Car::getCarName() const {
        return carName;
    }


    tm *Car::getProductionDate() const {
        return productionDate;
    }

    void Car::setRegNumber(int regNumber) {
        this->regNumber = regNumber;
    }

    void Car::setMileage(int mileage) {
        this->mileage = mileage;
    }

    void Car::setOwner(Owner *owner) {
        this->owner = owner;
    }

    void Car::setCompanyName(string companyName) {
        this->companyName = companyName;
    }

    void Car::setProductionDate(tm *productionDate) {
        this->productionDate = productionDate;
    }

    void Car::setCarName(string carName) {
        this->carName = carName;
    }
}