#define _UNICODE
#include <iostream>
#include <sstream>
#include <tchar.h>
#include <string>
#include <memory>
#include <cctype>
#include <cstring>
using namespace std;

bool check_polindrom(wstring word)
{
    int len = word.length();
    for (int i = 0; i < len / 2; ++i)
    {
        if (word[i] != word[len - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");

    _TCHAR sizebuf[8] = _TEXT("a b c d");
    wcout << sizebuf << endl;
    for (int i = 0; i < 8; i++) {
        if (sizebuf[i] == ' ') {
            sizebuf[i] = '	';
        }
    }
    wcout << sizebuf << endl;

    _TCHAR buf[7] = _TEXT("1b2c3*");
    wcout << buf << endl;
    int count_symbol = 0, count_number = 0, count_letter = 0;
    for (int i = 0; i < 7; i++) {
        if (isalpha(buf[i])) {
            count_letter++;
        }
        else if (isdigit(buf[i])) {
            count_number++;
        }
        else {
            count_symbol++;
        }
    }
    cout << "Symbols: " << count_symbol << endl;
    cout << "Number: " << count_number << endl;
    cout << "Letter: " << count_letter << endl;	

    _TCHAR buf[28] = _TEXT("Hi world, my name is Danya ");
    wcout << buf << endl;
    int count_word = 0;
    for (int i = 0; i < 28; i++) {
        if (buf[i] == ' ') {
            count_word++;
        }
    }
    cout << "Amount of words: " << count_word << endl;

    wstring str;
    cout << "Enter the word: ";
    wcin >> str;
    if (check_polindrom(str)) {
        cout << "Word is polindrom.";
    }
    else {
        cout << "Word is not polindrom";
    }
    return 0;

    wstring test = _TEXT("Hi, my name is...");
    {
        unsigned int nums = NULL;
        unsigned int letts = NULL;
        unsigned int others = NULL;
        for (auto i = test.begin(); i != test.end(); i++)
            if (*i >= '0' && *i <= '9')
            {
                ++nums;
            }
            else if (*i >= 'a' && *i <= 'z' || *i >= 'A' && *i <= 'Z')
            {
                ++letts;
            }
            else
            {
                ++others;
            }
        wcout << _TEXT("Nums: ") << nums << endl;
        wcout << _TEXT("Letts: ") << letts << endl;
        wcout << _TEXT("Others: ") << others << endl;
        wcout << endl;
    }
    {
        wstringstream m_stream(test);
        istream_iterator<wstring, wchar_t> it(m_stream);
        wcout << "Words: " << distance(it, istream_iterator<wstring, wchar_t>()) << endl << endl;
    }
    {
        bool palind = true;
        for (size_t i = NULL; i < test.size() / 2; i++)
            if (test[i] != test[test.size() - i - 1])
            {
                palind = false;
                break;
            }
        wcout << "This is " << (palind ? "palindrome" : "not palindrome") << endl << endl;
    }
    {
        size_t ind;
        do
        {
            while (true)
            {
                wcout << "Enter index: ";
                wcin >> ind;
                if (!wcin.good())
                {
                    wcin.clear();
                    wcin.ignore(32767, '\n');
                }
                else break;
            }
        } while (ind >= test.size());
        test.erase(test.begin() + ind);
        wcout << test << endl;
    }
    {
        wchar_t ch;
        while (true)
        {
            wcout << "Enter char: ";
            wcin >> ch;
            if (!wcin.good())
            {
                wcin.clear();
                wcin.ignore(32767, '\n');
            }
            else break;
        }
        auto i = test.begin();
        if (*i == ch) test.erase(i);
        while (i != test.end())
        {
            if (*i == ch) test.erase(i--);
            else ++i;
        }
        wcout << test << endl;
    }
    {
        size_t ind;
        do
        {
            while (true)
            {
                wcout << "Enter index: ";
                wcin >> ind;
                if (!wcin.good())
                {
                    wcin.clear();
                    wcin.ignore(32767, '\n');
                }
                else break;
            }
        } while (ind >= test.size());
        wchar_t ch;
        while (true)
        {
            wcout << "Enter char: ";
            wcin >> ch;
            if (!wcin.good())
            {
                wcin.clear();
                wcin.ignore(32767, '\n');
            }
            else break;
        }
        test.insert(test.begin() + ind, ch);
        wcout << test << endl;
    }



}
