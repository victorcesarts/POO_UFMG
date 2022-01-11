#include<iostream> 

class Ponto2D{
    private:

        int x, y;
    
    public:
        Ponto2D(int xx=0, int yy=0);
        ~Ponto2D(); 
        Ponto2D& operator-- ();
        Ponto2D operator+ (const Ponto2D& p2) const;

        void print() const;
        int getX() const;
        int getY() const;
        void setX (int x);
        void setY (int y);
};