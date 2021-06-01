#ifndef MODULESTALMAZAN_H
#define MODULESTALMAZAN_H

#include <iostream>
#include <fstream>
#include <wchar.h>
#include <io.h>
#include <fcntl.h>
#include <clocale>
#include <string>
#include <cstdlib>
#include <sstream>
#include <codecvt>
#include <ctime>
#include <bitset>
#include <cmath>

using namespace std;


void localisation(){

    setlocale(LC_ALL,"uk_UA.UTF-8");
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);
}


int validation(wstring check)
{
    if(check.length() < 1)
    {
        wcout << L"\nПомилка! Пустий файл." << endl;
        return 0;
    }
    else if(check.length() > 30)
    {
        wcout << L"\nПомилка! Занадто довге речення." << endl;
        return 0;
    }
    for(int i = 0; check[i] != '\0'; i++)
    {
        if(iswalpha(check[i]) == 0 && check[i] != '`')
        {
            wcout << L"\nПомилка! Слово мiстить невiрнi символи." << endl;
            return 0;
        }
    }
    return 1;
}


int input_symbol(char *exist_file)
{
    localisation();

    wifstream stream;
    wofstream output;
    wstring word;
    wifstream inputfile;
    wstring number;

    if (inputfile.good()){

        int number = 0;
        inputfile >> number;
    }

    stream.open(exist_file);

    if(stream.is_open()){

        stream.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
        getline(stream, number);
        stream.close();

        output.open(exist_file);
        output.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

        output << number << L"\nКiлькiсть символiв у файлi: " << number.length();
        output.close();

    }else{

        output.open(exist_file);
        output.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

        output << number << L"\nКiлькiсть символiв у файлi: " << number.length();
        output.close();
    }

    wcout << L"\nФайл був успiшно оброблений." << endl;

    return 1;
}


double s_calculation(double x, double y, double z){

    const double PI = 3.141592653589793;

    double S = abs(pow(y*z,abs(x)) - y / PI - sqrt(x));

    S = int(S*100 + 0.5)/100.0;

    return S;
}


int binary(int num){

    int bin = 0, k = 1;

    while (num){

        bin += (num % 2) * k;
        k *= 10;
        num /= 2;
    }

    return bin;
}


int task_10_2(char *exist_file){

    localisation();

    time_t cur_date = time(0);

    wofstream input2;

    input2.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    input2.open("input.txt", ios_base::app);

    input2 << L"\nДержавний Прапор України — стяг iз двох рiвновеликих горизонтальних смуг синього i жовтого кольорiв.\n\n";
    input2 << L"Великий Державний Герб України встановлюється з урахуванням малого Державного Герба України та герба \nВiйська Запорiзького законом, що приймається не менш як двома третинами \nвiд конституцiйного складу Верховної Ради України\n\n";
    input2 << L"Державний Гiмн України — ";
    input2 << L"Ще не вмерла України i слава, i воля,\n"
             "Ще нам, браття молодiї, усмiхнеться доля.\n"
             "Згинуть нашi ворiженьки, як роса на сонцi.\n"
             "Запануєм i ми, браття, у своїй сторонцi.\n"
             "Душу й тiло ми положим за нашу свободу,\n"
             "I покажем, що ми, браття, козацького роду.\n\n";

    input2 << endl << L"Дата дозапису: " << ctime(&cur_date);
    input2.close();

    wcout << L"\nФайл був успiшно оброблений." << endl;

    return 1;
}


void second_funct(){

    localisation();

    wchar_t input_file[100];
    char conv[100];

    wcout << L"\nВведiть назву вхiдного файлу з розширенням .txt" << endl;
    wcin >> input_file;
    const wchar_t * flag = input_file;
    wcstombs(conv, flag, sizeof(conv));

    task_10_2(conv);
}


