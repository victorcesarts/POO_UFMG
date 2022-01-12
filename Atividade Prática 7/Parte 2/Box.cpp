#include "Box.hpp"


Box::Box(Ponto3D pp1, Ponto3D pp2, Ponto3D pp3, Ponto3D pp4, Ponto3D pp5, Ponto3D pp6, Ponto3D pp7, Ponto3D pp8):
p1(pp1), p2(pp2), p3(pp3), p4(pp4), p5(pp5), p6(pp6), p7(pp7), p8(pp8){

    points = {p1, p2, p3, p4, p5, p6, p7, p8};
    setHeight();
    setWidth();
    setDepth();
};

Box::Box(){};

Box::~Box(){};

void Box::setHeight(){
    Ponto3D base = p1;
    Ponto3D upper = p5;
    height = sqrt(pow((base.get_x() - upper.get_x()), 2) + pow((base.get_y() - upper.get_y()),2) + pow((base.get_z() - upper.get_z()),2));
};

void Box::setWidth(){
    Ponto3D left = p1;
    Ponto3D right = p2;
    width = sqrt(pow((left.get_x() - right.get_x()), 2) + pow((left.get_y() - right.get_y()),2) + pow((left.get_z() - right.get_z()),2));
};

void Box::setDepth(){
    Ponto3D front = p1;
    Ponto3D back = p4;
    depth = sqrt(pow((front.get_x() - back.get_x()), 2) + pow((front.get_y() - back.get_y()),2) + pow((front.get_z() - back.get_z()),2));
};
 
inline double Box::getHeight() const {return height;}
inline double Box::getWidth() const{return width;};
inline double Box::getDepth() const{return depth;};

double Box::area(){
   return 2*getHeight()*getWidth() + 2*getHeight()*getDepth() + 2*getDepth()*getWidth();
};
double Box::volume(){
    return getDepth()*getWidth()*getHeight();
};



