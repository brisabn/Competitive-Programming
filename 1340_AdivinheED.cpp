#include <iostream>
#include <stack>
#include <queue>

// editar depois pq tá muito feio

using namespace std;

int q, s, p, vez_comando;
bool is_queue, is_stack, is_priority;
bool isFirstTime_q = true, isFirstTime_s = true, isFirstTime_p = true;
bool unico_q, unico_s, unico_p;

void is_fila(queue<int> &queue, int numero)
{
    if ((queue.front() == numero) && (q != -1))
    {
        queue.pop();
        is_queue = true;
    }
    else
    {
        q = -1;
        is_queue = false;
    }

    if (isFirstTime_q)
    {
        isFirstTime_q = false;
        unico_q = true;
    }
    else
    {
        unico_q = false;
    }
}

void is_pilha(stack<int> &stack, int numero)
{
    if ((stack.top() == numero) && (s != -1))
    {
        stack.pop();
        is_stack = true;
    }
    else
    {
        s = -1;
        is_stack = false;
    }

    if (isFirstTime_s)
    {
        isFirstTime_s = false;
        unico_s = true;
    }
    else
    {
        unico_s = false;
    }
}

void is_fila_prioritaria(priority_queue<int> &queue, int numero)
{
    if ((queue.top() == numero) && (p != -1))
    {
        queue.pop();
        is_priority = true;
    }
    else
    {
        p = -1;
        is_priority = false;
    }

    if (isFirstTime_p)
    {
        isFirstTime_p = false;
        unico_p = true;
    }
    else
    {
        unico_p = false;
    }
}

int main()
{
    int n, vez;

    queue<int> fila;
    stack<int> pilha;
    priority_queue<int> fila_prioritaria;

    while (scanf("%d", &n) == 1)
    {
        isFirstTime_q = true, isFirstTime_s = true, isFirstTime_p = true;
        unico_q = false, unico_s = false, unico_p = false;

        int comando, numero;

        vez = 0, vez_comando = 0;
        q = s = p = 0;

        while (vez < n)
        {
            scanf("%d %d", &comando, &numero);
            if (comando == 1)
            {
                fila.push(numero);
                fila_prioritaria.push(numero);
                pilha.push(numero);
                vez_comando++;
            }

            if (comando == 2)
            {
                is_fila(fila, numero);
                is_fila_prioritaria(fila_prioritaria, numero);
                is_pilha(pilha, numero);
            }
            vez++;
        }

        while (!fila_prioritaria.empty())
        {
            fila_prioritaria.pop();
        }

        while (!fila.empty())
        {
            fila.pop();
        }

        while (!pilha.empty())
        {
            pilha.pop();
        }

        if (is_queue && !is_stack && !is_priority)
            printf("queue\n");
        else if (!is_queue && is_stack && !is_priority)
            printf("stack\n");
        else if (!is_queue && !is_stack && is_priority)
            printf("priority queue\n");
        else if ((!is_queue && is_stack && is_priority) || (is_queue && !is_stack && is_priority) || ((is_queue && is_stack && !is_priority)))
            printf("not sure\n");
        else if ((unico_p && unico_q && unico_s) && (vez_comando > 0))
            printf("not sure\n");
        else
            printf("impossible\n");

        is_queue = false, is_stack = false, is_priority = false;
    }

    return 0;
}