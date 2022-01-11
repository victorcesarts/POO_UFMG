/*  Aluno: Víctor César Teixeira Santos
    Engenharia de Controle e Automação
    Matrícula: 2020021832
    victorcesarts@ufmg.br
*/
#include "ponto2d.hpp"
#include <iostream>

int main(){
  try{
    //instantiations of class ponto2d
    ponto2d A(2.0, 4.0);
    ponto2d B(6.0, 8.0);
    ponto2d C(5.0, 7.0);
    ponto2d D(4.0, 6.0);
    ponto2d E(A);
    ponto2d F = E;

    std::cout << std::endl << "Point A is: " 
    << std::endl;
    A.print();
    std::cout << std::endl << "Point E must be equal A. Point E is: " 
    << std::endl;
    E.print();
    std::cout << std::endl << "Point F must be equal E. Point F is: " 
    << std::endl;
    F.print();

    std::cout << std::endl << "-------------------------------------------" 
    << std::endl;

    //testing member functions
    double b = C.distTo(A);
    std::cout << "The distance of point C to point A is: " <<  
    b << std::endl;

    double a = A.distToOrig();
    std::cout << "The distance of point A to origin is: " <<
    a << std::endl;

    std::cout << std::endl << "-------------------------------------------" 
    << std::endl;
    
    std::cout << std::endl << "Point A is: " 
    << std::endl;
    A.print();
    std::cout << "Point D is: " 
    << std::endl;
    D.print();

    std::cout << std::endl << "The coordinates of point D plus coordinates of point A give an object D equal to:" 
    << std::endl;
    D.add(A);
    D.print();

    std::cout << std::endl << "-------------------------------------------" 
    << std::endl;

    std::cout << std::endl << "Point C is: " 
    << std::endl;
    C.print();
    std::cout << "Point B is: " 
    << std::endl;
    B.print();
    std::cout << "Point A is: " 
    << std::endl;
    A.print();

    std::cout << std::endl << "The point C will be the sum of point A plus point B. " 
    << std::endl;
    C = B.sumOf(A);
    std::cout << "Point C is now: " 
    << std::endl;
    C.print();

  }
  //exception when the number of objects is bigger than the number
  //of possible unique IDs for each one (range of IDs 0 - 1000)
  catch(const std::out_of_range& e)
  {
    std::cerr << e.what() << '\n';
  }
    return 0;
}