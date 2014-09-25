#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_VERT 28

typedef struct tArco{
    int vertice;

    struct tArco* next;
} tArco;

typedef struct{
    int colore;
    int distanza;

    tArco* arco;
} tVertice;

#define DIM_CODA 100

typedef struct
{
    int corpocoda[DIM_CODA];
    int cima;
    int fondo;
}tCoda;

void InsArco(tArco** vertice, int v);
bool BreathFirstSearch(tVertice vettore[], int inizio, int fine, tCoda *coda);
void ResetCoda(tCoda* c);
bool CodaVuota(tCoda c);
bool CodaPiena(tCoda c);
bool Enqueue(tCoda* c,int e);
bool Dequeue(tCoda* c, int* e);

int main()
{
    tVertice vettoreAddiacenze[NUM_VERT];
    int i, j;
    int v;
    int archi;
    FILE* labirinto;
    int inizio, fine;
    tCoda coda;

    ResetCoda(&coda);
    for(i = 0; i < NUM_VERT; i++)
    {
        vettoreAddiacenze[i].colore = 0;
        vettoreAddiacenze[i].arco = NULL;
        vettoreAddiacenze[i].distanza = -1; //-1 equivale ad infinito
    }

    labirinto = fopen("labirinto.txt", "r");

    for(i = 0; i < NUM_VERT - 1; i++)
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

    fclose(labirinto);

    printf("Inserire i vertici da controllare: ");
    scanf("%d %d", &inizio, &fine);

    vettoreAddiacenze[inizio].distanza = 0;
    if(BreathFirstSearch(vettoreAddiacenze, inizio, fine, &coda))
        printf("%d", inizio);
    else
        printf("Non Connesso!");
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

bool BreathFirstSearch(tVertice vettore[], int inizio, int fine, tCoda *coda)
{
    tArco* temp;
    bool trovato;
    int e;

    if(vettore[inizio].colore < 2)
    {
        if(inizio != fine)
        {
            vettore[inizio].colore = 2; //nero

            for(temp = vettore[inizio].arco; temp != NULL; temp = temp->next)
            {
                if(vettore[temp->vertice].colore < 1)
                {
                    vettore[temp->vertice].colore = 1; //grigio
                    vettore[temp->vertice].distanza = vettore[inizio].distanza + 1; //aumentiamo la distanza
                    Enqueue(coda, temp->vertice); //Salviamoci il prossimo vertice se non è stato ancora visitato
                }
            }

            trovato = false;
            while(Dequeue(coda, &e) && (!trovato)) //per ogni vertice nella coda
            {
                if(BreathFirstSearch(vettore, e, fine, coda))
                {
                    trovato = true;
                    printf("%d->", e);
                }
            }

            return trovato;
        }
        else
            return true;
    }
    else
        return false;
}

bool Dequeue(tCoda* c, int* e)
{
    if(!(CodaVuota(*c)))
    {
        (*c).cima=((*c).cima + 1) % DIM_CODA; //Aggiorniamo la cima mandandola avanti, se raggiungiamo la fine del vettore ritorniamo all'inizio
        (*e)=(*c).corpocoda[(*c).cima];

        return true;
    }
    else
        return false;
}

bool Enqueue(tCoda* c,int e)
{
    if(!(CodaPiena(*c)))
    {
        (*c).fondo = ((*c).fondo + 1) % DIM_CODA; //Aggiorniamo il fondo mandandolo avanti, se raggiungiamo la fine del vettore ritorniamo all'inizio
        (*c).corpocoda[(*c).fondo] = e;

        return true;
    }
    else
        return false;
}
void ResetCoda(tCoda* c)
{
    (*c).cima = 0;
    (*c).fondo = 0;
    return;
}

bool CodaVuota(tCoda c)
{
    if(c.fondo == c.cima)
        return true;
    else
        return false;
}

bool CodaPiena(tCoda c)
{
    if(c.cima == (c.fondo + 1) % DIM_CODA)
        return true;
    else
        return false;
}
