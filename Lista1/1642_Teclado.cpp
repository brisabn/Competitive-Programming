#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    while (cin >> m)
    {
        if (m == 0)
            return 0;

        string texto;
        getline(cin >> ws, texto);

        int tam = texto.size();
        int freq[128];

        int esq = 0, dir = 0;
        int tipos = 0;
        int resp = 0;

        memset(freq, 0, sizeof(freq));

        while (dir < tam)
        {
            if (freq[texto[dir]] == 0)
                tipos++;

            freq[texto[dir]]++;

            while (tipos > m)
            {
                freq[texto[esq]]--;
                if (freq[texto[esq]] == 0)
                    tipos--;
                esq++;
            }

            resp = max(resp, dir - esq + 1);
            dir++;
        }

        cout << resp << endl;
    }

    return 0;
}
