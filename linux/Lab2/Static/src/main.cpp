#include <iostream>
#include <ctime>
#include "Car.h"
#include "TaxiCompany.h"
#include "Owner.h"
#include "CarView.h"
#include "UserInterface.h"
#include "OwnerView.h"

using namespace Company;

int main()
{
    time_t now = time(0);

    Owner *owner1 = new Owner("Anton", "Vorobei", "Olegovich");
    Owner *owner2 = new Owner("Bogdan", "Nikitenko", "Petrovich");
    Owner *owner3 = new Owner("Vasil", "Budda", "Igorovich");

    Car *car1 = new Car(1111, owner1, 1000, "Opel", "Vectra c", localtime(&now));
    Car *car2 = new Car(2222, owner2, 2000, "BMV", "X5", localtime(&now));
    Car *car3 = new Car(3333, owner3, 10000, "BMV", "X4", localtime(&now));
    Car *car4 = new Car(4444, owner3, 333, "BMV", "x5", localtime(&now));
    Car *car5 = new Car(131231, owner3, 0, "BMV", "X5", localtime(&now));
    Car *car6 = new Car(21312, owner1, 400, "BMV", "Volt", localtime(&now));

    TaxiCompany company{
        "Astra",
        10,
        {owner1, owner2, owner3}};
    company.addCars({car1, car2, car3, car4, car5, car6});

    CarView carView;
    OwnerView ownerView;

    UserInterface ui{&ownerView, &carView, &company};
    ui.displayMenu();

    free(owner1);
    free(owner2);
    free(owner3);

    free(car1);
    free(car2);
    free(car3);
    free(car4);
    free(car5);
    free(car6);

    return 0;
}
