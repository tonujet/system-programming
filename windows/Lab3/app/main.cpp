#include "mainwindow.h"
#include "carcsvservice.h"
#include "ownercsvservice.h"
#include "hugewidgetfactory.h"
#include "defaultwidgetfactory.h"
#include <QApplication>


int main(int argc, char *argv[])
{

    std::vector<Owner *> ownersP;
    std::vector<Car *> carsP;
    std::vector<Car *> removedCarsP;
    CarCsvService carCsvService("E:/Tony/Edu/University/Sem5/system-programming/windows/Lab3/app/csv/cars.csv");
    CarCsvService removedCarCsvService("E:/Tony/Edu/University/Sem5/system-programming/windows/Lab3/app/csv/removedCars.csv");
    OwnerCsvService ownerCsvService("E:/Tony/Edu/University/Sem5/system-programming/windows/Lab3/app/csv/owners.csv");

    std::vector<Owner>owners = ownerCsvService.read();
    for(Owner &owner: owners) ownersP.push_back(&owner);

    carCsvService.setOwners(ownersP);
    std::vector<Car> cars = carCsvService.read();
    for(Car &car: cars) carsP.push_back(&car);

    removedCarCsvService.setOwners(ownersP);
    std::vector<Car> removedCars = removedCarCsvService.read();
    for(Car &car: removedCars) removedCarsP.push_back(&car);



    TaxiCompany company{
        "Astra",
        10,
        ownersP
    };
    company.addCars(carsP);
    company.addRemovedCars(removedCarsP);

    CarView carView;
    OwnerView ownerView;
    WidgetsFactory *defaulWidgetFactory = new DefaultWidgetFactory();
    WidgetsFactory *hugeWidgetFactory = new HugeWidgetFactory();


    QApplication a(argc, argv);
    MainWindow w(
        company, ownerView,
        carView, ownerCsvService,
        carCsvService, removedCarCsvService,
        defaulWidgetFactory, hugeWidgetFactory
        );


    w.show();
    return a.exec();
}
