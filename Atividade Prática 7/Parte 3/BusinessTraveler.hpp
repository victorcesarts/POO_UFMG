#include "Pager.hpp"
#include "Traveler.hpp"

class BusinessTraveler : public Traveler{

    private:
        string BusinessPerson;
    public:
        Pager P;
        BusinessTraveler();
        BusinessTraveler(string);
        BusinessTraveler(BusinessTraveler& that);
        ~BusinessTraveler();

        string getBsnsPerson() const;
        void setBsnsPerson(string);
        
       BusinessTraveler& operator=(const BusinessTraveler& BT); 

        friend ostream& operator<<(ostream& op, const BusinessTraveler& BT);
};