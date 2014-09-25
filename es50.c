#include <stdlib.h>
#include <stdio.h>

void InserisciElemento(int a, int ABR[]);
void GeneraABR(int vet[], int n, int ABR[]);

int main()
{
    int vet[5] = {10,37,8,12,5};
    int n, i;
    int ABR[8] = {0,0,0,0,0,0,0,0};
    n = 5;
    GeneraABR(vet, n, ABR);

    /** ABR rusultante
             10
        8           37
    5           12
    **/

    for(i = 0; i < 8; i++)
        printf("%d ", ABR[i]);

    return 0;
}

void GeneraABR(int vet[], int n, int ABR[])
{
    int i;

    for(i = 0; i < n; i++)
        InserisciElemento(vet[i], ABR);

    return;
}

void InserisciElemento(int a, int ABR[])
{
    int i;

    i = 0;
    while (ABR[i] != 0)
    {
        if(a < ABR[i])
            i = (i * 2) + 1;
        else
            i = (i * 2) + 2;
    }
    ABR[i] = a;

    return;
}
