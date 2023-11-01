#include "../ownerview.h"

OwnerView::OwnerView(){}

std::string OwnerView::getFull(Owner *owner){
    if (owner == nullptr) return "";
    return "| Owner id: " + std::to_string(owner->getId()) + "\n"
    "| " + owner->getFullName();
};

std::string OwnerView::getFull(std::vector<Owner *> *owners){
    std::string result;
    for(Owner *owner: *owners) {
        result+=getFull(owner);
        if(owner != owners->back())
            result+="\n\n";
    }
    return result;
};

std::string OwnerView::ownerNotFound(int id){
    return "Owner with id: " + std::to_string(id) + " not found";
}
