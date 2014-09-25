#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

double Sommatoria(int x);
double Fact(int x);

int main()
{
    int i;

    printf("Inserire il valore della potenza: ");
    scanf("%d", &i);

    printf("%lf\n%lf", Sommatoria(i), pow(M_E, i)); //Confrontiamo il valore ottenuto con quello reale

    return 0;
}

double Sommatoria(int x)
{
    float succ[256];
    int i;

    succ[0] = 1.0; succ[1] = succ[0] + (pow(x, 1) / Fact(1)); //Calcoliamo i primi due valori della successione
    i = 1;
    //Confrontare due float tra di loro is 0xabad1dea
    //Cicliamo fin quando il valore attuale è uguale a quello precedente
    while((succ[i] - succ[i - 1]) > FLT_EPSILON)
    {
        i++;
        succ[i] = succ[i - 1] + (pow(x, i) / Fact(i)); //calcolare il membro della successione
    }

    return succ[i];
}

double Fact(int x)
{
    if (x < 0)
        return -1;

    if (x == 0)
        return 1;
    else
        return x*Fact(x-1);
}
