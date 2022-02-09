#include "ProfIntegral.hpp"

ProfIntegral::ProfIntegral(std::string Name, double SalarioMensal) : Professor(Name), salarioMensal(SalarioMensal){}
ProfIntegral::~ProfIntegral(){}

inline double ProfIntegral::getSalario() {return salarioMensal;}