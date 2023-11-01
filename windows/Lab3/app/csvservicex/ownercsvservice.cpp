#include "../ownercsvservice.h"
#include "../csvservice.h"
#include "../rapidcsv.h"


OwnerCsvService::OwnerCsvService(std::string path)
    : CsvService(path){}

std::vector<Owner> OwnerCsvService::read()
{
    std::vector<Owner> owners;

    for(int i = 0; i < doc.GetRowCount(); i++){
        int id =  doc.GetCell<int>("id", i);
        std::string name = doc.GetCell<std::string>("name", i);
        std::string sName = doc.GetCell<std::string>("sName", i);
        std::string mName  = doc.GetCell<std::string>("mName", i);
        owners.push_back(Owner(id, name, sName, mName));
    }
    doc.Clear();
    return owners;
}

void OwnerCsvService::write(std::vector<Owner *> *cars)
{

}
