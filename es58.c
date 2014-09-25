#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_VERT 27

typedef struct tArco{
    int vertice;

    struct tArco* next;
} tArco;

typedef struct{
    int colore;

    tArco* arco;
} tVertice;

void InsArco(tArco** vertice, int v);
bool DepthFirstSearch(tVertice vettore[], int inizio, int fine);

int main()
{
    tVertice vettoreAddiacenze[NUM_VERT];
    int i, j;
    int v;
    int archi;
    FILE* labirinto;
    int inizio, fine;

    for(i = 0; i < NUM_VERT; i++)
    {
        vettoreAddiacenze[i].colore = 0;
        vettoreAddiacenze[i].arco = NULL;
    }

    labirinto = fopen("labirinto.txt", "r");

    for(i = 0; i < NUM_VERT; i++)
    {
        fscanf(labirinto, "%d", &archi);
        //printf("Numero archi vertice %d: %d\n", i, archi);

        for(j = 0; j < archi; j++)
        {
            fscanf(labirinto, "%d", &v);
            //printf("Vertice %d collegato con %d\n", i, v);

            InsArco(&vettoreAddiacenze[i].arco, v);
        }
    }

    inizio = 2;
    fine = 26;

    DepthFirstSearch(vettoreAddiacenze, inizio, fine);
    printf("%d", inizio);

    return 0;
}

void InsArco(tArco** vertice, int v)
{
    tArco* temp;

    temp = malloc(sizeof(tArco));
    temp->vertice = v;

    temp->next = (*vertice);
    (*vertice) = temp;

    return;
}

bool DepthFirstSearch(tVertice vettore[], int inizio, int fine)
{
    tArco* temp;
    bool trovato;

    if(vettore[inizio].colore == 0)
    {
        if(inizio != fine)
        {
            vettore[inizio].colore = 1;

            temp = vettore[inizio].arco; trovato = false;
            while((temp != NULL) && (!trovato))
            {
                if(DepthFirstSearch(vettore, temp->vertice, fine))
                {
                    trovato = true;
                    printf("%d->", temp->vertice);
                }
                else
                    temp = temp->next;
            }

            return trovato;
        }
        else
            return true;
    }
    else
        return false;
}
