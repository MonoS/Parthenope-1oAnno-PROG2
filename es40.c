#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct tLista{
    int elemento;
    struct tLista* next;
} tLista;

void StampaMenu();
void StampaLista(tLista* lista);
bool InsInTesta(tLista** lista, int elemento);
bool EliminaInTesta(tLista** lista);
bool InsInMezzo(tLista* lista, int posizione, int elemento);
bool EliminaInMezzo(tLista* lista, int posizione);

int main()
{
    tLista* lista;
    int operazione;
    int elemento;
    int posizione;

    lista = NULL;

    StampaMenu();
    do{
        printf("Operazione: ");
        scanf("%d", &operazione);

        switch(operazione)
        {
        case 0:
            printf("Uscita in corso...\n");
            while(EliminaInTesta(&lista)); //Eliminiamo ogni singolo elemento ciclando la funzione

            break;
        case 1:
            StampaLista(lista);
            break;

        case 2:
            printf("Inserire il valore: ");
            scanf("%d", &elemento);
            if(InsInTesta(&lista, elemento))
                printf("Elemento inserito\n");
            else
                printf("Impossibile inserire elemento\n");
            break;

        case 3:
            printf("Inserire il valore: ");
            scanf("%d", &elemento);
            printf("Inserire la posizione: ");
            scanf("%d", &posizione);
            if(posizione > 0)
            {
                if(InsInMezzo(lista, posizione, elemento))
                    printf("Elemento inserito\n");
                else
                    printf("Impossibile inserire elemento\n");
            }
            else
                printf("Impossibile inserire in posizioni minori di 1\n");

            break;

        case 4:
            if(EliminaInTesta(&lista))
                printf("Eliminazione effettuata\n");
            else
                printf("Impossibile eliminare\n");

            break;

        case 5:
            printf("Inserire la posizione: ");
            scanf("%d", &posizione);

            if(posizione > 0)
            {
                if(EliminaInMezzo(lista, posizione))
                    printf("Eliminazione effettuata\n");
                else
                    printf("Impossibile eliminare\n");
            }
            else
                printf("Impossibile eliminare in posizioni minori di 1\n");

            break;
        }
    }while(operazione != 0);

    return 0;
}
void StampaMenu()
{
    printf("1 - Visualizza lista\n");
    printf("2 - Inserisci elemento in testa\n");
    printf("3 - Inserisci elemento in mezzo\n");
    printf("4 - Elimina in testa\n");
    printf("5 - Elimina in mezzo\n");
    printf("0 - Esci\n");
    return;
}
void StampaLista(tLista* lista)
{
    tLista* next;

    if(lista != NULL) //Controlliamo che la lista non sia vuota
    {
        for(next = lista; next != NULL; next = next->next)
            printf("%d\n", next->elemento);
    }
    else
        printf("La lista e' vuota\n");

    return;
}

bool InsInTesta(tLista** lista, int elemento)
{
    bool ris;
    tLista* nuovo;

    nuovo = malloc(sizeof(tLista));

    if(nuovo != NULL)
    {
        //Inizializiamo il nuovo elemento
        nuovo->elemento = elemento;
        nuovo->next = (*lista);
        (*lista) = nuovo; //Aggiorniamo la testa della lista

        ris = true;
    }
    else
        ris = false;

    return ris;
}

bool EliminaInTesta(tLista** lista)
{
    bool ris;
    tLista* next;

    if((*lista) != NULL) //Controlliamo che la lista non sia vuota
    {
        next = (*lista)->next; //salviamoci il successivo
        free((*lista));
        (*lista) = next; //aggiorniamo la testa della lista

        ris =  true;
    }
    else
        ris = false;



    return ris;
}

bool InsInMezzo(tLista* lista, int posizione, int elemento)
{
    bool ris;
    tLista* nuovo;
    tLista* next;
    int i;

    i = 0; next = lista;
    //Cerchiamo la posizione corretta, controllando anche che la lista non finisca prima di arrivarci
    while((i < (posizione - 1)) && (next != NULL))
    {
        next = lista->next;
        i++;
    }

    if(i == (posizione - 1))
    {
        //Allochiamo e inizializziamo il nuovo elemento
        nuovo = malloc(sizeof(tLista));
        nuovo->elemento = elemento;

        //attacchiamoci gli elementi precedente e successivo
        nuovo->next = next->next;
        next->next = nuovo;

        ris =  true;
    }
    else
        ris = false;

    return ris;
}

bool EliminaInMezzo(tLista* lista, int posizione)
{
    tLista* next;
    bool ris;
    int i;
    tLista* temp;

    //Cerchiamo la posizione corretta, controllando anche che la lista non finisca prima di arrivarci
    i = 0; next = lista;
    while((i < (posizione - 1)) && (next->next != NULL))
    {
        next = lista->next;
        i++;
    }

    if(i == (posizione - 1))
    {
        //riattacchiamo l'elemento precedente
        temp = next->next;
        next->next = temp->next;

        free(temp);

        ris = true;
    }
    else
        ris = false;

    return ris;
}
