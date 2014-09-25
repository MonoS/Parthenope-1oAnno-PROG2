#include <stdio.h>
#include <stdbool.h>

void UselessFunction(int c);
void StampaBinario(void const * const ptr, size_t const size);

int main()
{
    int d;

    printf("Inserire un numero: ");
    scanf("%d", &d);

    UselessFunction(d);

    return 0;
}

void UselessFunction(int c)
{
    int size;
    int i;
    bool bit[64];
    int sig;
    unsigned int unsig;
    int orig;

    orig = c;

    size = sizeof(c)*8;

    for(i = 0; i <= size; i++) //Popoliamo l'array di bit
    {
        bit[i] = ((c & 1) == 0 ? false : true);
        c = c >> 1;
    }

    sig = 0;
    unsig = 0;
    for(i = 0; i < size; i++) //Inizializiamo la variabile usando la formula data
    {
        sig += ((bit[i] ? 1 : 0) * (1 << i));
        unsig += ((bit[i] ? 1 : 0) * (1 << i));
    }

    if(sig == orig)
        printf("Numero col segno uguale\n");
    else
        printf("Numero col segno diverso\n");

    if(unsig == orig)
        printf("Numero senza segno uguale\n");
    else
        printf("Numero senza segno diverso\n");
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
