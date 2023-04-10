// 1642 - TECLADO QUEBRADO
#include <iostream>
#include <string>

#include <fstream>
using namespace std;

ofstream out("filename.txt");

bool contains(string str, char letra)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == letra)
            return true;
    }
    return false;
}

bool new_key(int m, string &working, char letra, int &tam, bool contains_letra)
{
    if (!contains_letra && working.size() >= m)
    {
        return false;
    }
    else if (contains_letra)
    {
        tam++;
        return true;
    }
    else
    {
        working.push_back(letra);
        tam++;
        return true;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    int m;

    while (scanf("%d", &m))
    {
        if (m == 0)
            return 0;
        int c_maior = 0;
        int tam = 0;
        string texto;
        getline(cin >> ws, texto);

        for (int i = 0; i < texto.size(); i++)
        {
            string working;
            bool contains_letra = false;
            int j = i - 1;

            while (j < texto.length() && new_key(m, working, texto[j + 1], tam, contains(working, texto[j + 1])))
            {
                contains_letra = true;
                j++;
            }

            if (tam > c_maior)
                c_maior = tam;

            tam = 0;
        }

        out << c_maior << endl;
        // printf("%d", c_maior);
    }

    return 0;
}
