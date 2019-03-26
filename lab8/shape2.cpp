#include <iostream>

using namespace std;

class Cube {
public:
    Cube(){
        setL(0);
    }
    
    Cube(double in_l){
        setL(in_l);
    }
    
    double getL(){
        return L;
    }
    
    void setL(double in_l){
        L = in_l;
    }
    
    void display(){
        cout << "Cube Parameters: " << endl;
        cout << "Edge length: " << getL() << endl;
        cout << "Surface Area: " << getSurfaceArea() << endl;
        cout << "Volume: " << getVolume() << endl << endl;
    }
    
private:
    double getSurfaceArea(){
        return 6*L*L;
    }
    
    double getVolume(){
        return L*L*L;
    }
    
    double L;
    
};

int main(){
    
    Cube cube1;
    cube1.display();
    
    Cube cube2(2);
    cube2.display();
    
    cube2.setL(3);
    cube2.display();
    
    return 0;
}

