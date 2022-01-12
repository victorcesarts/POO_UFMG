#ifndef BOX_HPP
#define BOX_HPP
#include <iostream>
#include <cmath>
#include "Ponto3D.hpp"
#include <vector>

using namespace std;
class Box{
    Ponto3D p1, p2, p3, p4, p5, p6, p7, p8;
    private:
    double width, height, depth;
    
    vector<Ponto3D> points;

    public:
    Box(Ponto3D pp1, Ponto3D pp2, Ponto3D pp3, Ponto3D pp4, 
    Ponto3D pp5, Ponto3D pp6, Ponto3D pp7, Ponto3D pp8);
    Box();
    ~Box();

    double area();
    double volume();
    
    double getHeight() const;
    double getWidth() const;
    double getDepth() const;
    void setHeight();
    void setWidth();
    void setDepth();
};



#endif