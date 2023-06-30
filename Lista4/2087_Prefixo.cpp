#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool temPrefixo(const string conj[], int N)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i != j && conj[j].find(conj[i]) == 0) // substring começando na posição zero.
                return true;

    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    while (cin >> N && N != 0)
    {

        cin.ignore();

        string conj[N];
        for (int i = 0; i < N; i++)
            getline(cin, conj[i]);

        bool resul = temPrefixo(conj, N);
        cout << (resul ? "Conjunto Ruim\n" : "Conjunto Bom\n");
    }

    return 0;
}
