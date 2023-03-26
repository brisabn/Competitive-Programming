#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>

using namespace std;

char um[3][2] = {{'*', '.'},
                 {'.', '.'},
                 {'.', '.'}},
     dois[3][2] = {{'*', '.'},
                   {'*', '.'},
                   {'.', '.'}},
     tres[3][2] = {{'*', '*'},
                   {'.', '.'},
                   {'.', '.'}},
     quatro[3][2] = {{'*', '*'},
                     {'.', '*'},
                     {'.', '.'}},
     cinco[3][2] = {{'*', '.'},
                    {'.', '*'},
                    {'.', '.'}},
     seis[3][2] = {{'*', '*'},
                   {'*', '.'},
                   {'.', '.'}},
     sete[3][2] = {{'*', '*'},
                   {'*', '*'},
                   {'.', '.'}},
     oito[3][2] = {{'*', '.'},
                   {'*', '*'},
                   {'.', '.'}},
     nove[3][2] = {{'.', '*'},
                   {'*', '.'},
                   {'.', '.'}},
     zero[3][2] = {{'.', '*'},
                   {'*', '*'},
                   {'.', '.'}};

void qual_braille(int n, int j, int i)
{
    if (n == 0)
        cout << zero[j][i];
    if (n == 1)
        cout << um[j][i];
    if (n == 2)
        cout << dois[j][i];
    if (n == 3)
        cout << tres[j][i];
    if (n == 4)
        cout << quatro[j][i];
    if (n == 5)
        cout << cinco[j][i];
    if (n == 6)
        cout << seis[j][i];
    if (n == 7)
        cout << sete[j][i];
    if (n == 8)
        cout << oito[j][i];
    if (n == 9)
        cout << nove[j][i];
}

void qual_numero(const char *numero0, const char *numero1, int i)
{
    if (numero0[i] == um[0][0] &&
        numero1[i] == um[1][0] &&
        numero0[i + 1] == um[0][1] &&
        numero1[i + 1] == um[1][1])
    {
        cout << 1;
    }

    if (numero0[i] == dois[0][0] &&
        numero1[i] == dois[1][0] &&
        numero0[i + 1] == dois[0][1] &&
        numero1[i + 1] == dois[1][1])
        cout << 2;

    if (numero0[i] == tres[0][0] &&
        numero1[i] == tres[1][0] &&
        numero0[i + 1] == tres[0][1] &&
        numero1[i + 1] == tres[1][1])
        cout << 3;
}

int main()
{
    int D, j;
    cin >> D;
    string str1, str2, str3;
    getline(cin >> ws, str1);
    const char *numero0 = str1.c_str();
    getline(cin >> ws, str2);
    const char *numero1 = str2.c_str();
    getline(cin >> ws, str3);

    int k = 0;
    j = 0;
    while (j < D)
    {
        qual_numero(numero0, numero1, k);
        k += 3;
        j++;
    }

    /*cin >> str;
        const char *numero = str.c_str();

        j = 0;
        while (j < 3)
        {
            for (int k = 0; k < D; k++)
            {
                for (int i = 0; i < 2; i++)
                {
                    int n = numero[k] - '0';
                    qual_braille(n, j, i);
                }
                cout << " ";
            }

            cout << endl;
            j++;
        }*/

    return 0;
}