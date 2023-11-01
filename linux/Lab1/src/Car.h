#include <iostream>
#include <ctime>

using namespace std;

namespace Records
{

    class Car
    {

    private:
        int id;
        int brandId;
        int regNumber;
        int bodyId;
        int engineId;
        int mileage;
        int employeeDriverId;
        int employeeMechanicId;
        tm *productionDate;
        tm *lastMaintenance;
        string specialMarks;
        inline static int currentCarId = 1;

    public:
        Car(int brandId, int regNumber, int bodyId, int engineId, int mileage, int employeeDriverId,
            int employeeMechanicId, tm *productionDate, tm *lastMaintenance, string specialMarks);

        string toString();

        int getId() const;

        void setId(int id);

        int getBrandId() const;

        void setBrandId(int brandId);

        int getRegNumber() const;

        void setRegNumber(int regNumber);

        int getBodyId() const;

        void setBodyId(int bodyId);

        int getEngineId() const;

        void setEngineId(int engineId);

        int getMileage() const;

        void setMileage(int mileage);

        int getEmployeeDriverId() const;

        void setEmployeeDriverId(int employeeDriverId);

        int getEmployeeMechanicId() const;

        void setEmployeeMechanicId(int employeeMechanicId);

        tm *getProductionDate() const;

        void setProductionDate(tm *productionDate);

        tm *getLastMaintenance() const;

        void setLastMaintenance(tm *lastMaintenance);

        string getSpecialMarks() const;

        void setSpecialMarks(string specialMarks);
    };

}
