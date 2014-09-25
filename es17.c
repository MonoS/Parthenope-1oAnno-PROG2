#include <stdio.h>
#include <math.h>

float HornerSP(float x);
double HornerDP(float x);

int main()
{
    float SP;
    double DP;
    float x;

    printf("Ver Estesa: 512x^10 - 1280x^8 + 1120x^6 - 400x^4 + 50x^2 - 1\n");
    printf("Ver Horner: ((((512x^2 - 1280)x^2 + 1120)x^2 - 400)x^2 + 50)x^2 - 1\n");

    printf("Inserire il valore di x: ");
    scanf("%f", &x);

    SP = HornerSP(x);
    DP = HornerDP(x);

    printf("SP: %e\nDP: %e\n", SP, DP);

    printf("Errore relativo: %e", fabs((DP - SP)/DP));
    return 0;
}

float HornerSP(float x)
{
    double X = x*x;
    return ((((512*X - 1280)*X + 1120)*X - 400)*X + 50)*X - 1;
}

double HornerDP(float x)
{
    double X = x*x;
    return ((((512*X - 1280)*X + 1120)*X - 400)*X + 50)*X - 1;
}
