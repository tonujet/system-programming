#include "Owner.h"

namespace Company
{

    int Owner::currId = 0;

    Owner::Owner(string name, string sName, string mName)
        : name(name), sName(sName), mName(mName), id(currId++) {}

    int Owner::getId() const
    {
        return this->id;
    }

    string Owner::getName() const
    {
        return this->name;
    }

    string Owner::getMname() const
    {
        return this->mName;
    }

    string Owner::getFullName() const
    {
        return sName + " " + name + " " + mName;
    }

    string Owner::getSname() const
    {
        return this->sName;
    }

    void Owner::setName(string name)
    {
        this->name = name;
    }

    void Owner::setMname(std::string mName)
    {
        this->mName = mName;
    }

    void Owner::setSname(std::string sName)
    {
        this->sName = sName;
    }
}
