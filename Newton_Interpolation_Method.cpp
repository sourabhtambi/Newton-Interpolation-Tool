#include<iostream>
#include<vector>
using namespace std;

vector <double> DividedDifferences(vector<double>&x ,vector<double>&y ) {
    int n = x.size(); // Calculating the size of vector input 
    vector<double> coff = y ; // creating a new vector and assining the values same as y 

    for(int i = 1 ; i <n ; i++){
        for (int j = n -1 ; j >= i ; j--){
           coff[j] =  (coff[j] - coff[j - 1])/( x[j] - x[j-i]);  // every time changing values in y /coff reverse way to avoid over writting
        }
    }
    return coff ; // output the new coff as first values in every table of divided diffeence 
}
double NewtonInterpolation( vector<double> &x , vector<double> &coff , double value){
    int n = x.size();
    double result = coff[0];
    double a = 1.0;
    for(int i = 1; i < n; i++) {
        a *= (value - x[i - 1]);  
        result += coff[i] * a;
    }

    return result;

}
int main(){
    // Example data: y = x^2
    vector<double> x = {1, 2, 3, 4 };
    vector<double> y = {1, 4, 9, 16};

    // Compute divided difference coefficients
    vector<double> coff = DividedDifferences(x, y);

   
    cout << "Divided Difference Coefficients:\n";
    int m = coff.size();
    for (int i = 0; i < m; i++) {
        cout << "a[" << i << "] = " << coff[i] << endl; //Checking the coefficients 
    } 

    // value for which to calculate 
    double value = 5;
    double result = NewtonInterpolation(x, coff, value);

    cout << "Interpolated value at x = " << value << " is: " << result << endl;

    return 0;
}