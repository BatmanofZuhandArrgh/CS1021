#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

// Point class
class Point {
    friend ostream & operator<<( ostream &output, const Point &P ){
        output << "x: " << P.x << " y: " << P.y;
        return output;
    }
    
    friend istream & operator>>( istream &input, Point &P ){
        input >> P.x >> P.y;
        return input;
    }
    
public:
    Point(){
        x = 0;
        y = 0;
    }
    
    Point(int in_x, int in_y){
        x = in_x;
        y = in_y;
    }
    
    // Add your functions here
    
    void setCoordinates(int in_x, int in_y){
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
    int x,y;
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
    
    /*double x1 = P1.getX();
    double x2 = P2.getX();
    double y1 = P1.getY();
    double y2 = P2.getY();*/
    
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

int main(){
    Line L1;
    cout << "L1: should have all zeros for values" << endl;
    cout << L1 << endl;
    
    Line L2(1,1,2,2);
    cout << "L2: shoulde have 5,6,7,13 as values for 2 points" << endl;
    cout << L2 << endl;
    
    cout << "Enter Two Points For Line: ";
    cout << endl;
    cin >> L1;
    cout << L1 << endl;
    
    cout <<"The slope for L2 is: " << L1.slope() << endl;
    cout <<"The length for L2 is: " << sqrt(L1.length()) << endl;
    cout <<"The y-intercept for L2 is: " << L1.y_intercept() << endl;
    
    
    if (L1.vertical_test()){
        cout << "The line is vertical" << endl;
    }
    else{
        cout << "The line is not vertical" << endl;
    }
    
    
    if (L1.horizonal_test()){
        cout << "The line is horizontal" << endl;
    }
    else{
        cout << "The line is not horizontal" << endl;
    }
    
    if (L1.parallel_test(L2)){
        cout << "L1 is parallel to L2" << endl;
    }
    else { cout << "L1 isn't parallel to L2" << endl;}
    
    
    
    
    return 0;
}
