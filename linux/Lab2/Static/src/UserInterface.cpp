#include <iostream>
#include <limits>
#include <sstream>
#include "UserInterface.h"

using namespace std;
namespace Company
{

    UserInterface::UserInterface(OwnerView *ownerView, CarView *carView, TaxiCompany *taxiCompany)
        : ownerView(ownerView), carView(carView), taxiCompany(taxiCompany)
    {
        optionHandlers = {
            {1, [](UserInterface *ui)
             { ui->onFirstOption(); }},
            {2, [](UserInterface *ui)
             { ui->onSecondOption(); }},
            {3, [](UserInterface *ui)
             { ui->onThirdOption(); }},
            {4, [](UserInterface *ui)
             { ui->onFourthOption(); }},
            {5, [](UserInterface *ui)
             { ui->onFifthOption(); }},
            {6, [](UserInterface *ui)
             { ui->onSixthOption(); }},
            {7, [](UserInterface *ui)
             { ui->onSeventhOption(); }},
            {8, [](UserInterface *ui)
             { ui->onEighthOption(); }}};
    }

    void UserInterface::displayMenu()
    {
        while (true)
        {
            cout << "\n---------- Menu ----------"
                 << "\n";
            cout << "1. View car"
                 << "\n";
            cout << "2. View cars"
                 << "\n";
            cout << "3. View removed cars"
                 << "\n";
            cout << "4. Add mileage to car"
                 << "\n";
            cout << "5. View car owners"
                 << "\n";
            cout << "6. Change owner for car"
                 << "\n";
            cout << "7. Delete car"
                 << "\n";
            cout << "8. Regain car"
                 << "\n";
            cout << "9. Exit"
                 << "\n";
            cout << "--------------------------\n";
            int option = selectOption(0, 9);

            if (option == 9)
                return;
            optionHandlers[option](this);
            if (toMenuOrLeave() == 2)
                return;
        }
    }

    void UserInterface::onFirstOption()
    {
        int type = selectCarPrintingType();
        int id = selectId("car id", false);
        Car *car = taxiCompany->getCar(id);
        if (car != nullptr)
        {
            if (type == 1)
                carView->printShortInfo(car);
            else
                carView->printFullInfo(car);
        }
        else
        {
            cout << "Car with id: " + to_string(id) + " doesn`t exist"
                 << "\n";
        }
    }

    void UserInterface::onSecondOption()
    {
        viewCars(taxiCompany->getCars());
    }

    void UserInterface::onThirdOption()
    {
        viewCars(taxiCompany->getRemovedCars());
    }

    void UserInterface::onFourthOption()
    {
        cout << "Car modification"
             << "\n";
        int maxAdditionalMileage = 10000;
        int id = selectId("car id", false);
        cout << "Type additional mileage(Max: " + to_string(maxAdditionalMileage) + ")";
        int mileage = readNumber("", "Try again", 0, maxAdditionalMileage, true);
        Car *car = taxiCompany->increaseMileageBy(id, mileage);
        if (isSuccessfulCarOperation(car))
            carView->printFullInfo(car);
    }

    void UserInterface::onFifthOption()
    {
        auto owners = taxiCompany->getOwners();
        ownerView->print(owners);
    }

    void UserInterface::onSixthOption()
    {
        cout << "Changing owner"
             << "\n";
        int carId = selectId("car id", false);
        cout << "Do yo want to look at possible owners(1(Y)/2(N))";
        int number = readNumber("", "Try again", 1, 2, false);
        cout << "\n";
        if (number == 1)
            ownerView->print(taxiCompany->getOwners());
        int ownerId = selectId("owner id", true);
        Car *car = taxiCompany->changeOwner(ownerId, carId);
        if (isSuccessfulCarOperation(car))
            carView->printFullInfo(car);
    }

    void UserInterface::onSeventhOption()
    {
        cout << "Deleting car"
             << "\n";
        int id = selectId("car id", true);
        Car *car = taxiCompany->deleteCar(id);
        isSuccessfulCarOperation(car);
    }

    void UserInterface::onEighthOption()
    {
        cout << "Regaining car"
             << "\n";
        auto removedCars = taxiCompany->getRemovedCars();
        if (removedCars->empty())
        {
            cout << "There aren`t cars t regain"
                 << "\n";
            viewCars(removedCars);
            return;
        }
        else
        {
            cout << "Do yo want to look at car that possible regain(1(Y)/2(N))";
            int number = readNumber("", "Try again", 1, 2, false);
            if (number == 1)
                viewCars(taxiCompany->getRemovedCars());
            cout << "\n";
            int carId = selectId("car id", true);
            Car *car = taxiCompany->regainCar(carId);
            isSuccessfulCarOperation(car);
        }
    }

    int UserInterface::readNumber(string cursor, string errorMessage, int min, int max, bool addBlankLineAfter)
    {
        string line;
        int selectedOption;
        cout << cursor;
        while (getline(cin, line))
        {
            stringstream ss(line);
            if (ss >> selectedOption && ss.eof() &&
                selectedOption >= min && selectedOption <= max)
            {
                break;
            }
            cout << errorMessage << "\n";
            cout << cursor;
        }
        if (addBlankLineAfter)
            cout << "\n";

        return selectedOption;
    }

    int UserInterface::selectOption(int first, int last)
    {
        return readNumber(
            "Select option \n-------&&&>",
            "Wrong option. Type 8 if you want to leave",
            first,
            last,
            true);
    }

    int UserInterface::selectCarPrintingType()
    {
        cout << "---------- Form  ----------"
             << "\n";
        cout << "1. Short info"
             << "\n";
        cout << "2. Full info"
             << "\n";
        return readNumber(">>>>>>", "Try again", 1, 2, true);
    }

    int UserInterface::selectId(string whoseId, bool addBlankLineAfter)
    {
        cout << "Input " + whoseId + ":";
        return readNumber("", "Try again", 0, numeric_limits<int>::max(), addBlankLineAfter);
    }

    OwnerView *UserInterface::getOwnerView() const
    {
        return ownerView;
    }

    CarView *UserInterface::getCarView() const
    {
        return carView;
    }

    TaxiCompany *UserInterface::getTaxiCompany() const
    {
        return taxiCompany;
    }

    int UserInterface::toMenuOrLeave()
    {
        cout << "\n"
             << "Back to menu(1(Y)/2(N)):";
        return readNumber("", "Try again", 1, 2, false);
    }

    void UserInterface::viewCars(vector<Car *> *cars)
    {
        if (cars->empty())
        {
            cout << "+-------+"
                 << "\n";
            cout << "| Empty |"
                 << "\n";
            cout << "+-------+"
                 << "\n";
            return;
        }
        int type = selectCarPrintingType();
        if (type == 1)
            carView->printShortInfo(cars);
        else
            carView->printFullInfo(cars);
    }

    bool UserInterface::isSuccessfulCarOperation(Car *car)
    {
        if (car == nullptr)
        {
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
                 << "\n";
            cout << "!! Something went wrong.       !!"
                 << "\n";
            cout << "!! Most often it is invalid id !!"
                 << "\n";
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
                 << "\n";
            return false;
        }
        cout << "++-----------------------------++"
             << "\n";
        cout << "!! Operation successfully done !!"
             << "\n";
        cout << "++-----------------------------++"
             << "\n";
        return true;
    }

}