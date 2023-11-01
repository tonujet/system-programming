#include "../car.h"


using std::string;


Car::Car(int id, int regNumber, Owner *owner, int mileage, string companyName, string carName):
    id(id), regNumber(regNumber), owner(owner),
    mileage(mileage), companyName(companyName),carName(carName) {}

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


void Car::setCarName(string carName) {
    this->carName = carName;
}

