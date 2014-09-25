#include <stdio.h>
#include <stdbool.h>

#define N 5

int InsArco(bool m[N][N], int v1, int v2, int n);
void ResetMatrice(bool m[N][N], int n);
int Grado(bool m[N][N], int v, int n);

int main()
{
    /** GRAFO DI INPUT
            1
           /|\
          / | \
         2  |  4
          \ | /
           \|/
            3
    **/
    bool mAddiacenza[N][N];
    int archi;
    int i;
    int v1, v2;

    ResetMatrice(mAddiacenza, N);

    printf("Numero di archi da inserire: ");
    scanf("%d", &archi);

    printf("Inserire i due archi da collegare separati da spazio\n");

    i = 0;
    while(i < archi)
    {
        scanf("%d %d", &v1, &v2);
        if(InsArco(mAddiacenza, v1, v2, N) != 0)
            printf("Errore!\n");
        else
            i++;
    }

    printf("Inserire il vertice di cui calcolare il grado: ");
    scanf("%d", &v1);

    printf("grado: %d\n", Grado(mAddiacenza, v1, N));

    return 0;
}

void ResetMatrice(bool m[N][N], int n)
{
    int i, j;

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            m[i][j] = false;

    return;
}

int InsArco(bool m[N][N], int v1, int v2, int n)
{
    int ris;

    if(v1 != v2)
    {
        if((v1 < n) && (v2 < n))
        {
            if((!(m[v1][v2])) && (!(m[v2][v1])))
            {
                m[v1][v2] = true; m[v2][v1] = true;

                ris = 0;
            }
            else
                ris = -3; //L'arco già esiste
        }
        else
            ris = -2; //I vertici non fanno parte del grafo
    }
    else
        ris = -1; //Sono lo stesso vertice

    return ris;
}

int Grado(bool m[N][N], int v, int n)
{
    int i;
    int grado;

    if(v < n)
    {
        for(i = 0, grado = 0; i < n; i++)
            if(m[v][i])
                grado++;
    }
    else
        grado = -1;

    return grado;
}
