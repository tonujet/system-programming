#include <string>

#ifndef LAB2_OWNER_H
#define LAB2_OWNER_H

using namespace std;


namespace Company {

    class Owner {
    private:
        const int id;
        string name;
        string sName;
        string mName;
        static int currId;

    public:
        Owner(string name, string sName, string mName);

        int getId() const;

        string getName() const;

        string getSname() const;

        string getMname() const;

        string getFullName() const;

        void setName(string name);

        void setSname(string sName);

        void setMname(string mName);
    };


}


#endif //LAB2_OWNER_H
