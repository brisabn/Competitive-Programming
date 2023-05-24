#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
// #include <fstream>
// ofstream kout("filename.txt");

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
    if (numero0[i] == zero[0][0] &&
        numero1[i] == zero[1][0] &&
        numero0[i + 1] == zero[0][1] &&
        numero1[i + 1] == zero[1][1])
        cout << 0;

    if (numero0[i] == um[0][0] &&
        numero1[i] == um[1][0] &&
        numero0[i + 1] == um[0][1] &&
        numero1[i + 1] == um[1][1])
        cout << 1;

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

    if (numero0[i] == quatro[0][0] &&
        numero1[i] == quatro[1][0] &&
        numero0[i + 1] == quatro[0][1] &&
        numero1[i + 1] == quatro[1][1])
        cout << 4;

    if (numero0[i] == cinco[0][0] &&
        numero1[i] == cinco[1][0] &&
        numero0[i + 1] == cinco[0][1] &&
        numero1[i + 1] == cinco[1][1])
        cout << 5;

    if (numero0[i] == seis[0][0] &&
        numero1[i] == seis[1][0] &&
        numero0[i + 1] == seis[0][1] &&
        numero1[i + 1] == seis[1][1])
        cout << 6;

    if (numero0[i] == sete[0][0] &&
        numero1[i] == sete[1][0] &&
        numero0[i + 1] == sete[0][1] &&
        numero1[i + 1] == sete[1][1])
        cout << 7;

    if (numero0[i] == oito[0][0] &&
        numero1[i] == oito[1][0] &&
        numero0[i + 1] == oito[0][1] &&
        numero1[i + 1] == oito[1][1])
        cout << 8;

    if (numero0[i] == nove[0][0] &&
        numero1[i] == nove[1][0] &&
        numero0[i + 1] == nove[0][1] &&
        numero1[i + 1] == nove[1][1])
        cout << 9;
}

int main()
{
    int D, j, k;

    while (cin >> D)
    {
        // Encerrar
        if (D == 0)
        {
            exit(0);
        }

        char choice;
        cin >> choice;

        // Traduz digitos para braille
        if (choice == 'B')
        {
            string str1, str2, str3;
            getline(cin >> ws, str1);
            const char *numero0 = str1.c_str();
            getline(cin >> ws, str2);
            const char *numero1 = str2.c_str();
            getline(cin >> ws, str3);

            k = 0;
            j = 0;
            while (j < D)
            {
                qual_numero(numero0, numero1, k);
                k += 3;
                j++;
            }
            cout << endl;
        }

        // Traduz braille para digito
        else if (choice == 'S')
        {
            string str;
            getline(cin >> ws, str);
            const char *numero = str.c_str();

            j = 0;
            while (j < 3)
            {
                for (int q = 0; q < D; q++)
                {
                    for (int i = 0; i < 2; i++)
                    {
                        int n = numero[q] - '0';
                        qual_braille(n, j, i);
                    }
                    if (q < D - 1)
                        cout << " ";
                }
                cout << endl;
                j++;
            }
        }
    }

    return 0;
}