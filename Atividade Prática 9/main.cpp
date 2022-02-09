#include "ProfHorista.hpp"
#include "ProfIntegral.hpp"
#include "University.hpp"

int main(){
    ProfIntegral* VictorC = new ProfIntegral("Víctor", 20000);
    ProfHorista* JoseM = new ProfHorista("José", 40, 500);
    ProfHorista* GabrielL = new ProfHorista("Gabriel", 40, 250);
    University* UFMG = new University();
        
    UFMG -> addProfessor(VictorC);
    UFMG -> addProfessor(JoseM);
    UFMG -> addProfessor(GabrielL);

    std::cout << "Professor: " << VictorC -> getName() << " tem salário de: " << VictorC -> getSalario();
    UFMG -> totalPago();
    return 0;
}