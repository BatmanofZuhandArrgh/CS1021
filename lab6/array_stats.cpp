#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <iomanip>

using namespace std;


int randnumGen(int rand_max){ //Generate random numbers till the upper limit of rand_max
    return (rand() % rand_max);
}

int frequency(vector<int> x, int y){ //Count the frequency that a number appear in a vector
    int z = 0;
        for(int j = 0; j < x.size(); ++j){
            if (y==x.at(j)){
                z = z+1;
        }
    }
    return z;
}

//Sum of the list
int sumList(vector<int> x){
    int sum = 0;
    for(int i = 0; i<x.size(); ++i){
        sum = sum + x.at(i);
    }
    return sum;
}

double meanList(vector<int> x){ //Find the average in the vector
    double mean;
    int sum = 0;
    for(int i = 0; i<x.size(); ++i){
        sum = sum + x.at(i);
    }
    mean = static_cast<double>(sum)/ (x.size()+1);
    return mean;
}

int mostfrequentnumber(vector<int> x){ //Find the number with the largest frequency in the vector
    int mode = frequency(x, 0);
    int mostfrequentnumber;
    for (int i = 0; i< x.size(); ++i){
        if (frequency(x,i)>mode){
            mode = frequency(x,i);
            mostfrequentnumber = i;
        }
    }
    return mostfrequentnumber;
}

int leastfrequentnumber(vector<int> x){ //Find the number with the smallest frequency in the vector
    int least = frequency(x, 0);
    int leastfrequentnumber;
    for (int i = 0; i< x.size(); ++i){
        if (frequency(x,i)<least){
            least = frequency(x,i);
            leastfrequentnumber = i;
        }
    }
    return leastfrequentnumber;
}

int maxList(vector<int> x){ //Find the maximum value in the vector
    int max = x.at(0);
    for(int i = 0; i<x.size(); ++i){
        if(x.at(i)>max){
            max = x.at(i);
        }
    }
    return max;
}

int minList(vector<int> x){ //Find the minimum value in the vector
    int min = x.at(0);
    for(int i = 0; i<x.size(); ++i){
        if(x.at(i)<min){
            min = x.at(i);
        }
    }
    return min;
}

void bar(vector<int> y){ //Drawing some bars
    int i, j;
        double z = maxList(y)/60;
        if(z < 1)
            z = 1;
    
        //cout << "GOT HERE 1 " << endl;
        for(i=0; i<y.size(); i++){
            //cout << "GOT HERE 2" << endl;
            cout << i << '\t' << y.at(i) << '\t';
            for (j = 0; j < (y.at(i)/z); j++)
            //cout << "GOT HERE 3" << endl;
                cout << '*';
            cout << endl;
        }
}

int main(){
    srand (time(NULL));
    cout << "Enter upper limit for this randomization: (less than 101, pls): ";
    int rand_max;
    cin >> rand_max;
    cout << endl;
    
    //Make sure randmax is valid
    while (rand_max>100 || rand_max<=0){
        cout << "Pls enter something valid plsssssssss!";
        cin >> rand_max;
        cout << endl;
    }
    
    int numofnum;
    cout << "Enter the number of numbers you want in the array: ";
    cin >> numofnum;
    cout << endl;
    
    vector<int> List;
    
    for (int i = 0; i<numofnum; ++i){
        int z  = randnumGen(rand_max+1);
        List.push_back(z);
    }
    
    vector<int> freq; //Stores frequencies
    
    for (int i = 0; i<=rand_max; ++i){ //Count the frequency of number 0 to 100 appearing in a vector
        freq.push_back(frequency(List, i));
    }
    
    cout << "Sum of the list of numbers is: "<< sumList(List) << endl;
    cout << "Mean of the list of numbers is: "<< meanList(List) << endl;
    cout << "Max of the list of numbers is: "<< maxList(List) << endl;
    cout << "Min of the list of numbers is: "<< minList(List) << endl;
    cout << "The number appears the most often on the list is: "<< mostfrequentnumber(List)<< " with " << maxList(freq) << " times." << endl;
    cout << "The number appears the least often on the list is: "<< leastfrequentnumber(List) << " with " << minList(freq) << " times." << endl;
    
    
    /*for (int i = 0; i<List.size(); ++i){
        cout << List.at(i) << endl;
    }*/
    
    cout << "Index  " << "Frequency"<< endl;
    bar(freq);
    return 0;
}
