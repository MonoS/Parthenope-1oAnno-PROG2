#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct tLista{
    struct tLista* next;
    struct tLista* prec;
    int elem;
} tLista;

tLista* Array2Lista(char arr[]);
void SelectionSortIterVirt(tLista* lista);
void SelectionSortRicoVirt(tLista* lista);
void SelectionSortIterReal(tLista* lista);
void SelectionSortRicoReal(tLista* lista);
tLista* CercaMinimo(tLista* lista);
void StampaLista(tLista* lista);

int main()
{
    tLista *listaIterVirt, *listaIterReal, *listaRicoVirt, *listaRicoReal;
    char vet[6] = "35142";
    tLista* min;

    listaIterVirt = Array2Lista(vet);
    listaIterReal = Array2Lista(vet);
    listaRicoVirt = Array2Lista(vet);
    listaRicoReal = Array2Lista(vet);

    printf("listanonOrder: ");StampaLista(listaIterVirt);

    min = CercaMinimo(listaIterVirt);
    SelectionSortIterVirt(listaIterVirt);
    listaIterVirt = min;

    min = CercaMinimo(listaRicoVirt);
    SelectionSortRicoVirt(listaRicoVirt);
    listaRicoVirt = min;

    SelectionSortRicoReal(listaRicoReal);
    SelectionSortIterReal(listaIterReal);


    printf("listaIterVirt: ");StampaLista(listaIterVirt);
    printf("listaIterReal: ");StampaLista(listaIterReal);
    printf("listaRicoVirt: ");StampaLista(listaRicoVirt);
    printf("listaRicoReal: ");StampaLista(listaRicoReal);

    return 0;
}

void StampaLista(tLista* lista)
{
    tLista* next;
    for(next = lista; next != NULL; next = next->next)
        printf("%c->", next->elem);
    printf("NULL\n");
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

void SelectionSortIterVirt(tLista* lista)
{
    tLista* min;
    tLista* testa;
    tLista temp;

    testa = lista;
    while(testa != NULL)
    {
        min = CercaMinimo(testa); //Cerchiamo il minimo

        //Scambiamo i puntatori
        temp.next = min->next;
        temp.prec = min->prec;

        min->next = testa->next;
        min->prec = testa->prec;
        if(min->prec != NULL)
            min->prec->next = min;
        if(min->next != NULL)
            min->next->prec = min;

        testa->next = temp.next;
        testa->prec = temp.prec;
        if(testa->prec != NULL)
            testa->prec->next = testa;
        if(testa->next != NULL)
            testa->next->prec = testa;

        testa = min->next; //Andiamo al prossimo elemento e ripetiamo
    }

    return;
}

void SelectionSortRicoVirt(tLista* lista)
{
    tLista* min;
    tLista* testa;
    tLista temp;

    testa = lista;
    if(testa != NULL)
    {
        min = CercaMinimo(testa);

        temp.next = min->next;
        temp.prec = min->prec;

        min->next = testa->next;
        min->prec = testa->prec;
        if(min->prec != NULL)
            min->prec->next = min;
        if(min->next != NULL)
            min->next->prec = min;

        testa->next = temp.next;
        testa->prec = temp.prec;
        if(testa->prec != NULL)
            testa->prec->next = testa;
        if(testa->next != NULL)
            testa->next->prec = testa;

        testa = min->next;

        SelectionSortRicoVirt(testa);
    }

    return;
}

tLista* CercaMinimo(tLista* lista)
{
    tLista* min;
    tLista* next;

    min = lista;

    next = lista->next;
    while(next != NULL)
    {
        if(next->elem < min->elem)
            min = next;

        next = next->next;
    }

    return min;
}

void SelectionSortIterReal(tLista* lista)
{
    tLista* min;
    tLista* testa;
    tLista temp;

    testa = lista;
    while(testa != NULL)
    {
        min = CercaMinimo(testa);

        temp.elem = min->elem;

        min->elem = testa->elem;
        testa->elem = temp.elem;

        testa = testa->next;
    }

    return;
}

void SelectionSortRicoReal(tLista* lista)
{
    tLista* min;
    tLista* testa;
    tLista temp;

    testa = lista;
    if(testa != NULL)
    {
        min = CercaMinimo(testa);

        temp.elem = min->elem;

        min->elem = testa->elem;
        testa->elem = temp.elem;

        testa = testa->next;

        SelectionSortRicoVirt(testa);
    }

    return;
}
