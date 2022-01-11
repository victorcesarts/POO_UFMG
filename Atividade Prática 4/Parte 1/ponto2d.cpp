#include "ponto2d.hpp"
/*
Declaration of static members
*/
std::vector<int> ponto2d::idUsed;
int ponto2d::rID;

ponto2d::ponto2d(double x, double y) : _x(x), _y(y), _id(getNextID()){}

ponto2d::ponto2d(const ponto2d& p) : _x(p.getX()), _y(p.getY()), _id(getNextID()){}

/*
Using destructor to erase the correspondent object ID 
that is stored in vector "idUsed"
*/
ponto2d::~ponto2d(){
    int id = getID();
    auto it = idUsed.begin();
    for (it; it != idUsed.end(); ++it){
        if(*it == id){
            break;          
        }
    }
    idUsed.erase(it);
}

ponto2d ponto2d::operator=(const ponto2d& p2){
    this -> setX(p2.getX());
    this -> setY(p2.getY());
    return *this;
}

/*
Member function to get the unique ID and store it in the vector of already used IDs.
*/
const int ponto2d::getNextID() {
    generateID();
    idUsed.push_back(rID);
    return rID; 
}
/*
This function has a code to generate random numbers for the ID (library <random>). 
If the ID already exists (the generated ID is already in vector idUsed) than the 
function is called recursively until the generated random number hasn't been used yet. 
The function also has an exception in case someone try generating a new ID, but 
all the possible IDs have been already used.
*/
int ponto2d::generateID(){
  
    if(idUsed.size() != 1001){
        std::random_device rd; 
        std::mt19937 gen(rd()); 
        std::uniform_int_distribution<> distr(0, 1000); 
        rID = distr(gen);

        if(idUsed.empty() == true){
            return rID;
        }else{
            for (auto it = idUsed.begin(); it != idUsed.end(); ++it){
                if(*it == rID){
                    generateID();
                    break;             
                }
            }
        }
    }else
        throw std::out_of_range("You've reached the maximum number of allowed objects, the program is finishing.");
    
    return rID;
}

/*
Getters and setters inline
*/
inline double ponto2d::getX() const{return _x;}
inline double ponto2d::getY() const{return _y;}
inline int ponto2d::getID() const{return _id;}
inline void ponto2d::setX(double x) {this -> _x = x;}
inline void ponto2d::setY(double y) {this -> _y = y;}

/*
Calculating the distance from a given point and the origin
of cartesian plane (0, 0)
*/
double ponto2d::distToOrig() const{
    const double x = this -> getX();
    const double y = this -> getY();
    return sqrt(pow(x, 2) + pow(y, 2));
}

/*
Calculating the distance from a given point and another point
passed as argument (p2).
*/
double ponto2d::distTo(const ponto2d &p2){
    double x = this -> getX();
    double y = this -> getY();
    double x2 = p2.getX();
    double y2 = p2.getY();
    return sqrt(pow((x - x2), 2) + pow((y - y2), 2));
}

/*
Calculating the sum of a given point and another point
passed as argument (p2). The result of sum is used to change
the coordinates of the point that called function (this).
*/
void ponto2d::add(const ponto2d &p2){
    double sumX = p2.getX() + this -> getX();
    double sumY = p2.getY() + this -> getY();
    this -> setX(sumX);
    this -> setY(sumY);
}

/*
Calculating the sum of a given point and another point
passed as argument (p2). The result of sum is used to create 
another object of type ponto2d (p3), this oject will be used
in the overload of operator "=". 
This is necessary in order to be possible to assign the sum of objects to another object
*/
ponto2d ponto2d::sumOf(const ponto2d &p2){
    double sumX = p2.getX() + this -> getX();
    double sumY = p2.getY() + this -> getY();
    ponto2d p3(sumX, sumY);
    return p3;
}
 
/*
Just a function to print the atributes of the objects.
*/
void ponto2d::print() const{    
    std::cout << "(x, y):" << " ("
    << this -> getX() << ", " 
    << this -> getY()  << ") " << std::endl
    << "The ID of the point is: "
    << this -> getID() << std::endl;
}