#include "ProfHorista.hpp"

ProfHorista::ProfHorista(std::string Name, double nHorasTrabalhadas, double valorhora) : HorasTrabalhadas(nHorasTrabalhadas), ValorHora(valorhora), Professor(Name){}
ProfHorista::~ProfHorista(){}

double ProfHorista::getSalario(){double salary = ValorHora*HorasTrabalhadas; return salary;}