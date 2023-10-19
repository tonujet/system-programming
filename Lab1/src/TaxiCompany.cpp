#include <iostream>
#include "TaxiCompany.h"

using namespace std;

namespace Records
{

    TaxiCompany::TaxiCompany(string name, int carCapacity) : name(name), carCapacity(carCapacity)
    {
        carLength = 0;
    }

    void TaxiCompany::addCar(Car *car)
    {
        if (carLength == carCapacity)
            throw("Taxi company is full");
        cars[carLength] = car;
        carLength++;
    }

    Car *TaxiCompany::getCar(int id) const
    {
        for (int i = 0; i < carLength; i++)
        {
            Car *car = cars[i];
            if (car->getId() == id)
                return car;
        }
        throw("Such car does not exist in our company");
    }

    void TaxiCompany::reviewCar(int id) const
    {
        Car *car = getCar(id);
        cout << car->toString();
    }

    void TaxiCompany::reviewCars() const
    {
        for (int i = 0; i < carLength; i++)
        {
            cout << cars[i]->toString();
        }
    }

    void TaxiCompany::deleteLastCar()
    {
        if (carLength == 0)
            throw("Taxi company is empty");
        carLength--;
    }

    string TaxiCompany::getName() const
    {
        return this->name;
    }

    void TaxiCompany::setName(string name)
    {
        this->name = name;
    }

}
