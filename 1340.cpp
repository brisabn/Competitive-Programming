#include <iostream>
#include <algorithm>

using namespace std;

bool is_substring_queue(int in[], int out[], int j)
{
    for (int i = 0; i < j; i++)
        if (in[i] != out[i])
            return false;

    return true;
}

bool is_substring_stack(int in[], int out[], int j)
{
    int out_aux[j];
    for (int i = 0; i < j; i++)
    {
        out_aux[i] = out[j - 1 - i];
    }

    for (int i = 0; i < j; i++)
        if (in[i] != out_aux[i])
            return false;

    return true;
}

bool is_substring_priority(int in[], int out[], int j, int k)
{
    sort(in, in + k);

    int in_aux[k];
    for (int i = 0; i < k; i++)
    {
        in_aux[i] = in[k - 1 - i];
    }

    // sort(in, in + k, greater<int>()); // função aprendida de sort descending

    for (int i = 0; i < j; i++)
        if (in_aux[i] != out[i])
            return false;

    return true;
}

int main()
{
    // cria um array, le ele
    // se arr1 = arr2
    // se arr1 = arr2 reverso, na vdd nem precisa desse viu,, nao sei, o que seria o not sure?
    // pq o reverso poderia ser prioridade ou stack, hmmm preencheria as duas entao,
    // tipo, de ser em ordem de retirada E de ser do menor pro maior
    // nao é if else
    // coloca em ordem, se out é uma substring de ordenado, ent prioridade
    int n, sure;

    while (scanf("%d", &n))
    {
        int comando, numero;
        int in_sacola[n], out_sacola[n];
        int i = 0, j = 0, vez = 0;

        while (vez < n)
        {
            scanf("%d %d", &comando, &numero);
            if (comando == 1)
            {
                in_sacola[i] = numero;
                i++;
            }

            if (comando == 2)
            {
                out_sacola[j] = numero;
                j++;
            }
            vez++;
        }

        bool queue = false, stack = false, priority = false;
        sure = 0;
        if (is_substring_queue(in_sacola, out_sacola, j))
        {
            queue = true;
            sure++;
        }

        if (is_substring_stack(in_sacola, out_sacola, j))
        {
            stack = true;
            sure++;
        }

        if (is_substring_priority(in_sacola, out_sacola, j, i))
        {
            priority = true;
            sure++;
        }

        if (sure == 1)
        {
            if (queue)
                printf("queue\n");
            if (stack)
                printf("stack\n");
            if (priority)
                printf("priority queue\n");
        }
        else if (sure > 1)
            printf("not sure\n");
        else
            printf("impossible\n");

        // quando retira, também tem que tirar do array antigo, ent faria uma função de como ficou o array
        // tipo, na de prioridade, faz qsort e tals ai tira o 5, mas ai coloca e tira o 4
        // será que faço tipo, colocar tudo e ver se um é substring da outra? mas na ordem certa, um if else
    }

    return 0;
}