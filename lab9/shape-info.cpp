#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>
#include <sstream>
#define PI 3.14159265

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

        if (C.iscircle()){
            output << "The object is a circle." << endl;
            //2. Testing radius()
            output << "Radius of the circle: " <<  C.radius() << " units "<< endl;
            
            //3. Testing diameter()
            output << "Diameter of the circle: " <<  C.diameter() << " units "<< endl;
            
            //4. Testing circumference()
            output << "The circumference of the circle is: " << C.circumference() << " units "<< endl;
            
            //5. Testing area()
            output << "The area of the circle is: " << C.area() << " sq. units "<< endl;
        }
        else{
            output << "The object is not a circle." << endl;
        }

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
    
        if (T.istriangle()){
            output << "The object is a triangle."<< endl;
            //Testing the perimeter
            output << "The perimeter of the triangle is: " << T.perimeter() << " units "<< endl;
            
            //Testing the area
            output << "The area of the triangle is: " << T.area() << " sq. units "<< endl;
            
            //Testing if equlateral
            if (T.isequilateral()){
                output << "It is a equilateral triangle" << endl;
            }
            else{
                output << "The triangle is not an equilateral triangle" << endl;
            }
        }
        else{
            output << "The object is not a triangle" << endl;
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
        P2.setCoordinates(1,1);
        P3.setCoordinates(1,0);
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

        if (Q.isquad()){
            output << "The object is a Quadrilateral" << endl;
            output << "The area of the quadrilateral is: " << Q.area() << " sq. units "<< endl;
        }
        else{
            output << "The object is not a Quadrilateral" << endl;
        }

        
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
    
    void set4pointsCoordinates(double int_x1, double int_y1, double int_x2, double int_y2,
                               double int_x3, double int_y3, double int_x4, double int_y4){
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

vector<double> breakupstring(string str){
    vector<double> numdata;
    stringstream ss;     //requires sstream library included
    ss << str;
    
    while(!ss.eof()){
        double temp;
        ss >> temp;
        numdata.push_back(temp);
    }
    
    return numdata;
}


int main(){
    ifstream infile;
    infile.open("/Users/MACOS/shapes.txt");
    
    ofstream outfile;
    outfile.open("/Users/MACOS/shapes-info.txt");
    
    vector<double> numbers;
    char input;
    //double tempnum;
    string temp;
    
    //while (!infile.eof()){
    //while(getline(infile, input)) {
    //    strings.push_back(input);
    //}
    //}
    //numbers = breakupstring(input);
    
    //for (int i = 0; numbers.size(); i++){
      //  input.push_back(strings.at[i]);
    //}
    //for(int i = 0; i < numbers.size(); i++) {
    //    cout << numbers.at(i) << endl;
    //}

    while (getline(infile, temp)){
        istringstream inSS(temp);
        string space = " ";
        
        for(int i = 0; i < temp.length(); i++){
            if( temp.substr(i,1)== " " ){
                space += " ";
            }
        }
        numbers = breakupstring(temp);

        //cout << "There are " << space.length() << " numbers." << endl;
        if(space.length() == 6){
            outfile << "Sufficient coordinate input for a triangle." << endl;
            Triangle triangle;
            triangle.set3pointsCoordinates(numbers.at(0),numbers.at(1),numbers.at(2),numbers.at(3),
                                            numbers.at(4),numbers.at(5));
            outfile << triangle;
        }
        else if (space.length() == 8){
            outfile << "Sufficient coordinate input for a quadriliteral." << endl;
            Quadrilateral quad(numbers.at(0),numbers.at(1),numbers.at(2),numbers.at(3),
                               numbers.at(4),numbers.at(5),numbers.at(6),numbers.at(7));
            outfile << quad;
        }
        else if (space.length() == 4){
            outfile << "Sufficient coordinate input for a circle." << endl;
            Circle circle(numbers.at(0),  numbers.at(1),  numbers.at(2),  numbers.at(3));
            outfile << circle;
        }
        else{
            outfile << "Sufficient coordinates NOT input." << endl;
        }
        outfile << endl;
    }
    
    outfile << "Forgive me I don't know how to spell quadrililteral" << endl;
    outfile.close();
    infile.close();
    return 0;
}
