#include <stdio.h>

int SottrazioneBitwise(int a, int b);

int main()
{
    int a, b, ris;

    printf("Inserire i due numeri separati da spazio: ");
    scanf("%d %d", &a, &b);

    if(b > a) //Assicuriamoci che il primo operando sia maggiore del secondo
    {
        ris = b;
        b = a;
        a = ris;
    }

    ris = SottrazioneBitwise(a,b);

    printf("Risultato: %d", ris);

    return 0;
}

int SottrazioneBitwise(int a, int b)
{
    int dif, rip;

    do
    {
        dif = a ^ b;
        rip = ((~a) & b) << 1;
        a = dif;
        b = rip;

    }while(rip > 0);

    return dif;
}
