#include "Person.hpp"

Person::Person(int& age, std::string& name) : Age(age), Name(name){}
Person::Person() : Age(0), Name("Undefined"){}
Person::~Person(){}

inline std::string Person::getName() const {return Name;}
inline int Person::getAge() const {return Age;}

void Person::setName(std::string& name){
    this -> Name = name;
}
void Person::setAge(int& age){
    this -> Age = age;
}
