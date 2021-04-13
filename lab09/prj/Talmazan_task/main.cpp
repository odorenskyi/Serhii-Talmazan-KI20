#include <iostream>
#include <windows.h>
#include <clocale>
#include <wchar.h>
#include <fcntl.h>
#include <iomanip>
#include <io.h>
#include "ModulesTalmazan.h"

using namespace std;

int N;
double x, y, z, S, input;
float tem_arr[7], mid_temperature_celsius, mid_temperature_farengates;

void SoftwareDeveloper(){

    _wsetlocale(LC_ALL,L" ");
    _setmode(_fileno(stdout), _O_U8TEXT);

    wcout << (L" Талмазан Сергiй Дмитрович. ЦНТУ. 2021 рiк. ©\n");
}


void function8_1(){

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

    wcout << "\n S = " << s_calculation(x, y, z) << "\n";
}

void function9_1(){

    wcout << L"\n Уведiть силу вiтру: ";
    cin >> input;

    while (input < 0){

        wcout << L"\n Помилка....Уведiть силу вiтру ще раз: ";
        cin >> input;
    }

    wcout << L"\n Сила вiтру у м/с - " << wind_speed(input) << "\n";
    wcout << L"\n Бал Бофорта - " << beaufort_point(input) << "\n";
}


void function9_2(){

    for(int i = 0; i < 7; i++){

        while(true){

            wcout << L"\n Введiть середнi температурнi показники повiтря (вiд -100 до 100) за " << i + 1 << L" день: ";

            if(!scanf("%f", &tem_arr[i])){

                scanf("%*[^\n]");
                wcout << L"\n Помилка....Будь ласка введiть число.\n";
            }

            if(tem_arr[i] >= -100 && tem_arr[i] <= 100){

                break;

            }else{

                wcout << L"\n Помилка....Таких середнiх температурних показникiв повiтря не iснує.";
                wcout << L"\n Будь ласка спробуйте ще раз.\n";
            }
        }
    }

    mid_tem_week(tem_arr, 7, &mid_temperature_celsius, &mid_temperature_farengates);

    wcout << L"\n Середньотижнева температура за шкалою Цельсiя - " << mid_temperature_celsius << "\n";
    wcout << L"\n Середньотижнева температура за шкалою Фаренгейта - " << mid_temperature_farengates << "\n";
}


void function9_3(){

    while(true){

        wcout << L"\n Введiть цiле число в iнтервалi вiд 0 до 70700: ";

        if(!scanf("%d", &N)){

            scanf("%*[^\n]");
            wcout << L"\n Помилка....Будь ласка введiть число.\n";

        }else if(N >= 0 && N <= 70700){

            wcout << zero_one_counter(N);
            break;

        }else{

            wcout << L"\n Помилка....Будь ласка спробуйте ще раз.\n";
        }
    }
}

int main(){

    SoftwareDeveloper();

    char input = 0;

    do {
        wcout << L"\n Для виклику функцiї s_calculation натиснiть \"q\", Для виклику функцiї до задачi 9.1 натиснiть \"e\"\n";
        wcout << L"\n Для виклику функцiї до задачi 9.2 натиснiть \"r\", Для виклику функцiї до задачi 9.3 натиснiть \"t\"\n\n";
        cin >> input;

        if (input == 'q' || input == 'Q') {

            function8_1();

            wcout << L"\n\n Для того, щоб вийти натиснiть \"y\", \"Y\" або \"H\": " << "\n";
            cin >> input;

        }else if (input == 'e' || input == 'E'){

            function9_1();

            wcout << L"\n\n Для того, щоб вийти натиснiть \"y\", \"Y\" або \"H\": " << "\n";
            cin >> input;

        }else if (input == 'r' || input == 'R'){

            function9_2();

            wcout << L"\n\n Для того, щоб вийти натиснiть \"y\", \"Y\" або \"H\": " << "\n";
            cin >> input;

        }else if (input == 't' || input == 'T'){

            function9_3();

            wcout << L"\n\n Для того, щоб вийти натиснiть \"y\", \"Y\" або \"H\": " << "\n";
            cin >> input;

        }else if (input != 'y' && input != 'Y' && input != 'h' && input != 'H'){

            Beep(417, 500);
            wcout << L"\n Ви ввели невiрний символ" << "\n";
        }

    }while (input != 'y' && input != 'Y' && input != 'h' && input != 'H');

    system("pause");

    return 0;
}
