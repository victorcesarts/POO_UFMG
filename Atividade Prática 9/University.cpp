#include "University.hpp"

University::University(){};

void University::addProfessor(Professor* P){
    Professors.push_back(P);
}

double University::totalPago(){
    double Total = 0;
    for(auto it : Professors){
        double Total = Total + (it -> getSalario());
        this -> Salary = Total;
    }
    return Salary;
}