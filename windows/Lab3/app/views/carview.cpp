#include "../carview.h"
#include <algorithm>

using std::to_string;

CarView::CarView(){};


std::string CarView::getFull(Car *car){
    if (car == nullptr) return "";

    return
        "|| id: " + to_string(car->getId()) + " | RegNumber: " + to_string(car->getRegNumber()) + "\n"
        "|| Name: " + car->getCompanyName() + " " + car->getCarName() + "\n"
        "|| Mileage: " + to_string(car->getMileage()) + "\n"
        "|| Owner: " + car->getOwner()->getFullName();
};


std::string CarView::getFull(std::vector<Car *> *cars){
    std::string result;

    std::sort(cars->begin(), cars->end(), [ ]( const auto& lhs, const auto& rhs )
    {
        return lhs->getId() < rhs->getId();
    });

    if(!cars->empty()) {
        for (Car *car: *cars) {
            result+=getFull(car);
            if(car != cars->back())
                result+="\n\n";
        }
    }
    else result = "Empty";
    return result;
};

std::string CarView::carNotFound(int id){
    return  "Car with id: " + std::to_string(id) + " not found";
}

std::string CarView::carRegained(int id){
    return "Car with id: " + std::to_string(id) + " was regained";
}

std::string CarView::carDeleted(int id){
    return "Car with id: " + std::to_string(id) + " was deleted";
}
std::string CarView::deletingCar(Car *car, int id){
    std::string res;
    if (car == nullptr){
        res = carNotFound(id);
    } else {
        res = pointToCar(car, carDeleted(id));
    }
    return res;
}

std::string CarView::regainingCar(Car *car, int id){
    std::string res;
    if (car == nullptr){
        res = carNotFound(id);
    } else {
        res = pointToCar(car, carRegained(id));
    }
    return res;
}

std::string CarView::changedOwner(Car *car, Owner *owner)
{
    return pointToCar(car, "Owner was changed to: " + owner->getFullName());
}

std::string CarView::increasedMileage(Car *car, int id)
{
    std::string res;
    if (car == nullptr){
        res = carNotFound(id);
    } else {
        res = pointToCar(car, "Car with new mileage");
    }
    return res;
}

std::string CarView::pointToCar(Car *car, std::string label)
{
    return label + "\n"
        "|| || || || || || || || || || || || || |\n"
        "vvvvvvvvvvvvvvvvvvvv\n"
        + getFull(car);
}




