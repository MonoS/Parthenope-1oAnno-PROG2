#include <stdio.h>

#define MAX_GRADO 17
#define MAX_NODI 128

typedef struct{
    int elem;

    int grado;
    int figli[MAX_GRADO];
} tNodo;

typedef struct{
    int elem;
    int padre;
} tEsempio;

int InsNodo(int elem, int padre, tNodo albero[], int maxNodi, int* numNodi);
void Visita(tNodo albero[], int nodo);

int main()
{
    tNodo albero[MAX_NODI];
    int numNodi;
    /*           ________0__________
             ___/        |          \_______
            1            3                  6
         __/         ___/ \___          ___/
        2           4         5        7
                                     _/
                                    8
    */
    tEsempio esempio[9] = {{0, -1}, {1, 0}, {2, 1}, {3, 0}, {4, 3}, {5, 3}, {6, 0}, {7, 6}, {8, 7}};

    int i;

    numNodi = 0;

    for(i = 0; i < 9; i++)
        InsNodo(esempio[i].elem, esempio[i].padre, albero, MAX_NODI, &numNodi);

    Visita(albero, 0);


    return 0;
}

int InsNodo(int elem, int padre, tNodo albero[], int maxNodi, int* numNodi)
{
    int errore;

    if((padre >= -1) && (padre < maxNodi))
    {
        if(padre > -1)
        {
            if(padre < (*numNodi))
            {
                if(albero[padre].grado < MAX_GRADO)
                {
                    albero[(*numNodi)].elem = elem;
                    albero[(*numNodi)].grado = 0;

                    albero[padre].figli[albero[padre].grado] = (*numNodi);

                    albero[padre].grado++;
                    (*numNodi)++;

                    errore = 0;
                }
                else
                    errore = -3; //Il padre non può avere più figli di Kody Brown
            }
            else
                errore = -2; //Il padre specificato non esiste
        }
        else //Se il padre è definito come -1 stiamo inserendo la radice
        {
            if((*numNodi) == 0)
            {
                albero[0].elem = elem;
                albero[0].grado = 0;
                (*numNodi)++;

                errore = 0;
            }
            else
                errore = -4; //La radice già esiste

        }
    }
    else
        errore = -1; //Nodo non esistente

    return errore;
}

void Visita(tNodo albero[], int nodo)
{
    int i;

    printf("%d\n", albero[nodo].elem);

    for(i = 0; i < albero[nodo].grado; i++)
        Visita(albero, albero[nodo].figli[i]);

    return;
}
