#include <stdio.h>
#include <stdbool.h>

//const int DIM_CODA = 5;
#define DIM_CODA 5

typedef struct
{
    int corpocoda[DIM_CODA];
    int cima;
    int fondo;
}tCoda;


void ResetCoda(tCoda* c);
bool CodaVuota(tCoda c);
bool CodaPiena(tCoda c);
bool Enqueue(tCoda* c,int e);
bool Dequeue(tCoda* c, int* e);
void Menu();

int main()
{
    Menu();

    return 0;
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

void Menu()
{
    int operazione;
    int elem;
    tCoda coda;

    ResetCoda(&coda);

    do{
        printf("1 - Dequeue\n");
        printf("2 - Enqueue\n");
        printf("0 - Esci\n");

        scanf("%d", &operazione);

        switch(operazione)
        {
        case 1:
            if(Dequeue(&coda, &elem))
                printf("Valore estratto: %d\n", elem);
            else
                printf("Coda vuota\n");

            break;

        case 2:
            printf("Inserisci il valore da inserire: ");
            scanf("%d", &elem);

            if(Enqueue(&coda, elem))
                printf("Valore inserito\n");
            else
                printf("Coda piena\n");

            break;

        case 0:
            printf("Uscita\n");

            break;

        default:
            printf("Operazione errata");

            break;
        }
    }while(operazione != 0);

    return;
}
