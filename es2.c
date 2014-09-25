#include <stdio.h>

char rotate(char c, char nBit);
void StampaBinario(void const * const ptr, size_t const size);

int main()
{
    char c;
    int rot;

    printf("Inserisci un carattere: ");
    scanf("%c", &c);

    printf("Rappresentazione binaria: ");
    StampaBinario(&c, sizeof(c));

    printf("Valore della rotazione (valori negativi rotazione verso destra): ");
    scanf("%d", &rot);

    c = rotate(c, rot);

    printf("Rappresentazione binaria: ");
    StampaBinario(&c, sizeof(c));

    return 0;
}

char rotate(char c, char nBit)
{
    int size;
    int mask;
    int rot;

    size = sizeof(c)*8;

    //Controlliamo se dobbiamo ruotare a destra o a sinistra
    if(nBit > 0)
    {   //Prendiamo a sinistra
        nBit = nBit%size; //Otteniamo il modulo per evitare lavoro di costruzione inutile
        if(nBit > 0)
        {
            mask = (((1 << nBit) - 1) //Contruiamo la maschera
                     << (size - nBit)); //Spostiamo la maschera nella giusta posizione

            rot = ((c & mask) //Applichiamo la maschera per ottenere i bit che devono essere salvati
                   >> (size - nBit)); //e spostiamola nella posizione corretta

            c = c << nBit; //Shiftiamo la variabile delle posizioni necessarie
            c = c | rot; //Aggiungiamo i bit che sono stati eliminati dallo shift
        }
    }
    else
    {   //Prendiamo a destra
        nBit = -nBit;
        nBit = nBit % size;
        if(nBit > 0)
        {
            mask = ((1 << nBit) - 1);

            rot = ((c & mask) << (size - nBit));

            c = c >> nBit;
            c = c | rot;
        }
    }

    return c;
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