int calculation(char *outputName, double x, double y, double z, double *S, int *binNum){

    localisation();

    wofstream outputFile;

    outputFile.open(outputName, ios::app);
    outputFile.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

    *binNum = binary(*binNum);
    *S = s_calculation(x, y, z);

    outputFile << L"Результат виконання s_calculation: " << *S << endl
               << L"Число b у двiйковiй системi числення: " << *binNum;

    outputFile.close();

    return 0;
}


void first_funct(){

    localisation();

    wchar_t input_file[100];
    char conv[100],conv1[100], conv2[100];

    wcin >> input_file;
    const wchar_t * flag = input_file;
    wcstombs(conv, flag, sizeof(conv));

    input_symbol(conv);
}


int search_word(char *inputName, char *outputName, int *vowelNum){

    localisation();

    wifstream inputFile;
    wofstream outputFile;
    wstring number,word,check_word,data;
    wifstream stream;
    wofstream output;

    int iter=0;
    wchar_t wstr[50] = L"";
    *vowelNum = 0;
    int vows = 0;

    wchar_t vowelSounds[] = L"АаЕеЄєиІіЇїУуЮюЯяОо";
    wchar_t words[250] = {L"Модуль,модульчик,студент,студентка,програміст,програмістка."};

    inputFile.open(inputName);
    inputFile.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    inputFile.getline(wstr, 50);
    inputFile.close();

    for(int i = 0; i < wcslen(wstr); i++){
        for(int j = 0; j < wcslen(vowelSounds); j++)
            if(wstr[i] == vowelSounds[j]) vows++;
    }

    *vowelNum = vows;

    outputFile.open(outputName);
    outputFile.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    outputFile.clear();

    outputFile << L"\nТалмазан Сергiй Дмитрович.\nЦНТУ, Кропивницький.\nУкраїна 2021 рiк." << endl;

    bool Marker = 0;
    int testRes = 0;

    if(wcsstr(words, wstr)){

        outputFile << L"Cлово " << wstr << L" присутнє в задачi." << endl;

        outputFile << number << L"\nКiлькiсть символiв мiстяться в вхiдному файлi ";

        testRes = 1;

    }else{

        outputFile << L"Cлово " << wstr << L" вiдсутнє в задачi" << endl;
        outputFile << number << L"\nКiлькiсть символiв мiстяться в вхiдному файлi ";
        testRes = 2;
    }

    outputFile.close();

    return testRes;
}


void task10_1(){

    string path_1 = "output.txt";
    string path_2 = "input.txt";
    ofstream fout;
    ifstream fin;
    char s_1;
    string s_2;
    string input;
    char c;
    int pos = 0;
    int pos2=0;
    int counter = 0;
    fout.open(path_1);
    fin.open(path_2);

    if (!fout.is_open()){

        cout << "\nПомилка вiдкриття файлу!" << endl;

    }else{

        fout << L"\nТалмазан Сергiй Дмитрович.\nЦНТУ, Кропивницький.\nУкраїна 2021 рiк." << endl;

        while(!fin.eof()){

            fin.get(s_1);
            if(s_1 == '\n')
                counter++;
        }

        fout << "\n";
        fout << "\n";
        fin.close();
        fin.open(path_2);

        while(!fin.eof()){

            fin.get(c);
            s_2.push_back(c);
            input.push_back(c);
        }

        fin.close();

        string arr[] {"програміст","модуль","студент", "студентка", "модуль", "модульне", "модульчик","програміста"};
        string arr2[] {"модуль","студент", "студентка", "модуль", "модульне", "модульчик","програміста"};

        pos = s_2.find(*arr);
        pos2 = s_2.find(*arr2);

        if(pos == -1){

            fout << "У файлi input.txt немає слiв: модуль або програміст або студент\n";
            fout << "У файлi input.txt кiлькiсть символiв";

        }else{

            fout << "У файлi input.txt є слова: модуль або програмiст або студент\n";
            fout << "У файлi input.txt кількiсть символiв";
        }
    }

    fout << "\n";
    fout.close();
    fin.close();
}

#endif // MODULESTALMAZAN_H
