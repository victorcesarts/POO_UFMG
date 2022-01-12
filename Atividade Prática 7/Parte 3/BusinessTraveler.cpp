#include "BusinessTraveler.hpp"

BusinessTraveler::BusinessTraveler():Traveler("1"), P("1"), BusinessPerson("1"){};
BusinessTraveler::BusinessTraveler(string BT):Traveler(BT), P(BT), BusinessPerson(BT) {};
BusinessTraveler::BusinessTraveler(BusinessTraveler& that):Traveler(that.getBsnsPerson()), P(that.getBsnsPerson()), BusinessPerson(that.getBsnsPerson()) {};
BusinessTraveler::~BusinessTraveler() {};

inline string BusinessTraveler::getBsnsPerson() const {return BusinessPerson;};

void BusinessTraveler::setBsnsPerson(string BT){
    BusinessPerson = BT;
}

BusinessTraveler& BusinessTraveler::operator=(const BusinessTraveler& BT){
  
    this -> setBsnsPerson(BT.getBsnsPerson());
    Traveler::operator=(BT); //BT could acess getTraveler() as well
    this -> P = BT.P;
    return *this;
} 

 ostream& operator<<(ostream& op, const BusinessTraveler& BT){
     op << "BusinessTraveler: " << BT.getBsnsPerson() << ", Pager: " << BT.P.getPager() << ", Traveler: " << BT.getTraveler();
     return op;
 }

