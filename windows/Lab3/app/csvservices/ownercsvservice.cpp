#include "../ownercsvservice.h"
#include "../csvservice.h"
#include "../rapidcsv.h"


OwnerCsvService::OwnerCsvService(std::string path)
    : CsvService(path){}

std::vector<Owner> OwnerCsvService::read()
{
    std::vector<Owner> owners;

    try{
        for(int i = 0; i < doc.GetRowCount(); i++){
            int id =  doc.GetCell<int>("id", i);
            std::string name = doc.GetCell<std::string>("name", i);
            std::string sName = doc.GetCell<std::string>("sName", i);
            std::string mName  = doc.GetCell<std::string>("mName", i);
            owners.push_back(Owner(id, name, sName, mName));
        }
        doc.Clear();
    } catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return owners;
}

void OwnerCsvService::write(std::vector<Owner *> *owners)
{
    clearDataExceptHeader();

    try{
        for(int i = 0; i < owners->size(); i++){
            Owner *owner = owners->at(i);
            doc.SetCell("id", i, owner->getId());
            doc.SetCell("name", i, owner->getName());
            doc.SetCell("sName", i, owner->getSname());
            doc.SetCell("mName", i, owner->getMname());
        }
        doc.Save();
    } catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
