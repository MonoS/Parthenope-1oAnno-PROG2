#include <stdio.h>

int CambioBase2to10(unsigned int n, char cifre[]);

int main()
{
    int n;
    char cifre[64];
    int i;
    int numCifre;

    printf("Inserire il numero da convertire: ");
    scanf("%ud", &n);

    numCifre = CambioBase2to10(n, cifre);

    for(i = numCifre - 1; i >= 0; i--)
        printf("%c", cifre[i]);

    return 0;
}

int CambioBase2to10(unsigned int n, char cifre[])
{
    int k;

    k = 0;

    do{
        cifre[k] = ((n % 10) + 48); //Prendiamo la cifra decimale
        n = n/10; //E andiamo avanti

        k++;
    }while (n > 0);

    cifre[k] = '\0';

    return k;
}
