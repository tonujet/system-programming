#include <iostream>
#include <string>
#include <ctime>
#include "TaxiCompany.h"

using namespace std;
using namespace Records;

int displayMenu();
void CLI(TaxiCompany &taxiCompany);

int main(int argc, char **argv)
{
    time_t now = time(0);

    TaxiCompany taxiCompany("BBB", 5);
    Car car1(10, 1010, 10, 10, 1020, 10, 31, gmtime(&now), gmtime(&now), "Driver is mad");
    Car car2(11, 1111, 10, 10, 1300, 10, 10, gmtime(&now), gmtime(&now), "Driver is betrayer of humanity");
    Car car3(12, 1212, 1212, 10, 3100, 20, 10, gmtime(&now), gmtime(&now), "Driver is such a good guy");
    Car car4(13, 1313, 10, 10, 1211211, 10, 10, gmtime(&now), gmtime(&now), "Car demolished by users");
    Car car5(14, 1414, 10, 10, 1000, 15, 44, gmtime(&now), gmtime(&now), "Car must ne sold!!!");
    Car *car6 = new Car(16, 1616161616, 1616, 16, 1616161, 16, 16, gmtime(&now), gmtime(&now), "Be carefull");
    Car *car7 = new Car(17, 171717, 17, 17, 171717, 17, 10, gmtime(&now), gmtime(&now), "Car body is shabby");
    Car *car8 = new Car(18, 18181818, 18, 18, 181818, 18, 18, gmtime(&now), gmtime(&now), "TEST1231231");
    Car *car9 = new Car(19, 191919, 10, 10, 1000, 19, 10, gmtime(&now), gmtime(&now), "END!");
    Car *car10 = new Car(20, 20202020, 20, 10, 1000, 10, 20, gmtime(&now), gmtime(&now), "luxurious car");
    taxiCompany.addCar(car9);
    taxiCompany.addCar(&car2);
    taxiCompany.addCar(&car3);
    taxiCompany.addCar(&car4);
    taxiCompany.addCar(car6);

    CLI(taxiCompany);

    delete car6;
    delete car7;
    delete car8;
    delete car9;
    delete car10;

    return 0;
}

void CLI(TaxiCompany &taxiCompany)
{
    bool done = false;
    while (!done)
    {
        int selection = displayMenu();
        switch (selection)
        {
        case 1:
            taxiCompany.reviewCars();
            break;
        case 2:
            int id;
            cout << "Input id\n";
            cin >> id;
            try
            {
                taxiCompany.reviewCar(id);
            }
            catch (const char *str)
            {
                cerr << "\n"
                     << str << endl;
                done = true;
            }
            break;
        case 3:
            try
            {
                taxiCompany.deleteLastCar();
            }
            catch (const char *str)
            {
                cerr << "\n"
                     << str << endl;
                done = true;
            }
            break;
        case 0:
            done = true;
            break;
        default:
            cerr << "Unknown command."
                 << "\n"
                 << "Please try again\n";
        }
    }
}

int displayMenu()
{
    int selection;
    cout << endl;
    cout << "Taxi Company" << endl;
    cout << "=====================================" << endl;
    cout << "1) Car List" << endl;
    cout << "2) Get Car by id" << endl;
    cout << "3) Delete last car" << endl;
    cout << "0) Quit" << endl;
    cout << endl;
    cout << "--->   ";
    cin >> selection;
    return selection;
}
