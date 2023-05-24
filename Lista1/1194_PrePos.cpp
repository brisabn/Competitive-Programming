// 1194 - Prefixa, Infixa e Posfixa
#include <cstdio>
#include <cstring>

struct Nodo
{
    char C;
    Nodo *esq;
    Nodo *dir;
    Nodo(char letra) : C(letra), esq(nullptr), dir(nullptr) {}
};

int qual_idx(char *str, int inicio, int fim, char letra)
{
    for (int i = inicio; i <= fim; i++)
    {
        if (str[i] == letra)
        {
            return i;
        }
    }
    return -1;
}

Nodo *Arvore(char *prefix, char *infix, int preInicio, int preEnd,
             int inInicio, int inEnd)
{
    if (preInicio > preEnd || inInicio > inEnd)
    {
        return nullptr;
    }

    char raizLetra = prefix[preInicio];
    int raizIndex = qual_idx(infix, inInicio, inEnd, raizLetra);
    int tam_Esq = raizIndex - inInicio;

    Nodo *raiz = new Nodo(raizLetra);
    raiz->esq = Arvore(prefix, infix, preInicio + 1,
                       preInicio + tam_Esq, inInicio, raizIndex - 1);
    raiz->dir = Arvore(prefix, infix, preInicio + tam_Esq + 1, preEnd,
                       raizIndex + 1, inEnd);

    return raiz;
}

void imprimePos(Nodo *raiz)
{
    if (raiz == nullptr)
    {
        return;
    }
    imprimePos(raiz->esq);
    imprimePos(raiz->dir);
    printf("%c", raiz->C);
}

int main()
{
    int i = 0, vezes;
    scanf("%d", &vezes);

    while (i < vezes)
    {
        int n;
        char prefix[104], infix[104];

        scanf("%d %s %s", &n, prefix, infix);
        Nodo *raiz = Arvore(prefix, infix, 0, n - 1, 0, n - 1);
        imprimePos(raiz);
        printf("\n");
        i++;
    }
    return 0;
}