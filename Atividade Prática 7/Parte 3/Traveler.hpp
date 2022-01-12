#include <iostream>
using namespace std;

class Traveler{
    private:
    string TravelerV;
public:
    Traveler(string);
    Traveler(const Traveler &that);
    ~Traveler();
    
    string getTraveler() const;
    void setTraveler(string);
    Traveler& operator= (const Traveler &T);
};