#include <stdio.h>
#include <stdlib.h>

int CambioBase2to10(char num[], char cifre[]);

int main()
{
    char num[65];
    char cifre[64];
    int i;
    int numCifre;

    printf("Inserire le cifre binarie del numero: ");
    scanf("%64s", num);

    numCifre = CambioBase2to10(num, cifre);

    for(i = numCifre - 1; i >= 0; i--)
        printf("%c", cifre[i]);

    return 0;
}

int CambioBase2to10(char num[], char cifre[])
{
    int n;
    int k;

    n = strtol(num, NULL, 2); //Convetiamo le cifre binarie in un numero

    k = 0;
    do{
        cifre[k] = ((n % 10) + 48); //Prendiamo la cifra decimale
        n = n/10; //E andiamo avanti

        k++;
    }while (n > 0);

    cifre[k] = '\0';

    return k;
}

