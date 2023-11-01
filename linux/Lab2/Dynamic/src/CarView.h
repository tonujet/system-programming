#include <vector>
#include "Car.h"

#ifndef LAB2_CARVIEW_H
#define LAB2_CARVIEW_H


namespace Company {
    class CarView {
    public:
        void printShortInfo(Car *car);

        void printShortInfo(vector<Car *> *cars);

        void printFullInfo(Car *car);

        void printFullInfo(vector<Car *> *cars);

    };
}


#endif //LAB2_CARVIEW_H
