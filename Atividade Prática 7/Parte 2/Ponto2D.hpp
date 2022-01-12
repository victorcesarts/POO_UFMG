#ifndef PONTO2D_HPP
#define PONTO2D_HPP
#include<iostream> 
using namespace std;

class Ponto2D{
     private:                
        double x;
        double y;

     public:
        Ponto2D(int xx = 0.0, int yy = 0.0);
        ~Ponto2D();

        friend ostream& operator<< (ostream &op, const Ponto2D &p);
        Ponto2D& operator= (const Ponto2D &p);

        double get_x() const;
        double get_y() const;
        void set (double nx, double ny);
        
   
};

#endif