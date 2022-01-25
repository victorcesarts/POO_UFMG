#include "Acquaintance.hpp"

Acquaintance::Acquaintance() : Email ("Undefined"){}
Acquaintance::~Acquaintance(){}

inline std::string Acquaintance::getEmail() const { return Email; }

void Acquaintance::setEmail(std::string& email){
    this-> Email = email;
}

/* Only for friends */
inline std::string Acquaintance::getBirthDay() const{ return "Only friends have a birthday."; }
void Acquaintance::setBirthDay(std::string&) {std::cout << "Only friends have a birthday.";}

inline std::string Acquaintance::ObjectType() {return "Acquaintance";}