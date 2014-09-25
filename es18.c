#include <stdio.h>
#include <stdlib.h>

const int ITER = 100000000;
const float X = 0.000001;

float SommaBlocchi(float vet[], int n);

int main()
{
    float* vet;
    int i;
    float ris;

    vet = malloc(sizeof(float)*ITER); //Dobbiamo usare malloc altrimenti il nostro caro amico SIGSEGV si arrabbia

    for(i = 0; i < ITER; i++)
        vet[i] = X;

    ris = SommaBlocchi(vet, ITER);

    printf("%f", ris);

    return 0;
}

float SommaBlocchi(float vet[], int n)
{
    int nHalf;
    int i;

    while(n > 1)
    {
        for(i = 0, nHalf = n/2; i < nHalf; i++)
            vet[i] = vet[i] + vet[n - i - 1];

        if(n%2 == 1)
            n = nHalf + 1;
        else
            n = nHalf;
    }

    return vet[0];
}
