#include "Ponto2D.hpp"

Ponto2D::Ponto2D(int xx, int yy) : x(xx), y(yy) {};
Ponto2D::~Ponto2D(){};

inline int Ponto2D::getX() const { return x;}
inline int Ponto2D::getY() const { return y;}
inline void Ponto2D::setX(int x) { this -> x = x;}
inline void Ponto2D::setY(int y) { this -> y = y;}

Ponto2D Ponto2D::operator+(const Ponto2D& p2) const{
    int sumX = 0, sumY = 0;
    sumX = this -> getX() + p2.getX();
    sumY = this -> getY() + p2.getY();
    return Ponto2D(sumX, sumY);
}

Ponto2D &Ponto2D::operator--(){
    int decrementX = this -> getX() - 1;
    int decrementY = this -> getY() - 1;
    this -> setX(decrementX);
    this -> setY(decrementY);
    return *this;
}

void Ponto2D::print() const{
    std::cout << "(x, y):" << " ("
    << this -> getX() << ", " 
    << this -> getY()  << ") " << std::endl;
}