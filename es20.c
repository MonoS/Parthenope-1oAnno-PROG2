#include <stdio.h>

float SommaCrescente(float vet[], int n);
float SommaDecrescente(float vet[], int n);

int main()
{
    float vet[7] = {0.000002,0.000003,0.000008,0.000012,0.00002,1.000001,1000};
    int n = 7;
    float sommaCrescente, sommaDecrescente, diff;

    sommaCrescente = SommaCrescente(vet, n);
    sommaDecrescente = SommaDecrescente(vet, n);
    diff = sommaDecrescente - sommaCrescente;

    //Sommando i valori dal pi� piccolo al pi� grande si ottiene una maggiore precisione in quanto il tipo float non
    //pu� mostrare contemporaneamente valori molto grandi e valori molto piccoli.
    //Sommando in manira crescente i numeri pi� piccoli andranno man mano a sommarsi insieme diventando un numero pi� grande,
    //mentre facendo al contrario i numeri pi� piccoli verrano persi perch� sovrastati da quelli pi� grandi

    printf("%f\n%f\n%f\n", sommaCrescente, sommaDecrescente, diff);
    return 0;
}

float SommaCrescente(float vet[], int n)
{
    int i;
    float somma;

    for(i = 0, somma = 0; i < n; i++)
        somma += vet[i];

    return somma;
}

float SommaDecrescente(float vet[], int n)
{
    int i;
    float somma;

    for(i = n - 1, somma = 0; i >= 0; i--)
        somma += vet[i];

    return somma;
}
