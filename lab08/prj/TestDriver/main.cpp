#include <iostream>
#include "ModulesTalmazan.h"

using namespace std;

int main()
{
    double x[] = {2,  3,    4,   5,   6,    7,   2.5,  3.6,  4.2,  5.5};
    double y[] = {1, 3.5, -3.5, 2.2, 3.1,  4.2, -4.2, -6.3, -0.5, -1.4};
    double z[] = {2, 1.5, 0.99, 2.6, 0.8, -1.7, -5.4, -6.8, -8.3, -8.8};
    double S[] = {2.27, 141.86, 143.26, 6120.29, 229.22, 945996.02, 2449.43, 749304.13, 392.39, 996226.44};

    for(int i = 0; i < 10; i++){

        if(s_calculation(x[i], y[i], z[i]) == S[i]){

            cout << "Passed!" << endl;
        }

        if(s_calculation(x[i], y[i], z[i]) != S[i]){

            cout << "Failed!" << endl;
        }
    }

    system("pause");

    return 0;
}
