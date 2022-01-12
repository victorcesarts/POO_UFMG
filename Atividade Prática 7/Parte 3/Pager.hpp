#include <iostream>
using namespace std;
class Pager{
    private:
    string PagerVariable;
public:
    Pager(string);
    Pager(const Pager &that);
    ~Pager();
    
    string getPager() const;
    void setPager(string);
    Pager& operator= (const Pager &p);
};