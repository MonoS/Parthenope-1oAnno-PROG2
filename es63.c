#include <stdio.h>

#define NUM_ELEM 5

typedef struct
{
    char nome[28];
    int next;
} tLista;

void VisitaListaRico(tLista vet[], int inizio);
void VisitaListaIter(tLista vet[], int inizio);

int main()
{
    tLista vet[NUM_ELEM] = {
                                {"b", 3},
                                {"d", 4},
                                {"a", 0},
                                {"c", 1},
                                {"e", -1}
                            };
    int inizio = 2;
    int i;

    printf("Ver. orig\n");
    for(i = 0; i < NUM_ELEM; i++)
        printf("%s\n", vet[i].nome);
    printf("\n\n");

    printf("Ver. iter\n");
    VisitaListaIter(vet, inizio);
    printf("\n\n");

    printf("Ver. rico\n");
    VisitaListaRico(vet, inizio);
    printf("\n\n");
    return 0;
}

void VisitaListaIter(tLista vet[], int inizio)
{
    int temp;

    for(temp = inizio; temp != -1; temp = vet[temp].next)
        printf("%s\n", vet[temp].nome);

    return;
}

void VisitaListaRico(tLista vet[], int inizio)
{
    if(inizio != -1)
    {
        printf("%s\n", vet[inizio].nome);

        VisitaListaRico(vet, vet[inizio].next);
    }

    return;
}
