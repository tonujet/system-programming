#include "../csvservice.h"
#include "../car.h"
#include "../owner.h"

template<typename T>
CsvService<T>::CsvService(std::string path)
    :path(path)
{
    try{
        rapidcsv::Document doc(path, rapidcsv::LabelParams(0));
        this->doc = doc;
    } catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

template<typename T>
std::string CsvService<T>::getPath() const
{
    return path;
}

template<typename T>
void CsvService<T>::setPath(std::string path)
{
    this->path = path;
    doc.Load(path);
}


template<typename T>
void CsvService<T>::clearDataExceptHeader()
{
    try{
        for (int i = doc.GetRowCount() ; i > 0; --i) {
            doc.RemoveRow(i);
        }
        doc.Save();
    } catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }

}


template class CsvService<Car>;
template class CsvService<Owner>;


