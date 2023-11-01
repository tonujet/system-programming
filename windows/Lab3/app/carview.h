#ifndef CARVIEW_H
#define CARVIEW_H

#include <string>
#include <vector>
#include "car.h"

class CarView
{
public:
    CarView();
    std::string getFull(Car *car);
    std::string getFull(std::vector<Car *> *cars);
    std::string carNotFound(int id);
    std::string carRegained(int id);
    std::string carDeleted(int id);
    std::string deletingCar(Car *car, int id);
    std::string regainingCar(Car *car, int id);
    std::string changedOwner(Car *car, Owner *owner);
    std::string increasedMileage(Car *car, int id);
    std::string pointToCar(Car *car, std::string label);
};

#endif // CARVIEW_H
