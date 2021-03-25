#include <iostream>
#include <windows.h>
#include "ModulesTalmazan.h"

using namespace std;

char a, b;
double x, y, z, S;

void SoftwareDeveloper(){

    system("chcp 65001 > nul");

    cout << ("╔════════════════════════════════════════════╗\n");
    cout << ("║Талмазан Сергiй Дмитрович. ЦНТУ. 2021 рік. ©║\n");
    cout <<( "╠════════════════════════════════════════════╣\n");
}

void MyFunc(int x, int y, int z, double S){

    cout << "\n\n Уведіть x: ";
    cin >> x;
    cout << "\n Уведіть y: ";
    cin >> y;
    cout << "\n Уведіть z: ";
    cin >> z;

    cout << "\n x у десятковій системі = " << dec << x << endl;
    cout << " x у шістнадцятковій системі = " << hex << x << endl;

    cout << "\n y у десятковій системі = " << dec << y << endl;
    cout << " y у шістнадцятковій системі = " << hex << y << endl;

    cout << "\n z у десятковій системі = " << dec << z << endl;
    cout << " z у шістнадцятковій системі = " << hex << z << endl;

    S = s_calculation(x, y, z);
    cout << "\n S = " << s_calculation(x, y, z) << endl;
}

void Logical_expression(char a, char b){

    cout << "\n Уведіть a: ";
    cin >> a;
    cout << "\n Уведіть b: ";
    cin >> b;

    cout << "\n a + 7 = b: " << boolalpha << (a + 7 == b) << endl;
}

int main()
{
    SoftwareDeveloper();

    MyFunc(x,y,z,S);

    Logical_expression(a,b);

    system("pause");

    return 0;
}
