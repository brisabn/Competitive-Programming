// 2884 - Interruptores Teatro
#include <algorithm> // for std::find
#include <iostream>
#include <vector>

using std::find;
using std::vector;

class Lamp
{
public:
    int id;
    bool acessa = false;

    void aciona()
    {
        if (acessa)
            acessa = false;
        else
            acessa = true;
    }
};

struct Inter
{
    int id;
    vector<Lamp> lamp_conect;
};

int N, M, A;
vector<Lamp> lamp_teatro;
vector<Lamp> lamp_compare;

bool apagou_check()
{
    for (int i = 0; i < M; i++)
    {
        if (lamp_teatro[i].acessa)
            return false;
    }
    return true;
}

int main()
{
    scanf("%d %d", &N, &M);
    scanf("%d", &A);

    int acessas[A];

    for (int a = 0; a < A; a++)
    {
        int lamp_acessa;
        scanf("%d", &lamp_acessa);
        acessas[a] = lamp_acessa;
    }

    for (int k = 0; k < M; k++)
    {
        Lamp lamp;
        lamp.id = k + 1;
        int *end = acessas + A;
        if (find(acessas, end, k + 1) != end)
        {
            lamp.acessa = true;
        }
        lamp_teatro.push_back(lamp);
    }

    vector<Inter> inter_teatro;

    for (int i = 0; i < N; i++)
    {
        Inter inter_;
        inter_.id = i + 1;

        int L, X;
        scanf("%d", &L);

        for (int j = 0; j < L; j++)
        {
            scanf("%d", &X);
            Lamp lamp;
            lamp.id = X;
            inter_.lamp_conect.push_back(lamp);
        }
        inter_teatro.push_back(inter_);
    }

    int q = 0;
    while (true)
    {

        for (int i = 0; i < N; i++)
        {
            q++;
            for (int j = 0; j < inter_teatro[i].lamp_conect.size(); j++)
            {
                int X = inter_teatro[i].lamp_conect[j].id - 1;
                lamp_teatro[X].aciona();
            }

            if (q == 1)
            {
                for (int k = 0; k < M; k++)
                {
                    Lamp lamp;
                    lamp.id = k + 1;
                    if (lamp_teatro[k].acessa)
                    {
                        lamp.acessa = true;
                    }
                    lamp_compare.push_back(lamp);
                }
            }

            bool ok = false;
            if (i == 0 && q > 1)
            {
                for (int k = 0; k < M; k++)
                {
                    if (lamp_teatro[k].acessa != lamp_compare[k].acessa)
                    {
                        ok = true;
                    }
                }
                if (!ok)
                {
                    printf("-1\n");
                    return 0;
                }
            }

            if (apagou_check())
            {
                printf("%d\n", q);
                return 0;
            }
        }
    }

    return 0;
}