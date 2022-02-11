#include "Professor.hpp"
#include "ProfHorista.hpp"
#include "ProfIntegral.hpp"
#include "University.hpp"

int main(){
    ProfIntegral VictorC("Víctor", 8000); // = new ProfIntegral("Víctor", 20000);
    ProfHorista JoseM("JoseM", 40, 100);
    University* UFMG = new University();
        
    UFMG -> addProfessor(&VictorC);
    UFMG -> addProfessor(&JoseM);
    
    cout << "Professor: " << VictorC.getName() << " tem salário de: " << VictorC.getSalario() << endl;
    cout << "Professor: " << JoseM.getName() << " tem salário de: " << JoseM.getSalario() << endl;
    cout << "O total pago pela universidade é: " << UFMG -> totalPago() << endl;
    return 0;
}