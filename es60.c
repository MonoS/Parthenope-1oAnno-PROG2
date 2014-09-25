#include <stdio.h>

float SommaVetIter(float vet[], int n);
float SommaVetRicLin(float vet[], int n);
float SommaVetRicBin(float vet[], int n);

int main()
{
    float vet[9] = {1,2,3,4,5,6,7,8,9};

    printf("Somma da 1 a 9\n");
    printf("Iterativa: %f\n", SommaVetIter(vet, 9));
    printf("Ric. lin.: %f\n", SommaVetRicLin(vet, 9));
    printf("Ric. bin.: %f\n", SommaVetRicBin(vet, 9));
    return 0;
}

float SommaVetIter(float vet[], int n)
{
    int i;
    float somma;

    for(i = 0, somma = 0; i < n; i++)
        somma += vet[i];

    return somma;
}

float SommaVetRicLin(float vet[], int n)
{
    if(n <= 1)
        return vet[0];
    else
        //Passo il vettore meno il primo elemento
        return SommaVetRicLin(&vet[1], n - 1) + vet[0];
}

float SommaVetRicBin(float vet[], int n)
{
    if(n < 1)
        return 0;
    else if(n == 1)
        return vet[0];
    else //Passo la parte sinistra e destra del vettore
        return SommaVetRicBin(&vet[0], n / 2) + SommaVetRicBin(&vet[n / 2], n - (n/2));
}
