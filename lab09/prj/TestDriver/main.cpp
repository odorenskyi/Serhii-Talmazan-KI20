#include <iostream>
#include "ModulesTalmazan.h"

using namespace std;

int main()
{
    cout << "\n s_calculation function: \n\n";

    double x[] = {2,  3,    4,   5,   6,    7,   2.5,  3.6,  4.2,  5.5};
    double y[] = {1, 3.5, -3.5, 2.2, 3.1,  4.2, -4.2, -6.3, -0.5, -1.4};
    double z[] = {2, 1.5, 0.99, 2.6, 0.8, -1.7, -5.4, -6.8, -8.3, -8.8};
    double S[] = {2.27, 141.86, 143.26, 6120.29, 229.22, 945996.02, 2449.43, 749304.13, 392.39, 996226.44};

    for(int i = 0; i < 10; i++){

        if(s_calculation(x[i], y[i], z[i]) == S[i]){

            cout << " Passed!" << endl;
        }

        if(s_calculation(x[i], y[i], z[i]) != S[i]){

            cout << " Failed!" << endl;
        }
    }


    cout << "\n beaufort_point function: \n\n";

    double input[] = {0.2, 1.3, 2.5, 4.4, 7.8, 9.7, 12.3, 15.6, 18.8, 23.3, 27.1, 31.7, 32.8};

    double expected1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    for(int i = 0; i < 12; i++){

        if(beaufort_point(input[i]) == expected1[i]){

            cout << " Passed!" << endl;
        }

        if(beaufort_point(input[i]) != expected1[i]){

            cout << " Failed!" << endl;
        }
    }


    cout << "\n mid_tem_week function: \n\n";

    float tem[10][7] =
    {
        {1, 3, 4, 2, 6, 5, 5},
        {1, 4, 6, 2, 3, 5, 7},
        {5, 4, 7, 9, 8, 10, 9},
        {10, 12, 9, 11, 13, 15, 14},
        {20, 22, 19, 23, 21, 24, 22},
        {-1, 0, -2, -3, -1, -4, -6},
        {3, 1, 0, -2, -1, -3, -5},
        {-10, -9, -11, -13, -15, -14, -16},
        {29, 30, 32, 30, 31, 34, 38},
        {-20, -23, -25, -21, -21, -19, -20}
    };

    float celsius[10] = {3.57, 4, 7.43, 12, 21.57, -2.42, -0.99, -12.56, 32, -21.28};
    float farengates[10] = {38.43, 39.2, 45.37, 53.6, 70.83, 27.63, 30.2, 9.37, 89.6, -6.3};

    float mid_temperature_celsius = 0;
    float mid_temperature_farengates = 0;

    float temp_size[7];

    for(int i = 0; i < 10; i++){

        for(int j = 0; j < 10; j++){

            for(int k = 0; k < 7; k++)

                temp_size[k] = tem[i][k];

            mid_tem_week(temp_size, 7, &mid_temperature_celsius, &mid_temperature_farengates);

            if(celsius[j] == mid_temperature_celsius){

                if(farengates[j] == mid_temperature_farengates){

                    cout << " Passed!" << endl;
                }

                else{

                    cout << " Failed!" << endl;
                }
            }
        }
    }


    cout << "\n countNumber function: \n\n";

    int N[10] = {1, 100, 1000, 10000, 20000, 30000, 40000, 50000, 60000, 70700};
    int expected2[10] = {0, 4, 6, 9, 10, 8, 11, 10, 9, 11};

    for(int i = 0; i < 10; i++){

        if(zero_one_counter(N[i]) == expected2[i]){

            cout << "Passed!" << endl;

        } else {

            cout << "Failed!" << endl;
        }
    }

    system("pause");

    return 0;
}
