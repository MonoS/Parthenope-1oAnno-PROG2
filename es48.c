#include <stdio.h>

typedef struct{
    int elemento;
    int sinistra;
    int destra;
} tNodo;

void StampaElemento(tNodo nodo);
void VisitaInOrder(tNodo albero[], int index);
void VisitaPostOrder(tNodo albero[], int index);
void VisitaPreOrder(tNodo albero[], int index);

int main()
{
    /*              0
            1               3
        2       4       5       6
    */
    tNodo albero[7] = {{0,1,3}, {1,2,4}, {2,-1,-1}, {3,5,6}, {4,-1,-1}, {5,-1,-1}, {6,-1,-1}};


    printf("            0\n    1               3\n2       4       5       6\n\n");

    printf("In order\n");
    VisitaInOrder(albero, 0);
    printf("\n");

    printf("Post order\n");
    VisitaPostOrder(albero, 0);
    printf("\n");

    printf("Pre order\n");
    VisitaPreOrder(albero, 0);
    printf("\n");

    return 0;
}

void StampaElemento(tNodo nodo)
{
    printf("%d\n", nodo.elemento);

    return;
}

void VisitaInOrder(tNodo albero[], int index)
{
    if(albero[index].sinistra != -1)
        VisitaInOrder(albero, albero[index].sinistra);

    StampaElemento(albero[index]);

    if(albero[index].destra != -1)
        VisitaInOrder(albero, albero[index].destra);

    return;
}

void VisitaPostOrder(tNodo albero[], int index)
{
    if(albero[index].sinistra != -1)
        VisitaPostOrder(albero, albero[index].sinistra);

    if(albero[index].destra != -1)
        VisitaPostOrder(albero, albero[index].destra);

    StampaElemento(albero[index]);

    return;
}

void VisitaPreOrder(tNodo albero[], int index)
{
    StampaElemento(albero[index]);

    if(albero[index].sinistra != -1)
        VisitaPreOrder(albero, albero[index].sinistra);

    if(albero[index].destra != -1)
        VisitaPreOrder(albero, albero[index].destra);

    return;
}
