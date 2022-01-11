// Programa cliente para testar a classe Matrix

#include <cstdlib> // system()
#include <iostream>
using namespace std;

#include "matriz.hpp"

void clearscreen() {
if (system( "clear" )) system( "cls" );
}

int main(){
    try{
        cout << "\n ---------------Testando construtores -------------- \n" << endl;
        Matrix<double> m1;
        cout << "Matrix<int> m1" << endl;
        cout << "-> Matriz de dimensao " << m1.getRows() << " x " << m1.getCols() << endl;
        cout << "m1 = " << m1 << endl;

        Matrix<float> m2(5, 5, 7.5);
        cout << "Matrix<float> m2(5, 5, 7.5)" << endl;
        cout << "-> Matriz de dimensao " << m2.getRows() << " x " << m2.getCols() << endl;
        cout << "m2 = " << m2 << endl;

        cout << "\nPressione qualquer tecla para continuar...";
        getchar();
        clearscreen();
    
        Matrix<float> m3(m2);
        cout << "Matrix<float> m3(m2)" << endl;
        cout << "-> Matriz de dimensao " << m3.getRows() << " x " << m3.getCols() << endl;
        cout << "m3 = " << m3 << endl;

    
        Matrix<double> m4(2, 3, 6);
        cout << "Matrix<double> m4(2, 3)" << endl;
        cout << "-> Matriz de dimensao " << m4.getRows() << " x " << m4.getCols() << endl;
        cout << "m4 = " << m4 << endl;
    
        cout << "\nPressione qualquer tecla para continuar...";
        getchar();
        clearscreen();
    
        cout << "\n ---------------Testando Inicializacoes -------------- \n" << endl;
    
        Matrix<float> m6(3, 4, 2.3);
        cout << "Matrix<float> m6(3, 4, 2.3)" << endl;
        cout << "-> Matriz de dimensao " << m6.getRows() << " x " << m6.getCols() << endl;
        cout << "m6 = " << m6;
        m6.zeros();
        cout << "m6.zeros() :: Matriz Zeros" << endl;
        cout << "m6 = " << m6 << endl;
   
        cout << "\nPressione qualquer tecla para continuar...";
        getchar();
        clearscreen();
    
        cout << "\n --------------- Testando Sobrecarga de Operadores-------------------------- \n" << endl;

        m6(1, 1) = 7; 
        m6(1, 3) = -3; 
        m6(2, 1) = 3.6; 
        m6(2, 2) = -2; 
        //An exception has ocurred here, so this line is commented 
        m6(3, 1) = 4;
        cout << "-> Sobrecarga do Operador ( )" << endl;
        cout << "m6(1, 1) = 7; m6(1, 3) = -3; m6(2, 1) = 3.6; m6(2, 2) = -2; m6(3, 1) = 4;" << endl;
        cout << "m6 = " << m6 << endl;
    }
    catch(const out_of_range& e){
        std::cerr << e.what() << '\n';
    }
}