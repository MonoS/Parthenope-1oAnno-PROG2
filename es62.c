#include <stdio.h>

double HornerRico(float x, double coeff[], int n);
double HornerIter(float x, double coeff[], int n);

int main()
{
    double coeff[6] = {512.f, -1280.f, 1120.f, -400.f, 50.f, -1.f};
    int n = 6;
    float x;

    printf("Inserisci il valore di x: ");
    scanf("%f", &x);

    printf("Horner Iterativo: %e\n", HornerIter(x, coeff, n));
    printf("Horner Ricorsivo: %e\n", HornerRico(x, coeff, n - 1));
    return 0;
}

double HornerRico(float x, double coeff[], int n)
{
    if(n == 0)
        return coeff[0];
    else
        return (coeff[n] + (x * HornerRico(x, coeff, n - 1)));
}
double HornerIter(float x, double coeff[], int n)
{
    double ris;
    int i;

    for(i = 0, ris = 0; i < n - 1; i++)
    {
        ris += coeff[i];
        ris *= x;
    }

    ris += coeff[i];

    return ris;
}
