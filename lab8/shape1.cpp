#include <iostream>

const double pi = 3.14159265358979323846;

using namespace std;

class Sphere {
public:
    Sphere(){
        setR(0);
    }
    
    Sphere(double in_r){
        setR(in_r);
    }
    
    double getR(){
        return R;
    }
    
    void setR(double in_r){
        R = in_r;
    }
    
    void display(){
        cout << "Sphere Parameters: " << endl;
        cout << "Radius: " << getR() << endl;
        cout << "Surface Area: " << getSurfaceArea() << endl;
        cout << "Volume: " << getVolume() << endl << endl;
    }
    
private:
    double getSurfaceArea(){
        return 4*pi*R*R;
    }
    
    double getVolume(){
        return 4/3*pi*R*R*R;
    }
    
    double R;
    
};

int main(){
    
    Sphere sphere1;
    sphere1.display();
    
    Sphere sphere2(2);
    sphere2.display();
    
    sphere2.setR(3);
    sphere2.display();
    
    return 0;
}
