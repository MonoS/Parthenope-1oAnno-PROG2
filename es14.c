#include <math.h>
#include <stdio.h>
#include <float.h>

int main()
{
    float flt, flt2;
    double dbl, dbl2;
    //long double ldbl, ldbl2;

    for(flt = 1.0, flt2 = flt + 1.0; flt2 != 1.0; flt/=2, flt2 = 1.0 + flt);

    flt *= 2.0;

    printf("Epsilon float std: %e\n", FLT_EPSILON);
    printf("Epsilon float mio: %e\n", flt);

    for(dbl = 1.0, dbl2 = dbl + 1.0; dbl2 != 1.0; dbl/=2, dbl2 = 1.0 + dbl);

    dbl *= 2.0;

    printf("Epsilon double std: %e\n", DBL_EPSILON);
    printf("Epsilon double mio: %e\n", dbl);

    /*
    for(ldbl = 1.0, ldbl2 = ldbl + 1.0; ldbl2 != 1.0; ldbl/=2, ldbl2 = 1.0 + ldbl);

    ldbl *= 2;

    printf("Epsilon double std: %Lf\n", LDBL_EPSILON);
    printf("Epsilon double mio: %Lf\n", ldbl);
    */

    return 0;
}

