#ifndef OWNER_H
#define OWNER_H
#include <string>

class Owner
{
private:
    std::string name;
    std::string sName;
    std::string mName;
    const int id;

public:
    Owner(int id, std::string name, std::string sName, std::string mName);

    int getId() const;

    std::string getName() const;

    std::string getSname() const;

    std::string getMname() const;

    std::string getFullName() const;

    void setName(std::string name);

    void setSname(std::string sName);

    void setMname(std::string mName);
};

#endif // OWNER_H
