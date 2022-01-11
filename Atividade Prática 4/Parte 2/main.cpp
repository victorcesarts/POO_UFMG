/* Aluno: Víctor César Teixeira Santos 
Matrícula: 2020021832
Engenharia de Controle e Automação
e-mail: victorcesarts@ufmg.br / victorcesarts@gmail.com
*/
#include "matriz.hpp"
#include <iostream>
#include <fstream>

int main()
{
    std::ifstream in("myMatrix.txt");
    if (!in.is_open()){
        std::cout << "Não foi possível abrir o arquivo" << std::endl;
        return 0;
    } 

    Matrix Y;
    Matrix X(3,1);
    Matrix Z(3,2,7.0);
    Matrix W(in);
    Matrix D(Z);

    Y.print();

    std::cout << "Matrix W is: " << std::endl;
    W.print();
    W.unit();
    std::cout << "Now matrix W is: " << std::endl;
    W.print();
    std::cout << "-----------------------------------" << std::endl;

    std::cout << "Matrix X is: " << std::endl;
    X.print();
    X.ones();
    std::cout << "Now, matrix X is: " << std::endl;
    X.print();
    std::cout << "-----------------------------------" << std::endl;

    std::cout << "Matrix D is: " << std::endl;
    D.print();
    std::cout << "That's equal matrix Z, which is: " << std::endl;
    Z.print();
    std::cout << "-----------------------------------" << std::endl;

    std::cout << "We've changed Matrix D, now it has the values: " << std::endl;
    D.zeros();
    D.print();
    std::cout << "-----------------------------------" << std::endl;

    return 0;
}