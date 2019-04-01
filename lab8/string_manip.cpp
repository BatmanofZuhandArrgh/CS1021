// Please place your information here
//
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// This prototype is complete
class stringManip {
public:
    stringManip();
    stringManip(string input);
    string retrieve();
    void setString(string input);
    void chop();
    void padString(int n);
    void center(int length);
    void truncate(int n);
    void removeNonAlpha();
    void convertToUpperCase();
    void convertToLowerCase();
private:
    string tobeEdited;
};

// Not all functions are defined here

// Default Constructor
stringManip::stringManip(){
    tobeEdited = "";
}

// Overloaded Constructor
stringManip::stringManip(string in_string){
    tobeEdited = in_string;
}

// setting function
void stringManip::setString(string in_string){
    tobeEdited = in_string;
}

// retrieve function
string stringManip::retrieve(){
    return tobeEdited;
}

// 1. chop() function
void stringManip::chop(){
    for (int i = 0; i<tobeEdited.length(); i++)
        if(isspace(tobeEdited[i])){
            tobeEdited.erase(i);}
        else{
            break;
        }
    for (int i = tobeEdited.length()-1; i>=0; i--){
        if(isspace(tobeEdited[i])){
            tobeEdited.erase(i);}
        else{
            break;
        }
    }
}

// 2. padString() function
void stringManip::padString(int length){
    while (tobeEdited.size() < length) {
        tobeEdited = tobeEdited + " ";
    }
}

// 3. center() function
void stringManip::center(int length){
    int num = length - tobeEdited.length();
    for (int i = 1; i<(num/2); i++){
        tobeEdited = " " + tobeEdited + " ";
    }
    if ((num/2)%2 == 1){
        tobeEdited= tobeEdited + " ";
    }
}

// 4. truncate() function
void stringManip::truncate(int length){
    while (tobeEdited.size() > length) {
        tobeEdited.erase(tobeEdited.end()-1);
    }
}

// 5. removeNonAlpha() function
void stringManip::removeNonAlpha(){
    for(int i = 0; i< tobeEdited.length(); i++){
    if (isdigit(tobeEdited[i]) || isspace(tobeEdited[i])) {
        tobeEdited.erase(i);
    }
    }
}

// 6. convertToUpperCase() function
void stringManip::convertToUpperCase(){
    for(int i = 0; i< tobeEdited.length(); i++){
        if (islower(tobeEdited[i])) {
            tobeEdited[i] = toupper(tobeEdited[i]);
        }
    }
}

// 7. convertToLowerCase() function
void stringManip::convertToLowerCase(){
    for(int i = 0; i< tobeEdited.length(); i++){
        if (isupper(tobeEdited[i])) {
            tobeEdited[i] = tolower(tobeEdited[i]);
        }
    }
}

int main(){
    stringManip S1;
    stringManip S2("testing 123 ");
    
    // 1. Test case for chop() You should correct some of your own.
    cout << "S2 before chop(): <" << S2.retrieve() << ">" << endl;
    S2.chop();
    cout << "S2 after chop(): <" << S2.retrieve() << ">" << endl;
    cout << "Should be: <testing 123>" << endl;
    
    // 2. Test case for padString() You should correct some of your own.
    cout << "S2 before padString(20): <" << S2.retrieve() << ">" << endl;
    S2.padString(20);
    cout << "S2 after padString(20): <" << S2.retrieve() << ">" << endl;
    cout << "Should be: <testing 123       >" << endl;
    
    // 3. Test case for center() You should correct some of your own.
    cout << "S2 before center(): <" << S2.retrieve() << ">" << endl;
    S2.chop();
    S2.center(20);
    cout << "S2 after center(): <" << S2.retrieve() << ">" << endl;
    cout << "Should be:" << endl;
    
    // 4. Test case for truncate() You should correct some of your own.
    //cout << "S2 before truncate(5): <" << S2.retrieve() << ">" << endl;
    //S2.truncate(5);
    //cout << "S2 after truncate(5): <" << S2.retrieve() << ">" << endl;
    //cout << "Should be: <testi>" << endl;
    
    // 5. Test case for removeNonAlpha() You should correct some of your own.
    cout << "S2 before removeNonAlpha(): <" << S2.retrieve() << ">" << endl;
    S2.removeNonAlpha();
    cout << "S2 after removeNonAlpha(): <" << S2.retrieve() << ">" << endl;
    cout << "Should be: <testing>" << endl;
    
    // 6. Test case for convertToUpperCase() You should correct some of your own.
    cout << "S2 before convertToUpperCase(): <" << S2.retrieve() << ">" << endl;
    S2.convertToUpperCase();
    cout << "S2 after convertToUpperCase(): <" << S2.retrieve() << ">" << endl;
    cout << "Should be: " << endl;
    
    // 7. Test case for convertToLowerCase() You should correct some of your own.
    cout << "S2 before convertToLowerCase(): <" << S2.retrieve() << ">" << endl;
    S2.convertToLowerCase();
    cout << "S2 after convertToLowerCase(): <" << S2.retrieve() << ">" << endl;
    cout << "Should be: " << endl;
    
    return 0;
}
