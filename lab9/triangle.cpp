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
    
    bool operator== (Point &P){
        if(x == P.x &&
           y == P.y){
            return true;
        }
        else{return false;}
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




// Triangle Class:
class Triangle {
  public:
    // cin implementation for Triangle class
    friend istream &operator>>( istream  &input, Triangle &T ) {
        input >> T.P1 >> T.P2 >> T.P3;
        return input;
    }
    
    // cout implementation for Point class
    friend ostream & operator<<( ostream &output, Triangle &T ){
        //output << "This is " << P.x << " y: " << P.y;
        
        T.settingupcoordinatecuzusingthefullfunctionistoodamnlong();
        T.sidelength();
        
        output << "This is ";
        if (T.istriangle()){
            output << "a ";
        }
        else{
            output << "not a ";
        }
        output << "triangle." << endl;
        
        //Testing the perimeter
        output << "The perimeter of the triangle is: " << T.perimeter() << endl;
        
        //Testing the area
        output << "The area of the triangle is: " << T.area() << endl;
        
        //Testing if equlateral
        if (T.isequilateral()){
            output << "It is a equilateral triangle" << endl;
        }
        else{
            output << "That's not a equilateral triangle" << endl;
        }
        return output;
    }
        
    bool operator== (Triangle &T){
        if(P1 == T.P1 &&
           P2 == T.P2 &&
           P3 == T.P3
           ){
            return true;
        }
        else{ return false;}
    }
    
    
    Triangle(){
        P1.setCoordinates(0,0);
        P2.setCoordinates(0,0);
        P3.setCoordinates(0,0);
    }
    
    Triangle(double int_x1, double int_y1, double int_x2, double int_y2, double int_x3, double int_y3){
        P1.setCoordinates(int_x1, int_y1);
        P2.setCoordinates(int_x2, int_y2);
        P3.setCoordinates(int_x3, int_y3);
    }
    
    void set3pointsCoordinates(double int_x1, double int_y1, double int_x2, double int_y2, double int_x3, double int_y3){
        P1.setCoordinates(int_x1, int_y1);
        P2.setCoordinates(int_x2, int_y2);
        P3.setCoordinates(int_x3, int_y3);
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
    
    void settingupcoordinatecuzusingthefullfunctionistoodamnlong(){
        x1 = P1.getX();
        y1 = P1.getY();
        x2 = P2.getX();
        y2 = P2.getY();
        x3 = P3.getX();
        y3 = P3.getY();
    }
    
    bool istriangle(){
        return !(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) == 0);
    }
    
    void sidelength(){
        side1 = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        side2 = sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
        side3 = sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
        }
    
    double perimeter(){
        double p = (side1 + side2 + side3)/2;
        return p;
    }
    
    double area(){
        double a = perimeter() * (perimeter() - side1) * (perimeter() - side2);
        return sqrt(a);
    }
    
    double isequilateral(){
        return ((side1 == side2) && (side2 == side3) && (side3 == side1));
    }
    
    
private:
    Point P1, P2, P3;
    double x1, y1, x2, y2, x3, y3;
    double side1, side2, side3;
};


int main(){
    Triangle triangle1;
    Triangle triangle2;
    
    cin >> triangle2;
    
    cout<< triangle2.getP1()<<endl;
    cout<< triangle2.getP2()<<endl;
    cout<< triangle2.getP3()<<endl;

    cout << triangle2 << endl;
    cout << (triangle1 == triangle2) << endl;
    
    return 0;
}
