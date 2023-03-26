#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
int N, M;

bool same_array(int A[], int B[], int M)
{
    for (int i = 0; i < M; i++)
        if (A[i] != B[i])
            return false;

    return true;
}

int main()
{

    while (scanf("%d", &N))
    {
        // Leitura das Fitas de Referência
        int fita_in[15], fita_out[15];

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &fita_in[i]);
        }

        scanf("%d", &M);
        for (int i = 0; i < M; i++)
        {
            scanf("%d", &fita_out[i]);
        }

        // Dobraduras
        int fita_res1[15];
        int j, k = 0;
        for (int i = 0; i < M; i++)
        {
            if (i <= N - M - 1)
            {
                fita_res1[i] = fita_in[N - M - 1 - k] + fita_in[N - M + i];
                k++;
            }
            else
            {
                fita_res1[i] = fita_in[(2 * (N - M)) + j];
                j++;
            }
        }

        int fita_res2[15];
        k = 0;
        for (int i = 0; i < M; i++)
        {
            if (i > 2 * M - N - 1)
            {
                fita_res2[i] = fita_in[N - 1 - k] + fita_in[i];
                k++;
            }
            else
            {
                fita_res2[i] = fita_in[i];
            }
        }

        // Inversão das Fitas
        int fita_res3[15];
        for (int i = 0; i < M; i++)
        {
            fita_res3[i] = fita_res2[M - 1 - i];
        }

        int fita_res4[15];
        for (int i = 0; i < M; i++)
        {
            fita_res4[i] = fita_res1[M - 1 - i];
        }

        /* for (int i = 0; i < M; i++)
         {
             printf("%d ", fita_res1[i]);
         }
         printf("\n");
         for (int i = 0; i < M; i++)
         {
             printf("%d ", fita_res2[i]);
         }
         printf("\n");
         for (int i = 0; i < M; i++)
         {
             printf("%d ", fita_res3[i]);
         }
         printf("\n");
         for (int i = 0; i < M; i++)
         {
             printf("%d ", fita_res4[i]);
         }
         printf("\n");*/

        // Resultado
        if (same_array(fita_out, fita_res1, M))
            printf("S\n");
        else if (same_array(fita_out, fita_res2, M))
            printf("S\n");
        else if (same_array(fita_out, fita_res3, M))
            printf("S\n");
        else if (same_array(fita_out, fita_res4, M))
            printf("S\n");
        else
            printf("N\n");
    }
}