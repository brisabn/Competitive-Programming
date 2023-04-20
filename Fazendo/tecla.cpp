#include <iostream>
#include <string>

#include <fstream>
using namespace std;

ifstream in_file("filename.txt");
ofstream out_file("fileout.txt");

bool new_key(int m, string &working, char letra, int &tam, bool *seen)
{
    if (!seen[letra] && working.size() >= m)
    {
        return false;
    }
    else if (seen[letra])
    {
        tam++;
        return true;
    }
    else
    {
        seen[letra] = true;
        working.push_back(letra);
        tam++;
        return true;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    while (in_file >> m)
    {
        if (m == 0)
            return 0;
        int c_maior = 0;
        int tam = 0;
        string texto;
        getline(in_file >> ws, texto);

        for (int i = 0; i < texto.size(); i++)
        {
            string working;
            bool seen[128] = {false};
            int j = i - 1;

            while (j < texto.length() && new_key(m, working, texto[j + 1], tam, seen))
            {
                j++;
            }

            if (tam > c_maior)
                c_maior = tam;

            tam = 0;
        }

        out_file << c_maior << endl;
    }

    return 0;
}
