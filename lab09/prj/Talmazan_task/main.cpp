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

    wcout << L"\n Уведіть силу вітру: ";
    cin >> input;

    while (input < 0){

        wcout << L"\n Помилка....Уведіть силу вітру ще раз: ";
        cin >> input;
    }

    wcout << L"\n Сила вітру у м/с - " << wind_speed(input) << "\n";
    wcout << L"\n Бал Бофорта - " << beaufort_point(input) << "\n";
}


void function9_2(){

    for(int i = 0; i < 7; i++){

        while(true){

            wcout << L"\n Введiть середні температурні показники повітря (вiд -100 до 100) за " << i + 1 << L" день: ";

            if(!scanf("%f", &tem_arr[i])){

                scanf("%*[^\n]");
                wcout << L"\n Помилка....Будь ласка введіть число.\n";
            }

            if(tem_arr[i] >= -100 && tem_arr[i] <= 100){

                break;

            }else{

                wcout << L"\n Помилка....Таких середніх температурних показників повiтря не iснує.";
                wcout << L"\n Будь ласка спробуйте ще раз.\n";
            }
        }
    }

    mid_tem_week(tem_arr, 7, &mid_temperature_celsius, &mid_temperature_farengates);

    wcout << L"\n Середньотижнева температура за шкалою Цельсія - " << mid_temperature_celsius << "\n";
    wcout << L"\n Середньотижнева температура за шкалою Фаренгейта - " << mid_temperature_farengates << "\n";
}


void function9_3(){

    while(true){

        wcout << L"\n Введiть цiле число в інтервалі вiд 0 до 70700: ";

        if(!scanf("%d", &N)){

            scanf("%*[^\n]");
            wcout << L"\n Помилка....Будь ласка введіть число.\n";

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
        wcout << L"\n Для виклику функції s_calculation натисніть \"q\", Для виклику функції до задачі 9.1 натисніть \"e\"\n";
        wcout << L"\n Для виклику функції до задачі 9.2 натисніть \"r\", Для виклику функції до задачі 9.3 натисніть \"t\"\n\n";
        cin >> input;

        if (input == 'q' || input == 'Q') {

            function8_1();

            wcout << L"\n\n Для того, щоб вийти натисніть \"y\", \"Y\" або \"H\": " << "\n";
            cin >> input;

        }else if (input == 'e' || input == 'E'){

            function9_1();

            wcout << L"\n\n Для того, щоб вийти натисніть \"y\", \"Y\" або \"H\": " << "\n";
            cin >> input;

        }else if (input == 'r' || input == 'R'){

            function9_2();

            wcout << L"\n\n Для того, щоб вийти натисніть \"y\", \"Y\" або \"H\": " << "\n";
            cin >> input;

        }else if (input == 't' || input == 'T'){

            function9_3();

            wcout << L"\n\n Для того, щоб вийти натисніть \"y\", \"Y\" або \"H\": " << "\n";
            cin >> input;

        }else if (input != 'y' && input != 'Y' && input != 'h' && input != 'H'){

            Beep(417, 500);
            wcout << L"\n Ви ввели невірний символ" << "\n";
        }

    }while (input != 'y' && input != 'Y' && input != 'h' && input != 'H');

    system("pause");

    return 0;
}
