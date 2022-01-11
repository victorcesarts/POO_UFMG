/* Aluno: Víctor César Teixeira Santos 
Matrícula: 2020021832
Engenharia de Controle e Automação
e-mail: victorcesarts@ufmg.br / victorcesarts@gmail.com
*/

#include "matriz.hpp"
#include <iostream>

int main()
{
    Matrix Y(3,2);
    Matrix X(4,1);
    
    std::cout << "Y:: " << std::endl;
    Y.print();
    std::cout << "Numero de linhas de Y:: " << Y.getRows() << std::endl;
    std::cout << "Numero de colunas de Y:: " << Y.getCols() << std::endl;
   
    std::cout << "Z é transposta de Y:: " << std::endl;
    Matrix Z = Y.transpose();
    Z.print();
    std::cout << "Numero de linhas de Z:: " << Z.getRows() << std::endl;
    std::cout << "Numero de colunas de Z:: " << Z.getCols() << std::endl;
    
    std::cout << std::endl << "X:: " << std::endl;
    X.print();
    
    std::cout << "Numero de linhas de X:: " << X.getRows() << std::endl;
    std::cout << "Numero de colunas de X:: " << X.getCols() << std::endl;
   
    return 0;
}