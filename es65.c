#include <stdio.h>
#include <math.h>
#include <float.h>

double Funzione(double x);
void TrovaIntervallo(double a, double b, double* inter_a, double* inter_b, double(*funzione)(double));

int main()
{
    double a, b;
    double inter_a, inter_b;

    a = 0.5;
    b = 2;
    inter_a = 0;
    inter_b = 0;

    TrovaIntervallo(a, b, &inter_a, &inter_b, &Funzione);
    printf("Estremi di ricerca: [%e, %e]\n", a, b);
    printf("Zero trovato nell'intervallo: [%e,%e]\n", inter_a, inter_b);
    return 0;
}

void TrovaIntervallo(double a, double b, double* inter_a, double* inter_b, double(*funzione)(double))
{
    if(fabs(funzione(a) - funzione(b)) < DBL_EPSILON * 2)
    {
        (*inter_a) = a; (*inter_b) = b;
        return;
    }
    else
    {
        double meta = (a + b) / 2;

        if((funzione(a) * funzione(meta)) < 0)
        {
            TrovaIntervallo(a, meta, inter_a, inter_b, funzione);
            return;
        }
        else
        {
            TrovaIntervallo(meta, b, inter_a, inter_b, funzione);
            return;
        }
    }
}
double Funzione(double x)
{
    return log10(x);
}
