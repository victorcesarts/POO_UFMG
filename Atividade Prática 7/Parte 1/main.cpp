#include "Ponto2D.hpp"
#include "Ponto3D.hpp"
using namespace std;
// código para teste da classe Ponto3D
    
int main()
{
    Ponto2D p1(3,4), p2;
    p2.set(2,1.5);
    cout << p1 << endl;
    cout << p2 << endl;

    p2 = p1;
    cout << p2 << endl;


    Ponto3D p3(2,4.5,5), p4;
    p4.set(1,0.3,12);
    cout << p3 << endl;
    cout << p4 << endl;

    p4 = p3;
    cout << p4 << endl;

    p4 = p1;
    cout << p4 << endl;

    return 0;
}    