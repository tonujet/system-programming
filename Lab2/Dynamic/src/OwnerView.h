#include <vector>
#include "Owner.h"

#ifndef LAB2_OWNERVIEW_H
#define LAB2_OWNERVIEW_H

using namespace std;

namespace Company {
    class OwnerView {
    public:
        void print(Owner *owner);
        void print(vector<Owner *> *owners);
    };
}

#endif //LAB2_OWNERVIEW_H
