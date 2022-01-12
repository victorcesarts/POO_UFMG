#ifndef PONTO3D_HPP
#define PONTO3D_HPP
#include "Ponto2D.hpp"
class Ponto3D : public Ponto2D{

    private:
        double z;

    public:
        Ponto3D(double xx = 0, double yy = 0, double zz=0);
        ~Ponto3D();
        
        Ponto3D& operator= (const Ponto2D &p);
        friend ostream& operator<< (ostream &op, const Ponto3D &p);  
        
        void set(double nx = 0, double ny = 0, double nz=0);
        double get_z() const;

              
};    
#endif
