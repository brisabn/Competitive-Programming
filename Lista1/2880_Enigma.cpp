#include <iostream>
using namespace std;

int main()
{
    string mensagem, crib;
    cin >> mensagem;
    cin >> crib;
    bool ok = true;
    int posicoes = 0, i, muda = 0;

    for (int k = 0; k < mensagem.size() - crib.size() + 1; k++)
    {
        i = 0;
        for (int j = muda; j < crib.size() + muda; j++)
        {
            if (mensagem[j] == crib[i])
            {
                ok = false;
                break;
            }
            else
            {
                ok = true;
            }
            i++;
        }
        muda++;

        if (ok)
            posicoes++;
    }

    cout << posicoes << endl;

    return 0;
}
