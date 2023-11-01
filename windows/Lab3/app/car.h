#ifndef CAR_H
#define CAR_H

#include <string>
#include "owner.h"



class Car
{
public:
    Car(int id, int regNumber, Owner *owner, int mileage, std::string companyName, std::string carName);

    int getId() const;
    int getRegNumber() const;
    int getMileage() const;
    Owner *getOwner() const;
    std::string getCompanyName() const;
    std::string getCarName() const;

    void setRegNumber(int regNumber);
    void setMileage(int mileage);
    void setOwner(Owner *owner);
    void setCompanyName(std::string companyName);
    void setCarName(std::string carName);


private:
    const int id;
    int regNumber;
    Owner *owner;
    int mileage;
    std::string companyName;
    std::string carName;
};



#endif // CAR_H
