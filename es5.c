#include <stdio.h>
#include <stdbool.h>

void CambioBase10to2Div(unsigned int n, bool bit[]);
void CambioBase10to2Shift(unsigned int n, bool bit[]);
void StampaBinario(void const * const ptr, size_t const size);

int main()
{
    unsigned int d;
    bool bitDiv[64];
    bool bitShift[64];
    int i;

    printf("Inserire il numero da convertire: ");
    scanf("%d", &d);

    CambioBase10to2Div(d, bitDiv);
    CambioBase10to2Shift(d, bitShift);

    StampaBinario(&d, sizeof(d));

    printf("\nBit usando divisioni:\n");
    for(i = ((sizeof(d) * 8) - 1); i >= 0; i--)
        printf("%c", (bitDiv[i] ? '1' : '0'));

    printf("\nBit usando shift:\n");
    for(i = ((sizeof(d) * 8) - 1); i >= 0; i--)
        printf("%c", (bitShift[i] ? '1' : '0'));

    return 0;
}

void CambioBase10to2Div(unsigned int n, bool bit[])
{
    int k, j;

    k = 0;
    do
    {
        bit[k] = (n % 2 == 0 ? false : true); //Controlliamo il valore della prima cifra
        n = n/2; //Shiftiamo per andare alla prossima

        k++; //Questa variabile ci serve dopo, non controlla il ciclo
    }while(n > 0);

    for(j = k; j < ((sizeof(n))*8); j++) //Riempiamo le altre caselle con 0
        bit[j] = false;

    return;
}

void CambioBase10to2Shift(unsigned int n, bool bit[])
{
    int k, j;

    k = 0;
    do
    {
        bit[k] = (n % 2 == 0 ? false : true);
        n = n>>1;

        k++;
    }while(n > 0);

    for(j = k; j < ((sizeof(n))*8); j++)
        bit[j] = false;

    return;
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
