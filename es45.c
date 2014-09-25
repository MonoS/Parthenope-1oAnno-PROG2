#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct tElemento{
    int valore;
    struct tElemento* next;
    int riga;
    int colonna;
} tElemento;

typedef struct{
    tElemento* elem;
} tRiga;

typedef struct{
    tElemento* elem;
} tColonna;

typedef struct{
    int righe;
    int colonne;
    tRiga* riga;
    tColonna* colonna;
} tMatrice;

tMatrice* InizializzaMatriceSparsa(int righe, int colonne);
int Inserisci(tMatrice* matrice, int riga, int colonna, int valore);
int CercaElemento(tMatrice* matrice, int riga, int colonna);
tMatrice* ProdottoMatrici(tMatrice* a, tMatrice* b);
void StampaMatrice(tMatrice* a);

int main()
{
    tMatrice *a, *b, *c;

    a = InizializzaMatriceSparsa(3,3);
    Inserisci(a,0,2,1);
    Inserisci(a,1,0,2);
    Inserisci(a,2,1,3);

    StampaMatrice(a);

    b = InizializzaMatriceSparsa(3,5);
    Inserisci(b,0,0,4);
    Inserisci(b,1,2,5);
    Inserisci(b,2,4,6);

    StampaMatrice(b);

    c = ProdottoMatrici(a, b);

    StampaMatrice(c);

    return 0;
}

tMatrice* InizializzaMatriceSparsa(int righe, int colonne)
{
    tMatrice* matrice;

    int i;

    matrice = malloc(sizeof(tMatrice));

    if(matrice != NULL)
    {
        matrice->righe = righe;
        matrice->colonne = colonne;

        matrice->riga = malloc(sizeof(tRiga)*righe);
        matrice->colonna = malloc(sizeof(tColonna)*colonne);

        //Inizializiamo i vettori di righe e colonne
        for(i = 0; i < righe; i++)
            matrice->riga[i].elem = NULL;

        for(i = 0; i < colonne; i++)
            matrice->colonna[i].elem = NULL;
    }

    return matrice;
}
//Inserisce all'interno della matrice sparsa un elemento
//Gli elementi non sono ordinati per indice, ma inseriti in coda alla lista
int Inserisci(tMatrice* matrice, int riga, int colonna, int valore)
{
    int ris;

    tElemento* elem;
    tElemento* elemCur;

    if(valore != 0)
    {
        if((matrice->colonne > colonna) && (matrice->righe > riga))//Controlliamo le coordinate
        {
            if(CercaElemento(matrice, riga, colonna) == 0) //Controlliamo che quella cella non ci sia già
            {
                elemCur = malloc(sizeof(tElemento));

                if(elemCur != NULL) //Controlliamo se la cella è stata allocata con successo
                {
                    //Scorriamo la lista della riga per trovare il posto
                    elem = matrice->riga[riga].elem;
                    if(elem == NULL)
                        elem = matrice->riga[riga].elem = elemCur;
                    else
                    {
                        while(elem->next != NULL)
                            elem = elem->next;

                        elem->next = elemCur;
                    }
                    //Scorriamo la lista della colonna per trovare il posto
                    elem = matrice->colonna[colonna].elem;
                    if(elem == NULL)
                        elem = matrice->colonna[colonna].elem = elemCur;
                    else
                    {
                        while(elem->next != NULL)
                            elem = elem->next;

                        elem->next = elemCur;
                    }

                    //inizializziamo l'elemento
                    elemCur->colonna = colonna;
                    elemCur->riga = riga;
                    elemCur->next = NULL;
                    elemCur->valore = valore;

                    ris = 0; //YAYFICATION
                }
                else
                    ris = -3; //È finita la memoria
            }
            else
                ris = -2; //Quella cella esiste già
        }
        else
            ris = -1; //La cella è fuori dalla matrice
    }
    else
        ris = -4; //Il valore non può essere 0

    return ris;
}

//Gli elementi verranno cercati solo per riga, non c'è guadagno a cercare per righe o per colonne in quanto
//la deferenzazione non permetterà il caching degli elementi, inoltre, essendo gli elementi non inseriti in
//ordine, privileggiare la dimensione con indice minore non assicura un minor numero di dereferenzazioni
int CercaElemento(tMatrice* matrice, int riga, int colonna)
{
    tElemento* elem;
    bool trovato;

    //Cerchiamo l'elemento tra le righe
    elem = matrice->riga[riga].elem; trovato = false;
    while((elem != NULL) && (!trovato))
    {
        if((elem->riga == riga) && (elem->colonna == colonna))
            trovato = true;
        else
            elem = elem->next;
    }

    if(trovato)
        return elem->valore;
    else
        return 0;
}

tMatrice* ProdottoMatrici(tMatrice* a, tMatrice* b)
{
    tMatrice* c;

    int i, j, k;
    int somma;

    if(a->colonne == b->righe)
    {
        c = InizializzaMatriceSparsa(a->righe, b->colonne);

        if(c != NULL)
        {
            for(i = 0; i < a->righe; i++)
                for(j = 0; j < b->colonne; j++)
                {
                    for(k = 0, somma = 0; k < a->colonne; k++)
                        somma += CercaElemento(a,i,k) + CercaElemento(b,k, j);

                    Inserisci(c,i,j,somma);
                }
        }
    }
    else
        c = NULL;

    return c;
}

void StampaMatrice(tMatrice* a)
{
    int i, j;

    for(i = 0; i < a->righe; i++)
    {
        for(j = 0; j < a->colonne; j++)
            printf("%d ", CercaElemento(a, i, j));

        printf("\n");
    }

    return;
}
