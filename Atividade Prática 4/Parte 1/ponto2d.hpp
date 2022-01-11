#ifndef PONTO_2D
#define PONTO_2D
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

class ponto2d{

    private:
        static int rID;
        static std::vector<int> idUsed;
        const int _id;
        double _x;
        double _y;
        const int getNextID();
        int generateID();

    public:
        ponto2d(double x = 0.0, double y = 0.0);
        ponto2d(const ponto2d& p);
        ~ponto2d();
        
        ponto2d operator=(const ponto2d &p2);

        double getX() const;
        double getY() const;
        int getID() const;

        void setX(double x);
        void setY(double y);

        double distToOrig() const;
        double distTo(const ponto2d &p2);
        ponto2d sumOf(const ponto2d &p2);
        void add(const ponto2d &p2);
        void print() const;

};
#endif