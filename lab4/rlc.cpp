#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#define PI 3.14159265

using namespace std;

const double TOLERANCE = .001;

/*Declare and initialize variables to represent any or all of the following:
double R, L, C, A, , f, , Eo, T, Δt;
int nstep; // #timesteps/cycle */

double R; //Resistor
double L; //Inductor
double C; //Capacitor
const double PA = -67.029;//Phase Angle;
double E0;// Applied voltage amplitude
double f; // Frequency
const double Lf = 100 * PI; //Line frequency (rad/sec)
const double T  = 0.02;//AC Period (sec)

double AppliedVoltage(double t){
    double V;
    V = E0 * sin (Lf * t * 180 / PI);
    return V;
}

double CurrentAmplitude(double t){
    double A;
    A = E0 * Lf / sqrt(pow(L*Lf*Lf-1/C,2)+R*R*Lf*Lf);
    return A;
}

double inside(double t){
    return (Lf*t*180/PI - PA);
}

double TotalCurrent (double t){
    double It;
    It = CurrentAmplitude(t) * sin (inside(t));
    return It;
}

double VResistor(double t){
    double Vr;
    Vr = CurrentAmplitude(t) * R * sin (inside(t));
    return Vr;
}

double VInductor(double t){
    double Vi;
    Vi = CurrentAmplitude(t) * L * Lf * cos (inside(t));
    return Vi;
}

double VCapacitor(double t){
    double Vc;
    Vc = -CurrentAmplitude(t) * cos (inside(t)) /(C*Lf);
    return Vc;
}

double VTotal(double t){
    double Vt;
    Vt = VCapacitor(t) + VInductor(t) + VResistor(t);
    return Vt;
}

double VDiff(double t){
    double Vd;
    Vd = VTotal(t) - (VCapacitor(t) + VInductor(t) + VResistor(t));
    return Vd;
}

int main(){
    cout << "Applied Voltage Amplitude: " <<endl;
    cin >> E0;
    cout << endl;
    cout << "Frequency: " << endl;
    cin >> f;
    cout << endl;
    cout << "Resistor Value: "<<endl;
    cin >> R;
    cout << endl;
    cout << "Inductor Value: "<<endl;
    cin >> L;
    cout << endl;
    cout << "Capacitor Value: "<<endl;
    cin >> C;
    cout << endl;
    
    
    double t = 0;
    double V = AppliedVoltage(t);
    double I = CurrentAmplitude(t);
    double VR = VResistor(t);
    double VL = VInductor(t);
    double VC = VCapacitor(t);
    double VT = VTotal(t);
    double VD = VDiff(t);
    double nstep = 0.001;
    
    cout << "Current Amplitude: " << CurrentAmplitude(t) <<endl;
    cout << "Phase Angle: " << PA << endl;
    
    cout << "Iter. Time     AV     I     VR     VL     VC     VT     Vdiff" <<endl;
    for (int i = 0; i <= 20; ++i){
        V = AppliedVoltage(t);
        I = CurrentAmplitude(t);
        VR = VResistor(t);
        VL = VInductor(t);
        VC = VCapacitor(t);
        VT = VTotal(t);
        VD = VDiff(t);
        cout << i << '\t' << t << '\t' << V << '\t' << I << '\t' << VR << '\t' << VL << '\t' << VC << '\t' << VT << '\t' << VD << endl;
        t = t + nstep;
    }
    return 0;
    }
