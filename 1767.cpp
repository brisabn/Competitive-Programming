#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int N, viagem = 0;
    scanf("%d", &N);

    while (viagem < N)
    {
        int Pac, pacote = 0;
        int qt_total = 0, peso_total = 0;

        scanf("%d", &Pac);

        while (pacote < Pac)
        {
            int qt, peso;
            scanf("%d %d", &qt, &peso);

            qt_total += qt;
            peso_total += peso;

            pacote++;
        }

        cout << "qnt total: " << qt_total << endl
             << "peso total: " << peso_total << endl;

        if (peso_total > 50)
        {
            //
        }

        viagem++;
    }
}