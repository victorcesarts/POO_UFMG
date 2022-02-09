#ifndef PROFINTE_H
#define PROFINTE_H

#include "Professor.hpp"
class ProfIntegral : public Professor {
        double salarioMensal;
    public:
       ProfIntegral(std::string Name, double SalarioMensal);
       double getSalario();
       virtual ~ProfIntegral();
};
#endif