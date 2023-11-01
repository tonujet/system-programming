#ifndef OWNERVIEW_H
#define OWNERVIEW_H

#include <string>
#include <vector>
#include "Owner.h"


class OwnerView
{
public:
    OwnerView();
    std::string getFull(Owner *owner);
    std::string getFull(std::vector<Owner *> *owners);
    std::string ownerNotFound(int id);
};

#endif // OWNERVIEW_H
