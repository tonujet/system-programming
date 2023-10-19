#include <iostream>
#include "OwnerView.h"

namespace Company {
    void Company::OwnerView::print(Company::Owner *owner) {
        if (owner == nullptr) return;
        cout << "+-----------------------------------\n";
        cout << "| Owner id: " + to_string(owner->getId()) << "\n";
        cout << "| " + owner->getFullName() << "\n";
        cout << "+-----------------------------------\n";
    }


    void OwnerView::print(vector<Owner *> *owners) {
        for (Owner *owner: *owners) {
            print(owner);
        }
    }
}

