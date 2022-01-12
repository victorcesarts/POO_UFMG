#include "Derived.hpp"

class Derived2: public Derived{
    private:
        int h;
    public:
        Derived2(int hh = 0): h(hh) {}

        int member(){
            value(5);
            return read();
        }
};