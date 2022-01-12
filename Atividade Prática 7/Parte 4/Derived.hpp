#include "Base.hpp"
class Derived : protected Base{
        
        int j;
        public:
            Derived(int jj = 0) : j(jj) {}
            void change(int x) { 
                set(x); }
};