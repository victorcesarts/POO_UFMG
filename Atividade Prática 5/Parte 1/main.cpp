#include "Ponto2D.hpp"

int main() {

    Ponto2D a(1,4), b(3,2), c;
    std::cout << std::endl << "Point a is: " 
    << std::endl;
    a.print();
    std::cout << std::endl << "Point b is: " 
    << std::endl;
    b.print();
    std::cout << std::endl << "Point c is: " 
    << std::endl;
    c.print();
    std::cout << std::endl << "-------------------------------------------" 
    << std::endl;
    
    c = a + b;               // soma as coordenadas dos pontos a e b
    std::cout << "Point c must be equal point a plus point b"  
    << std::endl;
    c.print();
    std::cout << "Point c decremented by 1 unit is: "  
    << std::endl;
    --c;                    // decrementa em uma unidade as coordenadas de c
    c.print();
    std::cout << std::endl << "------------------THE END------------------" 
    << std::endl;

    return 0;
}