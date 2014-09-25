#include <stdio.h>

const int POS_ESP = 8;
const int POS_MAN = 23;

void EstraiFloat(float a);
void StampaBinario(void const * const ptr, size_t const size);

int main()
{
    float a;

    printf("Inseire il numero float da controllare: ");
    scanf("%f", &a);

    EstraiFloat(a);

    return 0;
}

void EstraiFloat(float a)
{
    unsigned int mantissa;
    unsigned int esp;
    unsigned int segno;

    unsigned int mask;

    unsigned int* flt;

    flt = &a; //Hack per poter utilizzare gli operatori bitwise su un float

    printf("numero:        "); StampaBinario(flt, 4);

    mask = ((1 << (POS_MAN)) - 1); //Contruiamo la maschera per la mantissa

    printf("mask mantissa: "); StampaBinario(&mask, 4);

    mantissa = ((*flt)&mask); //Estraiamo la mantissa

    mask = ((( 1 << (POS_ESP)) - 1) << POS_MAN); //Contruiamo la maschera per l'esponente

    printf("mask esp:      "); StampaBinario(&mask, 4);

    esp = ((*flt)&mask)>>POS_MAN; //Estriamo l'esponente

    mask = 1 << (POS_ESP + POS_MAN); //Costruiamo la maschera per il segno

    printf("mask segno:    "); StampaBinario(&mask, 4);

    segno = ((*flt)&mask)>>(POS_ESP + POS_MAN); //Estraiamo il segno

    //Stampiamo i valori ottenuti allineandoli al numero originale
    printf("Mantissa:              "); StampaBinario(&mantissa, 3);
    printf("Esponente:      "); StampaBinario(&esp, 1);
    printf("Segno:  "); StampaBinario(&segno, 1);
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
