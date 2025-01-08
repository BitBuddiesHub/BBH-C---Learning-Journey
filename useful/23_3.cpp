#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int *tmp = 0;
    tmp = a;
    a = b;
    b = tmp;
}

void card_generate(int card[])
{
    srand(time(0));
    for (int i = 1; i <= 5; i++)
    {
        card[i] = (rand() % 13 + 2) * 10 + (rand() % 4);
    }
}

void sort_card(int card[])
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = i; j <= 5; j++)
        {
            if ((card[i] / 10) > (card[j] / 10))
            {
                swap(card[i], card[j]);
            }
            else if ((card[i] / 10) == (card[j] / 10))
            {
                if ((card[i] % 10) > (card[j] % 10))
                {
                    swap(card[i], card[j]);
                }
            }
        }
    }
}

void unpack(int card[])
{
    for (int i = 1; i <= 5; i++)
    {
        int num = card[i] / 10;
        int color = card[i] % 10;
        switch (num)
        {
        case 11:
            cout << "J " << "of" << " ";
            break;
        case 12:
            cout << "Q " << "of" << " ";
            break;
        case 13:
            cout << "K " << "of" << " ";
            break;
        case 14:
            cout << "A " << "of" << " ";
            break;
        default:
            cout << num << " " << "of" << " ";
        }

        switch (color)
        {
        case 0:
            cout << "Diamonds" << endl;
            break;
        case 1:
            cout << "Clubs" << endl;
            break;
        case 2:
            cout << "Hearts" << endl;
            break;
        case 3:
            cout << "Spades" << endl;
            break;
        default:
            break;
        }
    }
}

int main()
{
    int card[6] = {0};
    card_generate(card);
    sort_card(card);
    unpack(card);
    return 0;
}
