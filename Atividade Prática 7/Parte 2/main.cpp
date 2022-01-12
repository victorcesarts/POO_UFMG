/*  Aluno: Víctor César Teixeira Santos
THE PROGRAMMER NEEDS TO KNOW WHAT IS THE RIGHT WAY TO USE THE 3D POINTS.
BASE is the lowest parallelogram and it must be parallel to the Upper parallelogram:
p4----------p3
|    Base   |       
P1----------P2
As mentioned, UPPER is another parallelogram:
p8----------p7
|    Upper  |
P5----------P6
A line segment "connect" the points of each parallelogram and generate the last four
parallelograms that together form the box

Distance (P1 to P5) or (P2 to P6) or (P3 to P7) or (P4 to P8) = Height
Distance (P1 to P2) or (P3 to P4) or (P5 to P6) or (P7 to P8) = Width
Distance (P1 to P4) or (P2 to P3) or (P5 to P8) or (P6 to P7) = Depth
*/
#include "Box.hpp"
#include <iostream>

int main(){
    Ponto3D p1(1, 2, 3), p2(3, 2, 3), p3(3, 1, 3), p4(1, 1, 3);
    Ponto3D p5(1, 2, 6), p6(3, 2, 6), p7(3, 1, 6), p8(1, 1, 6);
   
    Box b(p1, p2, p3, p4, p5, p6, p7, p8);

    cout << "Height: " << b.getHeight() << endl;
    cout << "Width: " << b.getWidth() << endl;
    cout << "Depth: " << b.getDepth() << endl;
    cout << "Area: " << b.area() << endl;
    cout << "Volume: " << b.volume() << endl;
    return 0;
}