#include <stdio.h>

int AddizioneBitwise(int a, int b);

int main()
{
    int a, b, ris;

    printf("Inserire i due numeri separati da spazio: ");
    scanf("%d %d", &a, &b);

    ris = AddizioneBitwise(a,b);

    printf("Risultato: %d", ris);

    return 0;
}

int AddizioneBitwise(int a, int b)
{
    int rip;
    int somma;

    do{
        somma = a ^ b;
        rip = a & b;
        rip = rip << 1;

        a = somma; b = rip;
    }while (rip > 0);

    return somma;
}
