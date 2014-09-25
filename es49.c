#include <stdio.h>

typedef struct tNodo{
    int elemento;
    struct tNodo* sinistra;
    struct tNodo* destra;
} tNodo;

void StampaElemento(tNodo* nodo);
void VisitaInOrder(tNodo* albero[]);
void VisitaPostOrder(tNodo* albero[]);
void VisitaPreOrder(tNodo* albero[]);

int main()
{
    /*              0
            1               3
        2       4       5       6
    */
    tNodo albero[7] = {{0,1,3}, {1,2,4}, {2,-1,-1}, {3,5,6}, {4,-1,-1}, {5,-1,-1}, {6,-1,-1}};


    printf("            0\n    1               3\n2       4       5       6\n\n");

    printf("In order\n");
    VisitaInOrder(albero);
    printf("\n");

    printf("Post order\n");
    VisitaPostOrder(albero);
    printf("\n");

    printf("Pre order\n");
    VisitaPreOrder(albero);
    printf("\n");

    return 0;
}

void StampaElemento(tNodo* nodo)
{
    printf("%d\n", nodo.elemento);

    return;
}

void VisitaInOrder(tNodo* nodo)
{
    if(nodo != NULL)
    {
        VisitaInOrder(nodo->sinistra));
        StampaElemento(albero[index]);
        VisitaInOrder(nodo->destra);
    }
    return;
}

void VisitaPostOrder(tNodo* nodo)
{
    if(nodo != NULL)
    {
        VisitaPostOrder(nodo->sinistra));
        VisitaPostOrder(nodo->destra);
        StampaElemento(albero[index]);
    }

    return;
}

void VisitaPreOrder(tNodo* nodo)
{
    if(nodo != NULL)
    {
        StampaElemento(albero[index]);
        VisitaPreOrder(nodo->sinistra));
        VisitaPreOrder(nodo->destra);
    }
    return;
}
