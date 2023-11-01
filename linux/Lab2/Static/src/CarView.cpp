#include <iostream>
#include "CarView.h"

using namespace Company;

namespace Company
{
    void CarView::printFullInfo(Car *car)
    {
        if (car == nullptr)
            return;

        cout << "++==================================\n";
        cout << "|| id: " + to_string(car->getId()) + " | RegNumber: " + to_string(car->getRegNumber()) << "\n";
        cout << "|| Name: " + car->getCompanyName() + " " + car->getCarName() << "\n";
        cout << "|| Year: " + to_string(car->getProductionDate()->tm_year + 1900) << "\n";
        cout << "|| Mileage: " + to_string(car->getMileage()) << "\n";
        cout << "|| Owner: " + car->getOwner()->getFullName() << "\n";
        cout << "++==================================\n";
    }

    void CarView::printShortInfo(Car *car)
    {
        if (car == nullptr)
            return;

        string output = car->getCompanyName() + " " +
                        car->getCarName() + " " +
                        to_string(car->getProductionDate()->tm_year + 1900);
        string bar = "++";
        for (int i = 0; i < output.length() + 2; i++)
        {
            bar.append("=");
        }
        bar.append("++");

        cout << bar << "\n";
        cout << "|| " << output << " ||\n";
        cout << bar << "\n";
    }

    void CarView::printShortInfo(vector<Car *> *cars)
    {
        for (Car *car : *cars)
        {
            printShortInfo(car);
        }
    }

    void CarView::printFullInfo(vector<Car *> *cars)
    {
        for (Car *car : *cars)
        {
            printFullInfo(car);
        }
    }
}
