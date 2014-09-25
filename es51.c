#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct tNodo{
    int elem;

    struct tNodo* sin;
    struct tNodo* des;
} tNodo;

void GeneraABR(int vet[], int n, tNodo** ABR);
void InserisciElemento(int a, tNodo* ABR);
void VisitaPreOrder(tNodo* nodo);
void GeneraNodo(tNodo** nodo, int a);

int main()
{
    int vet[5] = {10,37,8,12,5};
    int n;
    tNodo* ABR;

    n = 5; ABR = NULL;

    GeneraABR(vet, n, &ABR);

    VisitaPreOrder(ABR);

    return 0;
}

void GeneraABR(int vet[], int n, tNodo** ABR)
{
    int i;

    GeneraNodo(ABR, vet[0]);

    for(i = 1; i < n; i++)
        InserisciElemento(vet[i], (*ABR));

    return;
}

void InserisciElemento(int a, tNodo* ABR)
{
    tNodo* nodo;
    bool continua;

    nodo = ABR; continua = true;

    while(continua)
    {
        if(a < nodo->elem)
            if(nodo->sin != NULL)
                nodo = nodo->sin;
            else
                continua = false;
        else
            if(nodo->des != NULL)
                nodo = nodo->des;
            else
                continua = false;
    }

    if(a < nodo->elem)
        GeneraNodo(&nodo->sin, a);
    else
        GeneraNodo(&nodo->des, a);


    return;
}

void VisitaPreOrder(tNodo* nodo)
{
    if(nodo != NULL)
    {
        printf("%d ", nodo->elem);
        VisitaPreOrder(nodo->sin);
        VisitaPreOrder(nodo->des);
    }
    return;
}

void GeneraNodo(tNodo** nodo, int a)
{
    (*nodo) = malloc(sizeof(tNodo));
    (*nodo)->elem = a;
    (*nodo)->sin = NULL;
    (*nodo)->des = NULL;

    return;
}

