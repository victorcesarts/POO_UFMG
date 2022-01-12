#include "Pager.hpp"

Pager::Pager(string s):PagerVariable(s){};
Pager::Pager(const Pager& that):PagerVariable(that.getPager()){};
Pager::~Pager(){};

inline string Pager::getPager() const{return PagerVariable;};

void Pager::setPager(string P){
    PagerVariable = P;
}

Pager& Pager::operator= (const Pager &p){
    this -> setPager(p.getPager());
    return *this;
}