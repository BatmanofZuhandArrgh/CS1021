#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#define PI 3.14159265

//Point Class: line 16
//Line Class: line 66
//Circle Class: line 163

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


//Line class
class Line {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Line &L ){
        output << "Point 1: " << L.P1 << endl << "Point 2: " << L.P2;
        return output;
    }
    
    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Line &L ){
        input >> L.P1 >> L.P2;
        return input;
    }
    
public:
    // Constructors
    Line(){
        P1.setCoordinates(0,0);
        P2.setCoordinates(0,0);
    }
    
    Line(int int_x1, int int_y1, int int_x2, int int_y2){
        P1.setCoordinates(int_x1, int_y1);
        P2.setCoordinates(int_x2, int_y2);
    }
    
    void set2pointsCoordinates(int int_x1, int int_y1, int int_x2, int int_y2){
        P1.setCoordinates(int_x1, int_y1);
        P2.setCoordinates(int_x2, int_y2);
    }
    
    Point getP1(){
        return P1;
    }
    
    Point getP2(){
        return P2;
    }
    
    
    //Calculate slope
    double slope(){
        double s;
        if(P2.getX()==P1.getX()){
            cout << "This line is vertical. Slope is infinite!" << endl;
            s = -999999;
            return s;
        }
        else{
            s = (double(P2.getY()) - double(P1.getY()))/(double(P2.getX()) - double(P1.getX()));}
        return s;
    }
    
    //Calculate length
    double length(){
        double l;
        l = (P2.getX()-P1.getX())*(P2.getX()-P1.getX()) + (P2.getY()-P1.getY())*(P2.getY()-P1.getY());
        return l;
    }
    
    double y_intercept(){
        double b;
        if (slope() == -999999){
            b = -999999;
        }
        else{
            b = P2.getY() - slope() * P2.getX();}
        return b;
    }
    
    bool horizonal_test(){
        if (P1.getY() == P2.getY()){
            return true;
        }
        else{return false;}
    }
    
    bool vertical_test(){
        if(double(P2.getX()) - double(P1.getX()) == 0){
            return true;
        }
        else{return false;}
    }
    
    bool parallel_test(Line x){
        if ((x.vertical_test() == true) && (vertical_test() == true)){
            return true;}
        else{
            return (slope() == x.slope());
        }
    }
    
private:
    Point P1, P2;
};


//Circle class
class Circle {
public:
    // cin implementation for Triangle class
    friend istream &operator>>( istream  &input, Circle &C ) {
        input >> C.O >> C.P;
        return input;
    }
    
    // cout implementation for Point class
    friend ostream & operator<<( ostream &output, Circle &C ){
        // 1. Testing istriangle()
        output << "This is ";
        if (C.iscircle()){
            output << "a ";
        }
        else{
            output << "not a ";
        }
        output << "circle." << endl;
        
        //2. Testing radius()
        output << "Radius of the circle: " <<  C.radius() << endl;
        
        //3. Testing diameter()
        output << "Diameter of the circle: " <<  C.diameter() << endl;
        
        //4. Testing circumference()
        output << "The circumference of the circle is: " << C.circumference() << endl;
        
        //5. Testing area()
        output << "The area of the circle is: " << C.area() << endl;
        return output;
    }
    
    bool operator == (Circle &C){
        return O == C.O && P == C.P;}

    // Constructors
    Circle(){
        O.setCoordinates(0,0);
        P.setCoordinates(1,1);
    }
    
    Circle(int int_x1, int int_y1, int int_x2, int int_y2){
        O.setCoordinates(int_x1, int_y1);
        P.setCoordinates(int_x2, int_y2);
    }
    
    void set2pointsCoordinates(int int_x1, int int_y1, int int_x2, int int_y2){
        O.setCoordinates(int_x1, int_y1);
        P.setCoordinates(int_x2, int_y2);
    }
    
    Point getO(){
        return O;
    }
    
    Point getP(){
        return P;
    }
    
    bool iscircle(){
        return !(O==P);
    }
    
    double radius(){
        Line radiusline(O.getX(),O.getY(), P.getX(), P.getX());
        double l =  sqrt(radiusline.length());
        return l;
    }
    
    double diameter(){
        return 2* radius();
    }
    
    double area(){
        return radius() * radius() * PI;
    }
    
    double circumference(){
        return diameter() * PI;
    }
    
private:
    Point O, P;
};


int main(){
    Circle circle1;
    Circle circle2(1,3,4,5);

    cin>>circle2;
    cout << circle2 <<endl;
    
    cout << (circle1 == circle2) << endl;
    
    
    return 0;
}
