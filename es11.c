#include <stdio.h>

int SommaBitwise(int a, int b);

int main()
{
    int a, b;

    printf("Inserire i due numeri separati da spazio: ");
    scanf("%d %d", &a, &b);

    printf("Il risultato e': %d", SommaBitwise(a, b));

    return 0;
}

int SommaBitwise(int a, int b)
{
    int rip;
    int somma;

    //Se ambedue i numeri sono negativi ne facciamo il complemento
    if((a < 0) && (b < 0))
    {
        a = ((~a)+1);
        b = ((~b)+1);

        do{
            somma = a ^ b;
            rip = a & b;
            rip = rip << 1;

            a = somma; b = rip;
        }while (rip > 0);

        somma = ((~somma)+1);
    }
    else
    {
        do{
            somma = a ^ b;
            rip = a & b;
            rip = rip << 1;

            a = somma; b = rip;
        }while (rip > 0);
    }

    return somma;
}
