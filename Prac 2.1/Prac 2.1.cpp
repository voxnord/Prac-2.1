#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string TFstring(string inp) // Первое задание
{
    string res;
        
    if (inp.find('*') == string::npos) 
    {
        return "Строка не была преобразована из-за отсутствия символа '*': " + inp ;
    }
    
    for (char ch : inp)
    {
        if (ch != '*') 
        {
            res += ch;
            res += ch;
        }
    }
    return  "Текст после форматирования: " + res;
}

string LastToFirst(string word) 
{
    if (word.length() < 2) 
        return word; // Если слово меньше 2 букв, возвращаем его как есть
    return word.back() + word.substr(0, word.length() - 1);
}

string TFwords(string inp) {
    istringstream iss(inp);
    vector<string> words;
    string word;

    // Читаем все слова до последнего
    while (iss >> word) 
    {
        words.push_back(word);
    }

    // Последнее слово без точки
    string lastWord = words.back();
    lastWord.pop_back();

    string res;

    // Выводим обработанные слова кроме последнего
    for (size_t i = 0; i < words.size() - 1; ++i) 
    {
        res += LastToFirst(words[i]) + ' ';
    }
    // Обработка последнего слова
    res += LastToFirst(lastWord) + ".";

    return res;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Практика: 1 \r\nВариант: 8\r\n\r\n";

    string inp;

    cout << "Задание 1\r\n";
    cout << "Введите текст: ";
    getline(cin, inp);

    string TFs = TFstring(inp);
    cout << TFs << endl;

    cout << "Задание 2\r\n";
    cout << "Введите последовательность слов: ";
    getline(cin, inp);

    string TFw = TFwords(inp);
    cout << "Преобразованная последовательность: " << TFw << endl;


}