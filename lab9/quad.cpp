#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

// Please complete this Point class.
// The cin/cout operators have been overloaded for you
class Point {
public:
    // cout implementation for Point class
    friend ostream & operator<<( ostream &output, const Point &P ){
        output << "x: " << P.x << " y: " << P.y;
        return output;
    }
    
    // cin implementation for Point class
    friend istream & operator>>( istream &input, Point &P ){
        input >> P.x >> P.y;
        return input;
    }
    
    bool operator==(Point &rhs) {
        return (rhs.x == x && rhs.y == y);
    }
    
    
    
    Point(){
        x = 0;
        y = 0;
    }
    
    Point(double in_x, double in_y){
        x = in_x;
        y = in_y;
    }
    
    // Add your functions here
    
    void setCoordinates(double in_x, double in_y){
        x = in_x;
        y = in_y;
    }
    
    double getX(){
        return x;
    }
    
    double getY(){
        return y;
    }
    
private:
    double x,y;
};

class Quadrilateral{
public:
    //cin overload
    friend istream &operator>>( istream  &input, Quadrilateral &Q ) {
        input >> Q.P1 >> Q.P2 >> Q.P3 >> Q.P4;
        return input;
    }
    
    //cout overload
    friend ostream & operator<<( ostream &output, Quadrilateral &Q ){
        Q.settingupcoordinatecuzusingthefullfunctionistoodamnlong();
        
        output << "This is ";
        if (Q.isquad()){
            output << "a ";
        }
        else{
            output << "not a ";
        }
        output << "quadrilateral." << endl;
        
        //Testing the area
        output << "The area of the quadrilateral is: " << Q.area() << endl;
        
        return output;
    }
    
    Quadrilateral(){
        P1.setCoordinates(0,0);
        P2.setCoordinates(1,1);
        P3.setCoordinates(2,2);
        P4.setCoordinates(3,3);
    }
    
    Quadrilateral(double int_x1, double int_y1, double int_x2, double int_y2, double int_x3, double int_y3, double int_x4, double int_y4){
        P1.setCoordinates(int_x1, int_y1);
        P2.setCoordinates(int_x2, int_y2);
        P3.setCoordinates(int_x3, int_y3);
        P4.setCoordinates(int_x4, int_y4);
    }
    
    void set4pointsCoordinates(double int_x1, double int_y1, double int_x2, double int_y2, double int_x3, double int_y3, double int_x4, double int_y4){
        P1.setCoordinates(int_x1, int_y1);
        P2.setCoordinates(int_x2, int_y2);
        P3.setCoordinates(int_x3, int_y3);
        P4.setCoordinates(int_x4, int_y4);
    }
    
    Point getP1(){
        return P1;
    }
    
    Point getP2(){
        return P2;
    }
    
    Point getP3(){
        return P3;
    }
    
    Point getP4(){
        return P4;
    }
    
    void settingupcoordinatecuzusingthefullfunctionistoodamnlong(){
        x1 = P1.getX();
        y1 = P1.getY();
        x2 = P2.getX();
        y2 = P2.getY();
        x3 = P3.getX();
        y3 = P3.getY();
        x4 = P4.getX();
        y4 = P4.getY();
    }
    
    bool isquad(){
        if  ((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) == 0) ||
             (x2*(y3-y4) + x3*(y4-y2) + x4*(y2-y3) == 0) ||
             (x1*(y3-y4) + x3*(y4-y1) + x4*(y3-y1) == 0) ||
             (x1*(y2-y4) + x2*(y4-y1) + x4*(y1-y2) == 0)){
            return false;
        }
        else{
            return true;
        }
    }
    
    double area(){
        double A = 0.5 * abs(x1*y2 + x2*y3 + x3*y4 + x4*y1 - x2*y1 - x3*y2 - x4*y3 - x1*y4);
        return A;
    }
    
private:
    Point P1, P2, P3, P4;
    double x1, x2, x3, x4, y1, y2, y3, y4;
    
};

int main(){
    Quadrilateral quad1;
    Quadrilateral quad2(1,2,3,4,5,6,7,8);
    
    cin >> quad2;
    cout << quad2;
    
    return 0;
}
