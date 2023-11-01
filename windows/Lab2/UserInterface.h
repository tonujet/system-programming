#include <vector>
#include <string>
#include <map>
#include <functional>
#include "OwnerView.h"
#include "CarView.h"
#include "TaxiCompany.h"

#ifndef LAB2_USERINTERFACE_H
#define LAB2_USERINTERFACE_H

using namespace std;

namespace Company {
    class UserInterface {
    public:
        UserInterface(OwnerView *ownerView, CarView *carView, TaxiCompany *taxiCompany);
        void displayMenu();

        OwnerView *getOwnerView() const;
        CarView *getCarView() const;
        TaxiCompany *getTaxiCompany() const;

    private:
        OwnerView *ownerView;
        CarView *carView;
        TaxiCompany *taxiCompany;
        int selectOption(int first, int last);
        int readNumber(string cursor, string errorMessage, int min, int max, bool addBlankLineAfter);
        int selectCarPrintingType();
        int selectId(string whoseId, bool addBlankLineAfter);
        int toMenuOrLeave();
        void viewCars(vector<Car *> *cars);
        void onFirstOption();
        void onSecondOption();
        void onThirdOption();
        void onFourthOption();
        void onFifthOption();
        void onSixthOption();
        void onSeventhOption();
        void onEighthOption();
        bool isSuccessfulCarOperation(Car *car);
        map<int, function<void(UserInterface *)>> optionHandlers;
    };
}


#endif //LAB2_USERINTERFACE_H
