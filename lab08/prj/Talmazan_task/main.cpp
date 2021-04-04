#include <iostream>
#include <windows.h>
#include <clocale>
#include <wchar.h>
#include <fcntl.h>
#include <iomanip>
#include <io.h>
#include "ModulesTalmazan.h"

using namespace std;

char a, b;
double x, y, z, S;

void SoftwareDeveloper(){

    _wsetlocale(LC_ALL,L" ");
    _setmode(_fileno(stdout), _O_U8TEXT);

    wcout << (L" Талмазан Сергiй Дмитрович. ЦНТУ. 2021 рiк. ©\n");

}

void MyFunc(int x, int y, int z, double S){

    wcout << L"\n\n Уведiть x: ";
    cin >> x;

    while (x < 0){
            wcout << L"\n\n Уведiть x: ";
            cin >> x;
           }

    wcout << L"\n Уведiть y: ";
    cin >> y;
    wcout << L"\n Уведiть z: ";
    cin >> z;

    wcout << L"\n x у десятковiй системi = " << dec << x;
    wcout << L"\n x у шiстнадцятковiй системi = " << hex << x << "\n";

    wcout << L"\n y у десятковiй системi = " << dec << y;
    wcout << L"\n y у шiстнадцятковiй системi = " << hex << y << "\n";;

    wcout << L"\n z у десятковiй системi = " << dec << z;
    wcout << L"\n z у шiстнадцятковiй системi = " << hex << z << "\n";;

    S = s_calculation(x, y, z);
    wcout << "\n S = " << s_calculation(x, y, z) << endl;
}

void Logical_expression(char a, char b){

    wcout << L"\n Уведiть a: ";
    cin >> a;
    wcout << L"\n Уведiть b: ";
    cin >> b;

    wcout << "\n a + 7 = b: " << boolalpha << (a + 7 == b) << endl;
}

int main()
{
    SoftwareDeveloper();

    MyFunc(x,y,z,S);

    Logical_expression(a,b);

    system("pause");

    return 0;
}
