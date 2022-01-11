/*  Código por: Víctor César Teixeira Santos
    Engenharia de Controle e Automação - UFMG
    Matrícula: 2020021832
*/
#include <iostream>
#include "matriz.hpp"

int main()
{
    Matriz A, B, T, R;

    cout << "A:: " << endl;
    inicializaMatriz(A,2,3,7.0);
    imprimeMatriz(A);
    
    cout << "Transposta de A:: " << endl;
    T = transposta(A);
    imprimeMatriz(T);
    apagaMatriz(T);

    cout << endl << "B:: " << endl;
    inicializaMatriz(B,4,4,5.0);
    imprimeMatriz(B);
    
    cout << endl << "R = k*B " << endl;
    R = multiplica_por_cte(B,5); 
    imprimeMatriz(R);
    
    apagaMatriz(B);
    apagaMatriz(R);

    return 0;
}