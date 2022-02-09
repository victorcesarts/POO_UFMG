#ifndef PROFHOR_H
#define PROFHOR_H
#include "Professor.hpp"

class ProfHorista: public Professor {
        double HorasTrabalhadas;
        double ValorHora;
    public:
        ProfHorista(std::string Name, double nHorasTrabalhadas, double valorhora);
        double getSalario();
        virtual ~ProfHorista();
};

#endif