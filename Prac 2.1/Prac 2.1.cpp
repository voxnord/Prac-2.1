#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include <vector>

using namespace std;

string snull{ "   " };



void n1(string str)
{
    string lword;

    int lspace = str.find_last_of(' ');

    if (lspace == string::npos) // Проверяется, не существуют ли пробелы
    {
        lword = str; // Если да, то всё предложение является "последним" словом
    }
    else // Если существуют, то с позиции последнего пробела(+1 для начала с первой буквы слова) извлекается строка
    {
        lword = str.substr(lspace + 1);
    }

    int ch_count{ 0 };
    
    for (size_t i = 0; i < lword.size(); i++)
    {
        if (lword[i] == 'k') ch_count += 1;
    }

    cout << snull << "В последнем слове \"" << lword << "\" строки \"" << str << "\" содержится букв k = " << ch_count << endl;
}

string n2(string str)
{
    stringstream ss(str);
    string word, result;
    vector<string> words;
    
    while (ss >> word)
    {
        words.push_back(word);
    }
    string lword = words.back();
    lword.pop_back();

    for (size_t i = 0; i < words.size() - 1; ++i)
    {
        result += words[i].substr(0, words[i].length() - 1) + ' ';
    }

    result = result.substr(0, result.length() - 1) + '.';

    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    SetConsoleTitle(L"Семестр 2. Практическая работа 1");
     
    cout << "Вариант 10" << endl;

    cout << endl << "1) "; cout << "Введите любую строку(латинскими буквами): ";
    string first_str; getline(cin, first_str); n1(first_str);

    string second_str = "Tempus fugit sed memoria manet.";
    cout << endl << "2) " << "Предложение до преобразования" << second_str << endl;
    cout << snull << "Предложение после преобразования: " << n2(second_str) << endl;

    return 0;
}
