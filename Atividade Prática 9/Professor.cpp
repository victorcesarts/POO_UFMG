#include "Professor.hpp"

Professor::Professor(std::string n) : nome(n){}

Professor::~Professor(){}

inline std::string Professor::getName() const {return nome;}
 

