#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const int NUM_CAMERE = 10;

typedef struct{
    int dati;
} tDati;

typedef struct{
    int nCamera;
    tDati dati;
} tCamera;

typedef struct tLista{
    tCamera camera;
    struct tLista* next;
    struct tLista* prec;
} tLista;

void Uscita(tLista* libere, tLista* occupate);
tLista* CercaCamera(int nCamera, tLista* lista);
void Menu();
void LiberaCamera(tLista** libere, tLista** occupate);
tLista* EliminaCamera(tLista* elemento);
bool InizializzaLista(tLista** lista);
void OccupaCamera(tLista** libere, tLista** occupate);
tLista* TogliInTesta(tLista** lista);
void InsInTesta(tLista** lista, tLista* elemento);

int main()
{
    tLista* libere;
    tLista* occupate;

    int operazione;

    occupate = NULL;
    libere = NULL;

    if(InizializzaLista(&libere))
    {

        do{
            Menu();

            scanf("%d", &operazione);

            switch(operazione)
            {
            case 1:
                OccupaCamera(&libere, &occupate);
                break;
            case 2:
                LiberaCamera(&libere, &occupate);
                break;
            case 0:
                Uscita(libere, occupate);
                break;
            default:
                printf("Operazione errata!\n");

            }
        }while(operazione != 0);
    }
    else
        printf("errore, impossibile inizializzare la lista\n");
    return 0;
}

bool InizializzaLista(tLista** lista)
{
    int i;

    (*lista) = malloc(sizeof(tLista) * NUM_CAMERE); //Allochiamo la memoria in una sola volta

    if((*lista) != NULL)
    {
        //La prima e l'ultima camera vanno inizializzate a parte
        (*lista[0]).camera.nCamera = 0;
        (*lista[0]).next = &(*lista)[1];
        (*lista[0]).prec = NULL;
        for(i = 1; i < (NUM_CAMERE - 1); i++) //Inizializziamo le camere
        {
            (*lista)[i].camera.nCamera = i;
            (*lista)[i].next = &(*lista)[i+1];
            (*lista)[i].prec = &(*lista)[i-1];
        }
        (*lista)[i].camera.nCamera = i;
        (*lista)[i].next = NULL;
        (*lista)[i].prec = &(*lista)[i-1];

        return true;
    }
    else
        return false;
}

tLista* CercaCamera(int nCamera, tLista* lista)
{
    tLista* corrente;

    bool trovato;

    corrente = lista;
    trovato = false;
    //Scorriamo tutte le camere fin quando non troviamo quela che ci serve
    while((corrente != NULL) && (!trovato))
    {
        if ((*corrente).camera.nCamera == nCamera)
            trovato = true;
        else
            corrente = (*corrente).next;
    }

    return corrente; //Ritorniamo l'indirizzo della camera trovata
}

/*  Per eliminazione si intentende dall'interno di una lista, staccando i puntatori che gli fanno capo
    Il valore di riorno vale NULL se era l'unico elemento della lista, l'elemento stesso se non è il primo della lista
    e l'elemento successivo se è il primo della lista.
    In pratica ritorna la nuova testa della lista o se stesso se non c'è bisogno di aggiornare la testa.
*/
tLista* EliminaCamera(tLista* elemento)
{
    tLista* ris;

    if(((*elemento).next != NULL) || ((*elemento).prec != NULL))
    {
        if((*elemento).next != NULL) //Se esiste un successivo dobbiamo attaccargli il precedente giusto
            (*(*elemento).next).prec = (*elemento).prec;
        if((*elemento).prec != NULL)
        {
            (*(*elemento).prec).next = (*elemento).next;
            /*ris = (*elemento).next;*/ris = elemento;
        }
        else
            /*ris = elemento;*/ris = (*elemento).next;
    }
    else //Se ambedue i puntatori sono NULL vuol dire che l'elemento è l'unico della lista
        ris = NULL;

    (*elemento).prec = NULL;
    (*elemento).next = NULL;

    return ris;
}

void InsInTesta(tLista** lista, tLista* elemento)
{
    if((*lista) != NULL) //Se la list anon è vuota dobbiamo attaccare il precedente
        (*(*lista)).prec = elemento;

    (*elemento).next = (*lista);
    (*elemento).prec = NULL;

    (*lista) = elemento;

    return;
}

tLista* TogliInTesta(tLista** lista)
{
    tLista* corrente;

    if ((*lista) != NULL) //se la lista è vuota non possiamo togliere
    {
        corrente = (*lista); //Salviamoci l'elemento che dobbiamo togliere

        //Attacchaiamo il precedente al valore corretto, il successivo sarà già al giusto valore
        (*lista) = (*(*lista)).next;
        if((*lista) != NULL) //Se la lista è vuota non dobbiamo attaccare il precedente
            (*(*lista)).prec = NULL;

        (*corrente).next = NULL;
        (*corrente).prec = NULL;

        return corrente;
    }
    else
        return NULL;
}

void Menu()
{
    printf("1 - Occupa camera\n");
    printf("2 - Libera camera\n");
    printf("0 - Esci\n");

    return;
}

void OccupaCamera(tLista** libere, tLista** occupate)
{
    tLista* a;

    a = TogliInTesta(libere); //Togliamo una camera da quelle libere
    if(a != NULL)
    {
        InsInTesta(occupate, a); //E inseriamola nella lista di quelle occupate
        printf("Occupata la camera: %d\n", (*a).camera.nCamera);
    }
    else
    {
        printf("Non ci sono camere libere!\n");
    }

    return;
}

void LiberaCamera(tLista** libere, tLista** occupate)
{
    int nCamera;
    tLista* a,* b;

    printf("Inserire il numero della camera da liberare: ");
    scanf("%d", &nCamera);


    a = CercaCamera(nCamera, (*occupate));

    if(a != NULL)
    {
        b = EliminaCamera(a);

        if(b != a) //EliminaCamera ritorna la nuova testa della lista o se stesso, controlliamo se dobbiamo aggiornare la testa della lista
            (*occupate) = b;

        InsInTesta(libere, a); //Reinseriamo la camera nella lista di quelle libere
    }
    else
    {
        printf("Camera non trovata!\n");
    }

    return;
}

void Uscita(tLista* libere, tLista* occupate)
{
    tLista* a;

    //Per liberare la memoria cerchiamo la camera con numero 0
    a = CercaCamera(0,libere);

    if(a == NULL)
        a = CercaCamera(0, occupate);

    if(a != NULL)
        free(a);
    else
        printf("WTF!\n");

    return;
}
