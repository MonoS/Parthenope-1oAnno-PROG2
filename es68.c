#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct tLista{
    struct tLista* next;
    struct tLista* prec;
    int elem;
} tLista;

void BubbleSortReal(tLista* lista);
void ScambioReal(tLista* curr);

void BubbleSortVirt(tLista** lista);
tLista* ScambioVirt(tLista* curr);

tLista* Array2Lista(char arr[]);
void StampaLista(tLista* lista);

int main()
{
    tLista *listaReal, *listaVirt;
    char vet[6] = "35142";


    listaReal = Array2Lista(vet);
    listaVirt = Array2Lista(vet);

    printf("listanonOrder: ");StampaLista(listaVirt);

    BubbleSortReal(listaReal);
    printf("listaReal:     ");StampaLista(listaReal);

    BubbleSortVirt(&listaVirt);
    printf("listaVirt:     ");StampaLista(listaVirt);

    return 0;
}

void BubbleSortReal(tLista* lista)
{
    tLista* next;
    tLista* ult_scambio;
    tLista* fine_ord;

    for(next = lista; next->next != NULL; next = next->next);
    fine_ord = next;

    while (fine_ord != lista)
    {
        ult_scambio = lista;
        for (next = lista; ((next != fine_ord) && (next->next != NULL)); next = next->next)
        {
            if(next->elem > next->next->elem)
            {
                ScambioReal(next);
                ult_scambio = next;
            }
        }

        fine_ord = ult_scambio;

    }

    return;
}

void ScambioReal(tLista* curr)
{
    int elem;

    elem = curr->elem;

    curr->elem = curr->next->elem;
    curr->next->elem = elem;

    return;
}

tLista* Array2Lista(char arr[])
{
    int i;

    bool errore;

    tLista* testa;
    tLista* next;

    errore = false;
    if(arr[0] != '\0')
    {   //Proviamo a creare la testa in quanto deve essere inizializzata diversamente dagli altri
        testa = malloc(sizeof(tLista));
        if(testa != NULL)
        {
            testa->elem = arr[0];
            testa->next = NULL;
            testa->prec = NULL;
        }
        else
        {
            testa = NULL;
            errore = true;
        }
    }
    else
        testa = NULL;

    if(testa != NULL)
    {
        i = 1; next = testa;
        while((arr[i] != '\0') && (!errore)) //Creiamo gli altri elementi
        {
            next->next = malloc(sizeof(tLista));
            if(next->next != NULL) //E inizializziamoli coi giusti puntatori
            {
                next->next->prec = next;
                next = next->next;
                next->elem = arr[i];
                next->next = NULL;
                i++;
            }
            else
                errore = true;
        }

        if(errore) //Se c'è stato un problema liberiamo tutta la memoria occupata
        {
            while(next != NULL)
            {
                next = testa->next;
                free(testa);
                testa = next;
            }

            testa = NULL;
        }
    }

    return testa;
}

void StampaLista(tLista* lista)
{
    tLista* next;
    for(next = lista; next != NULL; next = next->next)
        printf("%c->", next->elem);
    printf("NULL\n");

    return;
}

void BubbleSortVirt(tLista** lista)
{
    tLista* next;
    tLista* temp;
    bool scambiato;

    scambiato = true;

    while (scambiato)
    {
        for (next = (*lista), scambiato = false; next->next != NULL; next = next->next)
        {
            if(next->elem > next->next->elem)
            {
                temp = ScambioVirt(next);

                if(temp != NULL)
                    (*lista) = temp;

                next = next->prec;
                scambiato = true;
            }
        }
    }

    return;
}

tLista* ScambioVirt(tLista* curr)
{
    tLista temp;
    tLista* next1st;
    //salviamo i puntatori del nodo corrente
    temp.prec = curr->prec;
    temp.next = curr->next->next;
    next1st = curr->next;

    //Cambiamo i puntatori del nodo corrente per essere come quelli del nodo successivo
    curr->next->prec = temp.prec;
    curr->next = temp.next;

    curr->prec = next1st;
    next1st->next = curr;

    if(temp.prec != NULL)
        temp.prec->next = next1st;

    if(temp.next != NULL)
        temp.next->prec = curr;

    if(temp.prec == NULL)
        return next1st;
    else
        return NULL;
}
