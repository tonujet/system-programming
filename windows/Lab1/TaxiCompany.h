#include <string>
#include "Car.cpp"


using namespace std;


namespace Records {


    class TaxiCompany{
    private:
        string name;
        int carLength;
        int carCapacity;
        Car *cars[];



    public:
        TaxiCompany(string name, int carCapacity);
        string getName() const;
        void setName(string name);
        void addCar(Car *car);
        Car *getCar(int id) const;
        void reviewCar(int id) const;
        void reviewCars() const;
        void deleteLastCar();
    };

}