#include <iostream>
using namespace std;

int isalpha(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

int isnum(char ch)
{
    return (ch >= '0' && ch <= '9');
}

int isspace(char ch)
{
    return (ch == ' ');
}

int main()
{
    char ch_1, ch_2;
    int letters = 0, space = 0, digit = 0, others = 0;
    int lines = 0, words = 0, chars = 0;
    bool in_word = false;

    cout << "Please input some characters (Ctrl+D to stop):" << endl;

    while ((ch_1 = cin.get()) != EOF)
    {
        chars++;

        if (isalpha(ch_1))
        {
            letters++;
        }
        else if (isnum(ch_1))
        {
            digit++;
        }
        else if (isspace(ch_1))
        {
            space++;
        }
        else
        {
            others++;
        }

        if (!isspace(ch_1) && !in_word)
        {
            in_word = true;
            words++;
        }
        else if (isspace(ch_1))
        {
            in_word = false;
        }

        if (ch_1 == '\n')
        {
            lines++;
        }
    }

    cout << "letters=" << letters << endl
         << "spaces=" << space << endl
         << "digits=" << digit << endl
         << "others=" << others << endl
         << "lines=" << lines << endl
         << "words=" << words << endl
         << "characters=" << chars << endl;

    return 0;
}
