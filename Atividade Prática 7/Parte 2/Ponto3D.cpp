#include "Ponto3D.hpp"

Ponto3D::Ponto3D(double xx, double yy, double zz): Ponto2D(xx, yy), z(zz){}
Ponto3D::~Ponto3D(){}

void Ponto3D::set(double nx, double ny, double nz){
    this -> Ponto2D::set(nx, ny);
    this -> z = nz;
}

inline double Ponto3D::get_z() const {return z;}

Ponto3D& Ponto3D::operator=(const Ponto2D &p){
    this -> set(Ponto2D::get_x(), Ponto2D::get_y());
    return *this;
}

ostream& operator<< (ostream &op, const Ponto3D &p){
    op << p.get_x() << ", " << p.get_y() << ", " << p.get_z();
    return op;
}

