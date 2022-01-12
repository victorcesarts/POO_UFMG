#include "Traveler.hpp"

Traveler::Traveler(string T):TravelerV(T) {};
Traveler::Traveler(const Traveler& that):TravelerV(that.getTraveler()){};
Traveler::~Traveler(){};


inline string Traveler::getTraveler() const {return TravelerV;};
void Traveler::setTraveler(string T){
    TravelerV = T;
}

Traveler& Traveler::operator= (const Traveler& T){
    this -> setTraveler(T.getTraveler()); 
    return *this;
}