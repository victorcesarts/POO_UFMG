#include "Ponto2D.hpp"

Ponto2D::Ponto2D(int xx, int yy):x(xx),y(yy){};

Ponto2D::~Ponto2D(){};

inline double Ponto2D::get_x() const {return x;}
inline double Ponto2D::get_y() const {return y;}

inline void Ponto2D::set(double nx, double ny){x=nx; y=ny;}

Ponto2D& Ponto2D::operator = (const Ponto2D &p){
    this -> set(p.x, p.y);
    return *this;
}

ostream& operator<< (ostream &op, const Ponto2D &p){
    op << p.get_x() << ", " << p.get_y();
    return op;
}