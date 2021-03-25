#include <iostream>
#include <cmath>

using namespace std;

double s_calculation(double x, double y, double z){

     const double PI = 3.141592653589793;

     double S = abs(pow(y*z,abs(x)) - y / PI - sqrt(x));

     S = int(S*100 + 0.5)/100.0;

     return S;
}
