#include <stdio.h>

#define M 4
#define N 6

void StampaColonne(int matrice[M][N]);
void StampaRighe(int matrice[M][N]);

int main()
{
    int matrice[M][N] = {{11,12,13,14,15,16},{21,22,23,24,25,26},{31,32,33,34,35,36},{41,42,43,44,45,46}};

    StampaRighe(matrice);
    StampaColonne(matrice);

    return 0;
}

void StampaColonne(int matrice[M][N])
{
    int i, j;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++) //cicliamo come se fosse una matrice normale solo cogli indici scambiati
            printf("%d ", matrice[j][i]);

        printf("\n");
    }

    return;
}

void StampaRighe(int matrice[M][N])
{
    int i, j;

    for(i = 0; i < M; i++)
    {
        for(j = 0; j < N; j++) //cicliamo come se fosse una matrice normale solo cogli indici scambiati
            printf("%d ", matrice[i][j]);

        printf("\n");
    }

    return;
}
