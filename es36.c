#include <stdio.h>
#include <stdbool.h>

//int const DIM_CODA = 5;
#define DIM_CODA 5

typedef struct{
    int corpo[DIM_CODA];
    int testa;
    int coda;
} tCoda;

void ResetCoda(tCoda* c);
bool Enqueue(tCoda* c, int e);
bool Dequeue(tCoda* c, int* e);
bool CodaPiena(tCoda c);
bool CodaVuota(tCoda c);
void Menu();

int main()
{
    Menu();

    return 0;
}

void ResetCoda(tCoda* c)
{
    c->testa = 0;
    c->coda = 0;

    return;
}

bool Enqueue(tCoda* c, int e)
{
    if(!CodaPiena(*c))
    {
        c->corpo[c->testa] = e;
        c->testa++;

        return true;
    }
    else
        return false;
}

bool Dequeue(tCoda* c, int* e)
{
    if(!CodaVuota(*c))
    {
        *e = c->corpo[c->coda];
        c->coda++;

        if(CodaVuota(*c))
            ResetCoda(c);

        return true;
    }
    else
        return false;

}

bool CodaPiena(tCoda c)
{
    if(c.testa < DIM_CODA)
        return false;
    else
        return true;
}

bool CodaVuota(tCoda c)
{
    if(c.coda == (c.testa))
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
