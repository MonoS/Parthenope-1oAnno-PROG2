#include <float.h>
#include <stdio.h>

float CalcolaULP(float x);

int main()
{
    float flt;

    printf("Inserire il numero float di cui calcolare l'ULP: ");
    scanf("%f", &flt);

    printf("L'ULP di %f e': %f", flt, CalcolaULP(flt));

    return 0;
}

float CalcolaULP(float x)
{
    int mask;
    int esp;
    float ulp;
    unsigned int* flt;

    flt = &x;

    mask = (((1 << 8) - 1) << 23);

    esp = (*flt & mask) >> 23;

    ulp = esp * FLT_EPSILON;

    return ulp;
}
