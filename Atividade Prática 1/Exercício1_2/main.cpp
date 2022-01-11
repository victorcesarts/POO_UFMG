/*  Código por: Víctor César Teixeira Santos
    Engenharia de Controle e Automação - UFMG
    Matrícula: 2020021832
*/
#include "ReplicatesVectors.hpp"

using namespace std;

int main() {
    int aux;
    ReplicatesVectors counting;
    while (cin >> aux && aux >= 0){
        counting.addSort(aux);
    }
    counting.countingReplicates(); 
    counting.printing();  
    return 0;
}