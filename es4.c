#include <stdio.h>

char EstraiMask(char c, int nBit);
char EstraiShift(char c, int nBit);
char EstraiDiv(char c, int nBit);
void StampaBinario(void const * const ptr, size_t const size);

int main()
{
    char c;
    char bitMask, bitShift, bitDiv;
    int bit;

    printf("Inserisci un carattere: ");
    scanf("%c", &c);

    printf("Rappresentazione binaria: ");
    StampaBinario(&c, sizeof(c));

    printf("Quantita di bit da estrarre (negativi meno significativi): ");
    scanf("%d", &bit);

    bitMask = EstraiMask(c, bit);
    bitShift = EstraiShift(c, bit);
    bitDiv = EstraiDiv(c, bit);

    printf("Bit estratti (rispettivamente mask, shift e div):\n");
    StampaBinario(&bitMask, sizeof(bitMask));
    StampaBinario(&bitShift, sizeof(bitShift));
    StampaBinario(&bitDiv, sizeof(bitDiv));

    return 0;

}
char EstraiMask(char c, int nBit)
{
    int size;
    int mask;

    size = sizeof(c)*8;

    //Controlliamo se dobbiamo ruotare a destra o a sinistra
    if(nBit > 0)
    {   //Prendo i più significativi
        if (nBit > size)
            nBit = size;

        if(nBit > 0)
        {
            mask = (((1 << nBit) - 1) //Contruiamo la maschera
                     << (size - nBit)); //Spostiamo la maschera nella giusta posizione

            c = ((c & mask) //Applichiamo la maschera per ottenere i bit che devono essere salvati
                   >> (size - nBit)); //e spostiamola nella posizione corretta
        }
    }
    else
    { //Prendo i meno significativi
        nBit = -nBit;
        if (nBit > size)
            nBit = size;

        if(nBit > 0)
        {
            mask = ((1 << nBit) - 1);

            c = (c & mask);
        }
    }

    return c;
}
char EstraiShift(char c, int nBit)
{
    int size;
    char fin;
    int i;

    size = sizeof(c)*8;

    //Controlliamo se dobbiamo ruotare a destra o a sinistra
    if(nBit > 0)
    {   //Prendo i più significativi
        if (nBit > size)
            nBit = size;

        fin = (c >> (size - nBit)); //Shiftiamo verso destra per eliminare le cifre che non ci servono
    }
    else
    {   //Prendo i meno significativi
        nBit = -nBit;
        if (nBit > size)
            nBit = size;

        for(i = 0, fin = 0; i < nBit; i++)
        {
            fin = fin | ((c & 1) << i); //Prendiamo il primo bit del numero
            c = c >> 1; //shiftiamo l'originale verso destra per passare al prossimo
        }
    }

    return fin;
}

char EstraiDiv(char c, int nBit)
{
    int size;
    char fin;
    int i;

    size = sizeof(c)*8;

    //Controlliamo se dobbiamo ruotare a destra o a sinistra
    if(nBit > 0)
    {   //Prendo i più significativi
        if (nBit > size)
            nBit = size;

        fin = c / (1 << (size - nBit)); //Dividiamo il numero di una potenza di 2 opportuna per eliminare i valori che non ci servono
    }
    else
    {   //Prendo i meno significativi
        nBit = -nBit;
        if (nBit > size)
            nBit = size;

        for(i = 0, fin = 0; i < nBit; i++)
        {
            fin = fin | ((c & 1) * (1 << i));
            c = c / 2;
        }
    }

    return fin;
}

void StampaBinario(void const * const ptr, size_t const size)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = b[i] & (1<<j);
            byte >>= j;
            printf("%u", byte);
        }
    }
    puts("");
}
