#include "Friend.hpp"

Friend::Friend() : BirthDay("Undefined"){}
Friend::~Friend(){}

inline std::string Friend::getBirthDay() const {return BirthDay;}

void Friend::setBirthDay(std::string& birthday){
    this-> BirthDay = birthday;
}

 /* Only for acquaintances */
inline std::string Friend::getEmail() const{ return "Only acquaintances have an e-mail address";}
void Friend::setEmail(std::string&) {std::cout << "Only acquaintances have an e-mail address";}

inline std::string Friend::ObjectType() {return "Friend";}