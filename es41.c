#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct tLista{
    char elemento;
    struct tLista* next;
} tLista;

tLista* Array2Lista(char arr[]);

int main()
{
    tLista* lista;
    char* arr = "123456";
    tLista* next;

    lista = Array2Lista(arr);

    for(next = lista; next != NULL; next = next->next)
        printf("%c->", next->elemento);
    printf("NULL");
    return 0;
}

tLista* Array2Lista(char arr[])
{
    int i;

    bool errore;

    tLista* testa;
    tLista* next;

    errore = false;
    if(arr[0] != '\0') //Controlliamo che abbiamo almeno un elemento
    {
        testa = malloc(sizeof(tLista)); //Creiamo la testa
        if(testa != NULL)
        {
            //e inizializiamola
            testa->elemento = arr[0];
            testa->next = NULL;
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
        i = 1; next = testa; //inseriamo tutti gli altri elementi
        while((arr[i] != '\0') && (!errore))
        {
            next->next = malloc(sizeof(tLista));
            if(next->next != NULL) //Controlliamo che sia stata creata la struttura
            {
                //Inizializiamola
                next = next->next;
                next->elemento = arr[i];
                next->next = NULL;
                i++;
            }
            else
                errore = true;
        }

        //nel caso ci siano stati errori dobbiamo liberare tutta la memoria occupata
        if(errore)
        {
            next = testa->next;
            while(next != NULL)
            {
                free(testa);
                next = next->next;
            }

            testa = NULL;
        }
    }

    return testa;
}
