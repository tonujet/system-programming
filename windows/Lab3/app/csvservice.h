#ifndef CSVSERVICE_H
#define CSVSERVICE_H

#include <string>
#include <vector>
#include "rapidcsv.h"


template <typename T>
class CsvService
{
public:
    CsvService(std::string path);
    virtual std::vector<T> read() = 0;
    virtual void write(std::vector<T *> *cars) = 0;
    std::string getPath() const;
    void setPath(std::string path);
    void clearDataExceptHeader();

protected:
    rapidcsv::Document doc;
    std::string path;

};

#endif // CSVSERVICE_H
