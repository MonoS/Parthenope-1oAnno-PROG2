#include <stdio.h>

#define NUM_VERT 4

typedef struct tArco{
    int vertice;

    struct tArco* next;
} tArco;

void InsArco(tArco** vertice, int v);

int main()
{
    /** GRAFO DI INPUT
            0
           /|\
          / | \
         1  |  3
          \ | /
           \|/
            2
    **/
    tArco* vettoreAddiacenze[NUM_VERT] = {NULL,NULL,NULL,NULL};
    int i, j;
    int v;
    int archi;


    for(i = 0; i < NUM_VERT; i++)
    {
        printf("Numero di archi da inserire per il vertice %d: ", i);
        scanf("%d", &archi);

        printf("Inserire gli archi addiacenti\n");
        for(j = 0; j < archi; j++)
        {
            scanf("%d", &v);

            InsArco(&vettoreAddiacenze[i], v);
        }
    }

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
