#include <iostream>
#include <fstream>
#include <wchar.h>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <cstdlib>
#include <sstream>
#include <codecvt>
#include <ctime>
#include <bitset>
#include <cmath>
#include <locale>
#include "modulestalmazan.h"

using namespace std;

void firsst_funct();

int checkXYZ(double num){

    wcout << L": ";

    if(!(wcin >> num)){
        wcin.clear();
        while (wcin.get() != '\n');
        wcout << L"\nВи ввели символ, введіть число." << endl;
        checkXYZ(num);
    }
    return num;
}

int main()
{
    setlocale(LC_ALL,"uk_UA.UTF-8");
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);


    ifstream inputFile;
    wifstream inFILE;
    wofstream inputFileWrite;
    wchar_t inputName[100] = L"";
    char outputName[] = "output.txt";
    wchar_t Key[2] = L"";
    wchar_t D[2] = L"D";
    wchar_t F[2] = L"F";
    int vowelNum = 0;
    char inputWord[50];

    wcout << L"|-------------------------------------------------------------------------------| " << endl;
    wcout << L"|Даний застосунок виконує операцiї над файлами, використовуючи функцiї:         | " << endl;
    wcout << L"| * search_word - шукає чи є в вхідному файлі слова з задачі та вносить до файлу| " << endl;
    wcout << L"|   iнформацiю про розробника та кiлькiсть символів у введеному реченні.        | " << endl;
    wcout << L"| * second_funct - перелік Державних символів та дата дозапису інформації.      | " << endl;
    wcout << L"| * calculation - рахує число S за формулою з лабораторної роботи №8 та пе-     | " << endl;
    wcout << L"|   реводить число binNum у двiйкову систему числення.                          | " << endl;
    wcout << L"|-------------------------------------------------------------------------------| " << endl;

    wcout << L"\nСтворіть файл input.txt та введіть його назву з розширенням .txt(Ви створюєте вхiдний файл wordfind.txt самостiйно через файловий менеджер у тецi з програмою): ";
    wcin.getline(inputName, 50);

    char ch_inputName[50] = "";
    wcstombs(ch_inputName, inputName, sizeof(ch_inputName));


    while(true){
        if(access(ch_inputName, 0) != -1){


            break;
        }
        else{
            wcout << L"\nФайл не знайдено. Можливе невiрно введенне iм'я або вiдсутнiсть файлу у тецi програми." << endl;
            wcin.getline(inputName, 50);
            wcstombs(ch_inputName, inputName, sizeof(ch_inputName));
        }
    }
    wcout << L"\nВведiть до файлу (через блокнот) слово, пiсля введення напишiть в консоль ключ \"D\"(отримання доступу до функцiй): ";
    wcin.getline(Key, 2);



    while(!wcsstr(D, Key) && !wcsstr(F, Key)){
        wcout << L"\nВи ввели невiрний ключ, спробуйте ще раз:";
        wcin >> Key;
    }
    if(wcsstr(F, Key)){
        wcout << L"\nЗастосунок завершиться пiсля натиснення Enter" << endl;
        system("pause");
        return 0;
    } else if(wcsstr(D, Key)){
        wcout << L"\nКлючi для виклику функцiй: " << endl;
        wcout << L"search_word -- W" << endl;
        wcout << L"second_funct -- S" << endl;
        wcout << L"calculation -- C" << endl;
        wcout << L"exit - E" << endl;

        while(true){

            wchar_t fKey;
            double x = 0;
            double y = 0;
            double z = 0;
            double S = 0;
            int binNum = 0;

            wcout << L"\nВведiть ключ для: ";
            wcin >> fKey;

            if(fKey == 'E')
                return 0;

            switch(fKey){

            case 'W':

                wcout << L"\nВведiть назву вхідного файлу input.txt: ";
                task10_1();
                first_funct();

                wcout << L"\nРобота с файлами була завершена, результати виконання search_word можна побачити у вихiдному файлi." << endl;

                break;

            case 'S':

                second_funct();

                wcout << L"\nРобота с файлами була завершена, результати виконання second_funct можна побачити у вихiдному файлi." << endl;

                break;

            case 'C':

                wcout << L"\nВведiть x ";
                x = checkXYZ(x);

                while (x < 0){

                    wcout << L"\n\n Введiть x: ";
                    cin >> x;
                }

                wcout << L"\nВведiть y ";
                y = checkXYZ(y);

                wcout << L"\nВведiть z ";
                z = checkXYZ(z);

                wcout << L"\nВведiть binNum ";

                binNum = checkXYZ(binNum);
                calculation(outputName, x, y, z, &S, &binNum);

                wcout << L"\nРобота с файлами була завершена, результати виконання calculation можна побачити у вихiдному файлi." << endl;

                break;

            default:

                wcout << L"\nНевiрно введений ключ" << endl;

                break;
            }
        }
    }

    return 0;
}
