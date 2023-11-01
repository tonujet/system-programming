#include <iostream>
#include <ctime>
#include "Car.h"
#include "TaxiCompany.h"
#include "Owner.h"
#include "CarView.h"
#include "UserInterface.h"
#include "OwnerView.h"

using namespace Company;

int main() {
    time_t now = time(0);

    Owner owner1("Anton", "Vorobei", "Olegovich");
    Owner owner2("Bogdan", "Nikitenko", "Petrovich");
    Owner owner3("Vasil", "Budda", "Igorovich");


    Car car1(1111, &owner1, 1000, "Opel", "Vectra c", localtime(&now));
    Car car2(2222, &owner2, 2000, "BMV", "X5", localtime(&now));
    Car car3(3333, &owner3, 10000, "BMV", "X4", localtime(&now));
    Car car4(4444, &owner3, 333, "BMV", "x5", localtime(&now));
    Car car5(131231, &owner3, 0, "BMV", "X5", localtime(&now));
    Car car6(21312, &owner1, 400, "BMV", "Volt", localtime(&now));

    TaxiCompany company{
            "Astra",
            10,
            {&owner1, &owner2, &owner3}
    };
    company.addCars({&car1, &car2, &car3, &car4, &car5, &car6});

    CarView carView;
    OwnerView ownerView;

    UserInterface ui{&ownerView, &carView, &company};
    ui.displayMenu();


    return 0;


}


