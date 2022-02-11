#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include "Professor.hpp"
#include "ProfHorista.hpp"
#include "ProfIntegral.hpp"
#include <vector>

class University{
    private:
        double Salary;
    public:
        University();
        ~University();
        void addProfessor(Professor*);
        double totalPago();
        std::vector<Professor*> Professors;
};
#endif