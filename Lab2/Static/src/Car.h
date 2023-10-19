#include <string>
#include "Owner.h"

#ifndef LAB2_CAR_H
#define LAB2_CAR_H

using namespace std;

namespace Company
{

    class Car
    {
    public:
        Car(int regNumber, Owner *owner, int mileage, string companyName, string carName, tm *productionDate);

        int getId() const;

        int getRegNumber() const;

        int getMileage() const;

        Owner *getOwner() const;

        string getCompanyName() const;

        string getCarName() const;

        tm *getProductionDate() const;

        void setRegNumber(int regNumber);

        void setMileage(int mileage);

        void setOwner(Owner *owner);

        void setCompanyName(string companyName);

        void setCarName(string carName);

        void setProductionDate(tm *productionDate);

    private:
        const int id;
        int regNumber;
        Owner *owner;
        int mileage;
        string companyName;
        string carName;
        tm *productionDate;
        static int currId;
    };
}

#endif // LAB2_CAR_H
