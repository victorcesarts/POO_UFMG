#include "Derived2.hpp"
#include <iostream>
using namespace std;

int main(){
    Base B;
Derived D(5);
Derived2 F(5);
cout << F.member();
    return 0;

/* D.read(); 
Não é possível pois read() é protected na Base.
e, portanto, só pode ser acessado dentro de Derived (ou da própria base)
    F.read();
Não é possível pelo mesmo motivo anterior, Derived herda read() como 
membro protected, como a herança em Derived2 é public, read() também
é visto como membro protected;    
*/

};