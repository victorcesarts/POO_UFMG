/*  Aluno: Víctor César Teixeira Santos
    Engenharia de Controle e Automação
    Matrícula: 2020021832
    victorcesarts@ufmg.br
 */

#include "Time.hpp"
#include <iostream>

int main(){

    //instantiating some objects
    Time t;
    Time t1(72);
    Time t2 (90, 3);
    Time t3(4, 7, 55);
    Time t4(45, 30, 56, 65);

    //printing objects
    t.print();
    t1.print();
    t2.print();
    t3.print();
    t4.print();

    //Sum two objects time
    t4.sum(t3);
    std::cout << std::endl << "T4 plus T3 is: " << std::endl;
    t4.print();

    //modifying objects that were instantiated already 
    //T1
    std::cout << std::endl << "Modifying object t: " << std::endl;
    t.in();
    std::cout << "Printing object t: " << std::endl;
    t.print();

    //T4
    std::cout <<std::endl << "Modifying object t4: " << std::endl;
    t4.in();
    std::cout << "Printing object t4: " << std::endl;
    t4.print();

    //Increasing T4
    std::cout << std::endl << "Increasing time t4 in 1 second" << std::endl;
    t4.increasing();
    t4.print();

    //Decreasing T
    std::cout << std::endl << "Decreasing time t in 1 second" << std::endl;
    t.decreasing();
    t.print(); 
    
}