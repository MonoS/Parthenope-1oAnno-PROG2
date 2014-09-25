#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    double dbl;
    float flt;
    unsigned short* temp;

    int i;

    temp = &dbl;

    for(i = 0, srand(time(NULL)); i < 4; i++)
        temp[i] = rand();

    flt = (float) dbl;

    printf("%e %e\n", flt, dbl);
    printf("L'errore assoluto e': %e\nL'errore relativo e': %e", fabsf(dbl - flt), fabsf((dbl - flt)/dbl));
    return 0;
}
