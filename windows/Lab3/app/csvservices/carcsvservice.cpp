#include "../carcsvservice.h"
#include "../rapidcsv.h"


CarCsvService::CarCsvService(std::string path):
    CsvService(path){}


std::vector<Car> CarCsvService::read()
{
    std::vector<Car> cars;
    try{
        for(int i = 0; i < doc.GetRowCount(); i++){
            int id =  doc.GetCell<int>("id", i);
            int regNumber =  doc.GetCell<int>("regNumber", i);
            Owner *owner =  getOwnerById(doc.GetCell<int>("ownerId", i));
            int mileage =  doc.GetCell<int>("mileage", i);
            std::string companyName = doc.GetCell<std::string>("companyName", i);
            std::string carName = doc.GetCell<std::string>("carName", i);
            cars.push_back(Car(id, regNumber, owner, mileage, companyName, carName));
        }
    } catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return cars;
}

void CarCsvService::write(std::vector<Car *> *cars)
{
    clearDataExceptHeader();

    try{
        for(int i = 0; i < cars->size(); i++){
            Car *car = cars->at(i);
            doc.SetCell("id", i, car->getId());
            doc.SetCell("regNumber", i, car->getRegNumber());
            doc.SetCell("ownerId", i, car->getOwner()->getId());
            doc.SetCell("mileage", i, car->getMileage());
            doc.SetCell("companyName", i, car->getCompanyName());
            doc.SetCell("carName", i, car->getCarName());
        }

        doc.Save();
    } catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

void CarCsvService::setOwners(std::vector<Owner *> owners)
{
    this->owners = owners;
}

std::vector<Owner *> *CarCsvService::getOwners()
{
    return &owners;
}

Owner *CarCsvService::getOwnerById(int id)
{
    for (Owner *owner: owners){
        if(owner->getId() == id) return owner;
    }
    return nullptr;
}
